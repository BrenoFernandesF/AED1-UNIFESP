#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int valor;
    char tipo;
} Problema;

// Função de comparação para qsort
int compara(const void *a, const void *b) {
    Problema *p1 = (Problema *)a;
    Problema *p2 = (Problema *)b;

    if (p1->tipo != p2->tipo) {
        return p1->tipo - p2->tipo;
    }
    return p2->valor - p1->valor;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    Problema problemas[N * M];
    int index = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int valor;
            char tipo;
            scanf("%1d%c", &valor, &tipo); 
            problemas[index].valor = valor;
            problemas[index].tipo = tipo;
            index++;
        }
    }
    qsort(problemas, N * M, sizeof(Problema), compara);
    for (int i = 0; i < N * M; i++) {
        if (problemas[i].tipo == 'V')
        printf("%d%c\n", problemas[i].valor, problemas[i].tipo);
    }
    for (int i = 0; i < N * M; i++) {
        if (problemas[i].tipo == 'D')
        printf("%d%c\n", problemas[i].valor, problemas[i].tipo);
    }    
}
