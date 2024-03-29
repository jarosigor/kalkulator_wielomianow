#include "func.h"

/* 
Igor Jarosz
Student index number: 324608
Project: Polynomials calculator in C
Enables user to add, substract, multiply, divide 2 polynomials,
get the reminder of polynomial division and also combine those polynomials
*/

void menu() {
    
    int *menu_choice;// variable storing users choice in main menu
    menu_choice = (int*) malloc(sizeof(int));
    if (menu_choice == NULL) {
        printf("Przydzielenie pamięci nie było możliwe (menu / choice)");
        exit(0);
    }
    
    //options 1 - go to calculator / 2 - help / 3 - info / credits / 4 - exit
    printf("Opcje");
    newline;
    printf("1 -> Przejdź do kalkulatora");
    newline;
    printf("2 -> Pomoc / Instrukcja");
    newline;
    printf("3 -> Info / Credits");
    newline;
    printf("4 -> Wyjście");
    wave;
    
    scanf("%d", menu_choice);
    if (*menu_choice == 1) 
        calculator();
    else if (*menu_choice == 2)
        help();
    else if (*menu_choice == 3)
        info();
    else if (*menu_choice == 4)
        exit(0);
    else {
        wave;
        printf("!!!Błędne wejście podaj numer opcji jeszcze raz!!!");
        wave;
        menu();
    }


    free(menu_choice);
}


int main(void) {
    wave;
    printf("Witaj w kalkulatorze wielomianów!");
    wave;
    
    while (1) 
        menu();   

    return 0;
}