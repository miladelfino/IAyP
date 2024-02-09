// DELFINO MILAGROS COMISION 3 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Max 100
typedef struct {
    int a[Max];
    int cant;
}Tdata;

Tdata datos;
int i;
int pos;
int num;
void CrearDatos(Tdata *d);
void Insercion(Tdata *d);
void BuscarDico(Tdata d, int e, int *pos);


int main(){
    printf("Ingrese la cantidad de elementos a cargar: ");
    scanf("%d", &datos.cant);
    CrearDatos(&datos);
    for(i = 0; i< datos.cant; i++){
      printf("%d\n", datos.a[i]);
    }
    printf("\n");
    Insercion(&datos);
    //primero ordeno el arreglo y despues busco
    for(i = 0; i< datos.cant; i++){
      printf("%d\n", datos.a[i]);
    }
    printf("Ingrese numero a buscar:");
    scanf("%d", &num);
    BuscarDico(datos, num, &pos);
    printf("\nLa posicion del numero buscado es (-1 si no esta): %d\n\n", pos);
  }
    


void CrearDatos(Tdata *d){
    int i;
    srand (time(NULL));
    for (i = 0; i<(d->cant); i++){
      d->a[i] = rand() % 101;
    }
}


void Insercion(Tdata *d){
    int aux, i, j;
    i = 1;
    while (i<(d->cant)){
      aux = d->a[i];
      j = i-1;
      while (j>=0 && d->a[j ]>aux){
        d->a[j+1] = d->a[j];
        j = j - 1;
      }
      d->a[j+1] = aux;
      i++;
    }
  }



void BuscarDico(Tdata d, int e, int *pos){
    int k;
    int inf; 
    int sup;
    if( (e<d.a[0]) || (e>d.a[d.cant-1])){
      *pos = -1;
    }
    else{
        if( e>=d.a[0] && e<=d.a[d.cant-1]){
            inf = 0;
            sup = d.cant - 2;
            while (inf< sup){
                k = (inf+sup)/2;
                if (e>d.a[k]){
                    inf = k+1;
                }else{
                    sup =k;
                }
            }
            if (d.a[inf] == e){
                *pos = inf+1;
            }else{
                *pos = -1;
            }
        }
    }
}
      