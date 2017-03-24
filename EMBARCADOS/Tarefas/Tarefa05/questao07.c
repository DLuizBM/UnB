#include <stdio.h> // Para a funcao printf()
#include <fcntl.h> // Para a funcao  open()
#include <unistd.h>// Para a funcao close()
#include <stdlib.h>// Para a função exit()
#include <string.h> // Para funções de string()
#include "bib_arqs.hpp"

int main(int argc, char *argv[]){

    char c, conteudo[100];
    int fp, i = 0, j = 0; // Definindo o ponteiro p/ ler o arquivo

    // Abre o arquivo de acordo com o 1º parâmetro que
    // foi passado, só como leitura.
    fp = open(argv[1], O_RDWR | O_CREAT, S_IRWXU);

    if(fp == -1){
        printf("Erro na abertura do arquivo.\n");
        exit(-1);
    }

    // Reposicionao ponteiro descrito do arquivo na posição 0
    lseek(fp, 0, SEEK_SET);
    
    while(i <= tam_arq_texto(argv[1])){
    	fscanf(&fp, "%s", conteudo);
    	if(strcmp(conteudo, argv[2]) == 0)
    		j++;
    	i++;
    }

    printf("\n%s ocorreu %d vezes no arquivo %s", argv[2], j, argv[1]);

    close(fp);

    return 0;
}