
#include "calc.h"






// helper function converting string into integer
int scanNum (char* p1) {
    int tmp = 0, m = 0;

    if(*p1 == '-') {
        m = 1;
        *p1++;
    }

    if(*p1 == '+') 
        *p1++;

    if (*p1 == 'x')
        return m ? -1 : 1;

    while (isdigit(*p1)) {
        tmp = 10 * tmp + (*p1++) - '0';
    }
    
    return m ? -tmp : tmp;
}

// function processing polynomial
void processIn(char *p, int *processedPolynPower, int *processedPolynNum) {
    int num = 0, power = 0;
    bool numO = true, numhelp = false;
    
    while (*p) {
        
        if (numO) {
            num = scanNum(p);
            numO = false;
            numhelp = false;
        }
            
        if (*p == 'x') {
            if (num != 0) {
                *processedPolynNum = num;
                *processedPolynNum++;
                
                //printf("%d", num);
                numhelp = true;

                *p++;
                if (*p == '^') {
                    *p++;
                    power = scanNum(p);
                    //printf("%d", power);
                    if (power == -1) {
                        printf("Błędne wejście!");
                        return;
                    }
                        
                    else {
                        *processedPolynPower = power;
                        *processedPolynPower++;
                    }
                }

                else {
                    *processedPolynPower = 1;
                    *processedPolynPower++;
                }

            }
            else {
                *p++;
                if (*p == '^'){
                    *p++;
                    numhelp=true;
                }
                else {
                    *processedPolynNum = num;
                    *processedPolynPower = 1;
                    *p++;
                    *processedPolynPower++;
                    *processedPolynNum++;
                    numhelp = true;
                }
            }
                
                
        }
        else *p++;

        if (!*p && !numhelp && num != 0) {
            *processedPolynPower = 0;
            *processedPolynNum = num;
        } 

        if (*p == '+' || *p == '-')
            numO = true;
        
    }
    
    
}



// calculator function where user types in polynomials then
// chooses what he/she wants to calculate and gets the result
void calculator() {
    
    
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
    
    // strings with the polynomials from input
    char *polyn1, *polyn2;
    int *polyn1Power, *polyn1Num, *polyn2Power, *polyn2Num;
    polyn1 = (char*) malloc(S);
    polyn2 = (char*) malloc(S);
    polyn1Power = (int*) calloc(*degree1 + 2, I);
    polyn1Num = (int*) calloc(*degree1 + 2, I);
    polyn2Power = (int*) calloc(*degree2 + 2, I);
    polyn2Num = (int*) calloc(*degree2 + 2, I);

    //processed polynomials
    Polynomial pol1, pol2;
    pol1.polynNum = polyn1Num;
    pol1.polynPower = polyn1Power;
    pol2.polynNum = polyn2Num;
    pol2.polynPower = polyn2Power;

    //print_polynomial(pol1);

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
    processIn(polyn2, polyn2Power, polyn2Num);

    /*
    for (int i=0; i <= sizeof(polyn1Power)/sizeof(polyn1Power[0]); i++) {
        printf("%d\n", polyn1Num[i]);
    }
    */
  

    int* calc_choice; // variable storing users choice in calculator menu
    calc_choice = (int*) malloc(I);
    if (calc_choice == NULL) {
        printf("Przydzielenie pamięci nie było możliwe (calculator / calc_choice)");
        exit(0);
    }

    //options 1 - add / 2 - substract / 3 - multiply / 4 - divide and get division reminder / 5 - combine 
    printf("Operacje");
    newline
    printf("1 -> Dodaj");
    newline
    printf("2 -> Odejmij");
    newline
    printf("3 -> Wymnóż");
    newline
    printf("4 -> Podziel z resztą");
    newline
    printf("5 -> Składanie wielomianów");
    newline
    printf("6 -> Wyjście");
    wave
    
    scanf("%d", calc_choice);
    waves
    newline
    if (*calc_choice == 1) 
        print_polynomial(add(pol1, pol2));
    else if (*calc_choice == 2)
        print_polynomial(substract(pol1, pol2));
    else if (*calc_choice == 3)
        print_polynomial(multiply(pol1, pol2));
    else if (*calc_choice == 4)
        print_polynomial(divide(pol1, pol2));
    else if (*calc_choice == 5)
        print_polynomial(combine(pol1, pol2));
    else if (*calc_choice == 6)
        exit(0);
    else {
        wave
        printf("!!!Błędne wejście podaj numer operacji jeszcze raz!!!");
        wave
        calculator();
    }

    

    free(degree1);
    free(degree2);
    free(polyn1);
    free(polyn2);
    free(calc_choice);
    free(polyn1Power);
    free(polyn1Num);
    free(polyn2Num);
    free(polyn2Power);
}

//opens a file with an instruction manual to the calculator
void help() {


    
}

//prints informations about the program
void info() {


    
}


