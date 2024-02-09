#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define NMax 150

struct Tfecha{
    int dia;
    int mes;
    int anio;
}Tfecha ;
struct TPersona{
    int DNI;
    char nombre[20];
    char apellido[20];
    struct Tfecha nacimiento; 
    int edad;
    char ciudad[20];
    char DP[30];  //direccion postal
    char CE[20]; //correo elecctronico
    char tel[15]; //telefono
    int VF; //vive/fallecio. 1 si vive, 0 si fallecio
    struct Tfecha fallecimiento; 
}TPersona;
typedef struct{
    struct TPersona a[NMax];
    int cant;
}TData;
typedef struct nodo{
    struct TPersona info;
    struct nodo *next;
}TNodo;
TNodo *x;
typedef struct elem{
    struct TPersona info;
    struct elem *next;
    struct elem *back;
}TElem;
TElem *m, *p;
int opcion;
int i;
int bot, top, r;
TData datos;
struct TPersona persona;
char localidad[100];
char arch[100];
FILE *g;
struct Tfecha nacim, fechaActual;
int Vacia(TData q);
int Llena(TData q);
void Fecha(struct Tfecha *fechaAct);
int Edad(struct Tfecha nacimiento, struct Tfecha fechaAct);
void Insertar(TData *q, struct TPersona z);
void Suprimir(TData *q);
void Mostrar(TData q);
void Modificar(TData *q);
void CrearListaS(TNodo **list);
void InsertarFallec(TData q, TNodo **list);
void MostrarLSE(TNodo *list);
void BorrarLista(TNodo **list);
void MostrarLocal(char nomArch[], TElem **z, TElem **y);
void OrdenarDNI(TData *q);
void OrdenarApe(TData *q);
void MostrarOpciones();
void PasarArchArre(TData *q, char nomArch[]);
void PasarArreArch(TData q, char nomArch[]);

