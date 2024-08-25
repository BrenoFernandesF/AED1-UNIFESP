#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct celula {
    char nome[21];
    struct celula* seg;
} celula;

void insere(celula **L, char *nome) {
    celula *novo = (celula*)malloc(sizeof(celula));
    strcpy(novo->nome, nome);
    novo->seg = NULL;

    if (*L == NULL) {
        *L = novo;
        return;
    }

    celula* atual = *L;
    while (atual->seg != NULL) {
        atual = atual->seg;
    }
    atual->seg = novo;
}
// A função recebe um ponteiro para o início de uma lista encadeada, uma string com uma nova lista de amigos e uma string com o nome de um amigo indicado.
void insere_nova_lista(celula **L, char *nova_lista, char *amigo_indicado) {
    if (strcmp(amigo_indicado, "nao") == 0) {
        char* token = strtok(nova_lista, " ");
        while (token != NULL) {
            insere(L, token);
            token = strtok(NULL, " ");
        }
    } else {
        celula* novo_inicio = NULL;
        char* token = strtok(nova_lista, " ");
        while (token != NULL) {
            insere(&novo_inicio, token);
            token = strtok(NULL, " ");
        }

        celula* anterior = NULL;
        celula* atual = *L;
        while (atual != NULL && strcmp(atual->nome, amigo_indicado) != 0) {
            anterior = atual;
            atual = atual->seg;
        }

        if (anterior == NULL) {
            *L = novo_inicio;
        } else {
            anterior->seg = novo_inicio;
        }

        while (novo_inicio->seg != NULL) {
            novo_inicio = novo_inicio->seg;
        }
        novo_inicio->seg = atual;
    }
}

void imprime(celula *L) {
    celula *p = L;
    while (p != NULL) {
        printf("%s ", p->nome);
        p = p->seg;
    }
    printf("\n");
}

void libera_memoria(celula *L) {
    celula *atual = L;
    while (atual != NULL) {
        celula *temp = atual;
        atual = atual->seg;
        free(temp);
    }
}

int main() {
    celula *L = NULL;
    char entrada[21000], nova_lista[21000], amigo_indicado[21];

    fgets(entrada, 21000, stdin);
    entrada[strcspn(entrada, "\n")] = '\0';
    char* token = strtok(entrada, " ");
    while (token != NULL) {
        insere(&L, token);
        token = strtok(NULL, " ");
    }

    fgets(nova_lista, 21000, stdin);
    nova_lista[strcspn(nova_lista, "\n")] = '\0';

    fgets(amigo_indicado, 21, stdin);
    amigo_indicado[strcspn(amigo_indicado, "\n")] = '\0';

    insere_nova_lista(&L, nova_lista, amigo_indicado);

    imprime(L);

    libera_memoria(L);

    return 0;
}
 
