// ARREGLOS BIDIMENSIONALES

#include <stdio.h>
#include <stdbool.h>

#define Fil 10
#define Col 30

typedef struct {
    int a[Fil][Col];
    int cantFil;
    int cantCol;
} TData;
TData k;
int num;

bool Repetido(int num, TData k) {
    int i, j, cont = 0;
    for (i = 0; i < k.cantFil; i++) {
        for (j = 0; j < k.cantCol; j++) {
            if (k.a[i][j] == num) {
                cont++;
            }
        }
    }
    return cont > 3;
}

int main() {
    int i, j;
    printf("Ingrese la cantidad de columnas del arreglo: ");
    scanf("%d", &k.cantCol);
    printf("Ingrese la cantidad de filas del arreglo: ");
    scanf("%d", &k.cantFil);
    printf("Ingrese %d numeros: ", k.cantFil * k.cantCol);
    for (i = 0; i < k.cantFil; i++) {
        for (j = 0; j < k.cantCol; j++) {
            scanf("%d", &k.a[i][j]);
        }
    }
    printf("Ingrese el numero que desea evaluar: ");
    scanf("%d", &num);
    if (Repetido(num, k)) {
        printf("Verdadero. El numero se encuentra repetido mas de 3 veces");
    } else {
        printf("Falso. El numero no se encuentra repetido mas de 3 veces");
    }
    return 0;
}
