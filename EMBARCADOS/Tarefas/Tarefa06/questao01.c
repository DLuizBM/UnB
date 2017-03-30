#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	pid_t child_pid01, child_pid02, child_pid03;

	printf("ID processo PAI: %d\n", (int) getpid ());
	
	child_pid01 = fork();

	if(child_pid01 != 0){

		printf("Esse é o Pai de Todos! Seu ID é: %d\n", (int) getpid());
		printf("Seu Filho 01 tem ID: %d\n", child_pid01);

		child_pid02 = fork();

		if(child_pid02 != 0){

			printf("Esse é o Pai de Todos! Seu ID é: %d\n", (int) getpid());
			printf("Seu Filho 02 tem ID: %d\n", child_pid02);

			child_pid03 = fork();

			if(child_pid03 != 0){

				printf("Esse é o Pai de Todos! Seu ID é: %d\n", (int) getpid());
				printf("Seu Filho 03 tem ID: %d\n", child_pid03);

			}

		}

	}
	
	return 0;
}