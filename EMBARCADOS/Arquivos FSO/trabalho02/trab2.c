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

void tratamento_SIGUSR1()
{
	//printf("CHAMOU FUNCAO\n");
	//printf("Processo %d recebeu sinal SIGUSR1... ele vai parar agora.\n", getpid());
	exit(1);
}


int main(int argc, char const *argv[])
{
	clock_t start, stop1, stop2, stopp;
	start = clock();

	pid_t pid1, pid2, pid3;
	
	int fd1[2], fd2[2];
	int turn1 = 0, turn2 = 0, total1 = 0, total2 = 0;

	signal(SIGUSR1, tratamento_SIGUSR1);

	int pid_pai = getpid();

	int fp; // Inteiro descritor de arquivo

	pipe(fd1);

	pid1 = fork();

	if(pid1 == 0){ // FILHO DORMINHOCO	
		char msg1[50];
		int j = 1, n1;

		printf(">> FILHO DORMINHOCO: %d\n", getpid());
		while(j < 10){

			//total1 = 0;

			srand((unsigned) clock());
			n1 = rand() % 3;

			total1 += n1;

			//printf("FILHO 1 vai escrever no pipe 1: \n");

			stop1 = clock();

			sprintf(msg1, "0:%d:%.3lf: Mensagem %d do FILHO DORMINHOCO\n", total1, (double)(stop1 - start)*-1000/CLOCKS_PER_SEC, j);

			write(fd1[1], msg1, sizeof(msg1));

			turn1 = 1;

			sleep((int)n1);

			j++;
		}
		printf(":: FILHO DORMINHOCO TERMINOU!\n");
		exit(0);
	}
	else{
		pipe(fd2);
		pid2 = fork();

		if(pid2 == 0){ // FILHO ATIVO

			char msg2[50];
			int i = 1, n2;

			printf(">> FILHO ATIVO: %d\n\n", getpid());

			//printf("ARGC: %d\n", argc);

			while(i < argc){

				//total2 = 0;

				//srand((unsigned) time(NULL));
				//n2 = rand() % 3;
				
				//total2 += n2;

				//printf("FILHO 2 vai escrever no pipe 2: \n");

				stop2 = clock();

				sprintf(msg2, "0:%d:%.3lf: Mensagem %d do usuario: <%s>\n", total2, (double)(stop2 - start)*-1000/CLOCKS_PER_SEC, i, argv[i]);

				write(fd2[1], msg2, sizeof(msg2));

				turn2 = 1;

				sleep(1);

				total2 += 1;

				i++;
			}
			
			printf(":: FILHO ATIVO TERMINOU!\n");
			//exit(0);
		}
		else{

			pid3 = fork();
			if(pid3 == 0){
				sleep(30);
				printf(":: FILHO 3 TERMINOU!\n");
				//wait(pid1, NULL, 0);
				//wait(pid2, NULL, 0);
				printf("FIM DE PROGRAMA!\n");
				close(fp);
				kill(pid_pai, SIGUSR1);
				kill(pid1, SIGUSR1); // Mata os processos, caso estejam sendo executados
				exit(0);

			}else{

				char msg[100], h[120];

				remove("trab2.txt"); // Remove arquivo, caso exista

				fp = open("trab2.txt", O_RDWR | O_CREAT, S_IRWXU);

			    if(fp == -1){
			        printf("Erro na abertura do arquivo.\n");
			        exit(-1);
			    }

				printf(">> PAI: %d\n\n", getpid());

				while(1){

					if(turn1 == 1){ // Recebe mensagens do filho 1
						//printf("PAI vai ler no pipe 1\n");
						read(fd1[0], msg, sizeof(msg));
						printf(" %s\n", msg);
						stopp = clock();
						sprintf(h, "0:%.3lf: ", (double)(stopp - start)*1000/CLOCKS_PER_SEC);
						strcat(h,msg);
						write(fp, h, strlen(h) * sizeof(char)); // Escreve no arquivo
						turn1 = 0;
					}else{
						//printf("VAI FILHO 1, pode escrever!\n");
						turn1 = 1;
					}

					if(turn2 == 1){ // Recebe mensagens do filho 2
						//printf("PAI vai ler o pipe 2\n");
						read(fd2[0], msg, sizeof(msg));
						printf(" %s\n", msg);
						stopp = clock();
						sprintf(h, "0:%.3lf: ", (double)(stopp - start)*1000/CLOCKS_PER_SEC);
						strcat(h,msg);
						write(fp, h, strlen(h) * sizeof(char)); // Escreve no arquivo
						turn2 = 0;
					}
					else{
						//printf("VAI FILHO 2, pode escrever!\n");
						turn2 = 1;
					}
				}
			}
		}
	}

	return 0;
}