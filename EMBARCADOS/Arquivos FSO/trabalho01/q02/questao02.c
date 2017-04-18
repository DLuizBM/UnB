#include <stdio.h>			// Para a funcao printf()
#include <stdlib.h>			// Para a função exit()

int main(int argc, char *argv[]){

	int i;

	printf("\n# de parametros: %d\n", argc);
	printf("Nome do executavel: %s\n", argv[0]);

	if(argc > 1){
		for(i = 1; i < argc ; i++)
			printf("Parametro #%d: %s\n", i, argv[i]);
	}

	printf("\nFIM DO PROGRAMA!\n");

	return 0;
}
