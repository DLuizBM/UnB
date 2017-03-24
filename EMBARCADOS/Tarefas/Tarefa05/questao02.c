#include <stdio.h> // Para a funcao printf()
#include <fcntl.h> // Para a funcao  open()
#include <unistd.h>// Para a funcao close()
#include <stdlib.h>// Para a função exit()
#include <string.h> // Para funções de string()

int main(int argc, const char *argv[]){

    char nome[50], idade[5], nome_arq[50];

    printf("\nDigite seu nome: ");
    scanf("%s", nome);
    printf("Digite sua idade: ");
    scanf("%s", idade);

    int fp;

    // Copia a string nome com cancatenação em nome_arq
    sprintf(nome_arq, "%s.txt", nome);

    fp = open(nome_arq, O_RDWR | O_CREAT, S_IRWXU);

    if(fp == -1){
        printf("Erro na abertura do arquivo.\n");
        exit(-1);
    }

    // Escrever no arquivo: write (fp, string, nº de bytes que ocupam)
    write(fp, "Nome: ", 6);
    write(fp, nome, strlen(nome) * sizeof(char));
    write(fp, "\n", 1);
    write(fp, "Idade: ", 7);
    write(fp, idade, strlen(idade) * sizeof(char));
    write(fp, "\n", 1);

    close(fp);

    return 0;
}
