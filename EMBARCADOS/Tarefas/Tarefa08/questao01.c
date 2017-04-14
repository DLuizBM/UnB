/**************************** QUESTÃO 01 - AULA 08 ******************************/
/*

1. Crie um programa em C que cria uma thread, e faça com que o programa principal
 envie os valores 1, 2, 3, 4, 5, 6, 7, 8, 9 e 10 para a thread, com intervalos de 
 1 segundo entre cada envio. Depois de o programa principal enviar o número 10, 
 ele aguarda 1 segundo e termina a execução. A thread escreve na tela cada valor 
 recebido, e quando ela receber o valor 10, ela termina a execução.
 
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* print_numero(void* v)
{
	int i;
	int *c = (int*) v;

	for(i = 0; i < 10; i++){
		sleep(1);
		printf("nº enviado p/ a thread: %d\n", c[i]);
	}
}

int main(int argc, char* argv){

	int v[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	// Definindo a thread
	pthread_t thread;

	// Definindo qual função e quais parâmetro serão passados p/ thread
	pthread_create (&thread, NULL, &print_numero, &v);

	// Espera a thread terminar de executar
	pthread_join (thread, NULL);

	printf(">> A thread terminou sua execução! \n");

	sleep(1); // Espera 1 segundo

	printf(">> O programa principal terminou sua execução! \n");
	printf(">> FIM DO PROGRAMA! \n\n");


	return 0; // Termina a execução
}