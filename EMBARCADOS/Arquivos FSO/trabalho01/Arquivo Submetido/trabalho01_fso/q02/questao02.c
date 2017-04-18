#include <stdio.h>			// Para a funcao printf()
#include <stdlib.h>			// Para a função exit()

int main(int argc, char *argv[]){

	int i;

	printf("\n# de parametros: %d\n", argc);
	printf("Nome do executavel: ");
	for(i = 2; argv[0][i] ; i++)
		printf("%c", argv[0][i]);

	printf("\n");

	if(argc > 1){
		for(i = 1; i < argc ; i++)
			printf("Parametro #%d: %s\n", i, argv[i]);
	}

	printf("\nFIM DO PROGRAMA!\n");

	return 0;
}
