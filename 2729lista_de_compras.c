#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
    char item[21];
    struct celula* prox;
} celula;

void insere(celula** inicio, char* item) {
    celula* novo = (celula*)malloc(sizeof(celula));
    strcpy(novo->item, item);
    novo->prox = *inicio;
    *inicio = novo;
}

int esta_na_lista(celula* inicio, char* dado) {
    celula* atual = inicio;
    while (atual != NULL) {
        if (strcmp(atual->item, dado) == 0) {
            return 1;
        }
        atual = atual->prox;
    }
    return 0;
}

void ordenar_lista(celula** inicio) {
    celula *atual = *inicio, *indice = NULL;
    char temp[21];
    if (*inicio == NULL) {
        return;
    }
    while (atual != NULL) {
        indice = atual->prox;

        while (indice != NULL) {
            if (strcmp(atual->item, indice->item) > 0) {
                strcpy(temp, atual->item);
                strcpy(atual->item, indice->item);
                strcpy(indice->item, temp);
            }
            indice = indice->prox;
        }
        atual = atual->prox;
    }
}

void imprimir_lista(celula* inicio) {
    while (inicio != NULL) {
        printf("%s", inicio->item);
        if (inicio->prox != NULL) {
            printf(" ");
        }
        inicio = inicio->prox;
    }
    printf("\n");
}

int main() {
    int N, i;
    scanf("%d", &N);
    getchar(); 
    for (i = 0; i < N; i++) {
        celula* lista = NULL;
        char entrada[21000];
        fgets(entrada, 21000, stdin); 
        entrada[strcspn(entrada, "\n")] = '\0'; 
        char* token = strtok(entrada, " ");
        while (token != NULL) {
            if (!esta_na_lista(lista, token)) {
                insere(&lista, token);
            }
            token = strtok(NULL, " ");
        }
        ordenar_lista(&lista);
        imprimir_lista(lista);
        celula* atual = lista;
        while (atual != NULL) {
            celula* temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }
    
    return 0;
}
