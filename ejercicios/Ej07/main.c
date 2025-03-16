#include <stdio.h>
#include "funMat/funMat.h"

int main(void){

    // Declaración de variables
    Punto punto = {4,5};
    int numero = 10;

    // Imprimos la situación original
    printf("Punto original (%d, %d), con un escalado '%d'\n", punto.X, punto.Y, numero);

    // Llamada a la función
    funcionEscalar(&punto, numero);

    // Imprimimos el resultado
    printf("Nuevo punto (%d, %d).", punto.X, punto.Y);

    return 0;
}