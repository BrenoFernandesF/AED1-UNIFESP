#include <stdio.h>

int main() {
    char s[100001];
    fgets(s, sizeof(s), stdin);
    int assuntos = 0;
    for (int i = 0; s[i] != '\0' && s[i] != '\n'; i++) {
        if (s[i] == '(') {
            assuntos++;
        } else if (s[i] == ')') {
            if (assuntos > 0) {
                assuntos--;
            }
        }
    }
    if (assuntos == 0) {
        printf("Partiu RU!\n");
    } else {
        printf("Ainda temos %d assunto(s) pendente(s)!\n", assuntos);
    }
}
