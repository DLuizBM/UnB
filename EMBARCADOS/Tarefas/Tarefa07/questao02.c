#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int pid;	// PID do processo filho
	int fd[2];	// Descritores do pipe
	int i;
	char mensagem[100];

	// Cria o pipe
	pipe(fd);

	// Cria o processo
	pid = fork();

	if(pid == 0) // Codigo do filho
	{
		strcpy(mensagem, "FILHO: Pai, qual é a verdadeira essência da sabedoria?\n");

		if (write(fd[1], mensagem, sizeof(mensagem)) < 0)
			printf("Erro na escrita do pipe\n");

		sleep(2);

		if(read(fd[0], mensagem, sizeof(mensagem)) < 0) 
			printf("Erro na leitura do pipe\n");
		else
			printf("%s\n", mensagem);

		strcpy(mensagem, "FILHO: Mas até uma criança de três anos sabe disso!\n");

		if (write(fd[1], mensagem, sizeof(mensagem)) < 0)
			printf("Erro na escrita do pipe\n");

		sleep(2);

		if(read(fd[0], mensagem, sizeof(mensagem)) < 0) 
			printf("Erro na leitura do pipe\n");
		else
			printf("%s\n", mensagem);

		sleep(3);

		printf("Filho encerrou a conversa!\n");

	}
	else // Codigo do pai
	{
		sleep(1);

		if(read(fd[0], mensagem, sizeof(mensagem)) < 0) 
			printf("Erro na leitura do pipe\n");
		else
			printf("%s\n", mensagem);

		strcpy(mensagem, "PAI: Não façais nada violento, praticai somente aquilo que é justo e equilibrado.\n");

		if (write(fd[1], mensagem, sizeof(mensagem)) < 0)
			printf("Erro na escrita do pipe\n");

		sleep(2);

		if(read(fd[0], mensagem, sizeof(mensagem)) < 0) 
			printf("Erro na leitura do pipe\n");
		else
			printf("%s\n", mensagem);

		strcpy(mensagem, "PAI: Sim, mas é uma coisa difícil de ser praticada até mesmo por um velho como eu...\n");

		if (write(fd[1], mensagem, sizeof(mensagem)) < 0)
			printf("Erro na escrita do pipe\n");

		sleep(5);

		printf("Pai encerrou a conversa!\n");

	}
	return 0;
}
