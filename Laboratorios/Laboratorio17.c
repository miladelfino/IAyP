// DELFINO MILAGROS COMISION 3

#include <stdio.h>
#include <string.h>


int lluvia10[3][4]={
    {2, 4, 6, 8},
    {10, 2, 15, 7},
    {5, 6, 3, 0}
};
int precMax;
int dia;
int mes;
char mesNombre[15];
void maxPrec(int matriz[3][4], int *max, int *dia, int *mes);

int main(){
    maxPrec(lluvia10, &precMax, &dia, &mes);
    switch (mes){
        case 1:
            strcpy(mesNombre, "Enero");
            break;
        case 2:
            strcpy(mesNombre, "Febrero");
            break;
        case 3:
            strcpy(mesNombre, "Marzo");
            break;
        case 4:
            strcpy(mesNombre, "Abril");
            break;
        case 5:
            strcpy(mesNombre, "Mayo");
            break;
        case 6:
            strcpy(mesNombre, "Junio");
            break;
        case 7:
            strcpy(mesNombre, "Julio");
            break;
        case 8:
            strcpy(mesNombre, "Agosto");
            break;
        case 9:
            strcpy(mesNombre, "Septiembre");
            break;
        case 10:
            strcpy(mesNombre, "Octubre");
            break;
        case 11:
            strcpy(mesNombre, "Noviembre");
            break;
        default:
            strcpy(mesNombre, "Dieciembre");
            break;
    }
    printf("La mayor precipitacion es de %d mm \n", precMax);
    printf("El dia %d de %s\n\n", dia, mesNombre);
    return 0;
}


void maxPrec(int matriz[3][4], int *max, int *d, int *m){
    int i, j;
    *max=matriz[0][0];
    *d = 1;
    *m = 1;
    i=0;
    while(i<= 3){
        j=0;
        while (j<=4){
            if (matriz[i][j] > *max){
                *max= matriz[i][j];
                *d = j+1;
                *m=i+1;
            }
            j++;
        }
        i++;
        
    }
}