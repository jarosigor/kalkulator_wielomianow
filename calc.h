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

void swap(int* a, int* b) {  
    int t = *a;  
    *a = *b;  
    *b = t;  
} 

void bubblesort(int *power, int *number, int arr_size) 
{ 
    for (int i = arr_size; i >= 0; i--)  
        for (int j = arr_size; j > arr_size - i; j--)  
            if (power[j] > power[j - 1]) {
                swap(&power[j], &power[j - 1]);
                swap(&number[j], &number[j - 1]);
            }

} 
int binarySearch(int array[], int left, int right, int searched_val){
    if (left <= right) {
        int mid = left + (right-left) / 2;

        if (array[mid] == searched_val) 
            return mid;
        else if (array[mid] > searched_val) 
            return binarySearch(array, mid + 1, right, searched_val);
        else 
            return binarySearch(array, left, mid - 1, searched_val);
    }

    return -1;

} 

void print_polynomial(Polynomial f) {
    int *fnum = f.polynNum, *fpow = f.polynPower;
    int i = 0;
    
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

    int i = 0, r = 0; // pointers to polynomial arrays
    while (fp[i] != 0 || fn[i] != 0) {
        int j = 0;
        while (gp[j] != 0 || gn[j] != 0) {
            int multiplied_powers = gp[j] + fp[i], multiplied_numbers = gn[j] * fn[i];
            int binsrc_res = binarySearch(resPower, 0, r - 1, multiplied_powers);

            if (binsrc_res == -1) {
                resPower[r] = multiplied_powers;
                resNum[r] = multiplied_numbers;
                r++;
            }
            else 
                resNum[binsrc_res] += multiplied_numbers;
            
            j++;
        }

        i++;

    }

    bubblesort(resPower, resNum, r-1);

    

    return result;
}

//function that divides 2 polynomials and prints the result and the reminder
Polynomial divide(Polynomial f, Polynomial g) {


}

//function that combines 2 polynomials and prints the result
Polynomial combine(Polynomial f, Polynomial g) {


}

