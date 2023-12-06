//
// Created by popma on 12/6/2023.
//

#include "MENIU.h"

bool Meniu::verificaIndex(int index) const {
    if (index < 0 || index >= masini.size())
        return false;
    return true;
}

void Meniu::afiseazaMeniu() const {
    cout << "----- MENIU -----\n";

    cout << "1. Adauga masina noua\n";
    cout << "2. Modifica masina\n";
    cout << "3. Sterge masina\n";
    cout << "4. Afiseaza masini\n";
    cout << "5. Calculeaza range-ul unei masini\n";
    cout << "6. Apeleaza functie masina hibrid\n";
    cout << "0. Inchide aplicatia\n";
}

void Meniu::startMeniu() {
    this->afiseazaMeniu();

    while(true) {
        int option;
        cout << "Introdu optiune:\n";
        cin >> option;
        cin.get();
        try{
            switch (option) {
                case 0: {
                    return;
                }
                case 1: {
                    Dealership* d = new Dealership();
                    cin >> *d;

                    this->masini.push_back(d);

                    this->afiseazaMeniu();
                    break;
                }
                case 2: {
                    try{
                        int index;
                        if(!masini.empty()) {
                            for (int i = 0; i < masini.size(); ++i) {
                                cout << "Masina: " << i << "\n\tBrand: " << masini[i]->getMasina()->getBrand()<<"\n";
                            }
                            cout << "Introdu index:\n";
                            cin >> index;
                            cin.get();

                            if (this->verificaIndex(index)) {
                                cin >> *(masini[index]->getMasina());
                            }
                            else throw logic_error("INDEX INVALID!\n");
                        }
                        else throw logic_error("NU EXISTA MASINI!\n");
                        this->afiseazaMeniu();

                    }catch(logic_error& e){
                        cout<<e.what();
                    }
                    break;
                }
                case 3: {
                    try{
                        int index;
                        if(!masini.empty()) {
                            for (int i = 0; i < masini.size(); ++i) {
                                cout << "Masina: " << i << "\n\tBrand: " <<     masini[i]->getMasina()->getBrand()<<"\n";
                            }
                            cout << "Introdu index:\n";
                            cin >> index;
                            cin.get();

                            if (this->verificaIndex(index)) {
                                this->masini.erase(this->masini.begin() + index);
                                cout << "~ MASINA STEARSA\n";
                            }
                            else throw logic_error("INDEX INVALID!\n");
                        }
                        else throw logic_error("NU EXISTA MASINI!\n");
                        this->afiseazaMeniu();
                    }catch(logic_error& e){
                        cout<<e.what();
                    }
                    break;
                }
                case 4: {
                    try{
                        if(!masini.empty()) {
                            for (auto it:masini) {
                                if (typeid(*it->getMasina()) == typeid(MasinaCombustibil))
                                    cout<<"------------------MASINA COMBUSTIBIL------------------\n\n";
                                else if (typeid(*it->getMasina()) == typeid(Electrica))
                                    cout<<"------------------MASINA ELECTRICA------------------\n";
                                else if (typeid(*it->getMasina()) == typeid(MasinaHibrid))
                                    cout<<"------------------MASINA HIBRID------------------\n";
                                cout << *it;
                                cout<<"-----------------------------------------------------\n\n";
                            }
                        }
                        else throw logic_error("NU EXISTA MASINI!\n");
                        this->afiseazaMeniu();
                    }catch(logic_error& e){
                        cout<<e.what();
                    }
                    break;
                }
                case 5: {
                    try{
                        if(!masini.empty()) {
                            for (int i = 0; i < masini.size(); ++i) {
                                cout << "Masina: " << i << "\n\tBrand: " << masini[i]->getMasina()->getBrand()<<"\n";
                            }
                            cout << "Introdu index:\n";
                            int index;
                            cin >> index;
                            cin.get();
                            if (this->verificaIndex(index)) {
                                masini[index]->getMasina()->findRange();
                            }
                            else throw logic_error("INDEX INVALID!\n");
                        }
                        else throw logic_error("NU EXISTA MASINI!\n");
                        this->afiseazaMeniu();
                    }catch(logic_error& e){
                        cout<<e.what();
                    }catch(runtime_error& e){
                        cout<<e.what();
                    }
                    this->afiseazaMeniu();
                    break;
                }
                default:
                    throw OptiuneInvalida();
            }
        }catch(OptiuneInvalida& e){
            cout<<e.what()<<endl;
        }
    }
}