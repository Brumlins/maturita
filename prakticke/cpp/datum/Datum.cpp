//
// Created by rehul on 6.5.26.
//

#include "Datum.h"
#include <ctime>

const int dny[] = {31,28,31,30,31,30,31,31,30,31,30,31};

Datum::Datum() {
    system_date();
}

Datum::Datum(const Datum &date) {
    this->y = date.y;
    this->m = date.m;
    this->d = date.d;
}

Datum::Datum(int y, int m, int d) {
    if (je_validni(y,m,d)) {
        this->y = y;
        this->m = m;
        this->d = d;
    }
    else {
        system_date();
    }
}

int Datum::get_year() const {
    return y;
}

int Datum::get_month() const {
    return m;
}

int Datum::get_day() const {
    return d;
}

bool Datum::set_year(int y) {
    if (!je_validni(y, this->m, this->d)) return false;
    this->y=y;
    return true;
}

bool Datum::set_month(int m) {
    if (!je_validni(this->y, m, this->d)) return false;
    this->m=m;
    return true;
}

bool Datum::set_day(int d) {
    if (!je_validni(this->y, this->m, d)) return false;
    this->d=d;
    return true;
}

bool Datum::set_date(int y, int m, int d) {
    if (!je_validni(y, m, d)) return false;
    this->y = y;
    this->m = m;
    this->d = d;
    return true;
}

int Datum::days_from_1970() const {
    int total = 0;
    for (int i = MIN_ROK; i < y; i++) {
        total += je_prestupny(i) ? 366 : 365;
    }
    for (int i = 1; i < m; i++) {
        total += pocet_dni(i, y);
    }
    total+=d;
    return total;

}

int Datum::day_in_week() const {
    return (days_from_1970() + 2) % 7 + 1;
}

bool Datum::change_date(int d) {
    return set_from_days(days_from_1970()+d);
}

bool Datum::set_from_days(int d) {
        int rok = MIN_ROK;
        int mesic = 1;
        if (d <= 0) return false;
        while (d >= (je_prestupny(rok) ? 366 : 365)) {
            d -= je_prestupny(rok) ? 366 : 365;
            if (++rok > MAX_ROK) return false;
        }
        while (d > pocet_dni(mesic, rok)) {
            d-=pocet_dni(mesic, rok);
            mesic++;
        }
        this->y = rok;
        this->m = mesic;
        this->d = d;
        return true;
    }

Datum & Datum::operator=(const Datum &date) {
    set_date(date.y, date.m, date.d);
    return *this;
}

bool Datum::operator==(const Datum &date) const {
    return (d == date.d && m == date.m && y == date.y);
}

bool Datum::je_prestupny(int y) {
    return y%4==0 && (y % 100!=0 || y % 400 == 0);
}

bool Datum::je_prestupny() const {
    return je_prestupny(y);
}

bool Datum::je_validni(int y, int m, int d) {
    if (y < MIN_ROK || y > MAX_ROK) return false;
    if (m < 1 || m > 12) return false;
    if (d > pocet_dni(m, y) || d < 1) return false;
    return true;
}

int Datum::pocet_dni(int m, int y) {
    if (m==2 && je_prestupny(y)) {
        return 29;
    }
    else {
        return dny[m-1];
    }
}

void Datum::system_date() {
    time_t timestamp = time(&timestamp);
    struct tm *datetime = localtime(&timestamp);
    y = datetime->tm_year + 1900;
    m = datetime->tm_mon + 1;
    d = datetime->tm_mday;
}

std::ostream & operator<<(std::ostream &os, const Datum &date) {
    os << date.get_day() <<". " << date.get_month() << ". " << date.get_year() << ", pocet dni od 1. 1. 1970 je " << date.days_from_1970() <<
        ", den v tydnu je " << date.day_in_week() << "." << std::endl;

    return os;
}