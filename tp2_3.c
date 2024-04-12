#include <stdio.h>
#include <stdlib.h>

#define N 5    // numero de filas
#define M 7    // numero de columans

int main(int argc, char *argv[])
{
// podrias hacer esta matriz de 2 formas distintas:
//    - con forma de matriz:
//        int matriz[N][M], *pmatriz;
//        pmatriz = &matriz[0][0];

//  - o con un vector en lugar de una matriz:
    int matriz[35], *pmatriz;
    pmatriz = matriz;

    printf("\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            *(pmatriz + i * M + j) = 1 + rand() % 100;

            if (*(pmatriz + i * M + j) < 10)
            {
                printf("0%i ", *(pmatriz + i * M + j));
            }
            else
            {
                printf("%i ", *(pmatriz + i * M + j));
            }
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}