#include <stdio.h>			// Para a funcao printf()
#include <stdlib.h>			// Para a função exit()
#include <string.h>			// Para funções de string()
#include "crescente.h"		// P/ função crescente()
#include "decrescente.h"	// p/ função decrescente()

int main(int argc, char *argv[]){

	// Declaração de variáveis
	int n = 1, i = 0, v[20], total;

	if(strcmp(argv[1],"-d") != 0 && strcmp(argv[1],"-r") != 0){

		printf("\nParametro nao incluso ou inexistente!\n");
    	printf("FIM DO PROGRAMA!\n\n");
    	exit(0);
	}

	printf("\nDigite os numeros (p/ encerrar digite -1):\n");

	while(n > 0){
		scanf("%i", &n);
		v[i] = n;
		i++;
	}

	total = i - 1; // tamanho do vetor
    
    if(strcmp(argv[1],"-d") == 0){ // if para ordem CRESCENTE

    	crescente(v, total);
    	/*
    	int aux;
	    int ordenador = 1;

	    while (ordenador <= total){

	        for (i = total - 1; i > 0; i--){

	            if (v[i] < v[i-1]){

	                aux = v[i];
	                v[i] = v[i-1];
	                v[i-1] = aux ;
	            }
	        }
	        
	        ordenador = ordenador + 1;
	    }

	    printf("Saida crescente:\n");

	    for (i = 0; i < total; i++)
            printf("%d ", v[i]);

        printf("\n");*/

    }
    else if(strcmp(argv[1],"-r") == 0){ // if para ordem DESCRESCENTE

		decrescente(v, total);

        /*
	    int aux;
	    int ordenador = 1;

	    while (ordenador <= total){

	        for (i = total - 1; i > 0; i--){

	            if (v[i] > v[i-1]){

	                aux = v[i];
	                v[i] = v[i-1];
	                v[i-1] = aux ;
	            }
	        }
	        
	        ordenador = ordenador + 1;
	    }

	    printf("Saida decrescente:\n");

	    for (i = 0; i < total; i++)
            printf("%d ", v[i]);

        printf("\n");*/

    }

    return 0;
}
