//
// Created by rehul on 2.3.26.
//

#include <string>
#include <ostream>

#ifndef RODNE_H
#define RODNE_H

using std::ostream;
using std::string;

const string default_rc = "5451010004";

class rodne {
public:
    rodne();
    ~rodne();
    rodne(string);
    rodne(const rodne&);
    string get_rodne() const;
    bool set_rodne(string rodne);
    int den()const;
    int mesic()const;
    int rok()const;
    int vek()const;
    bool pohlavi()const;
    friend ostream& operator<<(ostream&, const rodne&);

private:
    string rodneCislo;
    static bool validace(string rodne);
};



#endif //RODNE_H
