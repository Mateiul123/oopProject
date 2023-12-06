#include "DEALERSHIP.h"
#include "OPTIUNEINVALIDA.h"

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
