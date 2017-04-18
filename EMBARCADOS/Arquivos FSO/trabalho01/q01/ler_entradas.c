#include <stdio.h>
#include <stdlib.h>
#include "ler_entradas.h"

void read_in(double x[], double y[]){
    int i;
    
    for(i = 0; i <= 3; i++){
        scanf("%lf %lf", &x[i], &y[i]);
    }
}

void exibir(double x[], double y[]){
    int i;
    for(i = 0; i <= 3; i++){
        printf("<%lf,%lf>\n", x[i], y[i]);
    }
}
