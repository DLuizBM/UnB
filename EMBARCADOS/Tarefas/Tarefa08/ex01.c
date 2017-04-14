#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int main(int argc, char const *argv[])
{
	int i;
	int n[5] = {1, 2, 3, 4, 5};
	int *p;

	p = &n[0];

	printf(">> Exemplo de como funciona ponteiros: \n");
	printf("Vetor n: ");
	for (i = 0; i < 5; i++)
	{
		printf(" %d ", n[i]);
	}
	printf("\n");

	for (i = 0; i < 5; i++)
	{
		printf(">> Valor de n[%d]: %d (%d)\n", i, *p+i, p+i);
	}

	printf("\nFIM DO PROGRAMA!\n\n");
	return 0;
}