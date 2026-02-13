#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "basicfunc.h"
#include "sortalgs.h"

#define MAS_LEN 10


int main() {
    srand(time(NULL));

    int iterations = 0;
    int debug = 0;

    printf("iterations quantity - ");
    scanf("%d", &iterations);
    printf("debug? - ");
    scanf("%d", &debug);

    int T[iterations+1];
    int *array = malloc(1 * sizeof(int));

    int SumM = 0;
    int SumC = 0;

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

    create_graph(T, iterations+1);

    free(array);

    return 0;
}

