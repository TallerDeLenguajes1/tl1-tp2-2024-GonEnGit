#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* Estructuras */
typedef struct{
    int velocidad;
    int anio;
    int cantidad;
    char *tipo_cpu;
}caracteristicas;


/* Prototipos */
void mostrarLista(caracteristicas *lista);
void masAntiguo(caracteristicas *lista);
void masRapido(caracteristicas *lista);

int main(int argc, char *argv[])
{
    // esta linea está para que rand() cambie segun el tiempo
    // no usarla como hace el profesor si bien genera numeros aleatorios
    // no cambia por mucho que ejecutes el codigo
    srand(time(NULL));

    // declaraciones
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    int fechas[9] = {2015, 2016, 2017, 2018, 2019, 2020, 2021, 2022, 2023}, aux = 9;
    caracteristicas lista[5];

    for (int i = 0; i < 5; i++)
    {
        lista[i].velocidad = (rand() % 3) + 1;          // medio que no podes tener una CPU de 0 hz...
        lista[i].anio = *(fechas + (rand() % aux));     // desde fechas[0] hasta fechas[8]
        lista[i].cantidad = (rand() % 8) + 1;           // y dificil que no tenga ningun nucleo tampoco...
        lista[i].tipo_cpu = *(tipos + (rand() % 6));    // desde tipos[0][10] hasta tipos[5][10]
    }

    mostrarLista(lista);
    masAntiguo(lista);
    masRapido(lista);

    return 0;
}

void mostrarLista(caracteristicas *lista)
{
    for (int i = 0; i < 5; i++)
    {
        printf("\n  /----Procesador %d----/\n\n", i + 1);
        printf("Fabricado en: %d\n", (*(lista + i)).anio);
        printf("Velocidad de procesamiento: %d GHz\n", (*(lista + i)).velocidad);
        printf("Tipo de procesador: %s\n", (*(lista + i)).tipo_cpu);
        printf("Cantidad de nucleos: %d\n", (*(lista + i)).cantidad);
    }
}

void masAntiguo(caracteristicas *lista)
{
    int menor = 2025;                               // ningun año pasa de 2025
    int auxIndice = 0, auxContador = 0;
    for (int i = 0; i < 5; i++)
    {
        // usabas (*lista++), esto mueve el puntero, 
        // efectivamente estas cambiando la lista
        // y por eso, no podes usar ninguna forma de 'puntero++'
        if ((*(lista + i)).anio < menor)
        {
            // cambiando la direccion del puntero,
            // esta linea asigna valores que no existen
            menor = (*(lista + i)).anio;
        }
    }

    // si queres controlar los repetidos, 
    //no te queda otra que un bucle especificamente para eso
    for (int i = 0; i < 5; i++)
    {
        if ((*(lista + i)).anio == menor)
        {
            auxContador++;
        }
    }

    // imprimis el o los mas antiguos
    printf("\n  /------Los mas antiguos son------/\n");
    while (auxContador > 0)
    {
        // si usas un for en esta parte no tendrias como pararlo
        if ((*(lista + auxIndice)).anio == menor)
        {
            printf("\nFabricado en: %d\n", (*(lista + auxIndice)).anio);
            printf("Velocidad de procesamiento: %d GHz\n", (*(lista + auxIndice)).velocidad);
            printf("Tipo de procesador: %s\n", (*(lista + auxIndice)).tipo_cpu);
            printf("Cantidad de nucleos: %d\n", (*(lista + auxIndice)).cantidad);
            auxContador--;
        }
        auxIndice++;
    }
}

// esta funcion va a ser igual que masAntiguo
// pero en lugar de comparar año comparas velocidad
void masRapido(caracteristicas *lista)
{
    int mayor = 0;                               // el mas lento puede ser de 1GHz
    int auxIndice = 0, auxContador = 0;
    for (int i = 0; i < 5; i++)
    {
        if ((*(lista + i)).velocidad > mayor)
        {
            mayor = (*(lista + i)).velocidad;
        }
    }

    // controlar repetidos
    for (int i = 0; i < 5; i++)
    {
        if ((*(lista + i)).velocidad == mayor)
        {
            auxContador++;
        }
    }

    // imprimir
    printf("\n  /------Los mas rapidos son------/\n");
    while (auxContador > 0)
    {
        // si usas un for en esta parte no tendrias como pararlo
        if ((*(lista + auxIndice)).velocidad == mayor)
        {
            printf("\nFabricado en: %d\n", (*(lista + auxIndice)).anio);
            printf("Velocidad de procesamiento: %d GHz\n", (*(lista + auxIndice)).velocidad);
            printf("Tipo de procesador: %s\n", (*(lista + auxIndice)).tipo_cpu);
            printf("Cantidad de nucleos: %d\n", (*(lista + auxIndice)).cantidad);
            auxContador--;
        }
        auxIndice++;
    }
}
