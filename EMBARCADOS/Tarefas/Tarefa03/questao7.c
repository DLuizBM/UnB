#include <stdio.h>
#include <stdlib.h>
int i;
int main(int argc, const char *argv[])
{
    printf("Argumentos: ");
    for(i = 1; i < argc; i++){
        printf("%s ", argv[i]);
    }
    printf("\n");
    return 0;
}
