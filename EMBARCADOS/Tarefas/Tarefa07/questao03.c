#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int pid01, pid02;	// PID do processo filho
	int fd[2];	// Descritores do pipe
	int i;
	char mensagem[100];

	// Cria o pipe
	pipe(fd);

	// Cria o processo
	pid01 = fork();

	if(pid01 == 0) // Codigo do filho 01
	{
		strcpy(mensagem, "FILHO1: Quando o vento passa, é a bandeira que se move.\n");

		if(write(fd[1], mensagem, sizeof(mensagem)) < 0)
			printf("Erro na escrita do pipe\n");

		printf("Filho 01 encerrou a execução!\n");

	}
	else // Codigo do pai
	{
		pid02 = fork();

		if(pid02 == 0){ // Codigo do filho 02

			sleep(2);

			strcpy(mensagem, "FILHO2: Não, é o vento que se move.\n");
			
			if(write(fd[1], mensagem, sizeof(mensagem)) < 0)
				printf("Erro na escrita do pipe\n");

			printf("Filho 02 encerrou a execução!\n");

		}

		sleep(1);

		// Vai ler a mensagem do filho 01

		if(read(fd[0], mensagem, sizeof(mensagem)) < 0) 
			printf("Erro na leitura do pipe\n");
		else
			printf("%s\n", mensagem);

		sleep(2);

		// Vai ler a mensagem do filho 02

		if(read(fd[0], mensagem, sizeof(mensagem)) < 0) 
			printf("Erro na leitura do pipe\n");
		else
			printf("%s\n", mensagem);

		// Vai ler a mensagem do pai

		strcpy(mensagem, "PAI: Os dois se enganam. É a mente dos senhores que se move.\n");

		if (write(fd[1], mensagem, sizeof(mensagem)) < 0)
			printf("Erro na escrita do pipe\n");

		if(read(fd[0], mensagem, sizeof(mensagem)) < 0) 
			printf("Erro na leitura do pipe\n");
		else
			printf("%s\n", mensagem);

		printf("Pai encerrou a execução!\n");

	}
	return 0;
}
