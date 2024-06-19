// Inclusão de bibliotecas padrão de entrada/saída (stdio.h) e utilitárias (stdlib.h).
#include <stdio.h>
#include <stdlib.h>

//Define uma constante MAXN com valor 100, que será usada para limitar o tamanho da fila usada na busca em largura (BFS).
#define MAXN 100 

/* Definimos um novo tipo Cell usando struct. Esse tipo tem três campos:
x e y representam coordenadas no tabuleiro.
dist representa a distância desde o ponto inicial.*/
typedef struct {
    int x, y;
    int dist;
} Cell;

// Definimos os vetores dx e dy que contêm os possíveis movimentos do cavalo em um tabuleiro de xadrez.
int dx[8] = {2, 2, 1, -1, -2, -2, -1, 1};
int dy[8] = {1, -1, -2, -2, -1, 1, 2, 2};

// Função que verifica se uma posição (x, y) está dentro dos limites do tabuleiro de tamanho n.
int ehValido(int x, int y, int n) {
    return (x >= 0 && x < n && y >= 0 && y < n);
}

// Função para encontrar o menor caminho usando BFS
int bfs(int n, int iniX, int iniY, int fimX, int fimY, int caminho[n][n], Cell pai[n][n]) {
    // (31 - 38)
    // Estas linhas inicializam a matriz visitou (para rasttras posições visitadas) e a matriz pai (para armazenar o caminho de volta). 
    // Ambas têm o tamanho n x n. Cada célula é marcada como não visitada (0) e sem um pai (-1, -1, -1).

    int visitou[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            visitou[i][j] = 0;
            pai[i][j] = (Cell){-1, -1, -1};
        }

    // (42 - 46)
    // Uma fila de células é criada para a BFS, juntamente com os índices frente e tras para gerenciar a fila. 
    // A posição inicial é adicionada à fila e marcada como visitada.
    Cell fila[MAXN * MAXN];
    int frente = 0, tras = 0;

    fila[tras++] = (Cell){iniX, iniY, 0};
    visitou[iniX][iniY] = 1;

    // (51 - 56)
    // O loop while continua até que a fila esteja vazia (frente < tras). 
    // Dentro do loop, a célula da frente da fila é retirada para processamento. Se esta célula é a célula final, a função retorna a distância total.
    while (frente < tras) {
        Cell cell = fila[frente++];

        if (cell.x == fimX && cell.y == fimY) {
            return cell.dist;
        }

        // (62 - 74)
        // Para cada célula processada, os possíveis movimentos do cavalo são calculados e verificados se são válidos e não visitados. 
        // Se forem válidos, são marcados como visitados, seu pai é registrado, e a célula é adicionada à fila com a distância atualizada. 
        // Se a fila se esvazia sem encontrar a célula final, a função retorna -1, indicando que não há caminho.
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
    return -1; // Caminho não encontrado
}

// (81 - 90)
// Função de backtracking para marcar o caminho no tabuleiro
// Realiza o backtracking do caminho encontrado pela BFS. 
// Começa na célula final e segue os pais até a célula inicial, marcando o caminho no tabuleiro.
void backtrackCam(int n, int iniX, int iniY, int fimX, int fimY, int caminho[n][n], Cell pai[n][n]) {
    if (fimX == iniX && fimY == iniY) {
        caminho[iniX][iniY] = 0;
        return;
    }

    Cell p = pai[fimX][fimY];
    caminho[fimX][fimY] = p.dist;
    backtrackCam(n, iniX, iniY, p.x, p.y, caminho, pai);
}

// (96 - 116)
// Esta função imprime o tabuleiro com os passos do caminho. 
// Os valores do caminho são exibidos em cada célula. A célula inicial é destacada com um asterisco *.
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

// (122 - 149)
// No main(), o tamanho do tabuleiro e as posições inicial e final são lidas do usuário. Inicializa-se o tabuleiro caminho e a matriz pai. 
// A função bfs() é chamada para encontrar o menor caminho. 
// Se um caminho é encontrado, backtrackCam() é usada para registrar o caminho e imprimeTab() para imprimir o tabuleiro. 
// Se não há caminho, uma mensagem apropriada é exibida. Finalmente, o programa retorna 0.
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
