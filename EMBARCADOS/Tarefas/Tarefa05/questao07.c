#include <stdio.h> // Para a funcao printf()
#include <fcntl.h> // Para a funcao  open()
#include <unistd.h>// Para a funcao close()
#include <stdlib.h>// Para a função exit()
#include <string.h> // Para funções de string()
#include "bib_arqs.hpp"

int main(int argc, char *argv[]){

    char c, conteudo[500], palavra[20];
    int fp, i = 0, j = 0, k, l, ocorrencia = 0; // Definindo o ponteiro p/ ler o arquivo

    // Abre o arquivo de acordo com o 1º parâmetro que
    // foi passado, só como leitura.
    fp = open(argv[1], O_RDWR | O_CREAT, S_IRWXU);

    if(fp == -1){
        printf("Erro na abertura do arquivo.\n");
        exit(-1);
    }

    // Reposicionao ponteiro descrito do arquivo na posição 0
    lseek(fp, 0, SEEK_SET);

    while(read(fp, &c, 1) != 0){
		conteudo[i] = c;
		i++;
    }

    l = i;
    i = 0;

    printf("\nConteudo do arquivo: %s\n", conteudo);
    printf("Palavra procurada: %s\n", argv[2]);
    printf("Quantidade de caracteres do conteudo do arquivo: %d\n\n", l);
    
    while(i <= (l+20)){
    	if(conteudo[i] != ' ' && conteudo[i] != ',' && conteudo[i] != '.' && conteudo[i] != '!'){
    		palavra[j] = conteudo[i];
    		j++;
    	}else{

    		printf("Palavra: %s\n", palavra);
    		if(strcmp(palavra, argv[2]) == 0){
    			ocorrencia++;
    		}

    		// limpar a variável palavra
    		for(k = 0; k < j; k++)
    			palavra[k] = null;
    		j = 0;
    	}
    	i++;
    }

    printf("\n%s ocorreu %d vezes no arquivo %s\n\n", argv[2], ocorrencia, argv[1]);

    close(fp);

    return 0;
}