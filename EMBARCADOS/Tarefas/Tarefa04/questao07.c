#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    // Código do arquivo que será o cat_falsificado

    int contador = 0, i = 0, j = 0, k = 0, ocorrencia = 0;
    char conteudo[100], c;
    FILE *fp; // Definindo o ponteiro p/ ler o arquivo

    // Abre o arquivo de acordo com o 1º parâmetro que
    // foi passado, só como leitura.
    fp = fopen(argv[2], "r");

    if(!fp){
        printf("Nao foi possivel abrir o arquivo");
        exit(0);
    }

    // Enquanto não chegar ao fim do arquivo, não para de imprimir
    while( (c = getc(fp)) != EOF){
        conteudo[contador] = c;
        contador++;
    }

    if(strstr(conteudo, argv[1]) != 0)
        ocorrencia++;

    printf("\nConteudo: %s",conteudo);
    printf("\nPalavra: %s", argv[1]);
    printf("\nNumero de ocorrencias: %d\n\n", ocorrencia);

    fclose(fp);
    return 0;
}
