//
// Created by ucitel on 26.01.2026.
//


#include "datum.h"
#include <ctime>

Datum::Datum() {
    system_datum();
}

void Datum::system_datum() {
    time_t timestamp = time(&timestamp);
    struct tm *datetime = localtime(&timestamp);
    y = datetime->tm_year + 1900;
    m = datetime->tm_mon + 1;
    d = datetime->tm_mday;
}

Datum::Datum(int y, int m, int d) {
    if (je_valid(y, m, d)) {
        this->d = d;
        this->m = m;
        this->y = y;
    }
    else {
        system_datum();
    }

}

Datum::Datum(const Datum &other) {
    this->d = other.d;
    this->m = other.m;
    this->y = other.y;
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
    if (je_valid(y, this->m, this->d)) {
        this->y = y;
        return true;
    }
    return false;
}

bool Datum::set_month(int m) {
    if (je_valid(this->y, m, this->d)) {
        this->m = m;
        return true;
    }
    return false;
}

bool Datum::set_day(int d) {
    if (je_valid(this->y, this->m, d)) {
        this->d = d;
        return true;
    }
    return false;
}

bool Datum::set_date(int y, int m, int d) {
    if (je_valid(y, m, d)) {
        this->d = d;
        this->m = m;
        this->y = y;
        return true;
    }
    return false;
}

int Datum::days_from_1970()const {
    int total_days = 0;

    for (int i = MIN_ROK;i < y;++i) {
        total_days += je_prestupny(i) ? 366 : 365;
    }

    for (int i = 1; i < m; ++i) {
        total_days += pocet_dni(i, y);
    }

    total_days += d;

    return total_days;
}

int Datum::day_in_week()const {
    int day = days_from_1970();
    return (day + 2) % 7 + 1;

}

bool Datum::set_from_days(int days) {
    if (days <= 0) return false;
    int ny = MIN_ROK;
    while (days > (je_prestupny(ny) ? 366 : 365)) {
        days -= je_prestupny(ny) ? 366 : 365;
        if (++ny > MAX_ROK) return false;
    }
    int nm = 1;
    while (days > pocet_dni(nm, ny)) {
        days -= pocet_dni(nm, ny);
        ++nm;
    }
    y = ny; m = nm; d = days;
    return true;
}

bool Datum::change_date(int days) {
    return set_from_days(days_from_1970() + days);
}

Datum & Datum::operator=(const Datum &diff) {
    this->y = diff.y;
    this->m = diff.m;
    this->d = diff.d;
    return *this;
}

bool Datum::operator==(const Datum &diff) const {
    return y == diff.y && m == diff.m && d == diff.d;
}

bool Datum::je_valid(int y, int m, int d) {
    if (y<MIN_ROK || y>MAX_ROK) return false;
    if (m<1 || m>12) return false;
    if (d<1 || d>pocet_dni(m,y)) return false;

    return true;
}

bool Datum::je_prestupny(int y) {
    return y % 4 == 0 && (y % 400 == 0 || y % 100 != 0);
}

bool Datum::je_prestupny() const {
    return je_prestupny(this->y);
}

int Datum::pocet_dni(int m, int y) {
    int month[] = {31, 28, 31, 30, 31, 30,
                   31, 31, 30, 31, 30, 31};
    if (je_prestupny(y)) {
        month[1] = 29;
    }
    return month[m - 1];
}

std::ostream & operator<<(std::ostream &os, const Datum &d) {
    os << d.d << ". " << d.m << ". " << d.y << ", ";
    os << "pocet dni od 1. 1. " << MIN_ROK << " je " << d.days_from_1970() << ", ";
    os << "den v tydnu je " << d.day_in_week() << ".";
    return os;
}
