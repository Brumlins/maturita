#include <iostream>
#include <string>
#include "rodne.h"

using std::endl;
using std::cin;
using std::cout;

int main() {
    string vstup;
    rodne rc1;
    cout << rc1 << endl;

    rodne rc2("0703253386");
    cout << rc2 << endl;

    do {
        cout << "Zadej rodne cislo: " << endl;
        std::getline(cin, vstup);
        if (rc1.set_rodne(vstup)) {
            cout << rc1 << endl;
        }
        else {
            cout << "Chybny vstup" << endl;
            cout << "Program bude ukoncen" << endl;
            return 0;
        }
    }while (true);
}
