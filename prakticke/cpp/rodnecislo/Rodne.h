//
// Created by rehul on 7.5.26.
//

#ifndef RODNE_H
#define RODNE_H

#include <string>
#include <ostream>

const std::string DEFAULT_RC = "5451010004";

class Rodne {
public:
    Rodne();
    Rodne(std::string rodneC);
    ~Rodne();
    Rodne(const Rodne& rodneC);

    std::string get_rc() const;
    bool set_rc(std::string rodneC);
    int den() const;
    int mesic() const;
    int rok() const;
    int vek() const;
    bool pohlavi() const;

    friend std::ostream& operator<<(std::ostream& os, const Rodne& rodneC);

private:
    std::string rc;

    static bool je_validni(std::string rodneC);

};


#endif //RODNE_H