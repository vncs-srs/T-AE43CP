#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "cavaloBacktracking.h"

int main() {
    int tam, validaMov,mov;

    scanf("%d",&tam);

    int** Tabuleiro = iniciar_mat(tam);

    for (int i = 0; i < tam; i++){
        for(int j = 0; j < tam;j++){
            scanf("%d",&mov);
            validaMov = movimento_cavalo(Tabuleiro,tam,i,j,mov);
            if (validaMov == 1)
                imprimir(Tabuleiro,tam);
            else
                printf("Movimento Invalido!\n");
        }
    }

    return 0;
}
