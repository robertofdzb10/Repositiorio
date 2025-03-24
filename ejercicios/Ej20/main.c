#include <stdio.h>
#include <stdlib.h>
#include "point/point.h"

int main(void){

    // Declaración de estructuras
    Point *arrayPuntosEs = malloc(TAMANIO * sizeof(Point));
    if (arrayPuntosEs == NULL){
        printf("Error en la declaracion de la memeoria dinamica.");
        return 1;
    }
    Point *arrayPuntosLe = malloc(TAMANIO * sizeof(Point));
    if (arrayPuntosLe == NULL){
        printf("Error en la declaracion de la memeoria dinamica.");
        return 1;
    }

    // Declaramos el array
    for (int i = 0; i < TAMANIO; i++){
        arrayPuntosEs[i].X = i;
        arrayPuntosEs[i].Y = i;
    }

    // Declaración del archivo en modo escritura
    FILE *archivo = fopen("datos.txt", "wb");
    if (archivo == NULL){
        printf("Error en la gestion de archivos.");
        return 1;
    }

    // Escribimos los puntos en binario en el archivo
    fwrite(arrayPuntosEs, sizeof(Point), TAMANIO, archivo);

    // Cerramos el archivo 
    fclose(archivo);

    // Declaración del archivo en modo lectura
    archivo = fopen("datos.txt", "rb");
    if (archivo == NULL){
        printf("Error en la gestion de archivos.");
        return 1;
    }

    // Lectura del archivo en binario
    fread(arrayPuntosLe, sizeof(Point), TAMANIO, archivo);

    // Imprimimos el contenido del archivo por consola
    for (int i = 0; i < TAMANIO; i++){
        printf("Punto %d (%.2f,%.2f)\n", i, arrayPuntosLe[i].X, arrayPuntosLe[i].Y);
    }

    // Cerramos el archivo
    fclose(archivo);

    // Liberamos la memoria dinamica
    free(arrayPuntosEs);
    free(arrayPuntosLe);

    return 0;
}