#include <stdio.h>
/* A função recebe uma matriz 9x9, verifica se há números de 1 a 9 repetidos nas linhas da matriz e
* devolve 1 se não houver repetidos ou 0 se houver. */
int linhas(int matriz[9][9]) {
    int i, j, x;
    for (i = 0; i < 9; i++) {
        int numeros[10] = {0};
        for (j = 0; j < 9; j++) {
            x = matriz[i][j];
            if (numeros[x] == 1 || x > 9 || x < 1) {
                return 0;
            }
            numeros[x] = 1;
        }
    }
    return 1;
}
/* A função recebe uma matriz 9x9, verifica se há números de 1 a 9 repetidos nas colunas da matriz e
* devolve 1 se não houver repetidos ou 0 se houver. */
int colunas(int matriz[9][9]) {
    int i, j, x;
    for (j = 0; j < 9; j++) {
        int numeros[10] = {0};
        for (i = 0; i < 9; i++) {
            x = matriz[i][j];
            if (numeros[x] == 1 || x > 9 || x < 1) {
                return 0;
            }
            numeros[x] = 1;
        }
    }
    return 1;
}
/* A função recebe uma matriz 9x9, verifica se há números de 1 a 9 repetidos em cada "bloco" 3x3 e
* devolve 1 se não houver repetidos e 0 se houver. */
int blocos(int matriz[9][9]) {
    int i, j, h, l, x;
    for (i = 0; i < 9; i += 3) {
        for (j = 0; j < 9; j += 3) {
            int numeros[10] = {0};
            for (h = 0; h < 3; h++) {
                for (l = 0; l < 3; l++) {
                    x = matriz[i + h][j + l];
                    if (numeros[x] == 1 || x > 9 || x < 1) {
                        return 0;
                    }
                    numeros[x] = 1;
                }
            }
        }
    }
    return 1;
}
/* A função recebe uma matriz 9x9 e lê os valores digitados pelo usuário preenchendo cada posição da matriz. */
void lerMatriz(int matriz[9][9]) {
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
}

int main() {
    int n, i;
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        int matriz[9][9];
        lerMatriz(matriz);
        printf("Instancia %d\n", i);
        if (linhas(matriz) && colunas(matriz) && blocos(matriz)) {
            printf("SIM\n\n");
        } else {
            printf("NAO\n\n");
        }
    }

    return 0;
}
