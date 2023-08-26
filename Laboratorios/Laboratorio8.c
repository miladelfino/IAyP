// ARREGLOS BIDIMENSIONALES
#include <stdio.h>
#include <stdbool.h>

#define MaxF 20
#define MaxC 20
typedef struct{
    int mat[MaxF] [MaxC];
    int cantF;
    int cantC;
} TData;
TData data;

void Cargar(TData *k){
    int i;
    int j;
    printf("Ingrese la cantidad de filas: ");
    scanf("%d", &k->cantF);
    printf("Ingrese la cantidad de columnas: ");
    scanf("%d", &k->cantC);
    for (i=0; i<= k->cantF; i++){
        for (j=0; j<=k->cantC; j++){
            printf("Ingrese el número: ");
            scanf("%d", &k->mat[i][j]);
        }
    }
}

void Mostrar(TData k){
    int i;
    int j;
    for (i=0; j<=k.cantF; i++){
        for(j=0; j<=k.cantC; j++){
            printf("%d \n", k.mat[i][j]);
        }
        
    }
}

bool Bordes(TData k){
    int i;
    int j;
    int sumBor;
    int sumInt;
    sumBor=0;
    sumInt=0;
    for(i=0; i<=k.cantF; i++){
        for(j=0; j<=k.cantC; j++){
            if(i==1 || i==k.cantF || j==1 || j==k.cantC){
                sumBor=sumBor+k.mat[i][j];
            }else{
                sumInt=sumInt+k.mat[i][j];
            }
        }
    }
    return(sumBor=sumInt);
}

int main(){
    Cargar(&data);
    Mostrar(data);
    if (Bordes(data)){
        printf("La suma del borde es igual al corazón");
    }else{
        printf("La suma del borde es distinta al corazón");
    }
}