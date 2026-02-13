#include <stdio.h>
#include "basicfunc.h"

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
        M++; temp = A[i];
        M++; A[i] = A[min];
        M++; A[min] = temp;

        //debug
        if (debug) {
            PrintMas(A, n);
            printf("    min = %d Mф = %d Cф = %d\n", A[i], M, C);
        }
    }

    *SumM += M;
    *SumC += C;
}

void AdvancedSelectionSort(int *A, int n, int *SumM, int *SumC, int debug) {
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
        if (min != i) {
            M++; temp = A[i];
            M++; A[i] = A[min];
            M++; A[min] = temp;
        }

        //debug
        if (debug) {
            PrintMas(A, n);
            printf("    min = %d Mф = %d Cф = %d\n", A[i], M, C);
        }
    }

    *SumM += M;
    *SumC += C;
}
