// DELFINO MILAGROS

#include <stdio.h>
#include <string.h>

int n;
int d;
int primo;
char msg[50];

int main()
{
    printf("ingrese un numero entero: ");
    scanf("%d", &n);
    primo=1;
    if (n<=1){
        strcpy(msg, "el numero ingresado no es primo");
        printf("%s",msg);
        return 0;
    }
    
    for (d=2; d<n; d++){
        if (n%d==0){
            primo=0;
        }
    }
    
    if(primo==1 && n>1){
        strcpy(msg, "el numero ingresado es primo");
    } else{
        strcpy(msg, "el numero ingresado no es primo");
    }
    printf("%s", msg);
    return 0;
}
