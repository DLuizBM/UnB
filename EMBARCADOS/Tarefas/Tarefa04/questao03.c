#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    char nome[50], nome_arq[50];
    int idade;
    FILE *fp;

    printf("Digite seu nome:");
    scanf("%s", &nome);
    printf("\n\n Digite sua idade:");
    scanf("%d", &idade);

    // Função que escreve uma string na outra!
    sprintf(nome_arq, "%s.txt", nome);

    fp = fopen(nome_arq,"w");
    if(fp == null){
        prinf("Nao foi possivel abrir o arquivo!");
        exit(0);
    }

    fprintf(fp, "Nome: %s\n", nome);
    fprintf(fp, "Idade: %d anos\n", idade);

    fclose(fp);

    return 0;
}
