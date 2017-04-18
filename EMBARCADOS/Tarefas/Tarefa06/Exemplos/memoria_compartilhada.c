/* Comunicacao de processos atraves de Memória Compartilhada
 * Autor: Elgio Schlemer
 * Data: 17/12/2000
 * Ultima revisao: 30/12/2000
 * 
 * Paginas: 
 * 	http://www.ulbra.tche.br/~elgios/linux
 * 	http://www.inf.ufrgs.br/~elgios/linux
 *
 * Pre-requisito: estude o exemplo de fork antes, no arquico c de nome
 *      forki.c, do mesmo autor.
 *      Sugere-se a leitura do exemplo pipe.c, ver este este tipo de
 *      comunicação básico primeiro.
 * Referencias: 
 *      Linux A-Z, Phil Cornes, Prentice Hall: 1997. Pg 282.
 *
 * Programa para compartilhar memoria entre pai e filho.
 * Pode ser compartilhado POR QUALQUER PROCESSO, desde que eles conhecam o
 * identificador da area.
 * Como: Antes do fork, processo cria uma area para acomodar uma quantidade
 * certa de estrutura. Entao, o filho escreve algo nela. O pai, espera filho
 * terminar e então reproduz na tela os dados escritos pelo filho.*/

#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <termios.h>

#define TAM	50

typedef struct aluno {
	char nome[TAM + 1];
	char idade;
	char endereco[TAM + 1];
} dado;

int main()
{
	dado *a1;
	int area;
	int filho;

/* Cria area compartilhada: fica disponivel para QUALQUER PROCESSO, desde que
 * ele se conect nela. Precisa fazer antes do fork pq o filho deve conhecer o
 * valor da variavel area. Se fizer soh na area do processo pai, tb funciona,
 * mas de alguma forma o valor de "area" presisa ser comunicado ao filho, para
 * que ele use a aarea compartilhada
 * */

	area = shmget(IPC_PRIVATE, sizeof(dado), IPC_CREAT | 0644);
	if (area == -1) {
		fprintf(stderr, "Erro no shmget\n");
		exit(1);
	}
	filho = fork();

	if (filho < 0) {
		fprintf(stderr, "Erro no fork\n");
		exit(1);
	}
	/* agora temos DOIS processos aqui!! (ver exemplo forki.c) */

	/* O comando abaixo atacha a area ao processo. Pode ser comparado ao
	 * malloc */
	a1 = (dado *) shmat(area, 0, 0);

	if (a1 == (dado *) - 1) {
		fprintf(stderr, "Erro no shmat\n");
		exit(1);
	}
	if (filho) {
		/* Este eh o pai */
		a1->idade = 100;
		wait(filho);	/* espera filho morrer */

		printf("Nome: \"%s\"\tidade: %d\n", a1->nome, a1->idade);
		printf("Endereco: \"%s\"\n", a1->endereco);
        
		shmctl(area, IPC_RMID, 0); /* remove a area compartilhada */
	
	} else {
		/* Codigo do filho */
		sleep(1);
		printf("FILHO: idade=%d\n", a1->idade);
		sprintf(a1->nome, "ELgio Schlemer");
		sprintf(a1->endereco, "Avenida Acoures, 700");
		a1->idade = 27;
		exit(0);
	}
/* Se tem duvidas, execute um ipcs. Se quiser, faca um outro programa soh com a
 * a parte do pai, sem usar o shmget, mas soh o shmat, forcando o valor de area
 * para aquele que aparece no comando ipcs... */
}
