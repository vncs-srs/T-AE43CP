#ifndef cavaloBFSBacktrackingH
#define cavaloBFSBacktrackingH

#define MAXN 100 

typedef struct Cell Cell;

int ehValido(int x, int y, int n);

int bfs(int n, int iniX, int iniY, int fimX, int fimY, int caminho[n][n], Cell pai[n][n]);

void backtrackCam(int n, int iniX, int iniY, int fimX, int fimY, int caminho[n][n], Cell pai[n][n]);

void imprimeTab(int n, int caminho[n][n], int x, int y);

#endif

