#include <stdio.h>
#include <stdlib.h>

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


void PrintInfo(int *A, int n) {
    PrintMas(A, n);
    printf("    CheckSum = %d, Series = %d\n", CheckSum(A, n), RunNumber(A, n));
}


void create_graph(int *T, int n) {
    FILE *gp = fopen("graph.gp", "w");

    fprintf(gp, "plot '-' with lines title 'T'\n");

    for (int i = 0; i < n; i += 1) {
        fprintf(gp, "%d %d\n", i, T[i]);
    }

    fprintf(gp, "e\n");
    fclose(gp);
}
