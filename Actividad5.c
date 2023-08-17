// DELFINO MILAGROS - COMISIÓN 1

//EJERCICIO 11 PRACTICO 6

#include <stdio.h>

int a, b;
void Swap(int *x, int *y);

void Swap (int *x, int *y){
    *x= (*x)+(*y);  //suma los valores de x e y
    *y = (*x)-(*y); // le resta a la suma anterior el valor de y asignando el resultado (valor original de x) a y
    *x = (*x)-(*y); // le resta a la suma de la primera línea el valor de y que se obtuvo en la linea anterior (valor que originalmente tenía x), asignandole el resultado (valor de y) a x
}

int main() {
    printf("Introduce el valor de la variable a: "); //solicita que se ingrese el valor de a, a traves de la terminal
    scanf("%i",&a); // asigna el valor ingresado a la variable a 
    printf("Introduce el valor de la variable b: "); // solicita que se ingrese el valor de b a través de la terminal
    scanf("%i",&b); // asigna el valor ingresado a la variable b
    Swap (&a, &b); // realiza el intercambio de valores de las dos variables
    printf ("El valor de a es %d ", a); // imprime el valor de a luego del intercambio
    printf ("\nEl valor de b es %d ", b); //imprime el valor de b luego del intercambio
    printf("\nIntroduce el valor de la variable a "); //solicita nuevamente que se ingrese el valor de a
    scanf("%i",&a); // asigna el valor ingresado a la variable a
    printf("Introduce el valor de la variable b "); //solicita nuevamente que se ingrese le valor de b
    scanf("%i",&b); //asigna el valor ingresado a la variable b
    Swap (&a, &a); //realiza el intercambio pero con la misma variable dos veces como parámetro
    printf ("El valor de a es %d ", a); //imprime el valor de a luego de la acción que es 0
    return 0;
}

/*
Este algoritmo inicialmente solicita que se ingresen, a través de la terminal, los valores de 'a' y 'b'. Una vez ingresados, los valores de estas variables son intercambiados mediante la acción Swap, la cual toma dos numeros enteros como parámetros. Una vez finalizado el intercambio, los valores de a y b son mostrados en la terminal.

Posteriormente, se vuelve a solicitar que se ingresen valores a través de la terminal para ambas variables. Cuando se llama a la acción 
swap, sin embargo, los parámetros que se le pasan es dos veces el valor de 'a'. Al finalizar, se muestra a través de la terminal el valor de esta variable, que es 0.

Lo explicado anteriormente tiene sentido cuando analizamos detalladamente lo que realiza la accion swap. La misma utiliza punteros para realizar el intercambio de los valores de las variables, sin necesidad de utilizar una variable auxiliar. A esto lo realiza utilizando como parámetros un 'x' y un 'y' para modificar los valores de las variables (en este caso 'a' y 'b') de la siguiente manera:
    1. Suma los valores a los que apuntan x e y, asignandole el resultado a x (línea 11).
    2. Después, se resta el valor que originalmente tenia 'y' a 'x' de la suma anterior, y se le asigna a 'y' el resultado. Por lo que 'y' pasa a contener el valor de 'x' (linea 12).
    3. Por ultimo, en la linea 13, a 'x' (suma que se realiza en la línea 11) se le resta el valor de 'y' que le fue asignado en la línea 12, por lo que 'x' pasa a contener el valor original de 'y'. 

Teniendo en cuenta esto, tiene sentido que cuando los paramétros que se le pasan a la acción swap son 2 variables diferentes, el resultado sea el intercambio de esos valores, pero cuando, por ejemplo, se llama a la acción swap en la linea 28 con la misma variable dos veces como parámetro, el resultado de ese intercambio sea 0, ya que ambos punteros (x e y) apuntan hacia la misma dirección de memoria, por lo que las operaciones incluídas dentro de la acción se realizan siempre sobre la misma dirección de memoria, y no es posible realizar el intercambio como cuando los parámetros de la acción son dos variables diferentes. El resultado en este caso será siempre 0.

CASOS DE PRUEBA:

1. Supongamos que tomamos como ejemplo que a=4 y b=2. Cuando esos valores son ingresados a través de la terminal, la acción realizará un intercambio de los mismos:
    Swap (&a, &b) --> intercambiará los valores de a y b
    printf ("El valor de a es %d ", a) --> imprimirá el valor de a que luego de la acción swap es 2
    printf ("\nEl valor de b es %d ", b) --> imprimirá el valor de b que luego de la acción swap es 4
    Swap (&a, &a) --> realizará el intercambio pero con la misma variable dos veces como parámetro
    printf ("El valor de a es %d ", a) --> imprimirá el valor de a que es 0

2. Ahora supongamos que a=8 y b=17:
    Swap (&a, &b) --> intercambiará los valores de a y b
    printf ("El valor de a es %d ", a) --> imprimirá el valor de a que luego de la acción swap es 17
    printf ("\nEl valor de b es %d ", b) --> imprimirá el valor de b que luego de la acción swap es 8
    Swap (&a, &a) --> realizará el intercambio pero con la misma variable dos veces como parámetro
    printf ("El valor de a es %d ", a) --> imprimirá el valor de a que es 0
*/ 