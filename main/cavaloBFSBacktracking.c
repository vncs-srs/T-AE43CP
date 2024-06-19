#include "cavaloBFSBacktracking.h"

typedef struct {
    int x, y;
    int dist;
} Cell;

int dx[8] = {2, 2, 1, -1, -2, -2, -1, 1};
int dy[8] = {1, -1, -2, -2, -1, 1, 2, 2};

int ehValido(int x, int y, int n) {
    return (x >= 0 && x < n && y >= 0 && y < n);
}

int bfs(int n, int iniX, int iniY, int fimX, int fimY, int caminho[n][n], Cell pai[n][n]) {
    

    int visitou[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            visitou[i][j] = 0;
            pai[i][j] = (Cell){-1, -1, -1};
        }

    
    Cell fila[MAXN * MAXN];
    int frente = 0, tras = 0;

    fila[tras++] = (Cell){iniX, iniY, 0};
    visitou[iniX][iniY] = 1;

    while (frente < tras) {
        Cell cell = fila[frente++];

        if (cell.x == fimX && cell.y == fimY) {
            return cell.dist;
        }

        for (int i = 0; i < 8; i++) {
            int x = cell.x + dx[i];
            int y = cell.y + dy[i];

            if (ehValido(x, y, n) && !visitou[x][y]) {
                visitou[x][y] = 1;
                pai[x][y] = (Cell){cell.x, cell.y, cell.dist + 1};
                fila[tras++] = (Cell){x, y, cell.dist + 1};
            }
        }
    }
    return -1;
}

void backtrackCam(int n, int iniX, int iniY, int fimX, int fimY, int caminho[n][n], Cell pai[n][n]) {
    if (fimX == iniX && fimY == iniY) {
        caminho[iniX][iniY] = 0;
        return;
    }

    Cell p = pai[fimX][fimY];
    caminho[fimX][fimY] = p.dist;
    backtrackCam(n, iniX, iniY, p.x, p.y, caminho, pai);
}

void imprimeTab(int n, int caminho[n][n], int x, int y) {
    printf("    ");
    for (int j = 0; j < n; j++) {
        printf("%d:", j);
        printf(" ");
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        for (int j = 0; j < n; j++) {
            if(i == x && j == y){
                printf("%2d*", caminho[i][j]);
            }
            else{
                printf("%2d ", caminho[i][j]);
            }
        }
        printf("\n");
    }
}