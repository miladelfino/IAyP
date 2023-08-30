//PUNTEROS -> listas simplemente encadenadas

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int info;
    struct nodo *next;
} TNodo;

TNodo *q, *r, *s, *t, *p;

int main(){
    q = (TNodo *) malloc(sizeof(TNodo));
    q->info = 14;
    q->next = NULL;
    s = (TNodo *) malloc(sizeof(TNodo));
    s->info=25;
    s->next=q;
    q=s;
    s = (TNodo *) malloc(sizeof(TNodo));
    s->info = 20;
    s->next = q;
    q=s;
    s= (TNodo *) malloc(sizeof(TNodo));
    s->info = 11;
    s->next =q;
    q=s;
    s=NULL;
    r=q;
    r=r->next;
    t=r->next;
    s= (TNodo *) malloc(sizeof(TNodo));
    s->info=3;
    s->next=r->next;
    r->next = s;
    p=t;
    t->info=29;
    printf("%d\n", t->info);
    r=q;
    
    while(r!=NULL){
        printf("%d\n", r->info);
        r=r->next;
    }
    return 0;
}
