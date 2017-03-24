#include <stdio.h> // Para a funcao printf()
#include <fcntl.h> // Para a funcao  open()
#include <unistd.h>// Para a funcao close()
#include <stdlib.h>// Para a função exit()
#include <string.h> // Para funções de string()

int main(int argc, const char *argv[]){

    int fp;
    char ola[20] = {"Ola mundo!"};

    // O_RDWR - Dada a permissao para ler e escrever
    // O_CREAT - Se nao houver cria o arquivo
    fp = open("ola_mundo.txt", O_RDWR | O_CREAT, S_IRWXU);

    if(fp == -1){
        printf("Erro na abertura do arquivo.\n");
        exit(-1);
    }

    write(fp, ola, strlen(ola) * sizeof(char));

    close(fp);

    return 0;
}
