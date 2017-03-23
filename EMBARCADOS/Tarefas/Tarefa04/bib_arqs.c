#include <stdio.h>
#include <stdlib.h>
#include "bib_arqs.hpp"

int tam_arq_texto(char *nome_arquivo){
    
    FILE *fp;
    char c;
    int i = 0;

    fp = fopen(nome_arquivo, "r");

    while( (c = getc(fp)) != EOF )
        i++;

    return i;
}

void le_arq_texto(char *nome_arquivo, char *conteudo){

    FILE *fp;
    char c;
    int i = 0;

    fp = fopen(nome_arquivo, "r");

    while( (c = getc(fp)) != EOF ){
        conteudo[i] = c;
        i++;
    } 
    printf("Esta escrito no arquivo:\n %s", conteudo);

}
