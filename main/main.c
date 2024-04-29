#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "cavaloBacktracking.h"

int main() {
    int tam=0;
    scanf("%d",&tam);
    int Tab[tam][tam];

    Tab[tam][tam]=iniciar_mat(tam);

    int movX=0,movY=0,mov=0;
    int aux;

    scanf("%d",&movX);
    scanf("%d",&movY);
    printf(">>>>\n");
    aux=movimento_cavalo(Tab,tam,movX,movY,mov);
    printf(">>>>\n");
    imprimir(Tab,tam);
    printf(">>>>\n");
    return 0;
}
