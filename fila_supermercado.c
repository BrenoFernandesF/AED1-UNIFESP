#include <stdio.h>
#include <stdlib.h>

typedef struct Cliente {
    int id;
    int itens;
    struct Cliente* prox;
} Cliente;

typedef struct {
    Cliente* inicio;
    Cliente* fim;
} FilaClientes;

typedef struct {
    int id;
    int tempo_livre;
} Funcionario;

void inicializarFila(FilaClientes* fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

void enfileirar(FilaClientes* fila, int id, int itens) {
    Cliente* novoCliente = (Cliente*)malloc(sizeof(Cliente));
    novoCliente->id = id;
    novoCliente->itens = itens;
    novoCliente->prox = NULL;
    
    if (fila->fim != NULL) {
        fila->fim->prox = novoCliente;
    }
    fila->fim = novoCliente;
    
    if (fila->inicio == NULL) {
        fila->inicio = novoCliente;
    }
}

void desenfileirar(FilaClientes* fila) {
    if (fila->inicio == NULL) {
        return;
    }
    
    Cliente* clienteRemovido = fila->inicio;
    fila->inicio = fila->inicio->prox;
    free(clienteRemovido);
    
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int* tempos_funcionarios = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &tempos_funcionarios[i]);
    }

    FilaClientes fila;
    inicializarFila(&fila);

    for (int i = 0; i < M; i++) {
        int itens;
        scanf("%d", &itens);
        enfileirar(&fila, i + 1, itens);
    }

    Funcionario* funcionarios = (Funcionario*)malloc(N * sizeof(Funcionario));
    for (int i = 0; i < N; i++) {
        funcionarios[i].id = i + 1;
        funcionarios[i].tempo_livre = 0;
    }

    int tempo_total = 0;
    while (fila.inicio != NULL) {
        Cliente* cliente = fila.inicio;
        int cliente_id = cliente->id;
        int cliente_itens = cliente->itens;
        desenfileirar(&fila);

        int min_id = 0;
        for (int i = 1; i < N; i++) {
            if (funcionarios[i].tempo_livre < funcionarios[min_id].tempo_livre) {
                min_id = i;
            }
        }
        tempo_total = funcionarios[min_id].tempo_livre > tempo_total ? funcionarios[min_id].tempo_livre : tempo_total;
        funcionarios[min_id].tempo_livre += cliente_itens * tempos_funcionarios[min_id];
    }

    printf("%d\n", tempo_total);

    free(tempos_funcionarios);
    free(funcionarios);

    return 0;
}
