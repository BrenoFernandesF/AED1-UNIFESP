#include <stdio.h>
#include <string.h>

#define MAX_LEN 26

// A função recebe uma sequência de caracteres e seu tamanho e verifica se é possível corrigir a sequência com uma única troca.
int verificar_troca_necessaria(char* s, int len) {
    char ordenado[MAX_LEN + 1];
    strcpy(ordenado, s);
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (ordenado[i] > ordenado[j]) {
                char temp = ordenado[i];
                ordenado[i] = ordenado[j];
                ordenado[j] = temp;
            }
        }
    }
    int indices[2];
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] != ordenado[i]) {
            if (count < 2) {
                indices[count++] = i;
            } else {
                return 0;
            }
        }
    }
    if (count == 2) {
        char temp = s[indices[0]];
        s[indices[0]] = s[indices[1]];
        s[indices[1]] = temp;
        for (int i = 0; i < len - 1; i++) {
            if (s[i] > s[i + 1]) {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

//A funlção main lê o número de casos de teste, a quantidade de caracteres e a sequência de caracteres, e imprime se é possível corrigir a sequência com uma única troca.
int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        int M;
        char sequencia[MAX_LEN + 1];
        scanf("%d", &M);
        scanf("%s", sequencia);
        
        if (verificar_troca_necessaria(sequencia, M)) {
            printf("There are the chance.\n");
        } else {
            printf("There aren't the chance.\n");
        }
    }
}
