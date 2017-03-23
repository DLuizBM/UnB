#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char nome[50];
    FILE *fp;

    /* Como os parâmetros são passados por meio das
     * variáveis argv e argc, não são necessárias
     * as funções de recebimento de scanf. Lembrando que
     * basta chamar o executável do programa e Digitar
     * o Nome posteriormente.
     * */

    // Função que escreve uma string na outra!
    sprintf(nome, "%s.txt", argv[1]);

    fp = fopen(nome,"w");
    if(!fp){
        printf("Nao foi possivel abrir o arquivo!");
        exit(0);
    }

    fprintf(fp, "Nome: %s\n", argv[1]);
    fprintf(fp, "Idade: %s anos\n", argv[2]);

    fclose(fp);

    return 0;
}
