// imagem.h
#ifndef IMAGEM_H
#define IMAGEM_H

typedef struct {
    unsigned char *imagem;
    int largura, altura, max_intensidade;
} PGM;

PGM lerPGM(const char *caminho);
void liberarImagem(PGM *pgm);
void salvarImagem(const PGM *pgm, const int *clusters, int k, const char *pasta_destino, const char *nome_imagem);

#endif
