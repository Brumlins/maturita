//
// Created by ucitel on 09.03.2026.
//

#ifndef SOUSTAVA_H
#define SOUSTAVA_H
#include <string>
#include <ostream>

using std::string;
using std::ostream;


class soustava {
public:
    soustava();

    soustava(string n, int s);

    soustava(const soustava &Soustava);

    ~soustava() = default;

    string get_number(int s)const;

    bool set_number(string n, int s);

private:
    unsigned int number;

    static bool sIsValid(int s);

    static bool nIsValid(string n, int s);

    static unsigned int convertToDec(string n, int s);

    static string convertFromDec(unsigned int n, int s);
};


ostream &operator <<(ostream &os, const soustava &s);


#endif //SOUSTAVA_H
