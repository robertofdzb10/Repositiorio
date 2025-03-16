#include <stdio.h>
#include <stdlib.h>
#include "numComplejo/numComplejo.h"

int main(void){

    // Declaración de números complejos
    Complex num_1 = {2,3};

    // Declarammos un número complejo mediante punteros con memoria dinámica
    Complex *num_2 = malloc(sizeof(Complex));
    num_2->r=4;
    num_2->i=3;

    // Llamada a las funciones para sacar los operandos
    printf("Operandos:\n");
    printf("- Operando 1: ");
    imprimirNumComplejo(num_1);
    printf("- Operando 2: ");
    imprimirNumComplejo(*num_2);
    printf("\n");

    // Llamada a la función para calcular la suma de los operandos
    printf("Resultado Suma: ");
    Complex resultado  = sumarNumsComplejos(num_1, *num_2);
    imprimirNumComplejo(resultado);

    // Llamada a la función para calcular el módulo del nuevo número complejo
    printf("- Modulo: %.2lf.",moduloNumComplejo(resultado));
    printf("\n");

    // LLamada a la función para cálcular el tamaño en memoria de un número complejo
    printf("- Size en memoria: %lu bytes", sizeComplejo(resultado));
    printf("\n\n");

    // Llamada a la función para calcular la resta de los operandos
    restarNumsComplejos(num_1, *num_2); // Como vemos, no cambia el valor de num_1, ya que no estamos operando sobre el mismo, sino que lo estamos haciendo sobre una copia
    printf("Resultado Resta: ");
    imprimirNumComplejo(num_1);

    // Llamada a la función para calcular la resta de los operandos
    printf("Resultado Resta (Real): ");
    restarNumsComplejos_p(&num_1, num_2);
    imprimirNumComplejo(num_1);

    // Libermaos la memoria dinámica
    free(num_2);


    return 0;
}
