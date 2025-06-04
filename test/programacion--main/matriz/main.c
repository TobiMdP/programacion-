#include <stdio.h>
#include <stdlib.h>
#include "stAlumno.h"
#include <conio.h>
#define ESC 27
#define DIM 100
#include "mocks.h"
int main()
{
    stAlumno alumnos [DIM];
    int vAlumnos = 0;
    vAlumnos = cargaArregloAlumnosAuto(alumnos,DIM);
    printf("\n <<<<<< Listado de Alumnos >>>> \n");
    muestraArregloAlumnos(alumnos,vAlumnos);
    stAlumno a = alumnos[99];



    return 0;

    }




int cargaArregloAlumnos (stAlumno a[], int v, int dim){
char opcion = 0;
int i = v;

while(v <dim && opcion != ESC){
    a[i] = cargaUnAlumno();
    i++;
    printf("Esc para salir o cualquier tecla para continuar");
    opcion = getch ();
    system("cls");
}
return i;


}
void muestraArregloAlumnos(stAlumno a[], int v){
for (int i=0; i<v;i++){
    mostrarUnAlumno(a[i]);



}

}

void cuentaNotas(stAlumno a [], int v, int cont[]){
for(int i=0; i<v; i++)
{
    cont[a[i].nota]++;

}
}
void muestraContadorDeNotas(int cont[]){
for(int i=0; i<<11; )





}





}
