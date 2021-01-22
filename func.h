#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h"

#define waves for (int i = 0; i < 50; i++) printf("~");
#define newline printf("\n");
#define wave newline; waves; newline;

// calculator function where user types in polynomials then
// chooses what he/she wants to calculate and gets the result
void calculator() {
    // strings with the polynomials from input
    char *polyn1, *polyn2;
    polyn1 = (char*) malloc(sizeof(char)*200);
    polyn2 = (char*) malloc(sizeof(char)*200);
    if (polyn1 == NULL) {
        printf("Przydzielenie pamięci nie było możliwe (wejście / 1 wielomian)");
        exit(0);
    }
    if (polyn2 == NULL) {
        printf("Przydzielenie pamięci nie było możliwe (wejście / 2 wielomian)");
        exit(0);
    }

    waves;
    newline;
    printf("Podaj pierwszy wielomian");
    wave;
    scanf("%s", polyn1);
    waves;
    newline;
    printf("Podaj drugi wielomian");
    wave;
    scanf("%s", polyn2);
    waves;
    newline;

    int* calc_choice; // variable storing users choice in calculator menu
    calc_choice = (int*) malloc(sizeof(int));
    if (calc_choice == NULL) {
        printf("Przydzielenie pamięci nie było możliwe (calculator / calc_choice)");
        exit(0);
    }

    //options 1 - add / 2 - substract / 3 - multiply / 4 - divide and get division reminder / 5 - combine 
    printf("Operacje");
    newline;
    printf("1 -> Dodaj");
    newline;
    printf("2 -> Odejmij");
    newline;
    printf("3 -> Wymnóż");
    newline;
    printf("4 -> Podziel z resztą");
    newline;
    printf("5 -> Składanie wielomianów");
    wave;
    
    scanf("%d", calc_choice);
    if (*calc_choice == 1) 
        add();
    else if (*calc_choice == 2)
        substract();
    else if (*calc_choice == 3)
        multiply();
    else if (*calc_choice == 4)
        divide();
    else if (*calc_choice == 5)
        combine();
    else {
        wave;
        printf("!!!Błędne wejście podaj numer operacji jeszcze raz!!!");
        wave;
        calculator();
    }

    


    free(polyn1);
    free(polyn2);
    free(calc_choice);
}

//opens a file with an instruction manual to the calculator
void help() {


    
}

//prints informations about the program
void info() {


    
}


