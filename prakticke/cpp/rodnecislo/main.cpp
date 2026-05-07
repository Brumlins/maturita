#include <iostream>
#include <string>
#include "Rodne.h"

using std::endl;
using std::cin;
using std::cout;
using std::string;

int main() {
    string vstup;
    Rodne rc1;
    cout << rc1 << endl;

    Rodne rc2("0703253386");
    cout << rc2 << endl;

    do {
        cout << "Zadej rodne cislo: " << endl;
        std::getline(cin, vstup);
        if (rc1.set_rc(vstup)) {
            cout << rc1 << endl;
        }
        else {
            cout << "Chybny vstup" << endl;
            cout << "Program bude ukoncen" << endl;
            return 0;
        }
    }while (true);
}