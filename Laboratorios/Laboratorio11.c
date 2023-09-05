// DELFINO MILAGROS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo{
    char info[50];
    struct nodo *next;
    struct nodo *back;
}Tnodo;
Tnodo l;
Tnodo *r, *s, *t, *p;

void MostrarLista(Tnodo *l);

void MostrarLista(Tnodo *l){
    Tnodo *aux;
    aux = l;
    while (aux != NULL){
        printf("%s", aux->info);
        aux = aux->next;
    }
    printf("\n");
}

int main(){
    //crear LDE 
    r = (Tnodo *) malloc(sizeof(Tnodo));
    p=r;
    strcpy(r->info, "va?\n");
    r->next = NULL;
    p->back = NULL;

    t = (Tnodo *) malloc(sizeof(Tnodo));
    strcpy(t->info, "te");
    t->next = r;
    t->back =NULL;
    r->back=t;
    r=t;

    t = (Tnodo *) malloc(sizeof(Tnodo));
    strcpy(t->info, "Como");
    t->next= r;
    t->back = NULL;
    r->back = t;
    r = t;

    t = (Tnodo *) malloc(sizeof(Tnodo)); 
    strcpy(t->info, "Hola");
    t->next= r;
    t->back=NULL;
    r->back = t;
    r = t;

    //mostramos la lista incicial completa
    MostrarLista(r);

    s=r;

    //creamos e insertamos el nuevo nodo
    t = (Tnodo *) malloc(sizeof(Tnodo)); 
    strcpy(t->info, "Tito");
    t->back= s;
    t->next= s->next;
    (t->next)->back = t;
    s->next= t;

    //mostramos la lista completa con la inserción del nodo
    MostrarLista(r);

    //modificamos el tercer nodo
    s=r;

    while (strcmp(s->info, "te")){
        s= s->next;
    }
    strcpy(s->info, "estas?");

    MostrarLista(r);

    //borramos el ultimo
    t=p;
    (p->back)->next = NULL;
    p= p->back;
    free(t);

    MostrarLista(r);

}