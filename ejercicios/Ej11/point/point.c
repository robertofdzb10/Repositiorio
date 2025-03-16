#include <stdio.h>
#include "point.h"

/* Función que recibe un array de enteros y otro de puntos, de manera que multiplica cada punto por su equivaletne en el array, 
se le ha de indicar tambien el tamaño del array*/
void funcionEscalar(int *a1, Point **p1, int tamanio){

    // Recorremos todo el array de puntos, multiplicando cada punto por su equivalente
    for (int i = 0; i < tamanio; i++){
        p1[i]->x = p1[i]->x * a1[i];
        p1[i]->y = p1[i]->y * a1[i];
    }

}