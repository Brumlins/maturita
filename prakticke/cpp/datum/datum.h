//
// Created by ucitel on 26.01.2026.
//

#ifndef DATUM_H
#define DATUM_H
#include "iostream"

#endif //DATUM_H

const int MIN_ROK = 1970;
const int MAX_ROK = 2050;

class Datum {
public:
    Datum();
    Datum(int y, int m, int d);
    Datum(const Datum&);
    int get_year()const;
    int get_month()const;
    int get_day()const;
    bool set_year(int y);
    bool set_month(int m);
    bool set_day(int d);
    bool set_date(int y, int m, int d);
    int days_from_1970()const;
    int day_in_week()const;
    bool set_from_days(int days);
    bool change_date(int days);

    Datum& operator = (const Datum &diff);
    bool operator == (const Datum &diff)const;
    friend std::ostream& operator << (std::ostream &os, const Datum &d);


private:
    int y, m, d;

    static bool je_valid(int y, int m, int d);
    bool je_prestupny()const;
    static bool je_prestupny(int y);
    static int pocet_dni(int m, int y);
    void system_datum();

};