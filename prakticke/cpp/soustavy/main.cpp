#include <iostream>
#include "soustava.h"

string cislo() {
    std::cout << "Zadejte cislo :" << std::endl;
    string n;
    std::cin.ignore(255,'\n');
    std::getline(std::cin, n);
    return n;
}

int main() {
    soustava s1;                      // výchozí → 0
    soustava s2("11111111", 2);          // binární → 10
    soustava s3("ABCD", 16);         // hex → 43981
    soustava s4(s2);                  // kopírovací

    std::cout << "Objekt vytvoreny konstruktorem s parametrem" << std::endl;
    std::cout << s2 << std::endl;
    std::cout << s3 << std::endl;
    std::cout << "Objekt vytvoreny kopirovacim konstruktorem :" << std::endl;
    std::cout << s4 << std::endl;

    int s;
    std::cout << "Zadejte soustavu :" << std::endl;
    std::cin >> s;
    if (std::cin.fail() || std::cin.peek()!= '\n') {
        std::cin.clear(); std::cin.ignore(255,'\n');
        std::cout << "Chybny vstup." << std::endl;
    } else {
        string number = cislo();
        if (s1.set_number(number, s)) {
            std::cout << s1 << std::endl;
        } else {
            std::cout << "Chybne cislo, nebo soustava." << std::endl;
        }
    }
    return 0;
}