#include <stdio>.h
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Código do arquivo que será o cat_falsificado

    char c;
    FILE *fp; // Definindo o ponteiro p/ ler o arquivo

    // Abre o arquivo de acordo com o 1º parâmetro que
    // foi passado, só como leitura.
    fp = fopen(argv[1], "r");

    if(fp == null){
        printf("Nao foi possivel abrir o arquivo");
        exit(0);
    }

    // Enqaunto não chegar ao fim do arquivo, imprime o
    // caracter lido
    while((c = getc(fp)) != E0F)
        printf("%c", c);

    fclose(fp);

    return 0;
}
