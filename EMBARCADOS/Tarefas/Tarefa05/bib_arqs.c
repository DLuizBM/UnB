#include <stdio.h> // Para a funcao printf()
#include <fcntl.h> // Para a funcao  open()
#include <unistd.h>// Para a funcao close()
#include <stdlib.h>// Para a função exit()
#include <string.h> // Para funções de string()
#include "bib_arqs.hpp"

int tam_arq_texto(char *nome_arquivo){
    
    int fp;
    char c;
    int i = 0;

    fp = open(nome_arquivo, O_RDWR | O_CREAT, S_IRWXU);

    while(read(fp, &c, 1) != 0)
        i++;

    return i;
}

void le_arq_texto(char *nome_arquivo, char *conteudo){

    int fp;
    char c;
    int i = 0;

    fp = open(nome_arquivo, O_RDWR | O_CREAT, S_IRWXU);

    while(read(fp, &c, 1) != 0){
        conteudo[i] = c;
        i++;
    }

    printf("Esta escrito no arquivo: %s\n", conteudo);
}
