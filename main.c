// main.c
#include <stdio.h>
#include <time.h>
#include "utilidades.h"
// utilidades.c
#include "imagem.h"
#include "kmeans.h"
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>


void criarPastaDestino(const char *pasta) {
    struct stat st;
    if (stat(pasta, &st) == -1) mkdir(pasta);
}

void processarPasta(const char *pasta, const char *pasta_destino) {
    DIR *dir = opendir(pasta);
    if (!dir) return;
    
    criarPastaDestino(pasta_destino);
    struct dirent *entrada;
    
    while ((entrada = readdir(dir)) != NULL) {
        if (strstr(entrada->d_name, ".pgm")) {
            char caminho[256];
            snprintf(caminho, sizeof(caminho), "%s/%s", pasta, entrada->d_name);
            
            PGM pgm = lerPGM(caminho);
            if (!pgm.imagem) continue;
            
            int *clusters = malloc(pgm.largura * pgm.altura * sizeof(int));
            if (!clusters) {
                liberarImagem(&pgm);
                continue;
            }
            
            kmeans(&pgm, 10, clusters);
            salvarImagem(&pgm, clusters, 10, pasta_destino, entrada->d_name);
            
            free(clusters);
            liberarImagem(&pgm);
        }
    }
    closedir(dir);
}


int main() {
    clock_t begin = clock();
    processarPasta("C:/Users/Gleissi/Desktop/TrabalhoFinalLab/Carcinoma", "C:/Users/Gleissi/Desktop/TrabalhoFinalLab/Carcinoma_out10");
    clock_t end = clock();
    double time = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Tempo total: %lf segundos\n", time);
    return 0;
}
