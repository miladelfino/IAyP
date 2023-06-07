// ARREGLO UNIDIMENSIONAL

#include <stdio.h>
#include <string.h>
#define Max 150 //reemplaza todas las apariciones de Max por 150, no es lo mismo que una constante

typedef struct
{
    int d[Max]; /*significa que d es un arreglo de enteros que tiene Max elementos PERO las posiciones van de 0 a Max-1, 
    luego el indice que recorre el arreglo debe empezar en 0 e ir hasta d.cant-1 */
    int cant;
}TData;

TData datos;
int i;

int main(){
    i=0;
    printf("Ingrese la cantidad de elementos: ");
    scanf("%d",&datos.cant);
    printf("Ingrese %d numeros: ",datos.cant);
    while(i<datos.cant){
        scanf("%d",&datos.d[i]);
        i++;
    }
    i=datos.cant-1;
    while(i>=0){
        printf("El elemento en la posicion %d es %d \n", i,datos.d[i]);
        i--;
    }
    return 0;
}
