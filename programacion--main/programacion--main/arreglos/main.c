#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define ESC 27
#define DIM 100
#include "pila.h"

//int cargaArreglo2(int a[],int v, int DIM);
void muestraArregloInt(int a[], int v);
int sumaArregloInt();
int cargaArregloRandom();
void copiarArreglo();
void arreglo2Pila (int a[],int v, Pila *p);
void muestraArregloFloat();
float sumaFloat (float arreglo[], int validos);
int buscarCaracter (char arreglo[], int validos, char letra);
int posicionMenor (int arreglo[], int validos, int inicio);
void ordenaPorSeleccion(int a[], int v);
void ordenaPorInsercion(int a[], int v);
int insertaOrd(int a[],int v, int dim, int dato);
void intercambio (int *a,int *b);
int esCapicua (int arreglo[], int v);
void insertaOrd2(int arreglo[],int v, int dato);

int main()
{
    char opcion;
    int arreglo[DIM];
    float arregloFloat[DIM];
    int vArreglo = 0;
    int encontrado;
    float validosFloat = 0;
    char arregloCaracteres[] = {'p', 'r','o','g','a','m','a'};
    Pila pila;
    inicpila(&pila);

    do
    {

        menu();
        printf("\n ingrese el numero del ejercicio al que quiere acceder \n");
        opcion = getch();
        fflush(stdin);
        switch(opcion)
        {
        case '1':
            printf(" \n<<<Carga arreglo random>>>\n");
            vArreglo = cargaArregloRandom(arreglo,DIM);
            system("pause");
            break;

        case '2':
            printf("\n <<<Carga arreglo>>>\n");
            vArreglo = cargaArreglo2(arreglo,vArreglo,DIM);
            break;
        case '3':
            printf("\n <<<Muestra arreglo>>>\n");
            muestraArregloInt(arreglo,vArreglo);
            system("pause");
            break;
        case '4':
            printf("\nLa suma de los elementos es: %d\n",sumaArregloInt(arreglo,vArreglo));
            break;

        case '5':
            copiarArreglo(arreglo,vArreglo);

            break;
        case '6':
            printf("\n encontrar elemento \n");
            int encontrar;
            printf("ingrese el numero a encontrar \n");
            scanf("%d",&encontrar);
            encontrarElemento(arreglo,DIM,encontrar);
            break;
        case '7':
            vArreglo = cargaArreglo(arreglo,vArreglo, DIM);
            arreglo2Pila (arreglo,vArreglo, &pila);
        break;
        case '8':
            encontrado = buscarCaracter(arregloCaracteres,8,'o');
            if(encontrado==1)
            {
                printf("El caracter se encuentra en el arreglo");
            }
            else
            {
                printf("El caracter no se encuentra en el arreglo");
            }
        break;
        case '9':
            printf("Arreglo capicua. \n");
            vArreglo = cargaArreglo2 (arreglo,vArreglo,DIM);
            muestraArregloInt(arreglo,vArreglo);

            if(esCapicua(arreglo,vArreglo) == 1)
            {
                printf("El arreglo es capicua. \n");
            }
            else
            {
                printf("el arreglo no es capicua \n");
            }
        break;
        case 'a':
            vArreglo = cargaArreglo2(arreglo,vArreglo,DIM);

            printf("posicion del menor elemento de un arreglo.%i \n",posicionMenor(arreglo,vArreglo,0));
            break;
        case 'b':
            printf("ordenar el arreglo \n");
            ordenaPorSeleccion(arreglo,vArreglo);
            break;
        case 'c':
            printf("ordenar por insercion");
            ordenaPorInsercion(arreglo,vArreglo);


        }
    }while(opcion != ESC);

    return 0;
}

void menu()
{
    printf("\n \t\t\t <<<Tp Arreglos>>>");
    printf("\n \n 1.- Carga arreglo random");
    printf("\n \n 2.- Carga arreglo");
    printf("\n \n 3.- Muestra arreglo");
    printf("\n \n 4.- Suma arreglo");
    printf("\n \n 5.- Hacer una función que reciba como parámetro un arreglo, la cantidad de elementos (válidos) cargados en él y una Pila. La función debe copiar los elementos del arreglo en la pila. ");
    printf("\n \n B. - Ordenar arreglo damn");
    printf("\n \n B. - Ordenar arreglo por insercion damn");
    printf("\n \n ESC PARA SALIR");
}

int cargaArregloRandom(int a[],int dim)
{
    int i;
    for (i=0; i<dim; i++)
    {
        a[i] = rand()%1000;
    }
    return i;
}
void muestraArregloInt(int a[], int v)
{
    for(int i=0; i<v; i++)
    {
        if(i%7==0)
        {
            printf("\n");
        }
        printf("%5d",a[i]);
    }
}