int main(){
    printf("Ingrese el nombre del archivo: ");
    scanf(" %s", arch);
    Fecha(&fechaActual);
    g=fopen(arch, "rb");
    if (g == NULL) { // Si el archivo no existe lo creamos
        g = fopen(arch, "wb");
        fclose(g);
    }
    PasarArchArre(&datos, arch); //accion para pasar los datos del archivo al arreglo
    do{
        MostrarOpciones();
        scanf("%d", &opcion);
        switch(opcion){
            case 1:
                if((Vacia(datos)==0)&&(Llena(datos)==0)){
                    do{
                        printf("Ingrese el DNI de la persona que desea insertar (sin puntos): ");
                        scanf("%d", &persona.DNI);
                        if(persona.DNI>99999999){
                            printf("El DNI ingresado no es válido. Intente nuevamente");
                        }
                    }while(persona.DNI>99999999);
                    i=0;
                    while(datos.a[i].DNI!=persona.DNI && i<datos.cant){
                        i++;
                    }
                    if(i>=datos.cant){
                        printf("Ingrese el nombre de la nueva persona: ");
                        scanf(" %[^\n]", persona.nombre);
                        while(!"\n"){
                        getchar();
                        }
                        printf("Ingrese el apellido de la nueva persona: ");
                        scanf(" %[^\n]", persona.apellido);
                        while(!"\n"){
                        getchar();
                        }
                        printf("Ingrese la ciudad: ");
                        scanf(" %[^\n]", persona.ciudad);
                        while(!"\n"){
                            getchar();
                        }
                        printf("Ingrese el correo electronico: ");
                        scanf(" %s", persona.CE);
                        printf("Ingrese el dia de nacimiento: ");
                        scanf("%d", &persona.nacimiento.dia);
                        printf("Ingrese el mes de nacimiento: ");
                        scanf("%d", &persona.nacimiento.mes);
                        printf("Ingrese el año de nacimiento: ");
                        scanf("%d", &persona.nacimiento.anio);
                        printf("Ingrese la dirección postal: ");
                        scanf(" %s", persona.DP);
                        printf("Ingrese el telefono: ");
                        scanf(" %s", persona.tel);
                        do{
                            printf("Ingrese 1 si la persona vive y 0 si la persona fallecio: ");
                            scanf("%d", &persona.VF);
                        }while((persona.VF!=0) && (persona.VF!=1));
                        if(persona.VF==0){
                            printf("Ingrese el dia de fallecimiento: ");
                            scanf("%d", &persona.fallecimiento.dia);
                            printf("Ingrese el mes de fallecimiento: ");
                            scanf("%d", &persona.fallecimiento.mes);
                            printf("Ingrese el año de fallecimiento: ");
                            scanf("%d", &persona.fallecimiento.anio);     
                        }else{
                            Fecha(&fechaActual);
                            persona.edad=Edad(persona.nacimiento, fechaActual);
                        }
                        Insertar(&datos, persona);
                    }else{
                        printf("La persona ya se encuentra cargada en la lista.\n");
                    }
                }else if(Vacia(datos)==1){
                    printf("Ingrese el nombre de la nueva persona: ");
                    scanf(" %[^\n]", persona.nombre);
                    while(!"\n"){
                        getchar();
                    }
                    printf("Ingrese el apellido de la nueva persona: ");
                    scanf(" %[^\n]", persona.apellido);
                    while(!"\n"){
                    getchar();
                    }
                    do{
                        printf("Ingrese el DNI de la nueva persona(sin puntos): ");
                        scanf("%d", &persona.DNI);
                        if(persona.DNI>99999999){
                        printf("El DNI ingresado no es válido. Intente nuevamente.\n");
                        }
                    }while(persona.DNI>99999999);
                    printf("Ingrese la ciudad: ");
                    scanf(" %[^\n]", persona.ciudad);
                    while(!"\n"){
                        getchar();
                    }
                    printf("Ingrese el correo electronico: ");
                    scanf("%s", persona.CE);
                    printf("Ingrese el dia de nacimiento: ");
                    scanf("%d", &persona.nacimiento.dia);
                    printf("Ingrese el mes de nacimiento: ");
                    scanf("%d", &persona.nacimiento.mes);
                    printf("Ingrese el anio de nacimiento: ");
                    scanf("%d", &persona.nacimiento.anio);
                    printf("Ingrese la dirección postal: ");
                    scanf("%s", persona.DP);
                    printf("Ingrese el telefono: ");
                    scanf("%s", persona.tel);
                    do{
                        printf("Ingrese 1 si la persona vive y 0 si la persona fallecio: ");
                        scanf("%d", &persona.VF);
                    }while(persona.VF!=0 && persona.VF!=1);
                    if(persona.VF==0){
                        printf("Ingrese el dia de fallecimiento: ");
                        scanf("%d", &persona.fallecimiento.dia);
                        printf("Ingrese el mes de fallecimiento: ");
                        scanf("%d", &persona.fallecimiento.mes);
                        printf("Ingrese el año de fallecimiento: ");
                        scanf("%d", &persona.fallecimiento.anio);     
                    }else{
                        Fecha(&fechaActual);
                        persona.edad=Edad(persona.nacimiento, fechaActual);
                    }
                    strcpy(datos.a[0].nombre, persona.nombre);
                    strcpy(datos.a[0].apellido, persona.apellido);
                    datos.a[0].DNI=persona.DNI;
                    datos.a[0].edad=persona.edad;
                    strcpy(datos.a[0].ciudad, persona.ciudad);
                    strcpy(datos.a[0].DP, persona.DP);
                    strcpy(datos.a[0].CE, persona.CE);
                    datos.a[0].VF=persona.VF;
                    strcpy(datos.a[0].tel, persona.tel);
                    datos.a[0].nacimiento.dia=persona.nacimiento.dia;
                    datos.a[0].nacimiento.mes=persona.nacimiento.mes;
                    datos.a[0].nacimiento.anio=persona.nacimiento.anio;
                    datos.a[0].fallecimiento.dia=persona.fallecimiento.dia;
                    datos.a[0].fallecimiento.mes=persona.fallecimiento.mes;
                    datos.a[0].fallecimiento.anio=persona.fallecimiento.anio;
                    Insertar(&datos, persona);
                }else if(Llena(datos)==1){
                    printf("La persona no puede ser insertada ya que la lista está llena.\n");
                }
                break;
            case 2:
                Suprimir(&datos);
                break;
            case 3:
                Modificar(&datos);
                OrdenarApe(&datos);
                break;
            case 4:
                Mostrar(datos);
                break;
            case 5:
                CrearListaS(&x);
                InsertarFallec(datos, &x);
                MostrarLSE(x);
                BorrarLista(&x);
                break;
            case 6:
                PasarArreArch(datos, arch);
                MostrarLocal(arch, &m, &p);
                break;
            case 7:
                OrdenarDNI(&datos);
                Mostrar(datos);
                OrdenarApe(&datos);
                break;
            case 8:
                PasarArreArch(datos, arch);
                printf("Saliendo, adiós!\n");
                break;
        }
    }while(opcion!=8);
    return 0;
}

//accion que devuelve 1 si el arreglo esta vacio y 0 si no lo esta
int Vacia(TData q){
    if(q.cant==0){
        return (1);
    }else{
        return (0);
    }
}

//accion que devuelve 1 si el arreglo esta lleno o 0 si el arreglo no lo esta
int Llena(TData q){
    if(q.cant==150){
        return (1);
    }else{
        return (0);
    }
}

//accion que ajusta la fecha
void Fecha(struct Tfecha *fechaAct){
    time_t t;
    struct tm *fechaHora;
    t=time(NULL);
    fechaHora=localtime(&t);
    fechaAct->dia=fechaHora->tm_mday;
    fechaAct->mes=fechaHora->tm_mon + 1;
    fechaAct->anio= fechaHora->tm_year+1900;
}

