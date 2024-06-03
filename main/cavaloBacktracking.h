#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100
#define INF -1

typedef struct Posicao Posicao;

int posicao_valida(int x, int y, int N);

//int bfs_minimos_passos(int N, int x0, int y0, int xf, int yf, int matriz_passos[MAX_N][MAX_N], Posicao pai[MAX_N][MAX_N]);

void imprimir_matriz(int N, int matriz_passos[MAX_N][MAX_N]);

//void rastrear_caminho(int xf, int yf, int matriz_passos[MAX_N][MAX_N], Posicao pai[MAX_N][MAX_N]);

int** iniciar_mat(int n);
