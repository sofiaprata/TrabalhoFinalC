#include "kmeans.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "imagem.h"

#define MAX_ITER 100

void kmeans(PGM *pgm, int k, int *clusters) {
    int centroides[k];
    int soma[k], count[k];
    
    srand(time(NULL));
    for (int i = 0; i < k; i++) centroides[i] = rand() % 256;
    
    for (int iter = 0; iter < MAX_ITER; iter++) {
        memset(soma, 0, k * sizeof(int));
        memset(count, 0, k * sizeof(int));
        
        for (int i = 0; i < pgm->largura * pgm->altura; i++) {
            int pixel = pgm->imagem[i];
            int cluster = 0, min_dist = abs(pixel - centroides[0]);
            
            for (int c = 1; c < k; c++) {
                int dist = abs(pixel - centroides[c]);
                if (dist < min_dist) {
                    min_dist = dist;
                    cluster = c;
                }
            }
            clusters[i] = cluster;
            soma[cluster] += pixel;
            count[cluster]++;
        }
        
        for (int c = 0; c < k; c++)
            centroides[c] = count[c] ? soma[c] / count[c] : centroides[c];
    }
}
