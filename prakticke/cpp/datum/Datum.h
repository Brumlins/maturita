//
// Created by rehul on 6.5.26.
//


#ifndef DATUM_H
#define DATUM_H

#include <iostream>

const int MIN_ROK = 1970;
const int MAX_ROK = 2050;

class Datum {
public:
    Datum();
    Datum(const Datum&);
    Datum(int y, int m, int d);
    //~Datum() desktruktor nepotrebujeme, nemame dynamickou alokovanou pamet

    int get_year() const;
    int get_month() const;
    int get_day() const;

    bool set_year(int y);
    bool set_month(int m);
    bool set_day(int d);
    bool set_date(int y, int m, int d);

    int days_from_1970() const;
    int day_in_week() const;
    bool change_date(int d);
    bool set_from_days(int d);

    friend std::ostream& operator<<(std::ostream& os, const Datum& date);
    Datum& operator=(const Datum& date);
    bool operator==(const Datum& date) const;

private:
    int y, m, d;

    static bool je_prestupny(int y);
    bool je_prestupny() const;
    static bool je_validni(int y, int m, int d);
    static int pocet_dni(int m, int y);
    void system_date();
};



#endif //DATUM_H