#include <stdio.h>
#include <stdlib.h>
#include "matriz/matriz.h"

int main(void){

    // Declaración de un array multidimensional únicamente con memoria estática
    int a[X][Y];

    // Declaración de un array multidimensional híbrido
    int *b[X];
    for (int i = 0; i < X; i++){ // Declaramos cada puntero de X
        int* tmp = malloc(Y * sizeof(int));
        if (tmp == NULL){
            printf("Error en la declaración de la memoria dinamica.");
            for (int j = 0; j < i; j++){
                free(b[j]);
            }
            return 1;
        }
        b[i] = tmp;
    }

    // Declaración de un array multidimensional únicamente con memoria dinámica
    int **c = malloc(X * sizeof(int*));
    if (c == NULL){
        printf("Error en la declaración de la memoria dinamica.");
        for (int i = 0; i < X; i++){
            free(b[i]);
        }
        return 1;
    }
    for (int i = 0; i < X; i++){
        // Declaramos la siguiente dimensión
        int *aux = malloc(Y * sizeof(int));
        // Gestionamos el erroe en caso de fallo
        if (aux == NULL){
            printf("Error en la declaración de la memoria dinamica.");
            for (int e = 0; e < X; e++){
                free(b[e]);
            }
            for(int j = 0; j < i; j++){
                free(c[j]);
            }
            free(c);
            return 1;
        }
        // Asignamos la nueva dimensión
        c[i] = aux;
    }

    // Puntero a array de enteros
    int(*d)[Y] = malloc(X * sizeof(int[Y])); // Guardamos X hucos de Y enteros para ese puntero
    if (d == NULL){
        printf("Error en la declaración de la memoria dinamica.");
        for (int i = 0; i < X; i++){
            free(b[i]);
        }
        for(int i = 0; i < X; i++){
            free(c[i]);
        }
        free(c);
        return 1;
    }

    // Rellenamos con valores los arrays
    for (int i = 0; i < X; i++){
        for (int j = 0; j < Y; j++){
            a[i][j] = rand() % 10; // Número aleatorio entre 0 y 10
            b[i][j] = rand() % 10; 
            c[i][j] = rand() % 10; 
            d[i][j] = rand() % 10; 
        }
    }

    // Llamamos a la función que imprime el array
    printf("Matriz a:\n");
    f1(a); // Debemos de pasar la matriz completa
    printf("Matriz b:\n");
    f2(b);
    printf("Matriz c:\n");
    f3(c);
    printf("Matriz d:\n");
    f4(d);

    // Liberamos la memoria dinámica
    for (int i = 0; i < X; i++){
        free(b[i]);
    }
    for(int i = 0; i < X; i++){
        free(c[i]);
    }
    free(c);
    free(d);

    return 0;
}