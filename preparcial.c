// DELFINO MILAGROS - COMISION 3

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct data{
    int año;
    int monto;
}Tdata;

typedef struct nodo{
    Tdata info;
    struct nodo *next;
    struct nodo *back;
}Tnodo;

Tnodo *q;
Tdata p;
int monto2;
//char msg[100];
int cant;

void Crear (Tnodo **l){
    *l=NULL;
}

void MostrarLista(Tnodo **l, float x){
    Tnodo *aux;
    int cont;
    cont=0;
    aux= (*l)->next;
    while (aux != NULL){
        if ((aux->info).monto >= x){
            cont= cont+1;
        }
        aux = aux->next;
    }
    printf("%d", cont);
}

void CargarLista(Tnodo **l, int n){
    Tdata bono;
    Tnodo *s;
    int i;
    for(i=1; i<=n; i++){
        printf("Ingrese el año del bono: ");
        scanf("%d", &bono.año);
        printf("Ingrese el monto del bono: ");
        scanf("%d", &bono.monto);
        s = (Tnodo *) malloc(sizeof(Tnodo));
        s->info = bono;
        if (*l==NULL){
            s->next= *l;
            s->back = NULL;
            *l = s;
        }else{
            s->next = *l;
            s->back=NULL;
            (*l)->back= s;
            *l = s;
        }
    }
}

int main(){
    Crear(&q);
    //strcpy(msg, "Cuantos nodos va a agregar?");
    //printf("%s", msg);
    printf("Cuantos nodos va a agregar?");
    scanf("%d", &cant);
    CargarLista(&q, cant);
    //strcpy(msg, "Que monto quiere comparar?");
    //printf("%s", msg);
    printf("Que monto quiere comparar?");
    scanf("%d", &monto2);
    MostrarLista(&q, monto2);
}