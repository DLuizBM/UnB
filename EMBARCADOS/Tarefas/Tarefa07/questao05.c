#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void funcao_ps(int sig)
{
	system("ps aux --sort=-pcpu");
	printf("\n");
	printf("==============================================\n");
	printf("\n");
	alarm(1);
}

void funcao_para_control_c()
{
	printf("\nQuem mandou voce pressionar CTRL-C?\n");
	printf("Vou ter de fechar o programa!\n");
	exit(1);
}

int main()
{
	// Linkando os sinais as funções
	signal(SIGINT, funcao_para_control_c);
	signal(SIGALRM, funcao_ps);

	alarm(1);

	printf("Aperte CTRL+C para acabar.\n");

	while(1);
	
	return 0;
}