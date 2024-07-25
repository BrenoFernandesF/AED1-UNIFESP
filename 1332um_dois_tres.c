#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    
    char word[6]; // Tamanho máximo da palavra é 5 ("three") + 1 para o terminador nulo

    for (int i = 0; i < n; i++) {
        scanf("%s", word);

        if (strlen(word) == 3) {
            // Pode ser "one" ou "two"
            int countOne = 0, countTwo = 0;
            if (word[0] != 'o') countOne++;
            if (word[1] != 'n') countOne++;
            if (word[2] != 'e') countOne++;
            
            if (word[0] != 't') countTwo++;
            if (word[1] != 'w') countTwo++;
            if (word[2] != 'o') countTwo++;
            
            if (countOne <= 1) {
                printf("1\n");
            } else if (countTwo <= 1) {
                printf("2\n");
            }
        } else if (strlen(word) == 5) {
            // Pode ser "three"
            int countThree = 0;
            if (word[0] != 't') countThree++;
            if (word[1] != 'h') countThree++;
            if (word[2] != 'r') countThree++;
            if (word[3] != 'e') countThree++;
            if (word[4] != 'e') countThree++;
            
            if (countThree <= 1) {
                printf("3\n");
            }
        }
    }

    return 0;
}
