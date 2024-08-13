#include <stdio.h>
#include <string.h>

#define MAX_TESTES 100
#define MAX_NOME 31

typedef struct {
    char ant[MAX_NOME];
    char para[MAX_NOME];
} Conexao;

//A função funcao recebe o número de conexões e um vetor de conexões e verifica se as conexões formam uma função.

int funcao(int n, Conexao conexoes[]) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(conexoes[i].ant, conexoes[j].ant) == 0 &&
                strcmp(conexoes[i].para, conexoes[j].para) != 0) {
                return 0;
            }
        }
    }
    return 1;
}

// A função invertivel recebe o número de conexões e um vetor de conexões e verifica se a função é invertível.
int invertivel(int n, Conexao conexoes[]) {
    char lista_para[MAX_TESTES][MAX_NOME];
    int contagem_para[MAX_TESTES] = {0};
    int tamanho_para = 0;
    for (int i = 0; i < n; i++) {
        int encontrado = 0;
        for (int j = 0; j < tamanho_para; j++) {
            if (strcmp(conexoes[i].para, lista_para[j]) == 0) {
                contagem_para[j]++;
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            strcpy(lista_para[tamanho_para], conexoes[i].para);
            contagem_para[tamanho_para++] = 1;
        }
    }
    for (int i = 0; i < tamanho_para; i++) {
        if (contagem_para[i] > 1) {
            return 0;
        }
    }
    return 1;
}

//A função main lê o número de testes, lê as conexões e chama as funções eh_funcao e eh_invertivel para verificar se as conexões formam uma função e se ela é invertível.
int main() {
    int t;
    while (scanf("%d", &t) && t > 0) {
        Conexao conexoes[MAX_TESTES];
        for (int i = 0; i < t; i++) {
            scanf("%s -> %s", conexoes[i].ant, conexoes[i].para);
        }
        if (!funcao(t, conexoes)) {
            printf("Not a function.\n");
        } else if (invertivel(t, conexoes)) {
            printf("Invertible.\n");
        } else {
            printf("Not invertible.\n");
        }
    }
}
