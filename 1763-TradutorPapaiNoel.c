#include <stdio.h>
#include <string.h>


// A função recebe o nome de um país e retorna a saudação de Natal correspondente
int main() {
    char country[30];

    while (scanf("%s", country) != EOF) {
        if (strcmp(country, "brasil") == 0) {
            printf("Feliz Natal!\n");
        } else if (strcmp(country, "alemanha") == 0) {
            printf("Frohliche Weihnachten!\n");
        } else if (strcmp(country, "austria") == 0) {
            printf("Frohe Weihnacht!\n");
        } else if (strcmp(country, "coreia") == 0) {
            printf("Chuk Sung Tan!\n");
        } else if (strcmp(country, "espanha") == 0) {
            printf("Feliz Navidad!\n");
        } else if (strcmp(country, "grecia") == 0) {
            printf("Kala Christougena!\n");
        } else if (strcmp(country, "estados-unidos") == 0) {
            printf("Merry Christmas!\n");
        } else if (strcmp(country, "inglaterra") == 0) {
            printf("Merry Christmas!\n");
        } else if (strcmp(country, "australia") == 0) {
            printf("Merry Christmas!\n");
        } else if (strcmp(country, "portugal") == 0) {
            printf("Feliz Natal!\n");
        } else if (strcmp(country, "suecia") == 0) {
            printf("God Jul!\n");
        } else if (strcmp(country, "turquia") == 0) {
            printf("Mutlu Noeller\n");
        } else if (strcmp(country, "argentina") == 0) {
            printf("Feliz Navidad!\n");
        } else if (strcmp(country, "chile") == 0) {
            printf("Feliz Navidad!\n");
        } else if (strcmp(country, "mexico") == 0) {
            printf("Feliz Navidad!\n");
        } else if (strcmp(country, "antardida") == 0) {
            printf("Merry Christmas!\n");
        } else if (strcmp(country, "canada") == 0) {
            printf("Merry Christmas!\n");
        } else if (strcmp(country, "irlanda") == 0) {
            printf("Nollaig Shona Dhuit!\n");
        } else if (strcmp(country, "belgica") == 0) {
            printf("Zalig Kerstfeest!\n");
        } else if (strcmp(country, "italia") == 0) {
            printf("Buon Natale!\n");
        } else if (strcmp(country, "libia") == 0) {
            printf("Buon Natale!\n");
        } else if (strcmp(country, "siria") == 0) {
            printf("Milad Mubarak!\n");
        } else if (strcmp(country, "marrocos") == 0) {
            printf("Milad Mubarak!\n");
        } else if (strcmp(country, "japao") == 0) {
            printf("Merii Kurisumasu!\n");
        } else {
            printf("--- NOT FOUND ---\n");
        }
    }
    return 0;
}
