#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}
void cargaMatrizRandom(int fil, int col, int m[fil][col])
{
    for (int i=0; i <fil;i++){
        for(int j;j<col;j++){
            m[i][j] = rand()%100;
        }
    }
}

void mostrarMatriz(int fil, int col, int m[fil][col]){
 for (int i=0; i <fil;i++){
        for(int j;j<col;j++){
                printf("%d",m[i][j]);
        }
 }
}
