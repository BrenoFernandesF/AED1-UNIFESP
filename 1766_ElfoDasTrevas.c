#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 101

typedef struct {
    char nome[MAX_NAME_LENGTH];
    int peso;
    int idade;
    float altura;
} Reindeer;

// A função compare recebe dois ponteiros para Reindeer e retorna um inteiro que indica a relação de ordem entre os elementos.
int compare(Reindeer* r1, Reindeer* r2) {
    if (r1->peso != r2->peso) {
        return r2->peso - r1->peso;
    }
    if (r1->idade != r2->idade) {
        return r1->idade - r2->idade; 
    }
    if (r1->altura != r2->altura) {
        return (r1->altura > r2->altura) - (r1->altura < r2->altura);
    }
    return strcmp(r1->nome, r2->nome); 
}

// A função main lê o número de cenários, o número de renas e o número de renas que serão selecionadas, lê os dados das renas, ordena as renas e imprime as renas selecionadas.
int main() {
    int T;
    scanf("%d", &T);
    for (int cenario = 1; cenario <= T; cenario++) {
        int N, M;
        scanf("%d %d", &N, &M);
        Reindeer* reindeers = (Reindeer*)malloc(N * sizeof(Reindeer));
        for (int i = 0; i < N; i++) {
            scanf("%s %d %d %f", reindeers[i].nome, &reindeers[i].peso, &reindeers[i].idade, &reindeers[i].altura);
        qsort(reindeers, N, sizeof(Reindeer), (int (*)(const void*, const void*))compare);
        printf("CENARIO {%d}\n", cenario);
        for (int i = 0; i < M; i++) {
            printf("%d - %s\n", i + 1, reindeers[i].nome);
        }
        free(reindeers);
        }
    }
}