#include <stdio.h>
#include <math.h>
#include <string.h>

int num;
char msg[20];
int cont;
int i;

int main(){

    printf("Ingrese un numero: ");
    scanf("%d", &num);
    cont=0;
    i=2;
    if (num<=1){
        cont++;
    } else{
        while (i<=sqrt(num)){
            if (num%i==0){
                cont++;
            }
            i++;
        }
    }
    if (cont==0){
        strcpy(msg, "Es primo");
    } else{
        strcpy(msg, "No es primo");
    }
    printf("%s", msg);

    return 0;
}

