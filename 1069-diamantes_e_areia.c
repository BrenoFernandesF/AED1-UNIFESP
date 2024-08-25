#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    char c;
    struct celula* seg;
} celula;

// A função insere um caractere c em uma lista encadeada entre a celula p e p->seg 
void insere (char c, celula *p) {
    celula *nova = (celula*)malloc(sizeof(celula));
    nova->c = c;
    nova->seg = p->seg;
    p->seg = nova;
}
// A função remover remove a celula seguinte a p e retorna o caractere contido nela
char remover (celula *p) {
    char x; 
    celula *lixo;
    lixo = p->seg;
    x = lixo->c;
    p->seg = lixo->seg;
    free(lixo);
    return x;
}
// A função main lê um inteiro N e para cada N, lê uma string entrada e conta quantos diamantes foram formados
int main() {
    int N;
    scanf("%d", &N);
    getchar();
    for (int i = 0; i < N; i++) {
        char entrada[1001];
        fgets(entrada, 1001, stdin);
        celula *p = (celula*)malloc(sizeof(celula));
        p->seg = NULL;
        int count = 0;
        for (int j = 0; entrada[j] != '\0'; j++) {
            if (entrada[j] == '<') {
                insere(entrada[j], p);
            } 
            else if (entrada[j] == '>') {
                if (p->seg != NULL) {
                    remover(p);
                    count++;
                }
            }
        }
        free(p);
        printf("%d\n", count);
    }
    
    return 0;
}