//accion que calcula la edad de la persona
int Edad(struct Tfecha nacimiento, struct Tfecha fechaAct){
    int edad=fechaAct.anio - nacimiento.anio;
    if((fechaAct.mes<nacimiento.mes) || ((fechaAct.mes==nacimiento.mes) && (fechaAct.dia<nacimiento.dia))){
        edad--;
    }
    return edad;
}

//accion que inserta una nueva persona al arreglo
void Insertar(TData *q, struct TPersona z){
    int i, j;
    i=q->cant-1;
    q->cant=q->cant + 1;
    if(strcmp(z.apellido, q->a[i].apellido)>0){
        strcpy(q->a[i+1].nombre,z.nombre);
        strcpy(q->a[i+1].apellido, z.apellido);
        q->a[i+1].DNI=z.DNI;
        q->a[i+1].edad=z.edad;
        strcpy(q->a[i+1].ciudad,z.ciudad);
        strcpy(q->a[i+1].DP,z.DP);
        strcpy(q->a[i+1].CE,z.CE);
        strcpy(q->a[i+1].tel,z.tel);
        q->a[i+1].VF=z.VF;
        q->a[i+1].nacimiento.dia=z.nacimiento.dia;
        q->a[i+1].nacimiento.mes=z.nacimiento.mes;
        q->a[i+1].nacimiento.anio=z.nacimiento.anio;
        q->a[i+1].fallecimiento.dia=z.fallecimiento.dia;
        q->a[i+1].fallecimiento.mes=z.fallecimiento.mes;
        q->a[i+1].fallecimiento.anio=z.fallecimiento.anio;
    }else if (strcmp(z.apellido, q->a[i].apellido)<0){
    while(i>=0 && strcmp(z.apellido, q->a[i].apellido)<0){
        strcpy(q->a[i+1].nombre,q->a[i].nombre);
        strcpy(q->a[i+1].apellido, q->a[i].apellido);
        q->a[i+1].DNI=q->a[i].DNI;
        q->a[i+1].edad=q->a[i].edad;
        strcpy(q->a[i+1].ciudad,q->a[i].ciudad);
        strcpy(q->a[i+1].DP,q->a[i].DP);
        strcpy(q->a[i+1].CE,q->a[i].CE);
        strcpy(q->a[i+1].tel,q->a[i].tel);
        q->a[i+1].VF=q->a[i].VF;
        q->a[i+1].nacimiento.dia=q->a[i].nacimiento.dia;
        q->a[i+1].nacimiento.mes=q->a[i].nacimiento.mes;
        q->a[i+1].nacimiento.anio=q->a[i].nacimiento.anio;
        q->a[i+1].fallecimiento.dia=q->a[i].fallecimiento.dia;
        q->a[i+1].fallecimiento.mes=q->a[i].fallecimiento.mes;
        q->a[i+1].fallecimiento.anio=q->a[i].fallecimiento.anio;
        strcpy(q->a[i].nombre,z.nombre);
        strcpy(q->a[i].apellido, z.apellido);
        q->a[i].DNI=z.DNI;
        q->a[i].edad=z.edad;
        strcpy(q->a[i].ciudad,z.ciudad);
        strcpy(q->a[i].DP,z.DP);
        strcpy(q->a[i].CE,z.CE);
        strcpy(q->a[i].tel,z.tel);
        q->a[i].VF=z.VF;
        q->a[i].nacimiento.dia=z.nacimiento.dia;
        q->a[i].nacimiento.mes=z.nacimiento.mes;
        q->a[i].nacimiento.anio=z.nacimiento.anio;
        q->a[i].fallecimiento.dia=z.fallecimiento.dia;
        q->a[i].fallecimiento.mes=z.fallecimiento.mes;
        q->a[i].fallecimiento.anio=z.fallecimiento.anio;
        i--;
    }
    }else if(strcmp(z.apellido, q->a[i].apellido)==0){
    if(strcmp(z.nombre, q->a[i].nombre)<0){
        strcpy(q->a[i+1].nombre,q->a[i].nombre);
        strcpy(q->a[i+1].apellido, q->a[i].apellido);
        q->a[i+1].DNI=q->a[i].DNI;
        q->a[i+1].edad=q->a[i].edad;
        strcpy(q->a[i+1].ciudad,q->a[i].ciudad);
        strcpy(q->a[i+1].DP,q->a[i].DP);
        strcpy(q->a[i+1].CE,q->a[i].CE);
        strcpy(q->a[i+1].tel,q->a[i].tel);
        q->a[i+1].VF=q->a[i].VF;
        q->a[i+1].nacimiento.dia=q->a[i].nacimiento.dia;
        q->a[i+1].nacimiento.mes=q->a[i].nacimiento.mes;
        q->a[i+1].nacimiento.anio=q->a[i].nacimiento.anio;
        q->a[i+1].fallecimiento.dia=q->a[i].fallecimiento.dia;
        q->a[i+1].fallecimiento.mes=q->a[i].fallecimiento.mes;
        q->a[i+1].fallecimiento.anio=q->a[i].fallecimiento.anio;
        strcpy(q->a[i].nombre,z.nombre);
        strcpy(q->a[i].apellido, z.apellido);
        q->a[i].DNI=z.DNI;
        q->a[i].edad=z.edad;
        strcpy(q->a[i].ciudad,z.ciudad);
        strcpy(q->a[i].DP,z.DP);
        strcpy(q->a[i].CE,z.CE);
        strcpy(q->a[i].tel,z.tel);
        q->a[i].VF=z.VF;
        q->a[i].nacimiento.dia=z.nacimiento.dia;
        q->a[i].nacimiento.mes=z.nacimiento.mes;
        q->a[i].nacimiento.anio=z.nacimiento.anio;
        q->a[i].fallecimiento.dia=z.fallecimiento.dia;
        q->a[i].fallecimiento.mes=z.fallecimiento.mes;
        q->a[i].fallecimiento.anio=z.fallecimiento.anio;
        }else if(strcmp(z.nombre, q->a[i].nombre)>0){
            strcpy(q->a[i+1].nombre,z.nombre);
            strcpy(q->a[i+1].apellido, z.apellido);
            q->a[i+1].DNI=z.DNI;
            q->a[i+1].edad=z.edad;
            strcpy(q->a[i+1].ciudad,z.ciudad);
            strcpy(q->a[i+1].DP,z.DP);
            strcpy(q->a[i+1].CE,z.CE);
            strcpy(q->a[i+1].tel,z.tel);
            q->a[i+1].VF=z.VF;
            q->a[i+1].nacimiento.dia=z.nacimiento.dia;
            q->a[i+1].nacimiento.mes=z.nacimiento.mes;
            q->a[i+1].nacimiento.anio=z.nacimiento.anio;
            q->a[i+1].fallecimiento.dia=z.fallecimiento.dia;
            q->a[i+1].fallecimiento.mes=z.fallecimiento.mes;
            q->a[i+1].fallecimiento.anio=z.fallecimiento.anio;
        }else if(strcmp(z.nombre, q->a[i].nombre)==0){
            if(z.DNI<q->a[i].DNI){
                strcpy(q->a[i+1].nombre,q->a[i].nombre);
                strcpy(q->a[i+1].apellido, q->a[i].apellido);
                q->a[i+1].DNI=q->a[i].DNI;
                q->a[i+1].edad=q->a[i].edad;
                strcpy(q->a[i+1].ciudad,q->a[i].ciudad);
                strcpy(q->a[i+1].DP,q->a[i].DP);
                strcpy(q->a[i+1].CE,q->a[i].CE);
                strcpy(q->a[i+1].tel,q->a[i].tel);
                q->a[i+1].VF=q->a[i].VF;
                q->a[i+1].nacimiento.dia=q->a[i].nacimiento.dia;
                q->a[i+1].nacimiento.mes=q->a[i].nacimiento.mes;
                q->a[i+1].nacimiento.anio=q->a[i].nacimiento.anio;
                q->a[i+1].fallecimiento.dia=q->a[i].fallecimiento.dia;
                q->a[i+1].fallecimiento.mes=q->a[i].fallecimiento.mes;
                q->a[i+1].fallecimiento.anio=q->a[i].fallecimiento.anio;
                strcpy(q->a[i].nombre,z.nombre);
                strcpy(q->a[i].apellido, z.apellido);
                q->a[i].DNI=z.DNI;
                q->a[i].edad=z.edad;
                strcpy(q->a[i].ciudad,z.ciudad);
                strcpy(q->a[i].DP,z.DP);
                strcpy(q->a[i].CE,z.CE);
                strcpy(q->a[i].tel,z.tel);
                q->a[i].VF=z.VF;
                q->a[i].nacimiento.dia=z.nacimiento.dia;
                q->a[i].nacimiento.mes=z.nacimiento.mes;
                q->a[i].nacimiento.anio=z.nacimiento.anio;
                q->a[i].fallecimiento.dia=z.fallecimiento.dia;
                q->a[i].fallecimiento.mes=z.fallecimiento.mes;
                q->a[i].fallecimiento.anio=z.fallecimiento.anio;
            }else{
                strcpy(q->a[i+1].nombre,z.nombre);
                strcpy(q->a[i+1].apellido, z.apellido);
                q->a[i+1].DNI=z.DNI;
                q->a[i+1].edad=z.edad;
                strcpy(q->a[i+1].ciudad,z.ciudad);
                strcpy(q->a[i+1].DP,z.DP);
                strcpy(q->a[i+1].CE,z.CE);
                strcpy(q->a[i+1].tel,z.tel);
                q->a[i+1].VF=z.VF;
                q->a[i+1].nacimiento.dia=z.nacimiento.dia;
                q->a[i+1].nacimiento.mes=z.nacimiento.mes;
                q->a[i+1].nacimiento.anio=z.nacimiento.anio;
                q->a[i+1].fallecimiento.dia=z.fallecimiento.dia;
                q->a[i+1].fallecimiento.mes=z.fallecimiento.mes;
                q->a[i+1].fallecimiento.anio=z.fallecimiento.anio;
            }
        }
    }
}

