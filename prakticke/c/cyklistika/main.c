#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 200
#define INPUT "cyklistika.txt"

typedef struct {
    int hour;
    int min;
    int sec;
    int tenth;
} TIME;

typedef struct {
    int number;
    char name[50];
    char surname[50];
    int year;
    char club[SIZE];
    TIME time;
} RACER;

RACER *readFile(int *count) {
    FILE *fr = fopen(INPUT, "r");
    char buffer[SIZE];
    int lines = 0;

    RACER *racers = NULL;
    RACER *tmp = NULL;

    if (fr == NULL) {
        printf("File could not be opened.\n");
        return NULL;
    }

    while (fgets(buffer, SIZE, fr) != NULL) {
        if (lines != 0) {
            tmp = (RACER *) realloc(racers, lines * sizeof(RACER));
            if (tmp != NULL) {
                racers = tmp;
            } else {
                printf("Memory error.\n");
                free(racers);
                break;
            }
            int order = 0;
            char *currentDelim = ";:";
            char *pch = strtok(buffer, currentDelim);
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
                        strcpy(racers[lines - 1].club, pch);
                        currentDelim = ":;.";
                        break;
                    case 5:
                        racers[lines - 1].time.hour = atoi(pch);
                        break;
                    case 6:
                        racers[lines - 1].time.min = atoi(pch);
                        break;
                    case 7:
                        racers[lines - 1].time.sec = atoi(pch);
                        break;
                    case 8:
                        racers[lines - 1].time.tenth = atoi(pch);
                        break;
                }
                pch = strtok(NULL, currentDelim);
                order++;
            }
        }
        lines++;
    }

    *count = lines - 1;

    if (fclose(fr) == EOF) {
        printf("File could not be closed.\n");
    }

    return racers;
}

int timeToTenths(TIME time) {
    return time.hour * 36000 + time.min * 600 + time.sec * 10 + time.tenth;
}

void swap(RACER *a, RACER *b) {
    RACER tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubblSort(RACER *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (timeToTenths(arr[j].time) > timeToTenths(arr[j + 1].time)) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void printFile(RACER *racer, int count) {
    printf("V Y S L E D K O V A  L I S T I N A  -  O B R  D R A S A L\n");
    printf("----------------------------------------------------------[------------------------"
           "-----------\n");
    printf("poradi|startovni cislo|   prijmeni   |   jmeno    |rocnik|          klub          |"
           "   cas    |\n");
    printf("----------------------------------------------------------[------------------------"
           "-----------\n");
    for (int i = 0; i < count; i++) {
        printf("%6d|%15d|%15s|%10s|%7d|%35s|%02d:%02d:%02d:%d|\n",
            i + 1,
            racer[i].number,
            racer[i].surname,
            racer[i].name,
            racer[i].year,
            racer[i].club,
            racer[i].time.hour, racer[i].time.min, racer[i].time.sec, racer[i].time.tenth);
    }
}

int main(void) {
    RACER *racers;
    int count = 0;
    racers = readFile(&count);
    bubblSort(racers, count);
    printFile(racers, count);
    free(racers);
    return 0;
}