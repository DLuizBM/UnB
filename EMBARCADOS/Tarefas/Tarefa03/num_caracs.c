#include <stdio.h>
#include "num_caracs.hpp"
int main(int argc, const char *argv[])
{
    char string[100];
    int a = 0;

    printf("Digite seu nome:" );
    scanf("%[^\n]s", string);
    a = num_caracs(string);
    printf("O numero de caracteres e: %d \n", a);
    return 0;
}
