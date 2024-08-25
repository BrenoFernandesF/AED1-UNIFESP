#include <stdio.h>
#include <string.h>

/* A função recebe um número N e N frases e retorna o idioma inglês se houver mais de um idioma ou o idioma falado por todos*/
int main() {
    int N, i;
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        int K;
        scanf("%d", &K);
        char idioma[K][21]; 
        int count[100] = {0};
        int max_count = 0;
        char max_idioma[21]; 
        int j;
        for (j = 0; i < K; j++) {
            scanf("%s", idioma[i]);
            count[i]++;
            if (count[i] > max_count) {
                max_count = count[i];
                strcpy(max_idioma, idioma[j]);
            }
        }
        int diferentes = 0;
        for (i = 0; i < K; i++) {
            if (strcmp(idioma[i], max_idioma) != 0 && count[i] == max_count) {
                diferentes = 1;
                break;
            }
        }
        if (diferentes || max_count != K) {
            printf("ingles\n");
        } else {
            printf("%s\n", max_idioma);
        }
    }
    return 0;
}
