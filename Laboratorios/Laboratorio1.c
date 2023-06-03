#include <stdio.h>
#include <string.h>

int edad;
char madurez[30];

int main(){
    printf("Ingrese la edad: ");
    scanf("%d", &edad);
    if (edad>=0 && edad<=11){
      strcpy(madurez, "el ciudadano es ninia/o");
    } else {
      if (edad>=12 && edad<=17){
        strcpy(madurez, "el ciudadano es adolescente");
        } else {
            if (edad>=18 && edad<=49){
                strcpy(madurez, "el ciudadano es adulto");
            } else {
                if (edad>=50){
                    strcpy(madurez, "el ciudadano es adulto mayor");
                } else {
                    strcpy(madurez, "la edad es incorrecta");
                }
            }
        }
      }
    printf("%s", madurez);
    return 0;
}
