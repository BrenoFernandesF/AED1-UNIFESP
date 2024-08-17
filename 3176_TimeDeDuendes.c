#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[21];
    int idade;
} Duende;


int comparar(const void *a, const void *b) {
    Duende *d1 = (Duende *)a;
    Duende *d2 = (Duende *)b;
    if (d1->idade != d2->idade)
        return d2->idade - d1->idade;
    return strcmp(d1->nome, d2->nome);
}

int main() {
    int N;
    scanf("%d", &N);
    Duende duendes[N];
    for (int i = 0; i < N; i++) {
        scanf("%s %d", duendes[i].nome, &duendes[i].idade);
    }
    qsort(duendes, N, sizeof(Duende), comparar);
    int num_times = N / 3;
    for (int t = 0; t < num_times; t++) {
        printf("Time %d\n", t + 1);
        printf("%s %d\n", duendes[t].nome, duendes[t].idade);
        printf("%s %d\n", duendes[num_times + t].nome, duendes[num_times + t].idade);
        printf("%s %d\n", duendes[2 * num_times + t].nome, duendes[2 * num_times + t].idade);
        printf("\n");
    }
}
