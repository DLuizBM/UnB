#include <stdio.h> // Para a funcao printf()
#include <fcntl.h> // Para a funcao  open()
#include <signal.h> // Para chamar sinais
#include <unistd.h>// Para a funcao close()
#include <stdlib.h>// Para a função exit()
#include <string.h> // Para funções de string()
#include <time.h>  // P/ marcações de tempo
#include <sys/types.h>
#include <signal.h>
#include <semaphore.h>

int main(int argc, char const *argv[])
{
	int n, i = 1;

	//n = rand() % 5;

	srand((unsigned) time(NULL));
	n = rand() % 3;
	printf("n: %d\n", n);
	sleep((int)n);

	printf("FIM DE PROGRAMA!\n");
	return 0;
}