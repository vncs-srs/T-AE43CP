#include <stdio.h>
#include <stdlib.h>
#include "cavaloBFSBacktracking.c"

int main() {
    int n;
    printf("Digite o tamanho do tabuleiro: ");
    scanf("%d", &n);

    int iniX, iniY, fimX, fimY;
    printf("Digite a posição inicial (x y): ");
    scanf("%d %d", &iniX, &iniY);
    printf("Digite a posição final (xf yf): ");
    scanf("%d %d", &fimX, &fimY);

    int caminho[n][n];
    Cell pai[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            caminho[i][j] = 0;

    int result = bfs(n, iniX, iniY, fimX, fimY, caminho, pai);
    if (result != -1) {
        backtrackCam(n, iniX, iniY, fimX, fimY, caminho, pai);
        printf("Menor caminho encontrado (passos): %d\n", result);
        imprimeTab(n, caminho, iniX, iniY);
    } else {
        printf("Não há caminho possível para o cavalo.\n");
    }

    return 0;
}