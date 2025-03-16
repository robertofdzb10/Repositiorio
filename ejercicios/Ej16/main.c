#include <stdio.h>
#include <stdlib.h>
#include "point/point.h"

int main(void){

    // Declaración de variables
    Point ***puntoTridimensional = (malloc(5 * sizeof(Point**)));
    if (puntoTridimensional == NULL){
        printf("Error en la gestión de la memoria dinámcia.");
        return 1;
    }


    for(int i = 0; i < 5; i++){
        Point **puntoBidimensional = (malloc(4 * sizeof(Point*)));
        if (puntoBidimensional == NULL){
            for (int i_1 = 0; i_1 < i; i_1++){
                free(puntoTridimensional[i_1]);
            }
            free(puntoTridimensional);
            printf("Error en la gestión de la memoria dinámcia.");
            return 1;
        }
        puntoTridimensional[i] = puntoBidimensional;
    }

    for(int i = 0; i < 5; i++){
        for(int e = 0; e < 4; e++){
            Point *puntoUnidimensional = malloc(3 * sizeof(Point));
            if (puntoUnidimensional == NULL){
                for (int i_1 = 0; i_1 < i; i_1++){ // Hasta la que falla
                    for (int i_2 = 0; i_2 < 4; i_2++){
                        free(puntoTridimensional[i_1][i_2]);
                    }
                    free(puntoTridimensional[i_1]);
                }
                for (int i_2 = 0; i_2 < e; i_2++){ // En la que falla
                    free(puntoTridimensional[i][i_2]);
                }
                for (int i_1 = i; i_1 < 5; i_1++){ // Las que faltan
                    free(puntoTridimensional[i_1]);
                }
                free(puntoTridimensional);
                printf("Error en la gestión de la memoria dinámcia.");
                return 1;
            }
            puntoTridimensional[i][e] = puntoUnidimensional;
        }
    }

    // Asignación de valores
    puntoTridimensional[2][3][1].x = 3;
    puntoTridimensional[2][3][1].y = 4;

    // Imprimimos los valores
    printf("Punto (%d,%d)", puntoTridimensional[2][3][1].x, puntoTridimensional[2][3][1].y);

    //Liberamos la memoria dinámica
    for (int i_1 = 0; i_1 < 5; i_1++){
        for (int i_2 = 0; i_2 < 4; i_2++){
            free(puntoTridimensional[i_1][i_2]);
        }
        free(puntoTridimensional[i_1]);
    }
    free(puntoTridimensional);

    return 0;
}