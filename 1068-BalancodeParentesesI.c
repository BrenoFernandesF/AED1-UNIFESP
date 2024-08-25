#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char valor;
    struct No* proximo;
} No;

typedef struct Pilha {
    No* topo;
} Pilha;

void inicializar_pilha(Pilha* p) {
    p->topo = NULL;
}

int pilha_vazia(Pilha* p) {
    return p->topo == NULL;
}

void empilhar(Pilha* p, char valor) {
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->proximo = p->topo;
    p->topo = novo_no;
}

char desempilhar(Pilha* p) {
    if (pilha_vazia(p)) {
        return '\0';
    }
    char valor = p->topo->valor;
    No* temp = p->topo;
    p->topo = p->topo->proximo;
    free(temp);
    return valor;
}

// A função recebe uma expressão do tipo char e verifica se a expressão está balanceada
void verificar_expressao(const char* expressao) {
    Pilha pilha;
    inicializar_pilha(&pilha);

    for (int i = 0; expressao[i] != '\0'; i++) {
        char c = expressao[i];
        if (c == '(') {
            empilhar(&pilha, c);
        } else if (c == ')') {
            if (pilha_vazia(&pilha)) {
                printf("incorrect\n");
                limpar_pilha(&pilha);
                return;
            }
            desempilhar(&pilha);
        }
    }

    if (pilha_vazia(&pilha)) {
        printf("correct\n");
    } else {
        printf("incorrect\n");
    }

    limpar_pilha(&pilha);
}

void limpar_pilha(Pilha* p) {
    while (!pilha_vazia(p)) {
        desempilhar(p);
    }
}

int main() {
    char expressao[1001];
    while (fgets(expressao, sizeof(expressao), stdin) != NULL) {
        expressao[strcspn(expressao, "\n")] = '\0';

        if (strlen(expressao) == 0) {
            break;
        }
        verificar_expressao(expressao);
    }
}
