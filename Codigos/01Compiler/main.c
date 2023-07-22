#include <stdio.h>
#include <math.h>
#include "aditional.h"

#define PI acos(-1)

int main(){
    printf("Hello World!\n");
    printf("El valor de PI es: %lf\n",PI);

    #ifdef AGE
        printf("La edad es: %d\n",AGE);
    #else
        printf("No Definido");
    #endif
    foo();
    return 0;
}
