// DELFINO MILAGROS

#include <stdio.h>
int main()
{
    int horas; // horas trabajadas totales
    float salario; //salario semanal
    float horasExtras; //precio de horas extras
    
    printf("Ingrese las horas trabajadas semanales: ");
    scanf("%d", &horas);
    
    if (horas<0){
        printf("No se admiten horas negativas, intente nuevamente.");
    } else{
        if (horas<=40 && horas>=0){
            salario=horas*10;
            printf("El salario semanal es de: $%.2f\n", salario);
        } else{
            horasExtras=(horas-40)*15;        
            salario= (40*10)+horasExtras;
            printf("El salario semanal es de: $%.2f\n", salario);
        }
    }
    return 0;
}
