#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000000

int pilha_principal[MAX];
int pilha_min[MAX];
int topo_principal = -1;
int topo_min = -1;

void push(int valor) {
    pilha_principal[++topo_principal] = valor;
    if (topo_min == -1 || valor <= pilha_min[topo_min]) {
        pilha_min[++topo_min] = valor;
    }
}

void pop() {
    if (topo_principal == -1) {
        printf("EMPTY\n");
        return;
    }
    if (pilha_principal[topo_principal] == pilha_min[topo_min]) {
        topo_min--;
    }
    topo_principal--;
}

// Função que imprime o menor valor da pilha
void min() {
    if (topo_min == -1) {
        printf("EMPTY\n");
    } else {
        printf("%d\n", pilha_min[topo_min]);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    char operacao[5];
    int valor;
    for (int i = 0; i < N; i++) {
        scanf("%s", operacao);
        if (strcmp(operacao, "PUSH") == 0) {
            scanf("%d", &valor);
            push(valor);
        } else if (strcmp(operacao, "POP") == 0) {
            pop();
        } else if (strcmp(operacao, "MIN") == 0) {
            min();
        }
    }
}
