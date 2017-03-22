#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    FILE *fp;
    fp  = fopen ("questao01.txt", "w");
    if(fp == null){
        printf("Nao foi possivel abrir o arquivo!");
        exit(0);
    }
    fprintf("Ola mundo!");

    fclose(fp);

    return 0;
}
