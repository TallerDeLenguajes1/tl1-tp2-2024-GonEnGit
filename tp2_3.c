#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // constantes
    #define M 7     // filas
    #define N 5     // columnas

    // declaraciones
    int i,j;
    int numero;
    int mt[M][N];
    int *pmt;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            mt[i][j] = 1 + rand() % 100;   // hasta acá asignaste la matriz
        }
    }
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (*(mt + ((i * M) + j)) < 10)
            {
                printf("0%d " , *(mt + ((i * M) + j)));
            }
            else
            {
                printf("%d " , *(mt + ((i * M) + j)));
            }
        }
        printf("\n");
    }

    return 0;
}