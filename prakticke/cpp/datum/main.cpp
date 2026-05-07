#include <iostream>
#include "Datum.h"

using std::cout; using std::cin; using std::endl;

void tisk(const char* label, const Datum& d) {
    cout << label << endl;
    cout << "------------------------------------------" << endl;
    cout << d << endl << endl;
}

int nactiInt(const char* prompt) {
    int val;
    cout << prompt;
    cin >> val;
    cin.ignore();
    return val;
}

int main() {
    Datum d1;                   // výchozí konstruktor — dnešní datum
    Datum d2(2000, 1, 1);         // konstruktor s parametry
    Datum d3(d2);               // kopírovací konstruktor

    tisk("Objekt d1 vytvoreny vychozim konstruktorem", d1);
    tisk("Objekt d2 vytvoreny konstruktorem s parametry", d2);
    tisk("Objekt d3 vytvoreny kopirovacim konstruktorem", d3);

    cout << "Zadani noveho data\n------------------" << endl;
    int den   = nactiInt("Zadej den: ");
    int mesic = nactiInt("Zadej mesic: ");
    int rok   = nactiInt("Zadej rok: ");

    if (d1.set_date(rok, mesic, den))
        tisk("\nObjekt d1 po zmene", d1);
    else
        cout << "Neplatne datum!" << endl;

    int dni = nactiInt("Zadej pocet dni od 1. 1. 1970: ");
    if (d3.set_from_days(dni))
        tisk("\nObjekt d3 po prevedeni.", d3);

    cout << (d1 == d3 ? "Objekty d1 a d3 jsou shodne."
                       : "Objekty d1 a d3 nejsou shodne.") << endl << endl;

    char stop;
    do {
        int pridat = nactiInt("Kolik dnu chces k datu v objektu d3 pricist: ");
        if (d3.change_date(pridat)) {
            cout << "\nObjekt d3 po pricteni " << pridat << " dnu\n------------------------------------------" << endl;
            cout << d3 << endl << endl;
        }
        cout << "Klavesou 'k' bude zadavani ukonceno: ";
        cin >> stop; cin.ignore();
    } while (stop != 'k' && stop != 'K');

    return 0;
}