//accion que suprime una persona del arreglo
void Suprimir(TData *q){
    int i;
    int doc;
    printf("Ingrese el DNI de la persona que desea suprimir de la lista: ");
    scanf("%d", &doc);
    i=0;
    while(i<q->cant && q->a[i].DNI != doc){
       i++; 
    }
    if(i<q->cant){
        while(i<q->cant){
            q->a[i]=q->a[i+1];
            i++;
        }
        q->cant=q->cant-1;
        printf("Persona suprimida exitosamente.\n");
    }else if(i>=q->cant){
        printf("Persona no encontrada en la secuencia.\n");
    }
}

//accion que muestra todas las personas dentro del arreglo
void Mostrar(TData q){
    int i;
    for(i=0; i<q.cant; i++){
        printf("Nombre: %s\n", q.a[i].nombre);
        printf("Apellido: %s\n", q.a[i].apellido);
        printf("DNI: %d\n", q.a[i].DNI);
        printf("Fecha de nacimiento: %d/%d/%d\n", q.a[i].nacimiento.dia, q.a[i].nacimiento.mes, q.a[i].nacimiento.anio);
        printf("Ciudad de residencia: %s\n", q.a[i].ciudad);
        printf("Dirección postal: %s\n", q.a[i].DP);
        printf("Correo electrónico: %s\n", q.a[i].CE);
        printf("Teléfono: %s\n", q.a[i].tel);
        if(q.a[i].VF==0){
            printf("Falleció.\n");
            printf("Fecha de fallecimiento: %d/%d/%d\n", q.a[i].fallecimiento.dia, q.a[i].fallecimiento.mes, q.a[i].fallecimiento.anio);
        }else if(q.a[i].VF==1){
            printf("La persona vive.\n");
            printf("Edad: %d\n", q.a[i].edad);
        }
    }
}

