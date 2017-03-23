#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    FILE *fp; // Ponteiro p/ o arquivo
    fp  = fopen ("ola_mundo.txt", "w"); // Abrir o arquivo em modo de leitura
    if(!fp){
        printf("Nao foi possivel abrir o arquivo!");
        exit(0);
    }

    fprintf(fp,"Ola mundo!"); // Escreve no arquivo

    fclose(fp);

    return 0;
}
