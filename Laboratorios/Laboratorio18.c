//DELFINO MILAGROS COMISION 3

#include <stdio.h>

FILE *f;
char elementoActual;
char elementoDado;
int i;
int iguales;
int distintos;
void CargarArchivo (FILE* *g);

int main(){
    CargarArchivo(&f);
    f=fopen("secu.txt", "r");
    iguales =0;
    distintos=0;
    printf("Ingrese el caracter a buscar cuantos iguales y distintos hay: ");
    scanf(" %c", &elementoDado);
    while(!(feof(f))){
        elementoActual= fgetc(f);
        if (elementoActual == elementoDado){
            iguales++;
        }else{
            distintos++;
        }

    }
    fclose(f);
    printf("\n\nCantidad de elementos iguales: %d", iguales);
    printf("\n\nCantidad de elementos distintos: %d", distintos-1);
    return 0;
}

void CargarArchivo (FILE* *g){
    int cantElemen;
    int i;
    char elem;
    *g=fopen("secu.txt", "w");
    printf("Ingrese cuantos elementos desea cargar en el archivo: ");
    scanf("%d", &cantElemen);
    for (i=0; i<cantElemen; i++){
        printf("Ingrese un elemento: ");
        scanf(" %c", &elem);
        fputc(elem, *g);
    }
    fclose(*g);
}
