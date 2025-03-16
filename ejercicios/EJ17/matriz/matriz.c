#include <stdio.h>
#include "matriz.h"

void f1(int a[][], int X, int Y){
    a = a[X][Y];
    for (int i = 0; i < X; i++){
        for(int j = 0; j < Y; j++){
            printf("(%d)",a[i][j]);
        }
        printf("\n");
    }
}

/* Función que recibe un array de dos dimenisones, y el tamaño de cada una de estas
e imprime cada uno de los valores de la matriz */
void f3(int **c, int X, int Y){
    for (int i = 0; i < X; i++){
        for(int j = 0; j < Y; j++){
            printf("(%d)", c[i][j]);
        }
        printf("\n");
    }
}