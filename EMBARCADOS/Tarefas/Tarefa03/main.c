#include <stdio.h>
#include "num_caracs.hpp"
int main(int argc, char *argv[])
{
    int i = 0;

    for(i = 0; i < argc; i++){
        printf("Argumento: %s\n", argv[i]);
        printf("Numero de caracteres: %d\n", num_caracs(argv[i]));
    }

    return 0;
}
