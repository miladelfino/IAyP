// FUNCIONES

#include <stdio.h>
#include <string.h>

char caracter;
int esMayuscula(char c);
int esVocal(char c);
char aMinuscula(char c);

void main(){
  printf("Ingrese un caracter: ");
  scanf("%c",&caracter);
  if ((caracter >= 'a' && caracter <= 'z')||(caracter >= 'A' && caracter <= 'Z')){
        if (esVocal(caracter)){
         printf ("El caracter ingresado es una vocal.");
       }
       else{
         printf ("El caracter ingresado es una consonante.");
       }
  }else{
      printf("El caracter ingresado no es una letra.");
  }
}

int esMayuscula(char caracter){
    return ((caracter >= 'A') && (caracter <= 'Z'));
}

char aMinuscula(char caracter){
    return (caracter + ('a'-'A'));
}

int esVocal(char caracter){
    char minus; //Léxico local
    if (esMayuscula(caracter)){
        minus = aMinuscula(caracter);
    }else{
        minus = caracter;
    }
    return ((minus == 'a')|| (minus == 'e') || (minus == 'i')||(minus == 'o')||(minus =='u'));
}
