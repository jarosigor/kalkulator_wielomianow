#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "calc.h"

#define waves for (int i = 0; i < 50; i++) printf("~");
#define newline printf("\n");
#define wave newline waves newline
#define S sizeof(char)*200
#define I sizeof(int)

// helper function converting string into integer
int scanNum (char* p1) {
    int tmp = 0, m = 0;

    if(*p1 == '-') {
      m = 1;
      *p1++;
    }

    if(*p1 == '+') 
      *p1++;

    while (isdigit(*p1)) {
        tmp = 10 * tmp + (*p1++) - '0';
    }

    if(m && tmp == 0)
        return -1;
    
    return m ? -tmp : tmp;
}

// function m
void processIn(char *p, int *processedPolynPower, int *processedPolynNum) {
    int count = 0, num = 0, power = 0;
    bool numO = true, numhelp = false;
    
    while (*p) {
        if (numO) {
            num = scanNum(p);
            numO = false;
            numhelp = false;
        }
            
        if (*p == 'x') {
            if (num == 0) 
                processedPolynNum[count] = 1;
            else 
                processedPolynNum[count] = num;
            
            //printf("%d", num);
            numhelp = true;

            *p++;
            if (*p == '^') {
                *p++;
                power = scanNum(p);
                printf("%d", power);
                if (power == 0 || power == -1) {
                    printf("Błędne wejście!");
                    return;
                }
                    
                else {
                    processedPolynPower[count] = power;
                    count++;
                }
            }

            else {
                processedPolynPower[count] = 1;
                count++;
            }

        }
        else *p++;

        if (!*p && !numhelp && num != 0) {
            processedPolynPower[count] = 0;
            processedPolynNum[count] = num;
        } 

        if (*p == '+' || *p == '-')
            numO = true;

        
    }

    
    
}



// calculator function where user types in polynomials then
// chooses what he/she wants to calculate and gets the result
void calculator() {
    // strings with the polynomials from input
    
    int *degree1, *degree2;
    degree1 = (int*) malloc(I);
    degree2 = (int*) malloc(I);
    waves
    newline
    printf("Podaj stopień 1 wielomianu");
    newline
    scanf("%d", degree1);
    printf("Podaj stopień 2 wielomianu");
    newline
    scanf("%d", degree2);
    waves
    newline
    
    
    char *polyn1, *polyn2;
    int *polyn1Power, *polyn1Num, *polyn2Power, *polyn2Num;
    polyn1 = (char*) malloc(S);
    polyn2 = (char*) malloc(S);
    polyn1Power = (int*) malloc(*degree1 * I);
    polyn1Num = (int*) malloc(*degree1 * I);
    polyn2Power = (int*) malloc(*degree2 * I);
    polyn2Num = (int*) malloc(*degree2 * I);

    if (polyn1 == NULL) {
        printf("Przydzielenie pamięci nie było możliwe (wejście / 1 wielomian)");
        exit(0);
    }
    if (polyn2 == NULL) {
        printf("Przydzielenie pamięci nie było możliwe (wejście / 2 wielomian)");
        exit(0);
    }

    waves
    newline
    printf("Podaj pierwszy wielomian");
    wave
    scanf("%s", polyn1);
    waves
    newline
    printf("Podaj drugi wielomian");
    wave
    scanf("%s", polyn2);
    waves
    newline

    processIn(polyn1, polyn1Power, polyn1Num);
    printf("%d", polyn1Power[0]);

    

    //process1In(&polyn1, &polyn1Power, &polyn1Num);
    //process2In(&polyn2, &polyn2Power, &polyn2Num);

    

    int* calc_choice; // variable storing users choice in calculator menu
    calc_choice = (int*) malloc(I);
    if (calc_choice == NULL) {
        printf("Przydzielenie pamięci nie było możliwe (calculator / calc_choice)");
        exit(0);
    }

    //options 1 - add / 2 - substract / 3 - multiply / 4 - divide and get division reminder / 5 - combine 
    printf("Operacje");
    newline;
    printf("1 -> Dodaj");
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
        wave
        printf("!!!Błędne wejście podaj numer operacji jeszcze raz!!!");
        wave
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


