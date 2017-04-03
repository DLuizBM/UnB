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
	char nome[50];

	// Cria o pipe
	pipe(fd);

	// Cria o processo
	pid = fork();

	if(pid == 0) // Codigo do filho 01
	{
		printf("FILHO 01: Digite seu nome: \n");
		scanf("%s", &nome);


		if (write(fd[1], nome, sizeof(nome)) < 0)
			printf("Erro na escrita do pipe\n");

		printf("Filho 01 encerrou a conversa!\n");

	}
	else // Codigo do pai
	{
		sleep(2);

		if(read(fd[0], nome, sizeof(nome)) < 0) 
			printf("Erro na leitura do pipe\n");
		else
			printf("PAI: Nome do usuário: %s\n", nome);
		
	}
	return 0;
}
