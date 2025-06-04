#ifndef STALUMNO_H_INCLUDED
#define STALUMNO_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>

typedef struct{
int id;
char nombre[30];
char apellido[30];
char dni[9];
int nota;
int legajo;

}stAlumno;

void mostrarUnAlumno(stAlumno a);
stAlumno cargaUnAlumno();

#endif // STALUMNO_H_INCLUDED
