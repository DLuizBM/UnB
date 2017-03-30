#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{

	int v_global = 0; // Variavel global para este exemplo
	void Incrementa_Variavel_Global(pid_t id_atual)
	{
		v_global++;
		printf("ID do processo que executou esta funcao = %d\n", id_atual);
		printf("v_global = %d\n", v_global);
	}


	pid_t child_pid01, child_pid02, child_pid03;

	printf("ID processo PAI: %d\n", (int) getpid ());

	Incrementa_Variavel_Global((int) getpid ());
	
	child_pid01 = fork();

	if(child_pid01 != 0){

		printf("Esse é o Pai de Todos! Seu ID é: %d\n", (int) getpid());
		printf("Seu Filho 01 tem ID: %d\n", child_pid01);

		Incrementa_Variavel_Global(child_pid01);

		child_pid02 = fork();

		if(child_pid02 != 0){

			printf("Esse é o Pai de Todos! Seu ID é: %d\n", (int) getpid());
			printf("Seu Filho 02 tem ID: %d\n", child_pid02);

			Incrementa_Variavel_Global(child_pid02);

			child_pid03 = fork();

			if(child_pid03 != 0){

				printf("Esse é o Pai de Todos! Seu ID é: %d\n", (int) getpid());
				printf("Seu Filho 03 tem ID: %d\n", child_pid03);

				Incrementa_Variavel_Global(child_pid03);

			}

		}

	}
	
	return 0;
}