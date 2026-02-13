#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "basicfunc.h"
#include "sortalgs.h"

#define MAS_LEN 10

void check_all(int *array, int iterations, int debug, int SumM, int SumC) {
    int *tmp = realloc(array, MAS_LEN * sizeof(int));
    array = tmp;

    printf("\n---InsertSort---\n");

    printf("\nx%d RANDOM NUMBERS ARRAYS\n", iterations);
    for (int i = 0; i < iterations; i++) {
        FillRand(array, MAS_LEN);

        if (debug) { PrintInfo(array, MAS_LEN); }
        SelectionSort(array, MAS_LEN, &SumM, &SumC, debug);
        if (debug) { PrintInfo(array, MAS_LEN);
            printf("\n"); }
    }

    printf("Mф + Сф = %d\n\n", SumM + SumC);
    SumM = 0;
    SumC = 0;

    printf("x%d INCREMENT NUMBERS ARRAYS\n", iterations);
    for (int i = 0; i < iterations; i++) {
        FillInc(array, MAS_LEN);

        if (debug) { PrintInfo(array, MAS_LEN); }
        SelectionSort(array, MAS_LEN, &SumM, &SumC, debug);
        if (debug) { PrintInfo(array, MAS_LEN);
            printf("\n"); }
    }


    printf("Mф + Сф = %d\n\n", SumM + SumC);
    SumM = 0;
    SumC = 0;

    printf("x%d DECREMENT NUMBERS ARRAYS\n", iterations);
    for (int i = 0; i < iterations; i++) {
        FillDec(array, MAS_LEN);

        if (debug) { PrintInfo(array, MAS_LEN); }
        SelectionSort(array, MAS_LEN, &SumM, &SumC, debug);
        if (debug) { PrintInfo(array, MAS_LEN);
            printf("\n"); }
    }

    printf("Mф + Сф = %d\n", SumM + SumC);
    SumM = 0;
    SumC = 0;


    printf("\n---InsertSort+---\n");


    printf("\nx%d RANDOM NUMBERS ARRAYS\n", iterations);
    for (int i = 0; i < iterations; i++) {
        FillRand(array, MAS_LEN);

        if (debug) { PrintInfo(array, MAS_LEN); }
        AdvancedSelectionSort(array, MAS_LEN, &SumM, &SumC, debug);
        if (debug) { PrintInfo(array, MAS_LEN);
            printf("\n"); }
    }

    printf("Mф + Сф = %d\n\n", SumM + SumC);
    SumM = 0;
    SumC = 0;

    printf("x%d INCREMENT NUMBERS ARRAYS\n", iterations);
    for (int i = 0; i < iterations; i++) {
        FillInc(array, MAS_LEN);

        if (debug) { PrintInfo(array, MAS_LEN); }
        AdvancedSelectionSort(array, MAS_LEN, &SumM, &SumC, debug);
        if (debug) { PrintInfo(array, MAS_LEN);
            printf("\n"); }
    }


    printf("Mф + Сф = %d\n\n", SumM + SumC);
    SumM = 0;
    SumC = 0;

    printf("x%d DECREMENT NUMBERS ARRAYS\n", iterations);
    for (int i = 0; i < iterations; i++) {
        FillDec(array, MAS_LEN);

        if (debug) { PrintInfo(array, MAS_LEN); }
        AdvancedSelectionSort(array, MAS_LEN, &SumM, &SumC, debug);
        if (debug) { PrintInfo(array, MAS_LEN);
            printf("\n"); }
    }

    printf("Mф + Сф = %d\n", SumM + SumC);
    SumM = 0;
    SumC = 0;
}


void check_graph(int *array, int iterations, int debug, int SumM, int SumC) {
    int T[iterations+1];
    T[0] = 0;

    for (int i = 0; i < iterations; i++) {
        int *tmp = realloc(array, i * sizeof(int));
        array = tmp;

        FillRand(array, i);
        SelectionSort(array, i, &SumM, &SumC, debug);

        T[i+1] = SumM + SumC;

        SumM = 0;
        SumC = 0;
    }

    create_graph_file(T, iterations+1);
}


int main() {
    srand(time(NULL));

    printf("\nSelectionSort\n");
    printf("Excepted max T: M = %d, C = %d\n\n", 3*(MAS_LEN-1), (MAS_LEN*MAS_LEN-MAS_LEN)/2);

    int iterations = 0;
    int debug = 0;

    printf("\nRAND/INC/DEC test\n");

    printf("iterations quantity - ");
    scanf("%d", &iterations);
    printf("debug? - ");
    scanf("%d", &debug);


    int *array = malloc(sizeof(int));

    int SumM = 0;
    int SumC = 0;

    check_all(array, iterations, debug, SumM, SumC);


    printf("\ngraph\n");

    printf("iterations quantity - ");
    scanf("%d", &iterations);
    printf("debug? - ");
    scanf("%d", &debug);

    check_graph(array, iterations, debug, SumM, SumC);

    system("gnuplot -persistence graph.gp");

    free(array);

    return 0;
}

