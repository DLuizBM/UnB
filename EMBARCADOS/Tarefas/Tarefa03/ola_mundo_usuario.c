#include <stdio.h>
#include <stdlib.h>
int main(int argc, const char *argv[])
{
    char nome[20];

    printf("Digite seu nome: ");
    scanf("%s", nome);

    printf("Ola %s\n\n", nome);
    return 0;
}
