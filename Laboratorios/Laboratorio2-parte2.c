#include <stdio.h>
#include <string.h>

int num;
int i;
int mult;
char msg1[20];
char msg2[20];

int main(){
    printf("Ingrese un numero: ");
    scanf("%d", &num);
    strcpy(msg1, "*");
    strcpy(msg2, "=");
    for (i=0; i<=10; i++){
        mult=num*i;
        printf("%d * %d = %d \n", num, i, mult);
    }

    return 0;
}
