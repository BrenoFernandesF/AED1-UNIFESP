#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int identificador;
    struct celula* seg;
} celula;

// A função recebe um inteiro y e duas celulas cabeça es e et de uma fila em lista encadeada e enfileira um novo elemento com identificador y na fila.
void enfileira (int y, celula **es, celula **et) {
    celula *nova = (celula*)malloc(sizeof(celula));
    nova->identificador = y;
    nova->seg = NULL;
    if (*et == NULL) {
        *es = *et = nova;
    } else {
        (*et)->seg = nova;
        *et = nova;
    }
}

// A função recebe uma celula cabeça s de uma fila em lista encadeada e busca remove o elemento com identificador y da fila.
void busca_remove (celula **es, celula **et, int y) {
    celula *lixo = *es;
    celula *anterior = NULL;
    while (lixo != NULL && lixo->identificador != y) {
        anterior = lixo;
        lixo = lixo->seg;
    }
    if (lixo == NULL) {
        return;
    }
    if (lixo == *es) {
        *es = lixo->seg;
    } else {
        anterior->seg = lixo->seg;
    }
    if (lixo == *et) {
        *et = anterior;
    }
    free(lixo);
}

// A função recebe uma celula cabeça s de uma fila em lista encadeada e imprime os elementos da fila.
void imprime (celula *s) {
    celula *aux = s;
    while (aux != NULL) {
        if (aux->seg != NULL) {
            printf("%d ", aux->identificador);
        } else {
            printf("%d\n", aux->identificador);
        }
        aux = aux->seg;
    }
}
// A função recebe uma celula cabeça s de uma fila em lista encadeada e libera a memória alocada
void libera (celula *s) {
    celula *aux = s;
    while (aux != NULL) {
        celula *lixo = aux;
        aux = aux->seg;
        free(lixo);
    }
}

int main() {
    int N, M, i;
    int *vetorN, *vetorM;
    celula *s = NULL, *t = NULL;
    scanf("%d", &N);
    vetorN = (int*)malloc(N * sizeof(int));
    for (i = 0; i < N; i++) {
        scanf("%d", &vetorN[i]);
        enfileira(vetorN[i], &s, &t);
    }
    scanf("%d", &M);
    vetorM = (int*)malloc(M * sizeof(int));
    for (i = 0; i < M; i++) {
        scanf("%d", &vetorM[i]);
        busca_remove(&s, &t, vetorM[i]);
    }
    imprime(s);
    libera(s);
    free(vetorN);
    free(vetorM);
    return 0;
}