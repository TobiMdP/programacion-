#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define ESC 27
#define DIM 9
void cargaMatrizRandom(int fil, int col, int m[fil][col]);
void mostrarMatriz(int fil, int col, int m[fil][col]);
void muestraNombres(int dim, char n[dim][30], int v);
int cargaNombres(int dim, char n[dim][30]);
int SumaMatriz(int fil, int col, int m[fil][col]);
int main()
{
    char opcion;
    srand (time(NULL));
    int fil = 3;
    int col = 3;
    int matriz[fil][col];
    int vNumeros = 0;


    char nombres[DIM][30];
    int vNombres = 0;

    do
    {
        menuOpciones();
        printf("\nIngrese el numero del ejercicio al que quiere acceder\n");
        opcion = getch();

        switch(opcion)
        {

        case '1':
            printf("\n \t\t\t <<<<< Carga Matriz Random >>>>>\n ");
            cargaMatrizRandom(fil,col,matriz);

            break;
        case '2':
            printf("\n \t\t\t <<<<< Muestra matriz >>>>>\n ");
            mostrarMatriz(fil,col,matriz);
            break;
        case '3':
            printf("\n \t\t\t <<<<< Carga Nombres >>>>> \n");
            vNombres = cargaNombres(DIM,nombres);
            strcpy(nombres[vNombres],"Juanito");
            vNombres++;
            break;
        case '4':
            printf("\n \t\t\t <<<<< Muestra Nombres >>>>> \n");
            muestraNombres(DIM,nombres,vNombres);
            break;
        case '5':
            printf("\n \t\t\t <<<<< Suma matriz >>>>> \n");
            printf("La suma de los elementos de la matriz es: %d \n",SumaMatriz(fil,col, matriz));
            break;
        }
        system("pause");
        system("cls");

    }
    while (opcion != ESC);



    return 0;
}


void cargaMatrizRandom(int fil, int col, int m[fil][col])
{
    for (int i=0; i <fil; i++)
    {
        for(int j = 0; j<col; j++)
        {
            m[i][j] = rand() % 100;
        }
    }
}

void mostrarMatriz(int fil, int col, int m[fil][col])
{
    for (int i=0; i <fil; i++)
    {
        for(int j = 0; j<col; j++)
        {
            printf("%d |",m[i][j]);
        }
        printf("\n");
    }
}

void menuOpciones()
{
    printf("\n \t\t\t <<<<< Menu de opciones >>>>> ");
    printf("\n 1. <<<<< Carga matriz random >>>>> ");
    printf("\n 2. <<<<< Muestra matriz >>>>>");
    printf("\n 3. <<<<< Carga Nombres >>>>>");
    printf("\n 4. <<<<< Muestra Nombres >>>>>");
    printf("\n 5. <<<<< Suma matriz >>>>>");
    printf("\n 6. ");
}
int cargaNombres(int dim,char n[DIM][30])
{
    int i = 0;
    char opcion = 0;
    while(i<dim && opcion != ESC)
    {
        printf("\ningrese un nombre");
        gets(n[i]);
        i++;
        printf("\n\n ESC para salir, cualquier tecla para continuar");
        opcion = getch();
        system("cls");
    }
    return i;
}
void muestraNombres(int dim, char n[dim][30], int v)
{
    printf("\n Mostrando nombres");
    for (int i = 0; i<v; i++)
    {
        printf("\n %s\n",n[i]);


    }

}
int SumaMatriz(int fil, int col, int m[fil][col])
{
    int suma = 0;

    for (int i=0; i <fil; i++)
    {
        for(int j=0; j<col; j++)
        {
            suma += m[i][j];
        }
    }

    return suma;
}
