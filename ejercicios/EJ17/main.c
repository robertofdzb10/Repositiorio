#include <stdio.h>
#include <stdlib.h>
#include "matriz/matriz.h"

int main(void){

    // Declaración de un array multidimensional únicamente con memoria estática
    int a[X][Y];

    // Declaración de un array multidimensional híbrido

    // Declaración de un array multidimensional únicamente con memoria dinámica
    int **c = malloc(X * sizeof(int*));
    if (c == NULL){
        printf("Error en la declaración de la memoria dinamica.");
        return 1;
    }
    for (int i = 0; i < X; i++){
        // Declaramos la siguiente dimensión
        int *b = malloc(Y * sizeof(int));
        // Gestionamos el erroe en caso de fallo
        if (b == NULL){
            for(int j = 0; j < i; j++){
                free(c[j]);
            }
            free(c);
            return 1;
        }
        // Asignamos la nueva dimensión
        c[i] = b;
    }

    // Rellenamos con valores los arrays
    for (int i = 0; i < X; i++){
        for (int j = 0; j < Y; j++){
            a[i][j] = rand() % 10; // Número aleatorio entre 0 y 10
            c[i][j] = rand() % 10; 
        }
    }

    // Llamamos a la función que imprime el array
    f1(a[X][Y], X, Y);
    //f3(c, X, Y);

    // Liberamos la memoria dinámica
    for(int i = 0; i < X; i++){
        free(c[i]);
    }
    free(c);

    return 0;
}