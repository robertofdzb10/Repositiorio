#include <stdio.h>
#include <stdlib.h>
#include "point/point.h"

int main(void){

    // Declaración de variables estáticas
    int a[3] = {2, 3, 4};

    // Declaramos primero el array contendor de puntos
    Point **puntos = malloc(3 * sizeof(Point*));

    // Declaramos cada punto del array
    for (int i = 0; i < 3; i++){
        puntos[i] = malloc(sizeof(Point));
    }

    // Asignamos los valores correspondientes a cada punto
    puntos[0]->x = 2;
    puntos[0]->y = 2;
    puntos[1]->x = 3;
    puntos[1]->y = 3;
    puntos[2]->x = 4;
    puntos[2]->y = 4;

    /************* 
    // Opción 2
    Point *puntos = malloc(3*sizeof(Point));
    puntos[0].x = 1;
    puntos[0].y = 1;
    *************/

    // Llamada a la función escalar
    funcionEscalar(a, puntos, 3);

    // Imprimimos el nuevo estado de nuestro Array
    printf("Punto 1 (%d,%d)\nPunto 2 (%d,%d)\nPunto 3 (%d,%d)\n",  puntos[0]->x,  puntos[0]->y, puntos[1]->x,  puntos[1]->y, puntos[2]->x,  puntos[2]->y);

    // Liberamos individualmente cada punto del array
    for (int i = 0; i < 3; i++){
        free(puntos[i]);
    }

    // Liberamos el array en su totalidad
    free(puntos);

    return 0;
}