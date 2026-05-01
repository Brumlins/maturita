//
// Created by rehul on 2.3.26.
//

#include "rodne.h"
#include <ctime>

rodne::rodne() {
    this->rodneCislo = default_rc;
}

rodne::~rodne() {
}

rodne::rodne(string rodne) {
    if (!set_rodne(rodne)) {
        this->rodneCislo = default_rc;
    }
}

rodne::rodne(const rodne &rc) {
    this->rodneCislo = rc.get_rodne();
}

string rodne::get_rodne() const {
    return this->rodneCislo;
}

bool rodne::set_rodne(string rodne) {
    if (validace(rodne)) {
        this->rodneCislo = rodne;
        return true;
    }
    return false;
}

int rodne::den() const {
    return std::stoi(rodneCislo.substr(4, 2));
}

int rodne::mesic() const {
    int m = std::stoi(rodneCislo.substr(2, 2));
    return m > 12 ? m - 50 : m;
}

int rodne::rok() const {
    int r = std::stoi(rodneCislo.substr(0, 2));
    return r > 54 ? 1900 + r : 2000 + r;
}

int rodne::vek() const {
    time_t rawtime;
    struct tm * timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    int s_rok = timeinfo->tm_year + 1900;
    int s_mesic = timeinfo->tm_mon + 1;
    int s_den = timeinfo->tm_mday;
    int vek = s_rok - this->rok();
    if (s_mesic < this->mesic() || (s_mesic == this->mesic() && s_den < this->den())) {
        --vek;
    }
    return vek;
}

bool rodne::pohlavi() const {
    int m = std::stoi(rodneCislo.substr(2, 2));
    return m > 50;
}

bool rodne::validace(string rodne) {
    if (rodne.length() != 10) {
        return false;
    }
    for (int i = 0; i < rodne.length(); ++i) {
        if (rodne[i]<'0' || rodne[i]>'9') {
            return false;
        }
    }
    int zbytek = std::stoi(rodne.substr(0,9)) % 11;
    if (zbytek == std::stoi(rodne.substr(9,1))) {
        return true;
    }else if (zbytek == 10 && std::stoi(rodne.substr(9,1))==0) {
        return true;
    }
    return false;
}

ostream & operator<<(ostream &os, const rodne &r) {
    os << "Rodne cislo: " << r.rodneCislo << std::endl;
    os << "Narozen: " << r.den() << ". " << r.mesic() << ". " << r.rok() <<std::endl;
    os << "Pohlavi: " << (r.pohlavi() ? "Zena" : "Muz") << std::endl;
    os << "Vek: " << r.vek() << std::endl;
    return os;
}
