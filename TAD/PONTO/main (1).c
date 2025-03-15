#include <stdio.h>
#include "PONTO.h"
int main()
{
    Ponto *p1, *p2, *p3;
    p1=pto_cria(2,3);
    p2=pto_cria(4,5);
    p3=pto_cria(6,3);
 
 printf("perimetro: %lf ", pto_distancia(p1,p2)+pto_distancia(p2,p3)+pto_distancia(p3,p1));   
}