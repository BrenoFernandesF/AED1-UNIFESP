#include <stdio.h>
#include <stdlib.h>


typedef struct pilha {
    int valor;
    struct pilha* prox;
} pilha;


void push(pilha** topo, int valor) {
    pilha* nova = (pilha*)malloc(sizeof(pilha));
    nova->valor = valor;
    nova->prox = *topo;
    *topo = nova;
}


int pop(pilha** topo) {
    int valor = (*topo)->valor;
    pilha* aux = *topo;
    *topo = (*topo)->prox;
    free(aux);
    return valor;
}

int consulta(pilha* topo) {
    if (topo == NULL) {
        return -1;
    }
    return topo->valor;
}

void libera(pilha** topo) {
    while (*topo != NULL) {
        pop(topo);
    }
}

// A função main lê um inteiro n e um vetor de inteiros trem de tamanho n e verifica se é possível ordenar o vetor trem com uma pilha
int main() {
    int n;
    while (scanf("%d", &n), n != 0) {
        while (1) {
            int trem[n];
            scanf("%d", &trem[0]);
            if (trem[0] == 0) {
                break;
            }
            for (int i = 1; i < n; i++) {
                scanf("%d", &trem[i]);
            }
            pilha* Pilha = NULL;
            int j = 0;
            for (int i = 1; i <= n; i++) {
                push(&Pilha, i);
                while (Pilha != NULL && consulta(Pilha) == trem[j]) {
                    pop(&Pilha);
                    j++;
                }
            }
            if (Pilha == NULL) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
            libera(&Pilha); 
        }
        printf("\n");
    }
}
