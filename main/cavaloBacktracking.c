#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cavaloBacktracking.h"


// Estrutura para representar uma posição no tabuleiro
struct Posicao{
    int x, y;
};


// Função para verificar se a posição é válida no tabuleiro
int posicao_valida(int x, int y, int N) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

// Movimentos possíveis do cavalo no xadrez
int movimentos_cavalo[8][2] = {
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, 
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
};

// Função para encontrar a menor quantidade de passos usando BFS
int bfs_minimos_passos(int N, int x0, int y0, int xf, int yf, int matriz_passos[MAX_N][MAX_N], Posicao pai[MAX_N][MAX_N]) {
    // Inicializando a matriz de passos com -1 (não visitado)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriz_passos[i][j] = INF;
            pai[i][j] = (Posicao){-1, -1};
        }
    }
    matriz_passos[x0][y0] = 0;

    // Fila para realizar a BFS
    Posicao fila[MAX_N * MAX_N];
    int inicio = 0, fim = 0;
    fila[fim++] = (Posicao){x0, y0};

    while (inicio < fim) {
        Posicao atual = fila[inicio++];
        int x = atual.x, y = atual.y;

        if (x == xf && y == yf) {
            return matriz_passos[xf][yf];
        }

        for (int i = 0; i < 8; i++) {
            int nx = x + movimentos_cavalo[i][0];
            int ny = y + movimentos_cavalo[i][1];

            if (posicao_valida(nx, ny, N) && matriz_passos[nx][ny] == INF) {
                matriz_passos[nx][ny] = matriz_passos[x][y] + 1;
                pai[nx][ny] = (Posicao){x, y};
                fila[fim++] = (Posicao){nx, ny};
            }
        }
    }

    return INF;  // Retorna -1 se não for possível alcançar a posição final
}

// Função para imprimir a matriz de passos
void imprimir_matriz(int N, int matriz_passos[MAX_N][MAX_N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matriz_passos[i][j] == INF) {
                printf(" 0 ");
            } else {
                printf("%2d ", matriz_passos[i][j]);
            }
        }
        printf("\n");
    }
}

// Função para rastrear o caminho do ponto final ao ponto inicial
void rastrear_caminho(int xf, int yf, int matriz_passos[MAX_N][MAX_N], Posicao pai[MAX_N][MAX_N]) {
    Posicao atual = (Posicao){xf, yf};
    while (atual.x != -1 && atual.y != -1) {
        Posicao anterior = pai[atual.x][atual.y];
        if (anterior.x != -1 && anterior.y != -1) {
            matriz_passos[anterior.x][anterior.y] = matriz_passos[atual.x][atual.y] - 1;
        }
        atual = anterior;
    }
}

// função para inicializar uma matriz n x n
int** iniciar_mat(int n){
    int i, j;
    int **mat = (int**) malloc(sizeof(int*) * n);

    for (i = 0; i < n; i++){
        mat[i] = (int*) malloc(sizeof(int) * n);

        for (j = 0; j < n; j++)
            mat[i][j] = -1;
    }

    return mat;
}
