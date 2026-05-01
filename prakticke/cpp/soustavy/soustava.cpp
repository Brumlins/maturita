//
// Created by ucitel on 09.03.2026.
//

#include "soustava.h"
#include <cmath>
#include <algorithm>

string cifry = "0123456789ABCDEF";

soustava::soustava(): number(0) {
}

soustava::soustava(string n, int s) {
    if (!set_number(n, s)) {
        this->number = 0;
    }
}

soustava::soustava(const soustava &Soustava) {
    set_number(Soustava.get_number(2), 2);
}

string soustava::get_number(int s) const {
    return sIsValid(s) ? convertFromDec(this->number, s): "0";
}


bool soustava::set_number(string n, int s) {
    if (!nIsValid(n, s)) {
        return false;
    }
    this->number = convertToDec(n, s);
    return true;
}

bool soustava::sIsValid(int s) {
    return s >= 2 && s <= 16;
}

bool soustava::nIsValid(string n, int s) {
    std::size_t found;
    if (!sIsValid(s)) {
        return false;
    }
    for (int i = 0; i < n.length(); i++) {
        found = cifry.find(n[i]);
        if (found == string::npos || found >= s) {
            return false;
        }
    }
    return true;
}

unsigned int soustava::convertToDec(string n, int s) {
    unsigned int dec = 0;
    for (int i = 0; i < n.length(); i++) {
        dec += cifry.find(n[i]) * pow(s, n.length() - i - 1);
    }
    return dec;
}

string soustava::convertFromDec(unsigned int n, int s) {
    string tmp = n == 0 ? "0" : "";
    while (n > 0) {
        tmp += cifry[n % s];
        n /= s;
    }
    std::reverse(tmp.begin(), tmp.end());
    return tmp;
}

ostream & operator<<(ostream &os, const soustava &s) {
    os << "Cislo ve dvojkove soustave :" << s.get_number(2) << std::endl;
    os << "Cislo v desitkove soustave :" << s.get_number(10) << std::endl;
    os << "Cislo v sestnactkove soustave :" << s.get_number(16) << std::endl;
    os << "Cislo v osmickove soustave :" << s.get_number(8) << std::endl;
    return os;
}
