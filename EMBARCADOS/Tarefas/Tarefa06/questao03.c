#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{

	char * lista_de_argumentos[] = { "pwd", NULL};
	char * lista[] = { "ls","-l", NULL};
	pid_t pid_filho = fork();
	if (pid_filho == 0)
	{
		printf("*********************************************\n");
		printf("* Este é o processo FILHO, executando '%s'. *\n", lista_de_argumentos[0]);
		printf("*********************************************\n");
		printf("\n");
		execvp(lista_de_argumentos[0], lista_de_argumentos);
		perror("execvp");
		exit(EXIT_FAILURE);
		printf("*******************************************\n");
		execvp(lista[0], lista);
		printf("*******************************************\n");
		printf("* Este printf() so eh executado se houver *\n");
		printf("* um erro de execucao em execvp().        *\n");
		printf("*******************************************\n");
		printf("\n");
	}
	else
	{
		printf("*************************\n");
		printf("* Este é o processo PAI *\n");
		printf("*************************\n");
		printf("\n");
	}
	return 0;
}