#include <iostream>
#include "fraction.h"
#include <limits>
#include <string>

using std::cout; using std::endl; using std::cin; using std::string;

int vstup(const string text) {
    int input; bool err;
    do {
        err = false;
        // Odstraněna mezera za dvojtečkou a endl, aby uživatel psal hned za to
        cout << "Zadej " << text << ":";
        cin >> input;
        if (cin.fail() || cin.peek() != '\n') {
            cout << "Nebylo zadano cele cislo." << endl;
            err = true;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (err);
    return input;
}

int main() {
    fraction z1;                    // 1/1
    fraction z2(3,2);               // 3/2
    fraction z3(2,6);               // 2/6
    fraction z4(0,2);               // 0/2

    // Výpisy konstruktorů (správně zarovnané mezerami k dvojtečce) a přidání desetinné hodnoty
    cout << "Objekt 'z1' vytvoreny konstruktorem bez parametru: " << z1 << ", " << z1.toDec() << endl;
    cout << "Objekt 'z2' vytvoreny konstruktorem s parametry  : " << z2 << ", " << z2.toDec() << endl;
    cout << "Objekt 'z3' vytvoreny konstruktorem s parametry  : " << z3 << ", " << z3.toDec() << endl;
    cout << "Objekt 'z4' vytvoreny konstruktorem s parametry  : " << z4 << ", " << z4.toDec() << endl;
    cout << endl;

    // Převrácení
    if (z2.flip()) {
        cout << "Objekt 'z2' po prevraceni  : " << z2 << endl;
    }
    if (!z4.flip()) {
        cout << "Zlomek 'z4' nelze prevratit." << endl;
    }
    cout << endl;

    // Změna
    cout << "Zmena zlomku 'z1'" << endl;
    cout << "-----------------" << endl;
    int nahore = vstup("citatele");
    int dole   = vstup("jmenovatele");

    if (z1.setFraction(nahore, dole)) {
        cout << "Objekt 'z1' po zmene: " << z1 << endl;
    } else {
        cout << "Jmenovatel nemuze byt nula." << endl;
    }
    cout << endl;

    // Sčítání a přiřazení
    cout << "Scitani a prirazovani zlomku" << endl;
    cout << "----------------------------" << endl;

    // Nejprve vypíšeme celou rovnici ze současných stavů z1 a z2, až potom je fyzicky sečteme
    cout << "z3 = z1 + z2 = " << z1 << " + " << z2 << " = ";
    z3 = z1 + z2;
    cout << z3 << endl;

    return 0;
}