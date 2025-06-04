#include "stAlumno.h"

void mostrarUnAlumno (stAlumno a){
printf("\nId: %d",a.id);
printf("\nDni: %s",a.dni);
printf("\nNombre: %s",a.nombre);
printf("\nApellido: %s",a.apellido);
printf("\nLegajo: %d",a.legajo);
printf("\nNota:%d",a.nota);
printf("\n..........................");
}

stAlumno cargaUnAlumno(){
static int id = 0;
id++;
stAlumno a;
a.id = id;
printf("Nombre:");
gets(a.nombre);

printf("Apellido:");
gets(a.apellido);
printf("Dni:");
gets(a.dni);
printf("Legajo:");
scanf("%d",&a.legajo);
do{
printf("Nota:");
scanf("%d",&a.nota);
if(a.nota<1 || a.nota>10){
    printf("\n nota invalida,ingrese una nota valida");
}
}while(a.nota<1 || a.nota>10);

fflush(stdin);

return a;
}
