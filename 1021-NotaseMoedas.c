#include <stdio.h>

int main() {
    double valor;
    scanf("%lf", &valor);
    valor *= 100;  
    
    int notas[] = {10000, 5000, 2000, 1000, 500, 200};
    int moedas[] = {100, 50, 25, 10, 5, 1};

    printf("NOTAS:\n");
    for (int i = 0; i < 6; i++) {
        printf("%d nota(s) de R$ %.2f\n", (int)valor/notas[i], (float)notas[i]/100);
        valor = (int)valor % notas[i];
    }

    printf("MOEDAS:\n");
    for (int i = 0; i < 6; i++) {
        printf("%d moeda(s) de R$ %.2f\n", (int)valor/moedas[i], (float)moedas[i]/100);
        valor = (int)valor % moedas[i];
    }

    return 0;
}