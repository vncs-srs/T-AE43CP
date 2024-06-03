#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "cavaloBacktracking.c"

int main() {
    int N, x0, y0, xf, yf;
    //Tamanho do tabuleiro N
    scanf("%d", &N);

    //Posição inicial (x0, y0)
    scanf("%d %d", &x0, &y0);

    //Posição final (xf, yf)
    scanf("%d %d", &xf, &yf);

    if (!posicao_valida(x0, y0, N) || !posicao_valida(xf, yf, N)) {
        printf("Posição inicial ou final inválida.\n");
        return 1;
    }

    int matriz_passos[MAX_N][MAX_N];
    Posicao pai[MAX_N][MAX_N];

    int passos = bfs_minimos_passos(N, x0, y0, xf, yf, matriz_passos, pai);

    if (passos != INF) {
        printf("Quantidade mínima de passos: %d\n", passos);
        rastrear_caminho(xf, yf, matriz_passos, pai);
        imprimir_matriz(N, matriz_passos);
    } else {
        printf("Não é possível alcançar a posição final a partir da posição inicial.\n");
    }

    return 0;
}