int sumaArregloInt(int a[], int v)
{
    int suma= 0;

    for(int i=0; i<v; i++)
    {
        suma += a[i];

    }
    return suma;
}
void copiarArreglo(int a[], int v)
{
    int i;
    Pila aux;
    inicpila(&aux);
    for(i=0; i<v; i++)
    {
        apilar(&aux,a[i]);
    }
    mostrar(&aux);
}
void encontrarElemento(int a[], int dim, int encontrar)
{
    int v;
    int i=0;
    for(i<dim; i++; v=0)
    {
        if (a[i]==encontrar)
        {
            v = 1;
            printf("\n el elemento esta en el arreglo");
        }
    }
    printf("\n el elemento no se encuentra en el arreglo\n");
}

int pila2Arreglo (Pila p, int a[],int dim)
{
    int i = 0;
    while(!pilavacia(&p)&& i<dim)
    {
        if(tope(&p)>=6)
        {
            a[i] = tope(&p);
            i++;
        }

        desapilar(&p);
    }
    return i;
}

void arreglo2Pila (int a[],int v, Pila *p)
{
    for(int i=0; i<v; i++)
    {
        if(a[i]>=6)
        {
            apilar(p,a[i]);
        }
    }
}
int notaValida(int nota)
{
    int flag = 0;
    if(nota > 0 && nota < 11)
    {
        flag = 1;
    }
    return flag;
}

int cargaArreglo2(int a[],int v, int dim)
{
    char opcion = 0;
    while(v<dim && opcion != ESC)
    {
        do
        {
            printf("\n ingrese una nota: ");
            scanf("%d",&a[v]);
            v++;
            printf("\n ESC PARA SALIR o cualquier tecla para continuar: ");
            opcion = getch();
        }while (notaValida(a[v]==0));

    }
    return v;
}
int cargaArreglo(int a[],int v, int dim)
{
    char opcion = 0;
    while(v<dim && opcion != ESC)
    {
        if(notaValida(a[v] == 0))
        {
            printf("ingrese una nota valida\n ");
        }
        v++;
        printf("\n ESC PARA SALIR o cualquier tecla para continuar: ");
        opcion = getch();
    }
    return v;
}
void cargarArregloFloatRandom (float arreglo[], int dimension)
{

    for(int i = 0; i < dimension; i++)
    {
        arreglo[i] = (float)rand() / (RAND_MAX / 100.0f);
    }

}
void muestraArregloFloat(int a[], int v)
{
    for(int i=0; i<v; i++)
    {
        if(i%7==0)
        {
            printf("\n");
        }
        printf("%5.2f",a[i]);
    }
}
float sumaFloat (float arreglo[], int validos)
{
    float suma = 0;

    for(int i = 0; i < validos; i++)
    {
        suma = suma + arreglo[i];
    }

    return suma;
}

int buscarCaracter (char arreglo[], int validos, char letra)
{
    int flag = 0;

    for(int i =0; i < validos; i++)

        if(arreglo [i] == letra)
        {
            flag = 1;
        }
    return flag;
}
int esCapicua (int arreglo[], int validos)
{
    int i = 0;
    int ultimo = validos - 1;
    int flag = 0;

    while(i <= ultimo && flag == 1)
    {
        if(arreglo [i] != arreglo[ultimo])
        {
            flag = 0;
        }
        i++;
        ultimo--;

    }
    return flag;
}
int posicionMenor (int arreglo[], int v,int inicio)
{
    int posMenor = -1;
if(v>0){
        posMenor = inicio;
}
    for(int i = inicio; i < v - 1; i++)
    {
        if(arreglo[i] < arreglo[posMenor])
        {
            posMenor = i;
        }
    }


    return posMenor;
}

void ordenaPorSeleccion(int a[], int v)
{
    int posMenor;
    for(int i = 0; i<v;i++)
    {
        posMenor=posicionMenor(a,v, i);
    intercambio(&a[i],&a[posMenor]);
    }


}
void intercambio (int *a,int *b)
{
int aux;
aux = *a;
*a = *b;
*b = aux;
}
int insertaOrd(int a[],int v, int dim, int dato){
int validos = -1;
int i = v-1;
if (v<dim){
    while(1>0 && dato <a[i])
    {
        a[i+1] = a[i];
        i--;
    }
    a[i+1] = dato;
    validos = v+1;
}
return validos;
}
void insertaOrd2(int a [],int v, int dato){
int i = v - 1;
while (i>=0 && dato > a[i]){
    a[i+1] = a[i];
    i--;
}
a[i+1] = dato;

}

void ordenaPorInsercion(int a[], int v){
for (int i=0;i<v-1;i++)
{
    insertaOrd2(a,i,a[i+1]);
}
}
