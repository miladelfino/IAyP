// ACCIONES

#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct {
    float x;
    float y;
} Tpunto;

typedef struct{
    float a;
    float b;
} Trecta;

Tpunto p1;
Trecta rec;
char msg [50];
void cargaPunto(Tpunto *q);
void cargaRecta(Trecta *coef);
int pertenece(Tpunto p, Trecta recta);

int main(){
    cargaPunto(&p1);
    cargaRecta(&rec);
    if (pertenece(p1, rec)){
        strcpy(msg, "El punto pertenece a la recta");
    }else{
        strcpy(msg, "El punto NO pertenece a la recta");
    }
    printf("%s", msg);
    return 0;
}

void cargaPunto(Tpunto *p){
    printf("Ingrese los puntos a de la recta (x;y): ");
    scanf("%f %f", &p->x, &p->y);
}

void cargaRecta(Trecta *coef){
    printf("Ingrese los coeficientes de a y b: ");
    scanf("%f %f", &coef->a, &coef->b);
}

int pertenece(Tpunto p, Trecta recta){
    return(p.y== p.x * recta.a + recta.b);
}

