#include <stdio.h>

int num;
int resultado;

int factorialAumento(int n);
void FactorialCola(int n, int *res);
void menu();

int main(){
    menu();
}

int factorialAumento(int n){
    if (n==0){
        return 1;
    }else{
        return(n*factorialAumento(n-1));
    }
}

void FactorialCola(int n, int *res){
    if (n==0){
        *res=1;
    }else{
        if(n==1){
            *res=*res;
        }else{
            *res=*res*n;
            FactorialCola(n-1, res);
        }
    }
}

void menu(){
    printf("Ingrese un valor para ver su factorial en ambas versiones, en caso de ingresar negativo se finaliza el programa: ");
    scanf("%d", &num);
    while (num>=0){
        resultado=1;
        printf("Factorial con aumento: %d\n", factorialAumento(num));
        FactorialCola(num, &resultado);
        printf("Factorial con cola: %d\n", resultado);
        printf("Otro factorial: ");
        scanf("%d", &num);
    }
}

