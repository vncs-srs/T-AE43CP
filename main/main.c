#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "cavaloBacktracking.h"

int main() {
    int tam, validaMov,mov,movX,movY;

    scanf("%d",&tam);

    int** Tabuleiro = iniciar_mat(tam);

    imprimir(Tabuleiro,tam);

    scanf("%d",&movX);
    scanf("%d",&movY);
    scanf("%d",&mov);

    validaMov = movimento_cavalo(Tabuleiro,tam,movX,movY,mov);

    if (validaMov == 1)
        imprimir(Tabuleiro,tam);
    else
        printf("Movimento Invalido!\n");

    return 0;
}
