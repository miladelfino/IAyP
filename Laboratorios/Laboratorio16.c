// DELFINO MILAGROS - Comision 3 - METODOS DE ORDENAMIENTO

#include <stdio.h>
#define Max 50

typedef struct {
    char a[Max];
    int cant;
} Tdata;
Tdata cad;
int op;
void CargarArreglo (Tdata *c);
void MostrarArreglo (Tdata c);
void Burbuja (Tdata *c);
void Seleccion (Tdata *c);
void Insercion (Tdata *c);
void QuickSort (int izq, int der, Tdata *c);

int main(){
    CargarArreglo (&cad);
    MostrarArreglo (cad);
    printf ("\n ---Tipos de Ordenamientos---\n 1. Burbuja\n 2. Seleccion\n 3. Insercion\n 4. QuickSort\n");
    printf (" Ingrese el tipo de ordenamiento que desea ordenar: ");
    scanf ("%d", &op);
    if (op == 1){
        Burbuja (&cad);
        printf (" Datos ordenados por el metodo de Burbuja:\n");
        MostrarArreglo (cad);
    } else if (op == 2){
        Seleccion (&cad);
        printf (" Datos ordenados por el metodo de Seleccion:\n");
        MostrarArreglo (cad);
    } else if (op = 3){
        Insercion (&cad);
        printf (" Datos ordenados por el metodo de Insercion:\n");
        MostrarArreglo (cad);
    } else if (op == 4){
        QuickSort (0, cad.cant-1, &cad);
        printf (" Datos ordenados por el metodo Quicksort:\n");
        MostrarArreglo (cad);
    } else {
        printf (" Ingrese una opcion valida entre 1 y 4\n");
    }
    return 0;
}

void CargarArreglo (Tdata *c){
    int i, cant;
    i = 0;
    cant = 0;
    printf (" Ingrese la cantidad de elementos que desea cargar: ");
    scanf ("%d", &cant);
    while (i < cant){
        printf (" Letra: ");
        scanf ("%s", &c->a[i]);
        i = i + 1;
    }
    c->cant = cant;
}

void MostrarArreglo (Tdata c){
    int i;
    i = 0;
    while (i < c.cant){
        printf (" %c\n", c.a[i]);
        i = i + 1;
    }
}

void Burbuja (Tdata *c){
    int i, j;
    char temp;
    for (i = c->cant-1; i > 1; i--){
        for (j = 0; j < i; j++){
            if (c->a[j] > c->a[j+1]){
                temp = c->a[j];
                c->a[j] = c->a[j+1];
                c->a[j+1] = temp;
            }
        }
    }
}

void Seleccion (Tdata *c){
    int i, j, min;
    char temp;
    i = 0;
    while (i < c->cant){
        j = i;
        min = i;
        while (j < c->cant){
            if (c->a[j] < c->a[min]){
                min = j;
            }
            j = j + 1;
        }
        temp = c->a[i];
        c->a[i] = c->a[min];
        c->a[min] = temp;
        i = i + 1;
    }
}

void Insercion (Tdata *c){
    int i, j;
    char aux;
    i = 1;
    while (i < c->cant){
        aux = c->a[i];
        j = i - 1;
        while ((j >= 0)&&(c->a[j] > aux)){
            c->a[j+1] = c->a[j];
            j = j - 1;
        }
        c->a[j+1] = aux;
        i = i + 1;
    }
}

void QuickSort (int izq, int der, Tdata *c){
    int i, j;
    char p;
    char y;
    i = izq;
    j = der;
    p = c->a[(izq + der)/2];
    do {
        while ((c->a[i] < p)&&(j <= der)){
            i = i + 1;
        }
        while ((c->a[j] < p)&&(j > izq)){
            j = j - 1;
        }
        if (i <= j){
            y = c->a[i];
            c->a[i] = c->a[j];
            c->a[j] = y;
            i = i + 1;
            j = j - 1;
        }
    } while (i > j);
    if (izq < j){
        QuickSort (izq, j, c);
    }
    if (i < der){
        QuickSort (i, der, c);
    }
}