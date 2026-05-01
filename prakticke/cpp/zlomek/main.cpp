#include <iostream>
#include "fraction.h"
#include <limits>
using std::cout;
using std::endl;
using std::string;
using std::cin;

int vstup(const string text) {
    int input;
    bool error;
    do {
        error = false;
        cout << "Zadej " << text << ": " << endl;
        cin >> input;
        if (cin.fail() || cin.peek() != '\n') {
            cout << "Nebylo zadano cele cislo, zadejte ho znovu" << endl;
            error = true;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        }
    }while (error);
    return input;
}

int main() {
    fraction f1;
    fraction f2(3,2);
    fraction f3(2,6);
    fraction f4(0,2);
    fraction f5(f3);
    int nahore = vstup("citatele");
    int dole = vstup("jmenovatele");

    cout<<"Objekt "<<f1<<" vytvoreny konstruktorem bez parametru"<< endl;
    cout<<"Objekt "<<f2<<" vytvoreny konstruktorem s parametry"<< endl;
    cout<<"Objekt "<<f3<<" vytvoreny konstruktorem s parametry"<< endl;
    cout<<"Objekt "<<f4<<" vytvoreny konstruktorem s parametry"<< endl;
    cout<<"Objekt "<<f5<<" vytvoreny s kopirovacim konstruktorem"<< endl;
    if (f2.flip()) {
        cout<<"Objekt f2 "<<f2<<" byl otocen"<< endl;
    }
    else {
        cout<<"Objekt f2"<<f2<<"nelze otocit"<< endl;
    }

    if (f4.flip()) {
        cout<<"Objekt f4 "<<f4<<" byl otocen"<< endl;
    }
    else {
        cout<<"Objekt f4 "<<f4<<" nelze otocit"<< endl;
    }

    if (f1.setFraction(nahore, dole)) {
        cout << "objekt f1 po zmene " << f1 << endl;
    }else {
        cout << "nahore nemuze byt matej fojtik (NULA)" << endl;
    }

    f1+=f2;

    cout << f1 << endl;

    f1= f2+f3;

    cout << f1 << endl;



    return 0;

}