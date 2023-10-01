// EJERCICIO 4
//DELFINO MILAGROS

#include <stdio.h>

FILE* f;
char c;
char x;
int iguales;
int distintos;

void CargarArchivo(char nomExt[]);

int main(){
    CargarArchivo("secu.txt");
    iguales = 0;
    distintos = 0;
    printf("Ingrese un caracter: ");
    scanf(" %c", &c);
    f=fopen("secu.txt", "r");
    while (!feof(f)){
        x= fgetc(f);
        if (c==x){
            iguales= iguales+1;
        }else{
            distintos = distintos +1;
        }
    }
    fclose(f);
    printf("La cantidad de caracteres iguales es: %d", iguales);
    printf("La cantidad de caracteres distintos es: %d", distintos-1);
    return 0;
}

void CargarArchivo(char nomExt[]){
    char x;
    FILE* f;
    printf("Ingrese un caracter o *: ");
    scanf(" %c", &x);
    f=fopen(nomExt, "w");
    while (x!= '*'){
        fputc(x, f);
        printf("Ingrese un caracter o *: ");
        scanf(" %c", &x);
    }
    fclose(f);
}

