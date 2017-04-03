#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv[]){

	int i = 1;

	pid_t child[argc];

	while(i <= argc){

		child[i]= fork();

		if (child[i] == 0){
			
			char *lista[] = {NULL, NULL};
			lista[0] = argv[i];
			execvp(lista[0], lista);
		}
		else{
			sleep(1);
		}
		i++;

	}
}