// COMPOSICION SECUENCIAL

#include <stdio.h>

float altoPared;
float anchoPared;
float costoM2;
float supPared;
float costoMdeO;

int main()
{
    printf("\n Ingrese el alto de la pared: ");
    scanf("%f",&altoPared);
    printf("\n Ingrese el ancho de la pared: ");
    scanf("%f",&anchoPared);
    printf("\n Ingrese el costo de la mano de obra: ");
    scanf("%f",&costoM2);
    supPared = anchoPared*altoPared;
    costoMdeO= supPared*costoM2*1.2;
    printf("El costo de Mano de Obra para pintar la pared es: %.2f\n",costoMdeO);
    return 0;
}
