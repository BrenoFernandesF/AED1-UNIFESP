/*A função main recebe a quantidade de números a serem lidos e retorna a quantidade de leds necessários para escrever o número*/

#include <stdio.h>
#include <string.h>

int main() {
    int N, i, j;
    int leds;
    char V[103];
    int num_leds[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    
    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        scanf("%s", V);
        int tamanho = strlen(V);
        leds = 0;

        for(j = 0; j < tamanho; j++) {
            leds += num_leds[V[j] - '0'];
        }
        printf("%d leds\n", leds);
    }

    return 0;
}