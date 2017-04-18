#include <stdio.h>          // Para a funcao printf()
#include <stdlib.h>         // Para a função exit()
#include <string.h>         // Para funções de string()
#include "decrescente.h"    // p/ função decrescente()

void decrescente(int v[], int total){
    
        int aux, i, ordenador = 1;

        while (ordenador <= total){

            for (i = total - 1; i > 0; i--){

                if (v[i] > v[i-1]){

                    aux = v[i];
                    v[i] = v[i-1];
                    v[i-1] = aux ;
                }
            }
            
            ordenador = ordenador + 1;
        }

        printf("Saida decrescente:\n");

        for (i = 0; i < total; i++)
            printf("%d ", v[i]);

        printf("\n");

}