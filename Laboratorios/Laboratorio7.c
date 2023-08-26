//ARREGLOS UNIDIMENSIONALES 

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define Max 81
typedef struct{
    char a[Max];
    int cant;
} TData;
TData pal;

void CargarPalabra(TData *frase){
    printf("Ingrese una frase: ");
    scanf("%s", frase->a);
    frase->cant=strlen(frase->a);
}

bool EsCapicua(TData frase){
    int i;
    i=0;
    while((i<=(frase.cant/2)) && (frase.a[i]==frase.a[frase.cant-1-i])){
        i++;
    }
    if (i>(frase.cant/2)){
        return 1;
    } else{
        return 0;
    }
}

int main(){
    CargarPalabra(&pal);
    if (EsCapicua(pal)){
        printf("Esta palabra es palindroma");
    }else{
        printf("Esta palabra NO es palindroma");
    }
    return 0;
}
