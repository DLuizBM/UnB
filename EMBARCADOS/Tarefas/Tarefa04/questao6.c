#include <stdio.h>
#include "bib_arqs.hpp"

int main(int argc, char *argv[])
{
    char palavra[100];
    le_arq_texto(argv[1], palavra);

    return 0;
}
