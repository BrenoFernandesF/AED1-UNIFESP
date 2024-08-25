/*A função main recebe um valor em Real e retorna a quantidade de notas de 50, 20, 10, 5, 2 e 1 necessárias para compor o valor*/
#include <stdio.h>

int main() {
    int valor, notas100, notas50, notas20, notas10, notas5, notas2, notas1;
    do {
        scanf("%d", &valor);
    } while (valor < 0 || valor > 1000000);
    notas100 = valor/100;
	notas50 = (valor-(notas100*100))/50;
	notas20 = (valor-(notas100*100)-(notas50*50))/20;
	notas10 =  (valor-(notas100*100)-(notas50*50)-(notas20*20))/10;
	notas5 = (valor-(notas100*100)-(notas50*50)-(notas20*20)-(notas10*10))/5;
	notas2 = (valor-(notas100*100)-(notas50*50)-(notas20*20)-(notas10*10)-(notas5*5))/2;
	notas1 = (valor-(notas100*100)-(notas50*50)-(notas20*20)-(notas10*10)-(notas5*5)-(notas2*2))/1;
    printf("%d\n", valor);
    printf("%d nota(s) de R$ 100,00\n", notas100);
    printf("%d nota(s) de R$ 50,00\n", notas50);
    printf("%d nota(s) de R$ 20,00\n", notas20);
    printf("%d nota(s) de R$ 10,00\n", notas10);
    printf("%d nota(s) de R$ 5,00\n", notas5);
    printf("%d nota(s) de R$ 2,00\n", notas2);
    printf("%d nota(s) de R$ 1,00\n", notas1);
    return 0;
}