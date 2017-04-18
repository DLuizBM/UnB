#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h"



int verifica_convexo(double x[], double y[]){
	int i, flag_angulo = 0;
	double prod = 0, norma1 = 0, norma2 = 0,norma = 0,angulo = 0;
	int teste_area;
	double pi = 3.141592; 

	for(i = 0; i <= 3; i++){
		if(i != 3 ){
			prod = x[i]*x[i+1] - y[i]*y[i+1];
			prod = abs(prod);
			norma1 = pow( x[i] , 2) + pow ( y[i] , 2);
			norma1 = sqrt(norma1);
			norma2 = pow( x[i + 1] , 2) + pow ( y[i + 1] , 2);
			norma2 = sqrt(norma2);
			norma = norma1*norma2;
			angulo = acos(prod/norma);
			angulo = (angulo*180.00)/pi;
			if(prod == 0){
				angulo = 90;
			}
			if(angulo > 180){
				flag_angulo = 1;
			}
			//printf("%lf\n", angulo);
		
		}
		if (i == 3){
			prod = x[0]*x[3] - y[0]*y[3];
			prod = abs(prod);
			norma1 = pow( x[0] , 2) + pow ( y[0] , 2);
			norma1 = sqrt(norma1);
			norma2 = pow( x[3] , 2) + pow ( y[3] , 2);
			norma2 = sqrt(norma2);
			norma = norma1*norma2;
			angulo = acos(prod/norma);
			angulo = (angulo*180.00)/pi;
			if(prod == 0){
				angulo = 90;
			}
			if(angulo > 180){
				flag_angulo = 1;
			}			
			//printf("%lf\n", angulo);
		
		}
				
	}

	
	if(flag_angulo == 1){
		return 0; //return 0 para nao convexo
	}else{
		return 1; //convexo
	}

}

double calcula_area(double x[], double y[]){
    int i;
    double direita = 0, esquerda= 0, area;
    
	direita = 0;esquerda = 0;
    //calcula a parte da direita
    for(i = 0; i <= 3; i++){
        if(i == 3){
            direita +=abs(x[3]*y[0]);
			esquerda += abs(y[3]*x[0]);
			
        }else{
        	direita += abs(x[i]*y[i+1]);
			esquerda += abs(y[i] * x[i+1]);
		}
    }    
	//printf("%lf %lf\n\n", esquerda, direita);
	area = (esquerda - direita)/2;
	if(area < 0){
		area = abs(area);
	}
	return area;


}

/*    int i = 0;
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
*/