//accion que modifica los datos de una persona
void Modificar(TData *q){
    int i, doc, edad, vf, op;
    char nom[50];
    char ape[50];
    char ciu[100];
    char mail[50];
    char tel[20];
    char cp[30];
    struct Tfecha nac, fallec;
    struct TPersona reg;

    i=0;
    do{
        printf("Ingrese el DNI de la persona que desea insertar (sin puntos): ");
        scanf("%d", &reg.DNI);
        if(reg.DNI>99999999){
            printf("El DNI ingresado no es válido. Intente nuevamente");
        }
    }while(reg.DNI>99999999);

    while((q->a[i].DNI!=reg.DNI) && (i<=q->cant-1)){
        i++;
    }
    if (q->a[i].DNI == reg.DNI){
        printf("Nombre: %s\n", q->a[i].nombre);
        printf("Apellido: %s\n", q->a[i].apellido);
        printf("DNI: %d\n", q->a[i].DNI);
        printf("Fecha de nacimiento: %d/%d/%d\n", q->a[i].nacimiento.dia, q->a[i].nacimiento.mes, q->a[i].nacimiento.anio);
        printf("Ciudad de residencia: %s\n", q->a[i].ciudad);
        printf("Dirección postal: %s\n", q->a[i].DP);
        printf("Correo electrónico: %s\n", q->a[i].CE);
        printf("Teléfono: %s\n", q->a[i].tel);
        if(q->a[i].VF==0){
            printf("Falleció.\n");
            printf("Fecha de fallecimiento: %d/%d/%d\n", q->a[i].fallecimiento.dia, q->a[i].fallecimiento.mes, q->a[i].fallecimiento.anio);
        }else if(q->a[i].VF==1){
            printf("La persona vive.\n");
            printf("Edad: %d\n", q->a[i].edad);
        }
        printf("\n");
        printf("Ingrese el campo que desea modificar (-1 para finalizar):\n1.Nombre.\n2.Apellido.\n3.Ciudad.\n4.Correo Eléctronico.\n5.Nacimiento.\n6.Fallecimiento.\n7.Dirección Postal.\n8.Teléfono.\n9.Vive/Falleció\n");
        scanf("%d", &op);
        switch(op){
            case 1:
                printf("Ingrese el nombre: ");
                scanf(" %[^\n]", q->a[i].nombre);
                while(!"\n"){
                    getchar();
                }
                break;
            case 2:
                printf("Ingrese el apellido: ");
                scanf(" %[^\n]", q->a[i].apellido);
                while(!"\n"){
                    getchar();
                }
                break;
            case 3:
                printf("Ingrese la ciudad: ");
                scanf(" %[^\n]", q->a[i].ciudad);
                while(!"\n"){
                    getchar();
                }
                break;
            case 4:
                printf("Ingrese el correo electrónico: ");
                scanf(" %s", mail);
                strcpy(q->a[i].CE, mail);
                break;
            case 5:
                printf("Ingrese el dia de nacimiento: ");
                scanf("%d", &nac.dia);
                q->a[i].nacimiento.dia=nac.dia;
                printf("Ingrese el mes de nacimiento: ");
                scanf("%d", &nac.mes);
                q->a[i].nacimiento.mes=nac.mes;
                printf("Ingrese el año de nacimiento: ");
                scanf("%d", &nac.anio);
                q->a[i].nacimiento.anio=nac.anio;
                break;
            case 6:
                printf("Ingrese el dia de fallecimiento : ");
                scanf("%d", &fallec.dia);
                q->a[i].fallecimiento.dia=fallec.dia;
                printf("Ingrese el mes de fallecimiento: ");
                scanf("%d", &fallec.mes);
                q->a[i].fallecimiento.mes=fallec.mes;
                printf("Ingrese el año de fallecimiento: ");
                scanf("%d", &fallec.anio);
                q->a[i].fallecimiento.anio=fallec.anio;
                break;
            case 7:
                printf("Ingrese la dirección postal: ");
                scanf(" %s", cp);
                strcpy(q->a[i].DP, cp);
                break;
            case 8:
                printf("Ingrese el teléfono: ");
                scanf(" %s", tel);
                strcpy(q->a[i].tel, tel);
                break;
            case 9:
                printf("Ingrese '1' si la persona vive y '0' si falleció: ");
                scanf("%d", &vf);
                q->a[i].VF=vf;
                break;
        }
    }
}


