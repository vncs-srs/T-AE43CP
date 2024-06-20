#include <stdio.h>
#include <stdlib.h>
#include "cavaloBFSBacktracking.h"

// No main(), o tamanho do tabuleiro e as posições inicial e final são lidas do usuário. Inicializa-se o tabuleiro caminho e a matriz pai. 
// A função bfs() é chamada para encontrar o menor caminho. 
// Se um caminho é encontrado, backtrackCam() é usada para registrar o caminho e imprimeTab() para imprimir o tabuleiro. 
// Se não há caminho, uma mensagem apropriada é exibida. Finalmente, o programa retorna 0.
int main() {
    int n;
    scanf("%d", &n);

    int iniX, iniY, fimX, fimY;
    scanf("%d %d", &iniX, &iniY);
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