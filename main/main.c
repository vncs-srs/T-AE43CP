#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "cavaloBacktracking.h"

int main() {
    int tam, validaMov,mov,movX0,movY0,movXf,movYf;

    scanf("%d",&tam);

    int** Tabuleiro = iniciar_mat(tam);

    imprimir(Tabuleiro,tam);

    scanf("%d",&movX0);
    scanf("%d",&movY0);
    scanf("%d",&movXf);
    scanf("%d",&movYf);

    validaMov = movimento_cavalo(Tabuleiro,tam,movX0,movY0,1,movXf,movYf);

    if (validaMov){
        printf("Quantidade de passos: %d\n", Tabuleiro[movXf][movYf]);
        imprimir(Tabuleiro,tam);
    }
    else
        printf("Nao exite um movimento possivel!\n");

    return 0;
}