//accion para crear una LSE con ficticio
void CrearListaS(TNodo **list){
    *list = (TNodo*) malloc(sizeof(TNodo));
    (*list)->next=NULL;
}

//accion para insertar las personas fallecidas a la lista
void InsertarFallec(TData q, TNodo **list){
    TNodo *aux;
    int i;
    for(i=q.cant; i>=0; i--){
        if(q.a[i].VF==0){
            aux=(TNodo*) malloc(sizeof(TNodo));
            strcpy(aux->info.nombre, q.a[i].nombre);
            strcpy(aux->info.apellido, q.a[i].apellido);
            strcpy(aux->info.ciudad, q.a[i].ciudad);
            strcpy(aux->info.CE, q.a[i].CE);
            aux->info.nacimiento.dia=q.a[i].nacimiento.dia;
            aux->info.nacimiento.mes=q.a[i].nacimiento.mes;
            aux->info.nacimiento.anio=q.a[i].nacimiento.anio;
            aux->info.fallecimiento.dia=q.a[i].fallecimiento.dia;
            aux->info.fallecimiento.mes=q.a[i].fallecimiento.mes;
            aux->info.fallecimiento.anio=q.a[i].fallecimiento.anio;
            aux->info.DNI=q.a[i].DNI;
            aux->info.edad=q.a[i].edad;
            strcpy(aux->info.DP, q.a[i].DP);
            strcpy(aux->info.tel, q.a[i].tel);
            aux->info.VF=q.a[i].VF;
            aux->next=(*list)->next;
            (*list)->next=aux;
        }
    }
}

//accion para mostrar las personas de la LSE
void MostrarLSE(TNodo *list){
    TNodo *aux;
    aux=list->next;
    while(aux!=NULL){
        printf("Nombre: %s\n", aux->info.nombre);
        printf("Apellido: %s\n", aux->info.apellido);
        printf("DNI: %d\n", aux->info.DNI);
        printf("Fecha de nacimiento: %d/%d/%d\n", aux->info.nacimiento.dia, aux->info.nacimiento.mes, aux->info.nacimiento.anio);
        printf("Ciudad de residencia: %s\n", aux->info.ciudad);
        printf("Dirección postal: %s\n", aux->info.DP);
        printf("Correo electrónico: %s\n", aux->info.CE);
        printf("Teléfono: %s\n", aux->info.tel);
        printf("Fecha de fallecimiento: %d/%d/%d\n", aux->info.fallecimiento.dia, aux->info.fallecimiento.mes, aux->info.fallecimiento.anio);
        aux=aux->next;
    }
}

//accion para borrar la LSE
void BorrarLista(TNodo **list){
    TNodo *aux;
    aux=(*list)->next;
    while(aux!=NULL){
        (*list)->next=aux->next;
        free(aux);
        aux=(*list)->next;
    }
    free(*list);
}

