#include <stdio.h>
#include <ctype.h>
#include <string.h>

// A função recebe um sobrenome e retorna se ele é fácil ou não
int ehFacil(const char *sobrenome) {
    const char consoantes[] = "bcdfghjklmnpqrstvwxyz";
    int consoantesConsecutivas = 0;
    int maxConsoantesConsecutivas = 0;
    for (int i = 0; sobrenome[i] != '\0'; i++) {
        char c = tolower(sobrenome[i]);
        if (strchr(consoantes, c)) {
            consoantesConsecutivas++;
            if (consoantesConsecutivas > maxConsoantesConsecutivas) {
                maxConsoantesConsecutivas = consoantesConsecutivas;
            }
        } else {
            consoantesConsecutivas = 0;
        }
    }
    return maxConsoantesConsecutivas >= 3;
}

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        char sobrenome[43]; 
        scanf("%s", sobrenome); 
        if (ehFacil(sobrenome)) {
            printf("%s nao eh facil\n", sobrenome);
        } else {
            printf("%s eh facil\n", sobrenome);
        }
    }
}
