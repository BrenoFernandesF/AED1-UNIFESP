#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minLetrasParaPalindromo(char *sequencia) {
    int contagem[26] = {0};
    int i;
    for (i = 0; sequencia[i] != '\0'; i++) {
        contagem[sequencia[i] - 'a']++;
    }
    int impares = 0;
    for (i = 0; i < 26; i++) {
        if (contagem[i] % 2 != 0) {
            impares++;
        }
    }
    if (impares > 1) {
        return impares - 1;
    } else {
        return 0;
    }
}

int main() {
    char sequencia[1001];
    scanf("%s", sequencia);
    printf("%d\n", minLetrasParaPalindromo(sequencia));
    return 0;
}