void MostrarLocal(char nomArch[], TElem **z, TElem **y) {
    TElem *aux;
    struct TPersona reg;
    char loc[20];
    int op;
    FILE *f;

  f=fopen(arch, "rb");
  // Incialización de la LDE con ficticio
  *z = (TElem *)malloc(sizeof(TElem));
  *y = (TElem *)malloc(sizeof(TElem));
  (*z)->back = NULL;
  (*z)->next = *y;
  (*y)->next = NULL;
  (*y)->back = *z;
  printf("Ingrese la localidad: ");
  scanf(" %[^\n]", loc);
  fseek(f, 0, SEEK_SET);
  while (fread(&reg, sizeof(reg), 1, f) == 1) {
    if (strcasecmp(reg.ciudad, loc) == 0) {
      // Si la ciudad de la persona en el archivo coincide,
      // la insertamos al final de la LDE (para mantener el orden)
      aux = (TElem *)malloc(sizeof(TElem));
      aux->info.DNI = reg.DNI;
      strcpy(aux->info.nombre, reg.nombre);
      strcpy(aux->info.apellido, reg.apellido);
      aux->info.nacimiento.dia = reg.nacimiento.dia;
      aux->info.nacimiento.mes = reg.nacimiento.mes;
      aux->info.nacimiento.anio = reg.nacimiento.anio;
      aux->info.edad = reg.edad;
      strcpy(aux->info.ciudad, reg.ciudad);
      strcpy(aux->info.DP, reg.DP);
      strcpy(aux->info.CE, reg.CE);
      strcpy(aux->info.tel, reg.tel);
      aux->info.VF = reg.VF;
      aux->info.fallecimiento.dia = reg.fallecimiento.dia;
      aux->info.fallecimiento.mes = reg.fallecimiento.mes;
      aux->info.fallecimiento.anio = reg.fallecimiento.anio;
      aux->next = *y;
      aux->back = (*y)->back;
      (aux->back)->next = aux;
      (*y)->back = aux;
    }
  }
  if ((*z)->next == *y && (*y)->back == *z) {
    printf("No se encontraron personas que vivan en %s\n", loc);
  } else {
    do {
      printf("Mostrar personas de la localidad en orden:\n");
      printf("1. Ascendente\n");
      printf("2. Descendente\n");
      printf("Seleccione una opcion: ");
      scanf("%d", &op);
      switch (op) {
      case 1:
        aux = (*z)->next;
        while (aux->next != NULL) {
          printf("DNI: %d\n", aux->info.DNI);
          printf("Nombre: %s\n", aux->info.nombre);
          printf("Apellido: %s\n", aux->info.apellido);
          printf("Nacimiento %d/%d/%d\n", aux->info.nacimiento.dia,
                 aux->info.nacimiento.mes, aux->info.nacimiento.anio);
          printf("Ciudad: %s\n", aux->info.ciudad);
          printf("Código Postal: %s\n", aux->info.DP);
          printf("Correo electrónico: %s\n", aux->info.CE);
          printf("Teléfono: %s\n", aux->info.tel);
          if (aux->info.VF == 0) {
            printf("Fecha de fallecimiento: %d/%d/%d\n\n",
                   aux->info.fallecimiento.dia, aux->info.fallecimiento.mes,
                   aux->info.fallecimiento.anio);
          }
          aux = aux->next;
        }
        break;
      case 2:
        aux = (*y)->back;
        while (aux->back != NULL) {
          printf("DNI: %d\n", aux->info.DNI);
          printf("Nombre: %s\n", aux->info.nombre);
          printf("Apellido: %s\n", aux->info.apellido);
          printf("Nacimiento %d/%d/%d\n", aux->info.nacimiento.dia,
                 aux->info.nacimiento.mes, aux->info.nacimiento.anio);
          printf("Ciudad: %s\n", aux->info.ciudad);
          printf("Código Postal: %s\n", aux->info.DP);
          printf("Correo electrónico: %s\n", aux->info.CE);
          printf("Teléfono: %s\n", aux->info.tel);
          if (aux->info.VF == 0) {
            printf("Fecha de fallecimiento: %d/%d/%d\n\n",
                   aux->info.fallecimiento.dia, aux->info.fallecimiento.mes,
                   aux->info.fallecimiento.anio);
          }
          aux = aux->back;
        }
        break;
      default:
        printf("Opción no válida. Por favor, seleccione una opción válida.\n");
      }
    } while (op != 1 && op != 2);
  }
  fclose(f);
}

//accion para ordenas las personas mediante DNI - metodo de ordenamiento: burbuja
void OrdenarDNI(TData *q){
    int i,j;
    struct TPersona pers;
    i=q->cant;
    while(i>0 && q->cant>1){
        j=0;
        while(j<i-1){
            if(q->a[j].DNI > q->a[j+1].DNI){
                pers=q->a[j+1];
                q->a[j+1]=q->a[j];
                q->a[j]=pers;
            }
            j++;
        }
        i--;
    }
}


