#include <iostream>
#include "soustava.h"

#define VALID "0123456789ABCDE"

int vstup() {
    int soustava;
    std::cout << "Zadejte soustavu :" << std::endl;
    std::cin >> soustava;
    if (std::cin.fail() || std::cin.peek()!= '\n') {
        std::cin.clear();
        std::cin.ignore(255,'\n');
        std::cout << "Chybny vstup. " << std::endl;
    }else if (soustava < 2 || soustava > 16) {
        std::cout << "Zadali jste neplatnou soustavu" << std::endl;
    }
    return soustava;
}

string cislo() {
    std::cout << "Zadejte cislo :" << std::endl;
    string n;
    std::cin.ignore(255,'\n');
    std::getline(std::cin, n);
    return n;
}


int main() {
    soustava s1;
    soustava s2("1010", 2);
    soustava s3("ABCD", 16);
    soustava s4(s2);

    std::cout << "Objekt vytvoreny konstruktorem s parametrem" << std::endl;
    std::cout << s2 << std::endl;
    std::cout <<s3 << std::endl;

    std::cout << "Objekt vytvoreny kopirovacim konstruktorem :" << s4 << std::endl;

    int s = vstup();
    string number = cislo();

    if(s1.set_number(number, s)) {
        std::cout << s1 << std::endl;
    } else {
        std::cout << "Chybne cislo, nebo soustava. " << std::endl;
    }





    return 0;
}