#include <stdio.h> // Para a funcao printf()
#include <fcntl.h> // Para a funcao  open()
#include <signal.h> // Para chamar sinais
#include <unistd.h>// Para a funcao close()
#include <stdlib.h>// Para a função exit()
#include <string.h> // Para funções de string()
#include <time.h>  // P/ marcações de tempo
#include <sys/types.h>
#include <signal.h>   // Implementar sinais 
#include <semaphore.h> // Implementar o Mutex

/*Exemplo de utlização de */

int main(int argc, char const *argv[])
{
	pid_t filho;
	int i, status;

	filho = fork();

	if(filho == 0){ // Código do FILHO

		int i;

		printf("Sou o processo filho!\n");

		printf("FILHO: Aguarde 5 segundos\n");

		for(i = 0; i < 5; i++)
		{
			printf("%d segundo(s)\n", i);
			sleep(1);
		}
		printf("FILHO: TERMINEI!\n");
		exit(0);

	}
	else{ // Código do PAI
		printf("Estou esperando meu filho terminar...\n");
		wait(filho, NULL, 0);
		printf("Sou o PAI, agora posso finalizar o programa!\n");
	}

	printf("FIM DE PROGRAMA!\n");

	return 0;
}