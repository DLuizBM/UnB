#include <stdio.h> // Para a funcao printf()
#include <fcntl.h> // Para a funcao  open()
#include <unistd.h>// Para a funcao close()
#include <stdlib.h>// Para a função exit()
#include <string.h> // Para funções de string()
#include "bib_arqs.hpp"

int main(int argc, char *argv[])
{
    // Código do arquivo que será o cat_falsificado

    char c, conteudo[100];
    int fp; // Definindo o ponteiro p/ ler o arquivo

    // Abre o arquivo de acordo com o 1º parâmetro que
    // foi passado, só como leitura.
    fp = open(argv[1], O_RDWR | O_CREAT, S_IRWXU);

    if(fp == -1){
        printf("Erro na abertura do arquivo.\n");
        exit(-1);
    }

    le_arq_texto(argv[1], conteudo);
    printf("O arquivo tem o seguinte tamanho: %d BYTES\n", tam_arq_texto(argv[1]));

    close(fp);

    return 0;
}
