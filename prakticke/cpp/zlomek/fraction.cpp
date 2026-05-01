//
// Created by ucitel on 16.02.2026.
//

#include "fraction.h"
#include <numeric>

fraction::fraction(): numerator(1), denominator(1) {
}

fraction::fraction(int numerator, int denominator) {
    if (!setFraction(numerator, denominator)) {
        setFraction(1, 1);
    }
}

fraction::fraction(const fraction &a) {
    setFraction(a.getNumerator(), a.getDenominator());
}

fraction::~fraction() {
}

int fraction::getNumerator() const {
    return this->numerator;
}

int fraction::getDenominator() const {
    return this->denominator;
}

float fraction::toDec() const {
    return (float) numerator / (float) denominator;
}

bool fraction::flip() {
    if (numerator != 0) {
        swap(numerator, denominator);
        return true;
    }
    return false;
}

bool fraction::reduce() {
    int nsd = std::gcd(numerator, denominator);
    if (nsd == 1) {
        return false;
    }
    this->numerator /= nsd;
    this->denominator /= nsd;
    return true;
}

bool fraction::setFraction(int num, int den) {
    if (den != 0) {
        this->denominator = den;
        this->numerator = num;
        return true;
    }
    return false;
}

fraction & fraction::operator=(const fraction &a) {
    setFraction(a.getNumerator(), a.getDenominator());
    return *this;
}

fraction & fraction::operator+=(const fraction &a) {
    int nasobek = std::lcm(a.getDenominator(), this->getDenominator());
    int citatel = nasobek/denominator * numerator;
    int citatel1 = nasobek/a.getDenominator() * a.getNumerator();
    this->numerator = citatel + citatel1;
    this->denominator = nasobek;
    return *this;
}

fraction fraction::operator+(const fraction &a) const{
    fraction temp(*this);
    temp += a;
    return temp;
}

void fraction::swap(int &num, int &den) {
    int b;
    b = num;
    num = den;
    den = b;
}

ostream &operator<<(ostream &c, const fraction &d) {
    if ((d.getNumerator() < 0 && d.getDenominator() > 0) ||
        (d.getNumerator() > 0 && d.getDenominator() < 0)) {
        c << "-";
    }
    c << abs(d.getNumerator()) << "/" << abs(d.getDenominator());

    return c;
}
