#include <stdio.h> // Para a funcao printf()
#include <fcntl.h> // Para a funcao  open()
#include <unistd.h>// Para a funcao close()
#include <stdlib.h>// Para a função exit()
#include <string.h> // Para funções de string()
int main(int argc, char *argv[])
{
    char nome_arq[50];
    int fp;

    /* Como os parâmetros são passados por meio das
     * variáveis argv e argc, não são necessárias
     * as funções de recebimento de scanf. Lembrando que
     * basta chamar o executável do programa e Digitar
     * o Nome posteriormente.
     * */

    // Função que escreve uma string na outra!
    sprintf(nome_arq, "%s.txt", argv[1]);

    fp = open(nome_arq, O_RDWR | O_CREAT, S_IRWXU);

    if(fp == -1){
        printf("Erro na abertura do arquivo.\n");
        exit(-1);
    }

    // Escrever no arquivo: write (fp, string, nº de bytes que ocupam)
    write(fp, "Nome: ", 6);
    write(fp, argv[1], strlen(argv[1]) * sizeof(char));
    write(fp, "\n", 1);
    write(fp, "Idade: ", 7);
    write(fp, argv[2], strlen(argv[2]) * sizeof(char));
    write(fp, "\n", 1);

    close(fp);

    return 0;
}
