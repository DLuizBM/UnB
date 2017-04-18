//parte 01 do trabalho de fso
//o sentido de leitura é feito no sentido horario

#include <stdio.h>
#include <stdlib.h>
#include "ler_entradas.h" //rin = read inputs
#include "calc.h"
#include "pontos.h"




int main(){
	PONTOS quad;
    int convexo;
    
    read_in(quad.x, quad.y);  
    convexo = verifica_convexo(quad.x, quad.y);
    if(convexo == 1){
        printf("Convexo\n");
		calcula_area(quad.x, quad.y);
    }else{
        printf("Nao convexo\n");
    }
    
    //exibir(quad.x, quad.y);


    return 0;
}
