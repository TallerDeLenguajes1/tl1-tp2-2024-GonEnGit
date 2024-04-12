#include <stdio.h>
#include <stdlib.h>

#define N 20

int main (int argc, char* argv[])
{
    // declaraciones
    int i;
    double vt[N], *pvt;       // primero declaras el arreglo, despues declaras el puntero

    // asignaciones
    pvt = vt;           // recien ahora podes asignar la direccion
    // pvt = &vt[0];    // equivale a la linea de arriba

    // pero pide usar notacion indexada osea *(pvt + 1) no pvt++
    for(int i = 0; i < N; i++)
    {
        *pvt = 1 + rand() % 100;        // genera un numero y lo asigna a la direccion de memoria del elemento

        printf("%f\n", *(pvt++));       // muestra lo que está en esa direccion
        /* De la teoria:
            *(pvt++) usa lo referenciado e incrementa la direccion
            osea primero usas el valor en vt[i] y despues moves
            la referencia a vt[i + 1]
        */
    }
        /* este era un error grave:
            usar *(pvt + 1) en printf para despues usar pvt++
            para moverte en el arreglo parece desfasar el indice que queres usar
            haciendo eso si bien el vector si se rellenaba con valores nuevos
            cuando los queres mostrar solo terminas mostrando ceros
        */
    return 0;
}
