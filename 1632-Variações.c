#include <stdio.h>
#include <string.h>
#include <ctype.h>

// A função recebe um número T e T palavras S e retorna o número de variações possíveis dessas palavras
int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        char S[17];
        scanf("%s", S);
        int tamanho = strlen(S);
        int variacoes = 1;
        for (int j = 0; j < tamanho; j++) {
            char letra = tolower(S[j]);
            if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 's') {
                variacoes *= 3; 
            } else if (isalpha(S[j])) {
                variacoes *= 2; 
            }
        }
        printf("%d\n", variacoes);
    }   
}