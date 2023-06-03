// FUNCION MAYOR

#include <string.h>
#include <math.h>
#include <stdlib.h>

float a,b,c,d,e,f;
float mayorNum;
float Mayor(float x, float y);

int main(){
    
    printf("ingrese 6 numeros: ");
    scanf("%f" "%f" "%f" "%f" "%f" "%f", &a, &b, &c, &d, &e, &f);
    mayorNum= Mayor(Mayor(Mayor(a,b), Mayor(c,d)), Mayor(e,f));
    printf("%f", mayorNum);
    
    return 0;
}


float Mayor(float x, float y){
    return (((x+y)+ fabs(x-y))/2);
}
