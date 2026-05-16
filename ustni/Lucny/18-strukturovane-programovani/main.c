#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Dodaná funkce pro zjištění prvočísla
unsigned int prvocislo(int cislo){
    unsigned int delitel= 2;
    // Cyklus běží do odmocniny z čísla (matematická zkratka pro zrychlení)
    while (delitel <= sqrt(cislo)){
        if(cislo % delitel == 0)
            return 0; // Našli jsme dělitele, vrací 0 (není prvočíslo)
        else
            delitel++;
    }
    return 1; // Nenašli jsme dělitele, vrací 1 (je prvočíslo)
}

// ÚKOL 3: Vytvoření funkce mocnina
// Využil jsem logiku z tvého vývojového diagramu!
int mocnina(int x, int y) {
    int vysledek = 1;
    // Dokud je y větší než 0, násobíme výsledek základem x a y snížíme
    while (y > 0) {
        vysledek *= x;
        y--;
    }
    return vysledek;
}

int main(int argc, char** argv) {

    int x, y;

    // ÚKOL 2: Použití funkce prvocislo v těle programu
    printf("--- TEST PRVOCISLA ---\n");
    printf("Zadejte cele kladne cislo x: ");
    scanf("%d", &x);

    // Zavoláme funkci a podle toho, co vrátí (1 nebo 0), vypíšeme výsledek
    if (prvocislo(x) == 1) {
        printf("Cislo %d JE prvocislo.\n", x);
    } else {
        printf("Cislo %d NENI prvocislo.\n", x);
    }

    // OTESTOVÁNÍ ÚKOLU 3 (nepovinné, ale u maturity za to budou body navíc)
    printf("\n--- VYPOCET MOCNINY ---\n");
    printf("Zadejte zaklad (x) a exponent (y) oddelene mezerou: ");
    scanf("%d %d", &x, &y);

    // Zavoláme naši novou funkci pro mocninu
    printf("Vysledek: %d umocneno na %d je %d\n", x, y, mocnina(x, y));

    return (EXIT_SUCCESS);
}