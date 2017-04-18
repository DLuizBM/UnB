#include <stdio.h> // Para a funcao printf()
#include <fcntl.h> // Para a funcao  open()
#include <signal.h> // Para chamar sinais
#include <unistd.h>// Para a funcao close()
#include <stdlib.h>// Para a função exit()
#include <string.h> // Para funções de string()
#include <time.h>  // P/ marcações de tempo

int main(void)
{
	unsigned int i = 1;
	int n;

    clock_t Ticks[2];
    Ticks[0] = clock();

    //double times = Ticks[0] * 1000/CLOCKS_PER_SEC;

    //printf("Tempo: %ld\n", Ticks[0]);
    //printf("Tempo 2: %ld\n", CLOCKS_PER_SEC);

    //printf("\nHora 01: %d\n", Ticks[0]);

    //O código a ter seu tempo de execução medido ficaria neste ponto.
    while(i <= 5){

    	srand((unsigned) time(NULL));

    	n = rand() % 3;
    	printf("\nNumero Aleatório: %d ", n);

    	sleep((int)n);

    	//int tempo = clock(); //começa a contar o tempo

		//while((clock()-tempo)*1000/ CLOCKS_PER_SEC < 1528){ //enquanto não se passaram 1 segundo

		//printf("Mensagem para exibição enquanto repete ciclo");

		//}

		//printf("| Se passaram %d segundo(s)", i);

    	i++;
    }
    

    Ticks[1] = clock();
    //printf("\nHora 02: %lf\n", Ticks[1]);
    printf("\n");

    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("\nTempo gasto: %g ms.", Tempo);
    printf("\nTempo gasto: %g s.", Tempo/1000);

    printf("\nFIM DO PROGRAMA!\n");
    return 0;
}