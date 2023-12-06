#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <typeinfo>

using namespace std;

class OptiuneInvalida : public exception{
public:
    const char* what() const throw(){
        return "Optiune invalida!";
    }
};

class IOInterface {
public:
    virtual istream& read(istream& in) = 0;
    virtual ostream& print(ostream& out) const = 0;
};

class Vehicul : public IOInterface {
protected:
    string culoare, brand;
    int anFabricatie;
    const int id;
    static int contorID;

public:
    Vehicul(string culoare = "negru", string brand = "Necunoscut", int anFabricatie = 1990);
    Vehicul(const Vehicul& obj);
    virtual ~Vehicul();
    Vehicul &operator=(const Vehicul& obj);

    istream& read(istream& in);
    ostream& print(ostream& out) const;

    friend istream &operator>>(istream& in, Vehicul& obj);
    friend ostream &operator<<(ostream& out, const Vehicul& obj);

    static int getContorID() {
        return contorID;
    }

    // TODO: functie noua aici
    string getBrand() const {return this->brand;}
    virtual int getID() const { return this->id;}
};

int Vehicul::contorID = 0;

Vehicul::Vehicul(string culoare, string brand, int anFabricatie):id(contorID++) {
    this->culoare = culoare;
    this->brand = brand;
    this->anFabricatie = anFabricatie;
}

Vehicul::~Vehicul() {
    if (!this->culoare.empty()) this->culoare.clear();
    if (!this->brand.empty()) this->brand.clear();
}

Vehicul::Vehicul(const Vehicul &obj):id(contorID++) {
    this->culoare = obj.culoare;
    this->brand = obj.brand;
    this->anFabricatie = obj.anFabricatie;
}

Vehicul &Vehicul::operator=(const Vehicul &obj) {
    if (this != &obj) {
        this->culoare = obj.culoare;
        this->brand = obj.brand;
        this->anFabricatie = obj.anFabricatie;
    }

    return *this;
}

