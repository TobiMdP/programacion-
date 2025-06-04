#include "mocks.h"

void cargaNombre (char nombre []){
    char nombres [][30] = {
"juan", "maria", "carlos",

};
strcpy(nombre, nombres[(rand ()% sizeof(nombres)/30)]);



}
void cargaApellido(char apellido []){
char apellidos[][30] = {
"martinez","saez","sosa","fernandez","molina","messi","rojas","cruz"

};
strcpy(apellido, apellidos [(rand()%(sizeof(apellidos)/30))]);

}
void cargaDni (char dni[]){
 itoa(rand()%10000 * 1033, dni, 10);

}
int cargaLegajo(){
return rand()%10000;
}

int cargaArregloAlumnosAuto (stAlumno a[], int DIM){
    int i;
for (i=0; i<DIM; i++){
    a[i].id=i+1;
    cargaNombre(a[i].nombre);
    cargaApellido(a[i].apellido);
    cargaDni(a[i].dni);
    a[i].legajo=cargaLegajo();
}
return i;

}
