/*A função main recebe um tempo em segundos e retorna o tempo em horas, minutos e segundos*/
#include <stdio.h>

int main () {
    int tempo_segundos, horas, minutos, segundos;
    scanf("%d", &tempo_segundos);
    horas = tempo_segundos / 3600;
    minutos = (tempo_segundos % 3600) / 60;
    segundos = (tempo_segundos % 3600) % 60;
    printf("%d:%d:%d\n", horas, minutos, segundos);
}