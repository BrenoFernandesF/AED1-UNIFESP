#include <stdio.h>
#include <string.h>

/* A função recebe um número N e N frases e retorna o idioma inglês se houver mais de um idioma ou o idioma falado por todos*/
#include <stdio.h>
#include <string.h>

int main() {
    int N, i;
    scanf("%d", &N);

    char idioma[101][21];
    for (i = 0; i < N; i++) {
        int K, diferentes = 0;
        scanf("%d", &K);
        scanf("%s", idioma[0]);
        for (int j = 1; j < K; j++) {
            scanf("%s", idioma[j]);
            if (strcmp(idioma[j], idioma[0]) != 0) {
                diferentes = 1;
            }
        }
        if (diferentes) {
            printf("ingles\n");
        } else {
            printf("%s\n", idioma[0]);
        }
    }
}

