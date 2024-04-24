#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

typedef struct celula {
    char valor;
    struct celula *seg;
} celula;

void push(celula **p, char valor) {
    celula *nova = (celula *)malloc(sizeof(celula));
    nova->valor = valor;
    nova->seg = *p;
    *p = nova;
}

void pop(celula **p) {
    if (*p != NULL) {
        celula *velhoTopo = *p;
        *p = (*p)->seg;
        free(velhoTopo);
    }
}

int precedencia(char operador) {
    switch (operador) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    }
}

char* infixa_para_posfixa(char *infixa) {
    int tam = strlen(infixa);
    char *posfixa = (char *)malloc(tam + 1);
    celula *p = NULL;
    int j = 0;

    for (int i = 0; i < tam; ++i) {
        if (isalpha(infixa[i]) || isdigit(infixa[i])) {
            posfixa[j++] = infixa[i];
        }
        else if (infixa[i] == '(' || infixa[i] == '^') {
            push(&p, infixa[i]);
        }
        else if (infixa[i] == ')') {
            while (p != NULL && p->valor != '(') {
                posfixa[j++] = p->valor;
                pop(&p);
            }

            if (p != NULL) pop(&p);
        }
        else {
            while (p != NULL && p->valor != '(' && precedencia(infixa[i]) <= precedencia(p->valor)) {
                posfixa[j++] = p->valor;
                pop(&p);
            }
            push(&p, infixa[i]);
        }
    }

    while (p != NULL) {
        posfixa[j++] = p->valor;
        pop(&p);
    }
    posfixa[j] = '\0';

    return posfixa;
}

int main() {
    int N, tam;
    struct celula *p = NULL;
    char expressao[301];

    scanf("%d\n", &N);

    for (int i = 0; i < N; i++) {
        fgets(expressao, 301, stdin);
        tam = strlen(expressao);
        expressao[tam - 1] = '\0';

        char *posfixa = infixa_para_posfixa(expressao);
        printf("%s\n", posfixa);
        free(posfixa);
    }
    return 0;
}
