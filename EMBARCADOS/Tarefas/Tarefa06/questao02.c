#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int i;

	for(i = 1; i <= argc; i++){
		if(strcmp(argv[i], "ls") == 0)
			system("ls");
		else if(strcmp(argv[i], "echo") == 0)
			system("echo");
		else if(strcmp(argv[i], "cal") == 0)
			system("cal");
		else if(strcmp(argv[i], "pwd") == 0)
			system("cal");

	}
	
	return 0;
}