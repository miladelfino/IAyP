//DELFINO MILAGROS - Comision 1
// 38885273

#include <stdio.h>

#define Max 70
typedef struct{
    int a[Max];
    int cant;
} TData;
TData q;
int numero;
int m;

void Ordenar(int n, TData *q){
    int i;
    int j;
    i= q->cant-1;
    while(n!=99){
        if (q->a[i]<=n){
            q->a[i+1]=n;
            q->cant= q->cant+1;
            n=99;
        }else{
            q->a[i+1]=q->a[i];
        }
        i=i-1;
    }
}

int main(){
    printf("Ingrese la cantidad de números que desea ingresar: ");
    scanf("%d", &q.cant);
    printf("Ingrese %d numeros (de menor a mayor): ", q.cant);
    for (m=0; m<q.cant; m++){
        scanf("%d", &q.a[m]);
    }
    printf("Ingrese el numero que desea insertar en el arreglo: ");
    scanf("%d", &numero);
    Ordenar(numero, &q);
    printf("El resultado es: \n");
    for (m=0; m<q.cant; m++){
        printf("%d", q.a[m]);
    }
    return 0;
}