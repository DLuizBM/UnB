#include <stdio.h> // Para a funcao printf()
#include <fcntl.h> // Para a funcao  open()
#include <signal.h> // Para chamar sinais
#include <unistd.h>// Para a funcao close()
#include <stdlib.h>// Para a função exit()
#include <string.h> // Para funções de string()
#include <time.h>  // P/ marcações de tempo
#include <sys/types.h>
#include <signal.h>

int var = 1;

void acao_pai(int sig)
{
	
}

void tratamento_SIGUSR1()
{
	printf("CHAMOU FUNCAO\n");
	//printf("Processo %d recebeu sinal SIGUSR1... ele vai parar agora.\n", getpid());
	exit(1);
}

int main(int argc, char const *argv[])
{
	pid_t pid_filho;

	int fd[2]; // Descritor do pipe

	pipe(fd); // Cria o pipe

	int fp; // Descritor de arquivo

	signal(SIGALRM, acao_pai); // Define o sinal pra ser executado
	signal(SIGUSR1, tratamento_SIGUSR1);

	int pid_pai = getpid();

	pid_filho = fork();

	if(pid_filho == 0){ // Processo Filho

		char msg_filho[100];

		strcpy(msg_filho, "Mensagem 01 do FILHO!\n");

		printf("Vai escrever no pipe\n");

		if (write(fd[1], msg_filho, strlen(msg_filho) * sizeof(char)) < 0)
			printf("Erro na escrita do pipe01!\n");
		else{
			alarm(1);
		}

		printf("Aguarda 2 segundos...\n");
		sleep(2);

		strcpy(msg_filho, "Mensagem 02 do FILHO!\n");
		printf("Vai escrever no pipe\n");

		if (write(fd[1], msg_filho, strlen(msg_filho) * sizeof(char)) < 0)
			printf("Erro na escrita do pipe01!\n");
		else{
			alarm(1);
		}

		printf("Aguarda 2 segundos...\n");
		sleep(2);

		printf("FIM DE PROGRAMA!\n");
		close(fp);
		kill(pid_pai,SIGUSR1);
		exit(1);

	}
	else{ // Processo Pai

		char msg_pai[100];

		fp = open("pipe.txt", O_RDWR | O_CREAT, S_IRWXU);

		sleep(1);


		printf("Vai ler o pipe:\n");

		if(read(fd[0], msg_pai, strlen(msg_pai) * sizeof(char)) < 0){
			printf("Erro na leitura do pipe\n");
		}
		else{
			printf("Mensagem do filho: %s\n", msg_pai);
			write(fp, msg_pai, strlen(msg_pai) * sizeof(char)); // Escreve no arquivo
		}
		


	}

	return 0;
}