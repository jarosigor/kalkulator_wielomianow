
#include "calc.h"

#define FILENAME "baza_wielomianow.txt"


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

/*bool is_proper(char *polynomial) {
    int i = 0, len = strlen(polynomial);

    for(int i = 0; i < len; i++) {
        if (isdigit(polynomial[i]) != 0 || polynomial[i] == '-' || polynomial[i] == '+' || polynomial[i] == 'x' || polynomial[i] == '^');
        else 
            return false;
    }

    return true;
}
*/

void processPolynomial(char *p, int *processedPolynPower, int *processedPolynNum) {
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
                
                
                numhelp = true;

                *p++;
                if (*p == '^') {
                    *p++;
                    power = scanNum(p);

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

bool print_database(const char *file_name) {
    FILE *database;
    database = fopen(file_name, "r");
    
    if (database == NULL) {
        printf("Baza wielomianów jest pusta");
        return false;
    }

    char line[400];
    int count = 1;

    while (fgets(line, sizeof(line), database)) {
        printf("%d. %s", count, line);
        count++;
    }

    fclose(database);
    return true;

}

void add_to_database(char *polynomial, const char *file_name) {
    FILE *database;
    database = fopen(file_name, "a");

    fprintf(database, "%s\n", polynomial);

    fclose(database);
}

char *get_polynomial_database (int number, const char *file_name) {
    FILE *database;
    database = fopen(file_name, "r");

    static char line[400];
    int count = 1;
    static char *result;

    while (fgets(line, sizeof(line), database)) {
        if (count == number) {
            break;
        }
        count++;
    }

    fclose(database);
    return line;
    
    
}



// calculator function where user types in polynomials then
// chooses what he/she wants to calculate and gets the result
void calculator() {
    // strings with the polynomials from input
    char *polyn1 = (char*) malloc(S);
    char *polyn2 = (char*) malloc(S);
    int *polyn1Power = (int*) calloc(400, I);
    int *polyn1Num = (int*) calloc(400, I);
    int *polyn2Power = (int*) calloc(400, I);
    int *polyn2Num = (int*) calloc(400, I);

    //processed polynomials
    Polynomial pol1, pol2;
    pol1.polynNum = polyn1Num;
    pol1.polynPower = polyn1Power;
    pol2.polynNum = polyn2Num;
    pol2.polynPower = polyn2Power;

    bool input_from_data_base = false;
    int input_choice;
    printf("Pierwszy wielomian:");
    newline
    printf("Czy chcesz wybrać zapisany wielomian? (1 -> tak / 2 -> nie)");
    newline
    scanf("%d", &input_choice);

    if (input_choice == 1)
        input_from_data_base = true;
    else if (input_choice != 2) {
        printf("Błędne wejście!");
        wave
        calculator();
    }

    if (!input_from_data_base) {
        waves
        newline
        printf("Podaj wielomian");
        wave
        scanf("%s", polyn1);

        waves
        newline
        int saving_choice = 0;
        printf("Czy chcesz zapisać podany wielomian? (1 -> tak / 2 -> nie)");
        newline
        scanf("%d", &saving_choice);
        if (saving_choice == 1)
            add_to_database(polyn1, FILENAME);
        wave

    }
    else {
        int polynomial_choice = 0;
        wave
        print_database(FILENAME);
        wave
        printf("Podaj numer wielomianu");
        wave
        scanf("%d", &polynomial_choice);
        strcpy(polyn1, get_polynomial_database(polynomial_choice, FILENAME));
        printf("Wybrany wielomian: %s", polyn1);
        wave
    }

    input_from_data_base = false;
    printf("Drugi wielomian:");
    newline
    printf("Czy chcesz wybrać zapisany wielomian? (1 -> tak / 2 -> nie)");
    newline
    scanf("%d", &input_choice);

    if (input_choice == 1)
        input_from_data_base = true;
    else if (input_choice != 2) {
        printf("Błędne wejście!");
        wave
        calculator();
    }

    if (!input_from_data_base) {
        waves
        newline
        printf("Podaj wielomian");
        wave
        scanf("%s", polyn2);
        waves
        newline
        int saving_choice = 0;
        printf("Czy chcesz zapisać podany wielomian? (1 -> tak / 2 -> nie)");
        scanf("%d", &saving_choice);
        if (saving_choice == 1)
            add_to_database(polyn2, FILENAME);
        wave
        
    }
    else {
        int polynomial_choice = 0;
        wave
        print_database(FILENAME);
        wave
        printf("Podaj numer wielomianu");
        wave
        scanf("%d", &polynomial_choice);
        strcpy(polyn2, get_polynomial_database(polynomial_choice, FILENAME));
        printf("Wybrany wielomian: %s", polyn2);
        wave
    }

    

    processPolynomial(polyn1, polyn1Power, polyn1Num);
    processPolynomial(polyn2, polyn2Power, polyn2Num);


    int* calc_choice; 
    calc_choice = (int*) malloc(I);
    if (calc_choice == NULL) {
        printf("Przydzielenie pamięci nie było możliwe (calculator / calc_choice)");
        exit(0);
    }

    //options 1 - add / 2 - substract / 3 - multiply / 4 - divide and get division reminder / 5 - combine 
    printf("Operacje");
    newline
    printf("1 -> Oblicz wartość 1 wielomianu");
    newline
    printf("2 -> Oblicz wartość 2 wielomianu");
    newline
    printf("3 -> Dodaj");
    newline
    printf("4 -> Odejmij");
    newline
    printf("5 -> Wymnóż");
    newline
    printf("6 -> Podziel z resztą");
    newline
    printf("7 -> Składanie wielomianów");
    newline
    printf("8 -> Wyjście");
    wave
    
    scanf("%d", calc_choice);
    waves
    newline

    printf("\nWynik\n");

    if (*calc_choice == 1) {
        int x;
        printf("Podaj wartość x:");
        scanf("%d", &x);
        printf("f(%d) = %d", x, calculate_polynomial(pol1, x));
        wave
    }
    else if (*calc_choice == 2) {
        int x;
        printf("Podaj wartość x:");
        scanf("%d", &x);
        printf("g(%d) = %d", x, calculate_polynomial(pol2, x));
        wave
    }
    else if (*calc_choice == 3) 
        print_polynomial(add(pol1, pol2));
    else if (*calc_choice == 4)
        print_polynomial(substract(pol1, pol2));
    else if (*calc_choice == 5)
        print_polynomial(multiply(pol1, pol2));
    else if (*calc_choice == 6)
        print_polynomial(divide(pol1, pol2));
    else if (*calc_choice == 7)
        print_polynomial(combine(pol1, pol2));
    else if (*calc_choice == 8)
        exit(0);
    else {
        wave
        printf("!!!Błędne wejście podaj numer operacji jeszcze raz!!!");
        wave
        calculator();
    }

    
    free(polyn1);
    free(polyn2);
    free(calc_choice);
    free(polyn1Power);
    free(polyn1Num);
    free(polyn2Num);
    free(polyn2Power);
}

//opens a file with an instruction manual to the calculator
void help(const char *help_file) {
    FILE *in;
    in = fopen(help_file, "r");

    char line[400];
    wave
    while (fgets(line, sizeof(line), in)) {
        printf("%s", line);
    }
    wave

    fclose(in);
}

void info(const char *info_file) {
    FILE *in;
    in = fopen(info_file, "r");

    char line[400];
    wave
    while (fgets(line, sizeof(line), in)) {
        printf("%s", line);
    }
    wave

    fclose(in);
    
}


