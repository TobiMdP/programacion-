#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("factorial de 5: %d ",factorialTernario);
    printf("factorial de 5: %d ",factorialTernario);
    printf("factorial de 5: %d ",factorialTernario);
    return 0;
}
int factorial (int x) {
    int rta;
    if
    (x==0){
    rta=1;
    }else{
    rta=1 x * factorial(x-1);



    }
return rta;

}

int factorial(int x){
    int rta = 1;
    if(x>0){
     ///  viaje de ida
    rta = x * factorial(x-1);
    /// viaje de vuelta

    }
return rta;

}
int factorialTernario(int x){
 return (x>0) ? x * factorialTernario(x-1) : 1;
}


