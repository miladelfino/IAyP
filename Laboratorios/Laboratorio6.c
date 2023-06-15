#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define Max 30
typedef struct{
    int a[Max];
    int cant;
} TData;
TData numeros;
time_t t;
void Sortear (TData *num);
void Informar (TData num);

int main(){
    Sortear(&numeros);
    Informar(&numeros);
    return 0;
}

void Sortear (TData *num){
    int i;
    printf("Ingrese la cantidad de numeros: ");
    scanf("%d", &num->cant);
    srand((unsigned) time(&t));
    for(i=0; i<= num->cant; i++){
        num->a[i]= rand()%1000;
    }

}

void Informar(TData num){
    int i;
    for (i=0; i<= num.cant; i++){
    printf("%d \n", num.a[i]);
    }
}