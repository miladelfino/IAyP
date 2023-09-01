// LISTAS SIMPLEMENTE ENCADENADAS (LSE)

#include <stdio.h>
#include <stdlib.h>

typedef struct persona{
    char nom[20];
    char ape[20];
    int dni;
    int edad;
}TPers;

typedef struct nodo{
    TPersona info;
    struct nodo *next;
}Tnodo;
Tnodo *q;
int continuar;
int opcion;
Tpers p;
void Crear(Tnodo **list);
void InsertarCab(Tnodo **list, TPers reg);
bool Vacia(Tnodo **list);
void SuprimirCab (Tnodo **list);
void Listar(Tnodo **list);
void CargarPersona(Tpers *p);

void Crear(Tnodo **list){
    *list=NULL;
}

void InsertarCab(Tnodo **list, TPers reg){
    Tnodo *aux;
    aux = (Tnodo *) malloc(sizeof(Tnodo));
    aux->info=reg;
    aux->next = *list;
    *list=aux;
}

int Vacia(Tnodo *list){
    return(list==NULL);
}

void SuprimirCab (Tnodo **list){
    Tnodo *aux;
    aux=*list;
    *list = (*list)->next;
    free(aux);
}

void Listar(Tnodo **list){
    Tnodo *aux;
    *aux=*list;
    while (aux != NULL){
        printf("%s", aux->info.nom);
        printf("%s", aux->info.ape);
        printf("%d", aux->info.edad);
        printf("%d", aux->info.dni);
        aux = aux->next;
    }
}

void CargarPersona(Tpers *p){
    printf("Ingrese el nombre: ");
    scanf("%s", &p->nom);
    printf("Ingrese el apellido: ");
    scanf("%s", &p->ape);    
    printf("Ingrese la edad: ");
    scanf("%s", &p->edad);
    printf("Ingrese el dni: ");
    scanf("%s", &p->dni);
}

int main(){
    continuar=1;
    Crear(&q);
    do {
        printf("Seleccione lo que desea hacer:");
        scanf("%d", &opcion);
        if (opcion==1){
            CargarPersona(&p);
            InsertarCab(&q, p);
            printf("Carga exitosa");
        }else if(opcion==2){
            if (Vacia(q)){
                printf("La lista esta vacia.");
            } else {
                SuprimirCab(&q);
                printf("La persona fue suprimida con exito");
            }
        } else if (opcion==3){
            if (Vacia(q)){
                printf("La lista esta vacia");
            }else{
                printf("Las personas que se encuentran en la lista son:");
                Listar(&q);
            }
        } else if (opcion!=4){
            printf("La opcion no es valida.");
        }
    } while (opcion!=4){
        printf("Adios.");
        return 0;
    }
}
