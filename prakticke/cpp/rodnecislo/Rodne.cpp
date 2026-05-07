//
// Created by rehul on 7.5.26.
//

#include "Rodne.h"
#include <ctime>

Rodne::Rodne() {
    rc = DEFAULT_RC;
}

Rodne::Rodne(std::string rodneC) {
    if (je_validni(rodneC)) {
        rc = rodneC;
    }
    else {
        rc = DEFAULT_RC;
    }
}

Rodne::~Rodne() {
}

Rodne::Rodne(const Rodne &rodneC) {
    rc = rodneC.get_rc();
}

std::string Rodne::get_rc() const {
    return rc;
}

bool Rodne::set_rc(std::string rodneC) {
    if (je_validni(rodneC)) {
        rc = rodneC;
        return true;
    }
    return false;
}

int Rodne::den() const {
    return stoi(rc.substr(4,2));
}

int Rodne::mesic() const {
    int mesic = stoi(rc.substr(2,2));
    return mesic - (mesic > 12 ? 50 : 0);
}

int Rodne::rok() const {
    int rok = stoi(rc.substr(0,2));
    return rok + (rok >= 54 ? 1900 : 2000);
}

int Rodne::vek() const {
    time_t ts = time(&ts);
    struct tm *dt = localtime(&ts);
    int rokNow = dt->tm_year + 1900;
    int mesicNow = dt->tm_mon + 1;
    int denNow = dt->tm_mday;

    rokNow = rokNow-rok();
    if (mesicNow < mesic()) return rokNow-1;

    if (mesicNow==mesic()) {
        if (denNow<den()) return rokNow-1;
    }
    return rokNow;
}

bool Rodne::pohlavi() const {
    return stoi(rc.substr(2,2)) > 54; //zena je true, muz false
}

bool Rodne::je_validni(std::string rodneC) {
    if (rodneC.length() != 10) return false;
    for (int i = 0; i < rodneC.length();i++) {
        if (rodneC[i] < '0' || rodneC[i] > '9') return false;
    }
    int zbytek = std::stoi(rodneC.substr(0,9)) % 11;
    int posledni = std::stoi(rodneC.substr(9,1));
    if (zbytek == posledni) return true;
    if (zbytek == 10 && posledni == 0) return true;
    return false;
}

std::ostream & operator<<(std::ostream &os, const Rodne &rodneC) {
    os << "Rodne cislo je " << rodneC.get_rc() << "\nNarozen/a " << rodneC.den() <<
        "." << rodneC.mesic() << "." << rodneC.rok() << "\nVek " << rodneC.vek()
    << std::endl;
    return os;
}