#include "stAlumno.h"
#include <stdlib.h>

void mostrarUnAlumno (stAlumno a)
{
    printf("\n Id..........%d", a.id);
    printf("\n Nombre..........%s", a.nombre);
    printf("\n Apellido........%s",a.apellido);
    printf("\n Dni.............%s",a.dni);
    printf("\n Legajo..........%d",a.legajo);
    printf("\n ............................");
}
stAlumno cargaUnAlumno ()
{
    static int id = 0;
    id++;
    stAlumno a;
    a.id=id;
    printf("\n Nombre.......... %s");
    gets(a.nombre);
    printf("\n Apellido........ %s");
    gets(a.apellido);
    printf("\n Dni............. %s");
    gets(a.dni);
    printf("\n Legajo.......... %d");
    scanf("%d",&a.legajo);
    printf("\n ............................");
}
