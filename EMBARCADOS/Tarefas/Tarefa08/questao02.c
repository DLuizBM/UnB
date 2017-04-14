/**************************** QUESTÃO 02 - AULA 08 ******************************/
/*

2. Crie um programa em C que preenche o vetor 'long int v[50000]' completamente 
com valores aleatórios (use a função random()), e que procura o valor máximo do 
vetor por dois métodos:
	(a) Pela busca completa no vetor v[];
	(b) Separando o vetor em 4 partes, e usando 4 threads para cada uma encontrar
	 o máximo de cada parte. Ao final das threads, o programa principal compara o
	  resultado das quatro threads para definir o máximo do vetor.

Ao final do programa principal, compare os resultados obtidos pelos dois métodos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

int n[4]; // Variável GLOBAL p/ comunicação das threads

struct parametros_calculo
{
	int thread;
	int posicao;
	int *v;
};

void* calcula_maior(void* args)
{
	struct parametros_calculo* p = (struct parametros_calculo*) args;

	int i = p->posicao;

	int m = 0;

	while(i < (p->posicao + 12500)){

		if(m < p->v[i]){
			m = p->v[i];
			n[p->thread] = m;
		}

		i++;
	}
}

int main (int argc, char* argv){
	
	int i, maior = 0, v[50000];

	// Constroi vetor aleatório
	for (i = 0; i < 50000; i++){
		v[i] = random() % 100;
	}

	printf(">> Gerando vetor aleatório com numeros de 0 a 100...\n");
	sleep(2);

	int pid; // PID do processo filho

	pid = fork();

	if(pid == 0){ // Código do FILHO

		int j, major;

		printf("\nO FILHO vai resolver pelo método padrão!\n\n");

		for (j = 0; j < 50000; j++){
			if (major < v[j]){
				major = v[j];
			}
		}

		printf(">> FILHO: O numero maior do vetor é: %d\n", major);
		printf("FILHO TERMINOU!\n\n");
	}
	else{ // Código do PAI

		printf("\nO PAI vai resolver o problema por threads!\n");

		// Definindo as threads
		pthread_t t01;
		pthread_t t02;
		pthread_t t03;
		pthread_t t04;

		// Definindo as STRUCTs
		struct parametros_calculo p01;
		struct parametros_calculo p02;
		struct parametros_calculo p03;
		struct parametros_calculo p04;

		p01.thread = 0;
		p01.posicao = 0; // Vai ler da posição 0 até 12500
		p01.v = v;

		pthread_create (&t01, NULL, &calcula_maior, &p01);

		p02.thread = 1;
		p02.posicao = 12500; // Vai ler da posição 12500 até 25000
		p02.v = v;

		pthread_create (&t02, NULL, &calcula_maior, &p02);

		p03.thread = 2;
		p03.posicao = 2500; // Vai ler da posição 25000 até 37500
		p03.v = v;

		pthread_create (&t03, NULL, &calcula_maior, &p03);

		p04.thread = 3;
		p04.posicao = 37500; // Vai ler da posição 37500 até 50000
		p04.v = v;

		pthread_create (&t04, NULL, &calcula_maior, &p04);

		// Programa espera as threads terminarem suas execuções
		pthread_join(t01, NULL);
		pthread_join(t02, NULL);
		pthread_join(t03, NULL);
		pthread_join(t04, NULL);

		maior = 0;

		for (i = 0; i < 4; i++){
			if (maior < n[i]){
				maior = n[i];
			}
		}

		printf(">> PAI: O numero maior do vetor é: %d\n", maior);
		printf("PAI TERMINOU!\n\n");
	}

	return 0;
}