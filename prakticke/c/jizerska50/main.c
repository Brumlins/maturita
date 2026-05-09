#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define DELIMITERS ";,():"
#define SIZE 100
#define INPUT "jizerska50.txt"

typedef struct {
    int hour;
    int minute;
    int sec;
} TIME;

typedef struct {
    int number;
    char name[50];
    char surname[50];
    int year;
    char country[5];
    TIME time;
} RACER;

RACER *readFile(int *count) {
    FILE *fr = fopen(INPUT, "r");
    char buffer[SIZE];
    int lines = 0;
    RACER *racers = NULL;
    RACER *tmp = NULL;
    if (fr == NULL) {
        printf("File could not be opened\n");
        return NULL;
    }

    while (fgets(buffer, SIZE, fr) != NULL) {
        if (lines != 0) {
            tmp = (RACER *) realloc(racers, lines * sizeof(RACER));
            if (tmp != NULL) {
                racers = tmp;
            } else {
                printf("Memory error\n");
                free(racers);
                break;
            }
            int order = 0;
            char *pch = strtok(buffer, DELIMITERS);
            while (pch != NULL) {
                switch (order) {
                    case 0:
                        racers[lines - 1].number = atoi(pch);
                        break;
                    case 1:
                        strcpy(racers[lines - 1].surname, pch);
                        break;
                    case 2:
                        strcpy(racers[lines - 1].name, pch);
                        break;
                    case 3:
                        racers[lines - 1].year = atoi(pch);
                        break;
                    case 4:
                        strcpy(racers[lines - 1].country, pch);
                        break;
                    case 5:
                        racers[lines - 1].time.hour = atoi(pch);
                        break;
                    case 6:
                        racers[lines - 1].time.minute = atoi(pch);
                        break;
                    case 7:
                        racers[lines - 1].time.sec = atoi(pch);
                        break;
                }
                pch = strtok(NULL,DELIMITERS);
                order++;
            }
        }
        lines++;
    }

    if (fclose(fr) == EOF) {
        printf("File could not be closed\n");
    }

    *count = lines - 1;

    return racers;
}

int timeToSec(TIME time) {
    return time.hour * 3600 + time.minute * 60 + time.sec;
}

void swap(RACER *a, RACER *b) {
    RACER tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort(RACER *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (timeToSec(arr[j].time) > timeToSec(arr[j + 1].time)) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void printResults(RACER *racers, int count) {
    // 1. Hlavička tabulky
    printf("VYSLEDKOVA LISTINA JIZERSKA 50\n");
    printf("poradi cislo     prijmeni          jmeno  rocnik stat     cas\n");

    // 2. Výpis samotných seřazených závodníků
    for (int i = 0; i < count; i++) {
        // Vypisujeme i + 1, protože indexujeme od 0, ale pořadí závodů začíná od 1. místa
        printf("%02d. %6d %15s %15s %7d %5s %02d:%02d:%02d\n",
               i + 1,
               racers[i].number,
               racers[i].surname,
               racers[i].name,
               racers[i].year,
               racers[i].country,
               racers[i].time.hour, racers[i].time.minute, racers[i].time.sec);
    }
}

int main() {
    RACER *racers;
    int count = 0;
    racers = readFile(&count);
    bubbleSort(racers, count);
    printResults(racers, count);
    free(racers);
    return 0;
}
