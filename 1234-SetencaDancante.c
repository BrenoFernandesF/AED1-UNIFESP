#include <stdio.h>
#include <ctype.h>

// A função transforma a sentença em uma sentença que alterna entre maiúsculas e minúsculas
void transformar_sentenca(char* str) {
    int i = 0;
    int alterar = 1;
    while (str[i] != '\0') {
        if (isalpha(str[i])) {
            if (alterar) {
                str[i] = toupper(str[i]);
            } else {
                str[i] = tolower(str[i]);
            }
            alterar = !alterar;
        }
        i++;
    }
}

int main() {
    char linha[51];
    while (fgets(linha, sizeof(linha), stdin)) {
        int len = strlen(linha);
        if (len > 0 && linha[len - 1] == '\n') {
            linha[len - 1] = '\0';
        }
        transformar_sentenca(linha);
        printf("%s\n", linha);
    }
}
