#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define waves for (int i = 0; i < 50; i++) printf("~");
#define newline printf("\n");
#define wave newline waves newline
#define S sizeof(char)*200
#define I sizeof(int)

//structure keeping pointers to arrays with power and number of polynomial
typedef struct {
    int *polynPower;
    int *polynNum;
} Polynomial;


int binarySearch(){} 
/*{ 
    if (*r <= *l) { 
        int mid = l + (r - l) / 2; 
   
        if (arr[mid] == x) 
            return mid; 
   
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
   
        return binarySearch(arr, mid + 1, r, x); 
    } 
   
    return -1; 
} 
*/

//function printing given polynomial
void print_polynomial(Polynomial f) {
    int *fnum = f.polynNum, *fpow = f.polynPower;
    int i = 0;

    printf("Wynik: ");
    
    while (fnum[i]!=0 || fpow[i] != 0) {
        if (fnum[i] != 0) {
            if (fnum[i] > 0 && i != 0)
                printf("+");
        
            if (fnum[i] == 1 && fpow[i] == 1)
                printf("x");
            else if (fnum[i] == -1 && fpow[i] == 1) 
                printf("-x");
            else if (fpow[i] == 1) 
                printf("%dx", fnum[i]);
            else if (fnum[i] == 1)
                printf("x^%d", fpow[i]);
            else if (fpow[i] == 0)
                printf("%d", fnum[i]);
            else
                printf("%dx^%d", fnum[i], fpow[i]);
        }
        i++;
    }

    wave
    
}

//function that adds 2 polynomials and prints the result
Polynomial add(Polynomial f, Polynomial g) {
    Polynomial result;
    int *resPower, *resNum;
    int *fp = f.polynPower, *fn = f.polynNum, *gp = g.polynPower, *gn = g.polynNum;
    resPower = (int*) calloc(500, sizeof(int));
    resNum = (int*) calloc(500, sizeof(int));

    result.polynPower = resPower;
    result.polynNum = resNum;

    int i = 0, j = 0, r = 0; // pointers to polynomial arrays
    while (fp[i]!=0 || gp[j]!=0 || fn[i] != 0 || gn[j] != 0) {
        //printf("%d %d\n", hgp, hfp);

        bool czy_liczba = false;
        if (fn[i] != 0 && gn[j] !=0 && fp[i] == 0 && gp[j] == 0)
            czy_liczba = true;

        if ((fp[i] != 0 && gp[j] != 0) || czy_liczba) {
            
            if (fp[i] > gp[j]) {
                resPower[r] = fp[i];
                resNum[r] = fn[i];
                r++;
                i++;
            }
            else if (fp[i] < gp[j]){
                resPower[r] = gp[j];
                resNum[r] = gn[j];
                r++;
                j++;
            }

            else {
                if (fn[i] + gn[j] != 0) {
                    resNum[r] = fn[i] + gn[j];
                    resPower[r] = fp[i];
                    r++;
                }
                i++;
                j++;
                
            }
        }

        else {
            
            if (gp[j] != 0) {
                resPower[r] = gp[j];
                resNum[r] = gn[j];
                r++;
                j++;
            }
            else if (gn[j] != 0) {
                resPower[r] = 0;
                resNum[r] = gn[j];
                j++;
            }
            
            if (fp[i]!=0) {
                resPower[r] = fp[i];
                resNum[r] = fn[i];
                r++;
                i++;
            }
            else if (fn[i] != 0) {
                resPower[r] = 0;
                resNum[r] = fn[i];
                i++;
            }
        }


    }

    free(resNum);
    free(resPower);
    
    return result;
}

//-7x^5+2x^3-9x^2+10x
//5x^5-4x^3+5x^2-x

//function that substracts 2 polynomials and prints the result
Polynomial substract(Polynomial f, Polynomial g) {
    Polynomial result;
    int *resPower, *resNum;
    int *fp = f.polynPower, *fn = f.polynNum, *gp = g.polynPower, *gn = g.polynNum;
    resPower = (int*) calloc(500, sizeof(int));
    resNum = (int*) calloc(500, sizeof(int));

    result.polynPower = resPower;
    result.polynNum = resNum;

    int i = 0, j = 0, r = 0; // pointers to polynomial arrays
    while (fp[i]!=0 || gp[j]!=0 || fn[i] != 0 || gn[j] != 0) {
        //printf("%d %d\n", hgp, hfp);

        bool czy_liczba = false;
        if (fn[i] != 0 && gn[j] !=0 && fp[i] == 0 && gp[j] == 0)
            czy_liczba = true;

        if ((fp[i] != 0 && gp[j] != 0) || czy_liczba) {
            
            if (fp[i] > gp[j]) {
                resPower[r] = fp[i];
                resNum[r] = fn[i];
                r++;
                i++;
            }
            else if (fp[i] < gp[j]){
                resPower[r] = gp[j];
                resNum[r] = (-1) * gn[j];
                r++;
                j++;
            }

            else {
                if (fn[i] + gn[j] != 0) {
                    resNum[r] = fn[i] - gn[j];
                    resPower[r] = fp[i];
                    r++;
                }
                i++;
                j++;
                
            }
        }

        else {
            
            if (gp[j] != 0) {
                resPower[r] = gp[j];
                resNum[r] = gn[j] * (-1);
                r++;
                j++;
            }
            else if (gn[j] != 0) {
                resPower[r] = 0;
                resNum[r] = gn[j] * (-1);
                j++;
            }
            
            if (fp[i] != 0) {
                resPower[r] = fp[i];
                resNum[r] = fn[i];
                r++;
                i++;
            }
            else if (fn[i] != 0) {
                resPower[r] = 0;
                resNum[r] = fn[i] * (-1);
                i++;
            }
        }


    }

    free(resNum);
    free(resPower);
    
    return result;

}

//function that multplies 2 polynomials and prints the result 
Polynomial multiply(Polynomial f, Polynomial g) {
    Polynomial result;
    int *resPower, *resNum;
    int *fp = f.polynPower, *fn = f.polynNum, *gp = g.polynPower, *gn = g.polynNum;
    resPower = (int*) calloc(500, sizeof(int));
    resNum = (int*) calloc(500, sizeof(int));

    result.polynPower = resPower;
    result.polynNum = resNum;

    int i = 0, j = 0, r = 0; // pointers to polynomial arrays
    while (fp[i] != 0 || fn[i] != 0) {
        while (gp[j] != 0 || gn[j] != 0) {
            


            if (binarySearch) {
                
            }
        }

    }



    free(resPower);
    free(resNum);

    return result;
}

//function that divides 2 polynomials and prints the result and the reminder
Polynomial divide(Polynomial f, Polynomial g) {


}

//function that combines 2 polynomials and prints the result
Polynomial combine(Polynomial f, Polynomial g) {


}

