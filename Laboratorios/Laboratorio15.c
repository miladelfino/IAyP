// METODOS DE ORDENAMIENTO - BURBUJA

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX 100
typedef struct{
  int a[MAX];
  int cant;
} TData;

TData datos;
int i;

void InicializacionR(TData *d);
void Burbuja(TData *d);

int main(){
    srand(time(NULL));
    printf("Ingrese la cantidad de elementos a cargar: ");
    scanf("%d", &datos.cant);
  
    InicializacionR(&datos);
    for ( i = 0; i < datos.cant; i++){
        printf("\n%d", datos.a[i]);
    }
    printf("\n");
  
    Burbuja(&datos);
    for ( i = 0; i < datos.cant; i++){
        printf("\n%d", datos.a[i]);
    }
    printf("\n");
    return 0;
}

void InicializacionR(TData *d){
    int i;
    for ( i = 0; i< d->cant; i++){
        d->a[i] = rand() %100 + 1;
    }
}

void Burbuja(TData *d){
    int i, j, temp, aux;
    for (i = (d->cant -1); i > 0; i--){
        for( j = 0; j<i; j++){
            if(d->a[j] > d->a[j+1]){
                temp = d->a[j];
                d->a[j] = d->a[j+1];
                d->a[j+1] = temp;
            }
        }
    }
}
