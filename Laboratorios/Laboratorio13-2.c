//EJERCICIO 8 --> ARCHIVOS

#include <stdio.h>
#include <string.h>

#define Max 120
typedef struct{
    char nombre[50];
    int edad;
}Talumno;

typedef struct{
    Talumno a[Max];
    int cant;
}Tdata;

int i;
FILE* f;
Talumno alumno;
Tdata curso;

int main(){
    f= fopen("alumnos.dat", "r");
    curso.cant=0;
    while(curso.cant < Max && (!(feof(f)))){
        curso.cant= curso.cant+1;
        fread(&alumno,sizeof(alumno), 1, f);
        strcpy(curso.a[curso.cant].nombre, alumno.nombre);
        curso.a[curso.cant].edad = alumno.edad;
    }
    fclose(f);

    for (i=1; i<=curso.cant; i++){
        printf("Nombre: %s\n", curso.a[i].nombre);
        printf("Edad: %d\n", curso.a[i].edad);
    }
    return 0;
}
