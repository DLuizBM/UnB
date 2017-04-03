#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int pid;	// PID do processo filho
	int fd[2];	// Descritores do pipe
	int i,j;
	int mensagem[12];

	// Cria o pipe
	pipe(fd);

	// Cria o processo
	pid = fork();

	if(pid == 0) // Código do filho
	{
		sleep(12);
		printf("Filho vai ler o pipe.\n");

		if(read(fd[0], mensagem, sizeof(mensagem)) < 0) 
			printf("Erro na leitura do pipe\n");
		else{
			//printf("%d\n", mensagem);
			for(j = 0; j <= 10; j++){
				printf("Filho leu o pipe: %d\n", mensagem[j]);
			}
			
			sleep(1);

			printf("Filho terminou de ler o pipe\n");

		}
		
	}
	else // Codigo do pai
	{
		printf("Pai vai escrever no pipe os numeros de 1 a 10.\n");

		for(i = 0; i <= 10; i++){

			sleep(1); // Pai dorme por um segundo antes de escrever novamente

			mensagem[i] = i;
		}

		if (write(fd[1], mensagem, sizeof(mensagem)) < 0)
			printf("Erro na escrita do pipe.\n");
		else{
			for(i = 0; i <= 10; i++){
				printf("Pai escreveu no pipe: %d\n", mensagem[i] );
			}
		}


		printf("Pai terminou de escrever no pipe\n");

		sleep(1);
	}

	return 0;
}
