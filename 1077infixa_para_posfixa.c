#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    char dado;
    struct celula *seg;
} celula;

/* A função recebe um dado y do tipo char e uma pilha p do tipo celula e empilha um novo elemento no topo da pilha */
void push(char y, celula *p) {
    celula *nova;
    nova = malloc(sizeof(celula));
    nova->dado = y;
    nova->seg = p->seg;
    p->seg = nova;
}

/* A função recebe uma pilha p do tipo celula, desempilha o elemento do topo da pilha e retorne o valor do antigo topo*/
char pop(celula *p) {
    celula *lixo;
    char x;
    lixo = p->seg;
    x = lixo->dado;
    p->seg = lixo->seg;
    free(lixo);
    return x;
}

/* A função recebe um operador do tipo char e retorna a prioridade do operador */
int prioridade(char operador) {
    if (operador == '(') return 0;
    if (operador == '+' || operador == '-') return 1;
    if (operador == '*' || operador == '/') return 2;
    if (operador == '^') return 3;
    return -1;
}

/* A função recebe uma expressão na forma infixa do tipo char e imprime a expressão na forma posfixa */
void infixa_para_posfixa(char *expressao) {
    celula cabeca;
    celula *p;
    p = &cabeca;
    p->seg = NULL;

    for (int i = 0; expressao[i] != '\0'; i++) {
        char c = expressao[i];
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
            printf("%c", c); 
        } else if (c == '(') {
            push(c, p);
        } else if (c == ')') {
            while (p->seg != NULL && p->seg->dado != '(') {
                printf("%c", pop(p));
            }
            pop(p); 
        } else {
            while (p->seg != NULL && prioridade(c) <= prioridade(p->seg->dado)) {
                printf("%c", pop(p));
            }
            push(c, p);
        }
    }
    while (p->seg != NULL) {
        printf("%c", pop(p));
    }
    printf("\n");
}

int main() {
    int N;
    scanf("%d", &N);
    if (N < 0 || N > 1000) {
        return 1;
    }
    for (int i = 0; i < N; i++) {
        char expressao[301];
        scanf("%s", expressao);
        infixa_para_posfixa(expressao);
    }
    return 0;
}
