#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAS_LEN 10


void FillInc(int *A, int n) {
    for (int i = 0; i < n; i++) {
        A[i] = i + 1;
    }
}


void FillDec(int *A, int n) {
    for (int i = 0; i < n; i++) {
        A[i] = n - i;
    }
}


void FillRand(int *A, int n) {
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 20 + 1;
    }

}


int CheckSum(int *A, int n) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += A[i];
    }

    return sum;
}


int RunNumber(int *A, int n) {
    int series = 1;

    for (int i = 1; i < n; i++) {
        if (A[i - 1] > A[i]) {
            series++;
        }
    }

    return series;
}


void PrintMas(int *A, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
}


//SelectionSort Begin
void SelectionSort(int *A, int n, int *SumM, int *SumC, int debug) {
    int min, temp;
    int M = 0;
    int C = 0;

    for (int i = 0; i < n-1; i++) {
        //find min num index
        min = i;
        for (int j = i+1; j < n; j++) {
            C++; if (A[min] > A[j]) {
                min = j;            
            }        
        }

        //swap
        //if (min != i) {            
            M++; temp = A[i];
            M++; A[i] = A[min];
            M++; A[min] = temp;
        //}
        
        //debug
        if (debug) {
            PrintMas(A, n);
            printf("    min = %d Mф = %d Cф = %d\n", A[i], M, C);
        }    
    }
    
    *SumM += M;
    *SumC += C;
}
//SelectionSort End

void PrintInfo(int *A, int n) {
    PrintMas(A, n);
    printf("    CheckSum = %d, Series = %d\n", CheckSum(A, MAS_LEN), RunNumber(A, MAS_LEN));
}


int main() {
    srand(time(NULL));
    
    /*
    int a[MAS_LEN];
    FillInc(a, MAS_LEN);
    PrintMas(a, MAS_LEN);
    printf("\ncheck sum - %d\n", CheckSum(a, MAS_LEN));
    printf("series - %d\n", RunNumber(a, MAS_LEN));

    printf("\n");

    FillDec(a, MAS_LEN);
    PrintMas(a, MAS_LEN);
    printf("\ncheck sum - %d\n", CheckSum(a, MAS_LEN));
    printf("series - %d\n", RunNumber(a, MAS_LEN));

    printf("\n");

    FillRand(a, MAS_LEN);
    PrintMas(a, MAS_LEN);
    printf("\ncheck sum - %d\n", CheckSum(a, MAS_LEN));
    printf("series - %d\n", RunNumber(a, MAS_LEN));

    int series_sum = 0;
    for (int i = 0; i < 1000; i++) {
        FillRand(a, MAS_LEN);
        series_sum += RunNumber(a, MAS_LEN);
    }
    
    printf("\n");
    printf("AVG series length - %3.f\n", (float)(1000 * MAS_LEN) / series_sum);
    
    */

    int a[MAS_LEN];
    int SumM = 0;
    int SumC = 0;
    int iterations = 0;
    int debug = 0;


    printf("iterations quantity - ");
    scanf("%d", &iterations);
    printf("debug? - ");
    scanf("%d", &debug);


    printf("\nSelectionSort\n");
    printf("Excepted max T: M = %d, C = %d\n\n", 3*(MAS_LEN-1), (MAS_LEN*MAS_LEN-MAS_LEN)/2);


    printf("x%d RANDOM NUMBERS ARRAYS\n", iterations);
    for (int i = 0; i < iterations; i++) {    
        FillRand(a, MAS_LEN);
        
        if (debug) { PrintInfo(a, MAS_LEN); }
        SelectionSort(a, MAS_LEN, &SumM, &SumC, debug);
        if (debug) { PrintInfo(a, MAS_LEN);
        printf("\n"); } 
    }


    printf("Mф + Сф = %d\n\n", SumM + SumC);
    SumM = 0;
    SumC = 0;

    printf("x%d INCREMENT NUMBERS ARRAYS\n", iterations);
    for (int i = 0; i < iterations; i++) {
        FillInc(a, MAS_LEN);
      
        if (debug) { PrintInfo(a, MAS_LEN); }
        SelectionSort(a, MAS_LEN, &SumM, &SumC, debug);
        if (debug) { PrintInfo(a, MAS_LEN);
        printf("\n"); } 
    }


    printf("Mф + Сф = %d\n\n", SumM + SumC);
    SumM = 0;
    SumC = 0;

    printf("x%d DECREMENT NUMBERS ARRAYS\n", iterations);
    for (int i = 0; i < iterations; i++) {
        FillDec(a, MAS_LEN);
        
        if (debug) { PrintInfo(a, MAS_LEN); }
        SelectionSort(a, MAS_LEN, &SumM, &SumC, debug);
        if (debug) { PrintInfo(a, MAS_LEN);
        printf("\n"); } 
    }

    printf("Mф + Сф = %d\n", SumM + SumC);
    SumM = 0;
    SumC = 0;
    
    return 0;
}
