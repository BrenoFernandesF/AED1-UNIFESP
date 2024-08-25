#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função recebe um número real e um valor de corte e retorna o número arredondado
int arredondar_por_corte(double num, double cutoff) {
    double parte_fracionaria = num - (int)num;
    if (parte_fracionaria > cutoff) {
        return (int)num + 1;
    } else {
        return (int)num;
    }
}

int main() {
    char num_str[11]; 
    char cutoff_str[11]; 
    while (scanf("%s", num_str) != EOF) {
        scanf("%s", cutoff_str);
        double num = atof(num_str);
        double cutoff = atof(cutoff_str);
        int resultado = arredondar_por_corte(num, cutoff);
        printf("%d\n", resultado);
    }
    return 0;
}
