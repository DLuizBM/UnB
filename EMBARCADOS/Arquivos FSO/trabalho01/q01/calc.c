#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h"



int verifica_convexo(double x[], double y[]){
    int i = 0;
    double dx = 0, dy = 0, sum_angulo = 0, angulo = 0, hip;     

    for(i = 0; i <= 3; i++){
        if(i == 3){
            dx = abs(x[3] - x[0]);
            dy = abs(y[3] - y[0]);
            angulo = atan(dx/dy);
            angulo = abs(angulo);
            sum_angulo += angulo;
            //printf("%lf\n", angulo);
            break;
        }else if (i == 0 || i == 2){   
            dx = abs(x[i+1] - x[i]);
            dy = abs(y[i+1] - y[i]);
            angulo = atan(dy/dx);
            angulo = abs(angulo);
            sum_angulo += angulo;     
            //printf("%lf\n", angulo);
        }else if (i == 1){
            dx = abs(x[i+1] - x[i]);
            dy = abs(y[i+1] - y[i]);
            angulo = atan(dx/dy);
            angulo = abs(angulo);
            sum_angulo += angulo;     
            //printf("%lf\n", angulo);
        }
    }
    //printf("\n\n\t %lf\n\n", sum_angulo);
	//sum_angulo == 4 para primeiro quadrante
	//sum_angulo == 0 para outros quadrantes
    if(sum_angulo == 4 || sum_angulo == 0){
        return 1;
    }else{
        return 0;
    }
}

void calcula_area(double x[], double y[]){
    int i;
    double direita = 0, esquerda= 0, area;
    
	direita = 0;esquerda = 0;
    //calcula a parte da direita
    for(i = 0; i <= 3; i++){
        if(i == 3){
            direita +=x[3]*y[0];
			
        }else{
        	direita += x[i]*y[i+1];
		}
    }    
    for(i = 0; i <= 3; i++){
        if(i == 3){
            esquerda += y[3]*x[0];
        }else{
			esquerda += y[i] * x[i+1];
		}
    }
	
	area = abs((esquerda - direita)/2.00);
	printf("Area: %lf\n", area);


}

