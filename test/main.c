#include <stdio.h>
#include <stdlib.h>
#include "stAlumno.h"
#include "mocksAlumnos.h"
#include "mocks.h"
#define DIM 20
#define ARCHI_ALUMNOS "alumnos.dat"
#define ARCHI_APROBADOS "aprobados.dat"
#define ARCHI_DESAPROBADOS "desaprobados.dat"
void muestraArchivoAlumnos(char nombreArchivo[]);
void pasarAprobadosDesaprobadosAlumnos(char nombreArchivo[], char aprobados[], char desaprobados[]);
void arreglo2archivo(stAlumno a[], int v, char nombreArchivo[]);
int archivo2Arreglo (char archivo[],int dim, stAlumno arreglo[]);
int ultimoIdAlumno(char nombreArchivo[]);
void muestraArregloAlumnos(stAlumno a[], int v);
int main()
{
     stAlumno alumnos[DIM];
    int vAlumnos=0;
    ///vAlumnos = cargaArregloAlumnosAuto(alumnos, DIM);
stAlumno alumnosArreglo [DIM];
int vAlumnosArreglo = 0;

// muestraArregloAlumnos(alumnos, vAlumnos);
///arreglo2archivo(alumnos, vAlumnos, ARCHI_ALUMNOS);
 printf("Listado de alumnos");
 muestraArchivoAlumnos(ARCHI_ALUMNOS);
 pasarAprobadosDesaprobadosAlumnos(ARCHI_ALUMNOS,ARCHI_APROBADOS,ARCHI_DESAPROBADOS);
 printf("Listado de aprobados");
 muestraArchivoAlumnos(ARCHI_APROBADOS);
 printf("Listado de desaprobados");
 muestraArchivoAlumnos(ARCHI_DESAPROBADOS);
 printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaa");
 vAlumnosArreglo = archivo2Arreglo(ARCHI_ALUMNOS, DIM, alumnosArreglo);
 printf("%d",vAlumnosArreglo);
 muestraArregloAlumnos(alumnosArreglo, vAlumnosArreglo);

    return 0;
}

void arreglo2archivo(stAlumno a[], int v, char nombreArchivo[]){
    //int contId = cuentaRegistros(nombreArchivo, sizeof(stAlumno));
    int contId = ultimoIdAlumno(nombreArchivo);
    FILE *archi = fopen(nombreArchivo, "ab");
    if(archi){  /// if(archi!=NULL)
        for(int i=0; i<v; i++){
            contId++;
            a[i].id = contId;
            fwrite(&a[i], sizeof(stAlumno), 1, archi);
        }
        fclose(archi);
    }
}
void muestraArchivoAlumnos(char nombreArchivo[]){
    FILE *archi = fopen(nombreArchivo, "rb");
    stAlumno alumno;
    if(archi){
        while(fread(&alumno, sizeof(stAlumno), 1, archi)>0){
            if(alumno.nota >= 6){

                printf("\n APROBADO");
            }else{

                printf("\n NO APROBO");
            }
            mostrarUnAlumno(alumno);
        }
        fclose(archi);
    }
}
void pasarAprobadosDesaprobadosAlumnos(char nombreArchivo[], char aprobados[], char desaprobados[])
{
    FILE *archi = fopen(nombreArchivo, "rb");
    FILE *archiAprobados = fopen(aprobados,"wb");
    FILE *archiDesaprobados = fopen(desaprobados,"wb");
    stAlumno alumno;

    if(archi && archiAprobados && archiDesaprobados)
    {
        while(fread(&alumno, sizeof(stAlumno), 1, archi)>0)
        {
            if(alumno.nota >= 6)
            {
                fwrite(&alumno,sizeof(stAlumno),1,archiAprobados);

            }
            else
            {
                fwrite(&alumno,sizeof(stAlumno),1,archiDesaprobados);
            }
        }
        fclose(archi);
        fclose(archiAprobados);
        fclose(archiDesaprobados);
    }
}
int ultimoIdAlumno(char nombreArchivo[]){
    FILE *archi = fopen(nombreArchivo, "rb");
    stAlumno alumno;
    int ultimoId = 0;
    if(archi){
        fseek(archi, -1 * sizeof(stAlumno), SEEK_END);
        fread(&alumno, sizeof(stAlumno), 1, archi);
        ultimoId=alumno.id;
    }
    return ultimoId;
}
int archivo2Arreglo (char archivo[],int dim, stAlumno arreglo[]){
FILE *archi = fopen(archivo,"rb");
stAlumno alumno;
int i = 0;
if(archi)
{
    while (fread(&alumno,sizeof(stAlumno),1,archi)>0 && i <= dim)
    {
        arreglo[i] = alumno;
        i++;
    }
    fclose(archi);
}
return i;
}
