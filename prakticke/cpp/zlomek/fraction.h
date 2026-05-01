//
// Created by ucitel on 16.02.2026.
//

#ifndef FRACTION_H
#define FRACTION_H
#include <ostream>
using std::ostream;


class fraction {

public:

    fraction();
    fraction(int numerator, int denominator);
    fraction(const fraction&);
    ~fraction();
    int getNumerator()const;
    int getDenominator()const;
    float toDec()const;
    bool flip();
    bool reduce();
    bool setFraction(int num,int den);
    fraction& operator=(const fraction&);
    fraction& operator+=(const fraction&);
    fraction operator+(const fraction&)const;


private:
    int numerator;
    int denominator;
    void swap(int &num, int &den);





};



ostream& operator << (ostream&,const fraction&);


#endif //FRACTION_H
