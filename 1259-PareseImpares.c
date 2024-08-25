#include <stdio.h>
#include <stdlib.h>

// A função compara dois inteiros para ordenação crescente
int comparacao_crescente(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// A função compara dois inteiros para ordenação decrescente
int comparacao_decrescente(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int N;
    scanf("%d", &N);
    int pares[N], impares[N];
    int qtd_pares = 0, qtd_impares = 0;
    for (int i = 0; i < N; i++) {
        int valor;
        scanf("%d", &valor);
        if (valor % 2 == 0) {
            pares[qtd_pares++] = valor;
        } else {
            impares[qtd_impares++] = valor;
        }
    }
    qsort(pares, qtd_pares, sizeof(int), comparacao_crescente);
    qsort(impares, qtd_impares, sizeof(int), comparacao_decrescente);
    for (int i = 0; i < qtd_pares; i++) {
        printf("%d\n", pares[i]);
    }
    for (int i = 0; i < qtd_impares; i++) {
        printf("%d\n", impares[i]);
    }
}