int cantRegistros(char nomArch[]) {
  struct TPersona pers;
  FILE *f;
  int cantR = 0;
  fseek(f, 0, SEEK_SET);
  while (fread(&pers, sizeof(struct TPersona), 1, f) == 1) {
    cantR++;
  }
  fseek(f, 0, SEEK_SET);
  return cantR;
}
//accion para ordenar personas alfabeticamente
void OrdenarApe(TData *q){
    int i,j;
    struct TPersona aux;
    i=q->cant;
    while(i>0 && q->cant > 1){
        j=0;
        while(j<i-1){
            if((strcmp(q->a[j].apellido,q->a[j+1].apellido)>0) || 
            (strcmp(q->a[j].apellido,q->a[j+1].apellido)==0 && strcmp(q->a[j].nombre,q->a[j+1].nombre)>0)||
            (strcmp(q->a[j].apellido,q->a[j+1].apellido)==0 && strcmp(q->a[j].nombre,q->a[j+1].nombre)==0 && q->a[j].DNI > q->a[j+1].DNI)){
                aux=q->a[j+1];
                q->a[j+1]=q->a[j];
                q->a[j]=aux;
            }
            j++;
        }
        i--;
    }
}


/*void OrdenarApe(char nomArch[]) {
  struct TPersona aux;
  int cant, i, j;
  FILE *f;
  cant = cantRegistros(nomArch);

  fseek(f, 0, SEEK_SET);
  struct TPersona a[cant]; 

  for (i = 0; i < cant; i++) { // Pasamos el archivo al arreglo
    fread(&a[i], sizeof(struct TPersona), 1, f);
  }

  for (i = 1; i < cant; i++) {
    aux = a[i];
    j = i - 1;
    while (j >= 0 &&
           ((strcasecmp(a[j].apellido, aux.apellido) > 0) ||
            ((strcasecmp(a[j].apellido, aux.apellido) == 0) &&
             (strcasecmp(a[j].nombre, aux.nombre) > 0)) ||
            ((strcasecmp(a[j].apellido, aux.apellido) == 0) &&
             (strcasecmp(a[j].nombre, aux.nombre) == 0) &&
             (a[j].DNI > aux.DNI)))) { 
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = aux;
  }
  fseek(f, 0, SEEK_SET);
  i = 0;
  for (i = 0; i < cant; ++i) { // Pasamos del arreglo al archivo
    fwrite(&a[i], sizeof(struct TPersona), 1, f);
  }
}*/

//accion para mostrar el menu de opciones
void MostrarOpciones(){
    printf("Ingrese el número de la opción que desea ejecutar:\n1.Insertar personas.\n2.Eliminar personas.\n3.Modificar datos de personas.\n4.Listar todas las personas.\n5.Listar personas fallecidas\n6.Listar personas de una localidad.\n7.Ordenar por DNI.\n8.Salir.\n");
}

//accion para pasar los datos del archivo al arreglo
void PasarArchArre(TData *q, char nomArch[]){
    int i;
    struct TPersona reg;
    FILE *f;
    f=fopen(nomArch, "a+");
    i=0;
    q->cant=i;
    fseek(f,0,SEEK_SET);
    while((fread(&reg,sizeof(reg),1,f)==1)){
        reg.edad=Edad(reg.nacimiento, fechaActual);
        q->a[i]=reg;
        i++;
    }
    q->cant=i;
    fclose(f);
}

//accion para pasar los datos del arreglo al archivo
void PasarArreArch(TData q, char nomArch[]){
    int i;
    struct TPersona reg;
    FILE *f;
    f=fopen(nomArch, "wb");
    for(i=0;i<q.cant;i++){
        strcpy(reg.nombre, q.a[i].nombre);
        strcpy(reg.apellido, q.a[i].apellido);
        reg.DNI=q.a[i].DNI;
        strcpy(reg.ciudad, q.a[i].ciudad);
        strcpy(reg.CE, q.a[i].CE);
        reg.nacimiento.dia=q.a[i].nacimiento.dia;
        reg.nacimiento.mes=q.a[i].nacimiento.mes;
        reg.nacimiento.anio=q.a[i].nacimiento.anio;
        strcpy(reg.DP, q.a[i].DP);
        strcpy(reg.tel, q.a[i].tel);
        reg.fallecimiento.dia=q.a[i].fallecimiento.dia;
        reg.fallecimiento.mes=q.a[i].fallecimiento.mes;
        reg.fallecimiento.anio=q.a[i].fallecimiento.anio;  
        reg.VF=q.a[i].VF;
        fwrite(&reg, sizeof(reg), 1, f);
    }
    fclose(f);
}
