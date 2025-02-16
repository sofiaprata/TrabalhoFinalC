// main.c
#include <stdio.h>
#include <time.h>
#include "utilidades.h"


int main() {
    clock_t begin = clock();
    processarPasta("C:/Users/Gleissi/Desktop/TrabalhoFinalLab/Carcinoma", "C:/Users/Gleissi/Desktop/TrabalhoFinalLab/linkedizado/output");
    ;
    clock_t end = clock();
    double time = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Tempo total: %lf segundos\n", time);
    return 0;
}
