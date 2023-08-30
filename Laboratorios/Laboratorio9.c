// EJERCICIO 1 PRACTICO 9 -> ARREGLOS DE REGISTROS

#include <stdio.h>
#include <string.h>

#define Max 20
typedef struct {
    char ape[20];
    int dni;
}TPersona;
typedef struct{
    TPersona per[Max];
    int cant;
}TData;
TData data;
int doc;
void NombreDoc(TData com, int doc);
void Cargar(TData *com);

void Cargar (TData *com){
    printf("Ingrese la cantidad de registros a cargar: ");
    scanf("%d", &com->cant);
    printf("Ingrese los datos de cada persona: ");
    for (int i=0; i<com->cant; i++){
        printf("Persona %d\n", i+1);
        printf("Apellido: ");
        scanf("%s", com->per[i].ape);
        printf("DNI: ");
        scanf("%d", &com->per[i].dni);
    }
}

void NombreDoc(TData com, int doc){
    int i;
    char msg[60];
    int encontrado;
    encontrado=0;
    i=0;
    while((i<com.cant)&&(!(encontrado))){
        if (com.per[i].dni==doc){
            strcpy(msg, com.per[i].ape);
            encontrado=1;
        }
        i++;
    }
    if (!(encontrado)){
        strcpy(msg, "No existe una persona con ese dni");
    }
    printf("%s", msg);
}

int main(){
    Cargar(&data);
    printf ("Ingrese el DNI que quiere buscar: ");
    scanf("%d", &doc);
    NombreDoc(data, doc);
    return 0;
}
