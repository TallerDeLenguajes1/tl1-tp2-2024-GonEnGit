#include <stdio.h>
#include <stdlib.h>

#define N 20

int main (int argc, char* argv[])
{
    // declaraciones
    int i;
    double numero;
    double vt[N];       // primero declaras el arreglo
    double *pvt;        // despues declaras el puntero

    // asignaciones
    pvt = &vt[0];       // recien ahora podes asignar la direccion

    for(int i = 0; i < N; i++)
    {
        *pvt = 1 + rand() % 100;    // genera un numero y lo asigna a la direccion de memoria del elemento

        printf("%f\n", *pvt);       // muestra lo que está en esa direccion

        pvt++;                      // mueve el puntero a la direccion siguiente
    }
    
    return 0;
}
