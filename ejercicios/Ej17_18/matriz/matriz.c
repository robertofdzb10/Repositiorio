#include <stdio.h>
#include "matriz.h"

/* Función que recibe un array estático de dos dimenisones,
e imprime cada uno de los valores de la matriz */
void f1(int a[X][Y]){
    for (int i = 0; i < X; i++){
        for(int j = 0; j < Y; j++){
            printf("(%d)", a[i][j]);
        }
        printf("\n");
    }
}
    
/* Función que recibe un array híbrido de dos dimenisones,
e imprime cada uno de los valores de la matriz */
void f2(int *b[X]){
    for (int i = 0; i < X; i++){
        for(int j = 0; j < Y; j++){
            printf("(%d)", b[i][j]);
        }
        printf("\n");
    }
}

/* Función que recibe un array de dos dimenisones, y el tamaño de cada una de estas
e imprime cada uno de los valores de la matriz */
void f3(int **c){
    for (int i = 0; i < X; i++){
        for(int j = 0; j < Y; j++){
            printf("(%d)", c[i][j]);
        }
        printf("\n");
    }
}

void f4(int (*d)[Y]){
    for (int i = 0; i < X; i++){
        for(int j = 0; j < Y; j++){
            printf("(%d)", d[i][j]);
        }
        printf("\n");
    }
}
