#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função de comparação para qsort
int comparar(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int N;
    char *codigos[1000];
    char buffer[5];
    while (scanf("%d", &N) != EOF) {
        for (int i = 0; i < N; i++) {
            codigos[i] = malloc(5 * sizeof(char));
            scanf("%s", codigos[i]);
        }
        qsort(codigos, N, sizeof(char *), comparar);
        for (int i = 0; i < N; i++) {
            printf("%s\n", codigos[i]);
            free(codigos[i]);
        }
    }
}
