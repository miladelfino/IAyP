#include <stdio.h>

int num;
int fibonacci(int n);

int main(){
    do{
        printf("Ingrese que número de la serie fibonacci quiere saber: ");
        scanf("%d", &num);
        num=num-1;
    }while (num<0);
    printf("%d", fibonacci(num));
    return 0;
}

int fibonacci(int n){
    if (n<=0){
        return 0;
    }else{
        if (n==0 || n==2){
            return 1;
        }else{
            return(fibonacci(n-1)*fibonacci(n-2));
        }
    }
}