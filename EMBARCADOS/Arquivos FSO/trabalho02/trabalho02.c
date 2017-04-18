
/* ***************** TRABALHO 02 - FSO *********************/

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

//static pthread_mutex_t mutexLock;

void tratamento_SIGUSR1()
{
	printf("CHAMOU FUNCAO\n");
	//printf("Processo %d recebeu sinal SIGUSR1... ele vai parar agora.\n", getpid());
	exit(1);
}

int main(int argc, char const *argv[]){

	/*

	No pipe de comunicação:

	>> ARRAY[0]: LEITURA
	>> ARRAY[1]: ESCRITA

	*/

	pid_t pid01;   // PID do processo FILHO 01
	pid_t pid02;   // PID do processo FILHO 02
	pid_t pid03;   // PID do processo FILHO 03

	int fd1[2]; // Descritor do pipe
	int fd2[2]; // Descritor do pipe

	int turn1 = 0, turn2 = 0;

	//int i, j = 1;
	int tempo = 0;
	int n;


	int fp; // Inteiro p/ criação de arquivo


	int pid_pai = getpid();


	signal(SIGUSR1, tratamento_SIGUSR1);

	pipe(fd1); // Cria o pipe p/ comunicação entre PAI e FILHO 01

	pid01 = fork(); // Cria o processo FILHO 01

	if(pid01 == 0){ // Código do FILHO 01: DORMINHOCO

		int j = 1;

		printf("\nFILHO DORMINHOCO INICIOU!\n");

		char msg01[100], id_msg01[100], m[10];

		//close(fd1[0]);

		while(j <= 20){

			tempo = clock();

			// Função que escreve uma string na outra!
			sprintf(msg01, "%ld", tempo / CLOCKS_PER_SEC);

			sprintf(id_msg01, ": Mensagem %d do FILHO DORMINHOCO\n", j);

			strcat(msg01, id_msg01);

			// FILHO 01 vai escrever no PIPE01
			write(fd1[1], msg01, strlen(msg01) * sizeof(char));
			turn1 = 1;

			//printf("%s\n", msg01);


			// Dormindo por um tempo aleatório: 1, 2 ou 3 segundos
			//srand((unsigned) time(NULL));

	    	//n = (rand() % 4);

	    	sleep(1);
	    	j++;

			//while((clock()-tempo) * 1000.000 / CLOCKS_PER_SEC < n){
				// Espera o tempo aleatório gerado
			//}
		}

		//close(fd1[1]);
		//exit(1);
	}
	else{ // Código do PAI

		pipe(fd2); // Cria o pipe p/ comunicação entre PAI e FILHO 02
		
		pid02 = fork(); // Cria o processo FILHO 02

		if(pid02 == 0){ // Código do FILHO 02: ATIVO

			printf("\nFILHO ATIVO INICIOU!\n");

			char msg02[100], id_msg02[100];

			int i;

			//close(fd2[0]);

			for(i = 1; i < argc ; i++){

				tempo = clock();

				// Função que escreve uma string na outra!
				sprintf(msg02, "%ld", tempo / CLOCKS_PER_SEC);

				sprintf(id_msg02, ": Mensagem %d do usuario: <%s>\n", i, argv[i]);

				strcat(msg02, id_msg02);

				// FILHO 01 vai escrever no PIPE01
				write(fd2[1], msg02, strlen(msg02) * sizeof(char));
				turn2 = 1;

				printf("%s\n", msg02);

				// Dormindo por um tempo aleatório: 1, 2 ou 3 segundos
				//srand((unsigned) time(NULL));

		    	//n = (rand() % 4) * 1000;

		    	sleep(1);

				//while((clock()-tempo) * 1000.000 / CLOCKS_PER_SEC < n){
					// Espera o tempo aleatório gerado
				//}
			}
			//close(fd2[1]);
			//exit(0);
		}
		else{ // Código do PAI


			pid03 = fork();

			if(pid03 == 0){ // FILHO QUE VAI CONTAR O TEMPO

				sleep(15);

				printf("FIM DE PROGRAMA!\n");
				close(fp);
				kill(pid01,SIGUSR1);
				kill(pid_pai,SIGUSR1);
				//var = 0;
				//printf("VAR: %d\n", var);
				//exit(0);

			}
			else{ // Código do PAI
				

			    // O_RDWR - Dada a permissao para ler e escrever
			    // O_CREAT - Se nao houver cria o arquivo
			    fp = open("output.txt", O_RDWR | O_CREAT, S_IRWXU);

			    if(fp == -1){
			        printf("Erro na abertura do arquivo.\n");
			        exit(-1);
			    }

				char msg[100];

				//close(fd1[1]);
				//close(fd2[1]);

				printf("PAI INICIOU!\n");

				while(1)
					if(turn1 == 1){
						//printf("entrou1\n");

						// PAI vai ler o PIPE01 >> FILHO DORMINHOCO
						if(read(fd1[0], msg, sizeof(msg)) < 0){
							printf("Erro na leitura do pipe\n");
						}
						else{
							printf("%s\n", msg);
							write(fp, msg, strlen(msg) * sizeof(char)); // Escreve no arquivo
						}

						turn1 = 0;
					}
					else{
						turn1 = 1;
					}

					if(turn2 == 1){
						//printf("entrou2\n");

						// PAI vai ler o PIPE02 >> FILHO ATIVO
						if(read(fd2[0], msg, sizeof(msg)) < 0){
							printf("Erro na leitura do pipe\n");
						}
						else{
							printf("%s\n", msg);
							write(fp, msg, strlen(msg) * sizeof(char)); // Escreve no arquivo
						}

						turn2 = 0;
					}else{
						turn2 = 1;
					}

				

				//close(fd1[0]);
				//close(fd2[0]);

				//printf("TERMINOU\n");
				//exit(1);

			}

					
		}
	}
		
	return 0;
}