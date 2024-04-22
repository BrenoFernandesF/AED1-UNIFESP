#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
    char nome[21];
    int indice;
    struct celula* seg;
} celula;

// A função recebe uma string nome e uma celula cabeça lst e insere uma nova celula na lista encadeada entre lst e a seguinte. 
void insere (char nome[21], celula *p) {
    if (p == NULL) exit(1);
    celula *novo = (celula*)malloc(sizeof(celula));
    strcpy(novo->nome, nome);
    novo->seg = p->seg;
    p->seg = novo;
}

// A função recebe uma celula cabeça p e ordena a lista encadeada em ordem alfabética.
celula* ordena (celula *p) {
    if (p == NULL) return NULL;
    
    celula *atual = p->seg, *aux = NULL;
    char temp[21];
    
    while (atual != NULL) {
        aux = atual->seg;
        while (aux != NULL) {
            if (strcmp(atual->nome, aux->nome) > 0) {
                strcpy(temp, atual->nome);
                strcpy(atual->nome, aux->nome);
                strcpy(aux->nome, temp);
            }
            aux = aux->seg;
        }
        atual = atual->seg;
    }
    return p;
}

// A função recebe uma celula cabeça p e um indice inteiro k e imprime o nome do k-ésimo elemento da lista encadeada.
char* busca (celula *p, int k) {
    if (p == NULL) exit(1);
    int count = 1;
    celula *aux = p->seg;
    while (aux != NULL) {
        if (count == k) {
            printf("%s\n", aux->nome);
            return aux->nome;
        }
        count++;
        aux = aux->seg;
    }
    return NULL;
}

// A função recebe uma celula cabeça p e libera a memória alocada para a lista encadeada.
void libera (celula *p) {
    celula *aux = p->seg;
    while (aux != NULL) {
        p->seg = aux->seg;
        free(aux);
        aux = p->seg;
    }
    free(p);
}

int main () {
    celula *lst = (celula*)malloc(sizeof(celula));
    lst->seg = NULL;
    char nome[21];
    int N, k;
    scanf("%d %d", &N, &k);
    for (int i = 0; i < N; i++) {
        scanf("%s", nome);
        insere(nome, lst);
    }
    lst = ordena(lst);
    busca(lst, k);
    free (lst);
}