istream& Vehicul::read(istream &in) {
    cout << "Introdu culoare: " << endl;
    in >> this->culoare;

    cout << "Introdu nume brand: " << endl;
    in >> this->brand;

     while (true) {
         cout << "Introdu an fabricatie: " << endl;
         in >> this->anFabricatie;

         if (in.fail()) {
             cout<<"INVALID! Introduceti un numar!\n";
             in.clear();
             in.ignore(numeric_limits<streamsize>::max(), '\n');
         } else {
             break;
         }
     }
    while (true) {
        try {
            cout << "Introdu an fabricatie: " << endl;
            in >> this->anFabricatie;

            if (in.fail()) {
                throw runtime_error("INVALID! Introduceti un numar!\n");
            } else {
                break;  // daca s a citit input valid break the loop
            }
        } catch (const runtime_error& e) {
            cout << e.what();
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    return in;
}

istream &operator>>(istream& in, Vehicul& obj) {
    return obj.read(in);
}

ostream& Vehicul::print(ostream &out) const {
    out << "\t Vehicul cu id: " << this->id <<endl;
    out << "Culoare: " << this->culoare <<endl;
    out << "Brand " << this->brand << endl;
    out << "An Fabricatie: " << this->anFabricatie << endl;

    return out;
}

ostream &operator<<(ostream& out, const Vehicul& obj) {
    return obj.print(out);
}

class Masina:public Vehicul {
protected:
    float volumPortbagaj, vitezaMaxima;
    int nrUsi;

public:

    Masina(string culoare = "negru", string brand = "Necunoscut", int anFabricatie = 1990,
           float volumPortbagaj = 0, float vitezaMaxima = 50, int nrUsi = 3):Vehicul(culoare,brand,anFabricatie) {
        // si dupa ce construim partea legata de vehicul, in constructorul masina construim si datele noi
        this->volumPortbagaj = volumPortbagaj;
        this->vitezaMaxima = vitezaMaxima;
        this->nrUsi = nrUsi;
    }

    Masina(const Masina& obj):Vehicul(obj) {
        this->volumPortbagaj = obj.volumPortbagaj;
        this->vitezaMaxima = obj.vitezaMaxima;
        this->nrUsi = obj.nrUsi;
    }


    Masina &operator=(const Masina& obj) {
        if (this != &obj) {
            Vehicul::operator=(obj);
            this->volumPortbagaj = obj.volumPortbagaj;
            this->vitezaMaxima = obj.vitezaMaxima;
            this->nrUsi = obj.nrUsi;
        }

        return *this;
    }

    istream& read(istream& in);
    ostream& print(ostream& out) const;


    virtual void findRange()  = 0;
    virtual ~Masina(){};
};

istream& Masina::read(istream &in) {
    Vehicul::read(in);

    cout << "Introdu volum portbagaj: " << endl;
    in >> this->volumPortbagaj;

    cout << "Introdu viteza maxima: " << endl;
    in >> this->vitezaMaxima;

    cout << "Introdu numarul de usi: " << endl;
    in >> this->nrUsi;

    return in;
}

ostream& Masina::print(ostream &out) const {
    Vehicul::print(out);

    out << "Volum Portbagaj: " << this->volumPortbagaj << endl;
    out << "Viteza Maxima " << this->vitezaMaxima << endl;
    out << "Numarul de usi: " << this->nrUsi << endl;

    return out;
}

class Electrica: virtual public Masina {
protected:
    float capacitateBaterie,putereInKw;
public:
    Electrica(string culoare = "negru", string brand = "Volkswagen", int anFabricatie = 2000,float volumPortbagaj = 0, float vitezaMaxima = 100, int nrUsi = 3, float capacitateBaterie = 0, float putereInKw = 0);
    Electrica(const Electrica& obj);
    Electrica &operator=(const Electrica &obj);
    virtual ~Electrica();

    istream& read(istream& in);
    ostream& print(ostream& out) const;

    void findRange();
};

Electrica::Electrica(string culoare, string brand, int anFabricatie,
                     float volumPortbagaj, float vitezaMaxima, int nrUsi,
                     float capacitateBaterie, float putereInKw):Masina(
        culoare, brand, anFabricatie, volumPortbagaj,
        vitezaMaxima, nrUsi
) {
    this->capacitateBaterie = capacitateBaterie;
    this->putereInKw = putereInKw;
}

Electrica::Electrica(const Electrica &obj):Masina(obj) {
    this->capacitateBaterie = obj.capacitateBaterie;
    this->putereInKw = obj.putereInKw;
}

Electrica &Electrica::operator=(const Electrica &obj) {
    if (this != &obj) {
        Masina::operator=(obj);
        this->capacitateBaterie = obj.capacitateBaterie;
        this->putereInKw = obj.putereInKw;
    }

    return *this;
}

istream& Electrica::read(istream &in) {
    Masina::read(in);

    cout << "Introdu capacitatea bateriei: " << endl;
    in >> this->capacitateBaterie;

    cout << "Introdu puterea (kw): " << endl;
    in >> this->putereInKw;

    return in;
}

ostream& Electrica::print(ostream& out) const {
    Masina::print(out);

    out << "Capacitatea bateriei: " << this->capacitateBaterie << endl;
    out << "Putere (kw): " << this->putereInKw << endl;

    return out;
}

void Electrica::findRange() {
    if (this->putereInKw <= 0) {
        throw runtime_error("Nu se poate calcula range-ul\n");
    }

    cout << "Range-ul este de: " << this->capacitateBaterie/this->putereInKw << " km\n";
}

Electrica::~Electrica() {
}

class MasinaCombustibil: virtual public Masina{
protected:
    float capacitateRezervor;
    float consum;

public:

    MasinaCombustibil(string, string, int, float, float, int, float, float);
    MasinaCombustibil(const MasinaCombustibil&);
    MasinaCombustibil& operator=(const MasinaCombustibil& m);

    istream& read(istream& in);
    ostream& print(ostream& out) const;

    void findRange();

    virtual ~MasinaCombustibil();
};

MasinaCombustibil::MasinaCombustibil(string culoare = "negru", string brand = "Necunoscut", int anFabricatie = 1990,
                                     float volumPortbagaj = 0, float vitezaMaxima = 50, int nrUsi = 3,
                                     float capacitateRezervor = 4.0, float consum = 6.5): Masina(culoare, brand, anFabricatie, volumPortbagaj, vitezaMaxima, nrUsi){
    this->capacitateRezervor = capacitateRezervor;
    this->consum = consum;
}

MasinaCombustibil::MasinaCombustibil(const MasinaCombustibil& m): Masina(m){
    this->capacitateRezervor = m.capacitateRezervor;
    this->consum = m.consum;
}

MasinaCombustibil& MasinaCombustibil::operator=(const MasinaCombustibil& m){
    if(this != &m){
        Masina::operator=(m);
        this->capacitateRezervor = m.capacitateRezervor;
        this->consum = m.consum;
    }
    return *this;
}

istream& MasinaCombustibil::read(istream &in) {
    Masina::read(in);

    cout << "Introdu capacitate rezervor: " << endl;
    in >> this->capacitateRezervor;

    cout << "Introdu consum: " << endl;
    in >> this->consum;

    return in;
}

ostream& MasinaCombustibil::print(ostream &out) const {
    Masina::print(out);

    out << "Capacitate rezervor: " << this->capacitateRezervor << endl;
    out << "Consum: " << this->consum << endl;

    return out;
}

void MasinaCombustibil::findRange(){
    if(this->consum <= 0)
        throw runtime_error("Nu se poate calcula range-ul\n");
    else
        cout<<"Range-ul este: "<<this->capacitateRezervor/this->consum * 100<<" km\n";
}

MasinaCombustibil::~MasinaCombustibil(){}

class MasinaHibrid: public MasinaCombustibil, public Electrica {
public:
    MasinaHibrid(string, string, int,
                 float, float , int ,
                 float, float,
                 float, float);
    MasinaHibrid(const MasinaHibrid&);
    MasinaHibrid& operator=(const MasinaHibrid&);

    istream& read(istream& in);
    ostream& print(ostream& out) const;

    void findRange();
    void functieMasinaHibrid1(){
        cout<<"Asta e o functie proprie si doar masinile de tip hibrid o pot apela\n";
    }
    int functieMasinaHibrid2(){
        return this->capacitateBaterie;
    }
    ~MasinaHibrid();
};
MasinaHibrid::MasinaHibrid(string culoare = "rosu", string brand = "ford", int anFabricatie = 2019,
                           float volumPortbagaj = 100, float vitezaMaxima = 200, int nrUsi = 4,
                           float capacitateRezervor = 4.0, float consum = 6.5,
                           float capacitateBaterie = 500, float putereInKw = 10):Masina(culoare, brand, anFabricatie, volumPortbagaj, vitezaMaxima, nrUsi), MasinaCombustibil(culoare, brand, anFabricatie, volumPortbagaj, vitezaMaxima, nrUsi, capacitateRezervor, consum),
                                                                                 Electrica(culoare, brand, anFabricatie, volumPortbagaj, vitezaMaxima, nrUsi, capacitateBaterie, putereInKw)
{}

MasinaHibrid::MasinaHibrid(const MasinaHibrid& mh):MasinaCombustibil(mh), Electrica(mh){

}

MasinaHibrid& MasinaHibrid::operator=(const MasinaHibrid& mh){
    if (this != &mh){
        MasinaCombustibil::operator=(mh);
        Electrica::operator=(mh);
    }
    return *this;
}

MasinaHibrid::~MasinaHibrid(){

}

istream& MasinaHibrid::read(istream &in) {
    MasinaCombustibil::read(in);

    cout << "Introdu capacitatea bateriei: " << endl;
    in >> this->capacitateBaterie;

    cout << "Introdu puterea (kw): " << endl;
    in >> this->putereInKw;

    return in;
}

ostream& MasinaHibrid::print(ostream& out) const {
    MasinaCombustibil::print(out);

    out << "Capacitatea bateriei: " << this->capacitateBaterie<<endl;
    out << "Putere: " << this->putereInKw<<endl;

    return out;
}

void MasinaHibrid::findRange(){
    cout<<"Range-ul masinii hibrid este:\n";
    if(this->consum < 0 && this->putereInKw < 0)
        throw runtime_error("Nu se poate calcula range-ul masinii cu indexul " + to_string(this->getID()) + "\n");

    if(this->consum){
        cout<<"Daca propulsia masinii este pe combustibil: ";
        MasinaCombustibil::findRange();
    }
    else if(this->putereInKw){
        cout<<"Daca propulsia masinii este pe baterie: ";
        Electrica::findRange();
        throw runtime_error("Nu se poate calcula range-ul masinii (combustibil)\n");

    }
    if(this->putereInKw){
        cout<<"Daca propulsia masinii este pe baterie: ";
        Electrica::findRange();
    }else if(this->consum){
        cout<<"Daca propulsia masinii este pe combustibil: ";
        MasinaCombustibil::findRange();
        throw runtime_error("Nu se poate calcula range-ul masinii (electrica)\n");
    }
}

class Dealership {
private:
    Masina* masina;
public:
    Dealership() { this->masina = NULL; }
    Masina* getMasina() { return this->masina; }

    friend istream& operator>>(istream& in, Dealership& obj);
    friend ostream& operator<<(ostream& out, const Dealership& obj);
};

istream& operator>>(istream& in, Dealership& obj) {
    cout << "----- CITESTE MASINA -----\n";

    cout <<"1. Pe combustibil\n";
    cout <<"2. Electrica\n";
    cout <<"3. Hibrid\n";

    int option;
    cin >> option;
    cin.get();

    switch (option) {
        case 1:
        {
            obj.masina = new MasinaCombustibil();
            break;
        }
        case 2:
        {
            obj.masina = new Electrica();
            break;
        }
        case 3:
        {
            obj.masina = new MasinaHibrid();
            break;
        }
        default:
            throw OptiuneInvalida();
    }

    if(obj.masina != NULL)
        in >> *obj.masina;

    return in;
}

ostream& operator<<(ostream& out, const Dealership& obj) {
    if (obj.masina != NULL)
        out << *obj.masina << endl;

    return out;
}

class Meniu {
private:
    vector<Dealership*> masini;
    Meniu() { }
    ~Meniu() {
        for (int i=0; i<masini.size(); i++) {
            if (masini[i] != NULL)
                delete masini[i];
        }

        masini.clear();
    }
public:
    Meniu(Meniu const&) = delete;
    void operator=(Meniu const&) = delete;

    static Meniu& getInstance() {
        static Meniu instance;
        return instance;
    }

    // metode
    bool verificaIndex(int index) const;
    void afiseazaMeniu() const;
    void startMeniu();
};

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

int main() {
    Meniu& m = Meniu::getInstance();
    m.startMeniu();
    return 0;
}