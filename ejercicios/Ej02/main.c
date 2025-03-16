#include <stdio.h>
#include "operaciones/operaciones.h"

int main(void){

    // Declaración de varaibales para los operadores
    double a_d = 5;
    double b_d = 3;
    int a_i = 5;
    int b_i = 3;

    // Declaración de variables para el resultado
    double suma;
    double resta;
    int multiplicacion;
    int potencia;

    // Llamada a las funciones
    suma = sumar(a_d, b_d);
    resta = restar(a_d, b_d);
    multiplicacion = multiplicar(a_i, b_i);
    potencia = elevarNumero(a_i, b_i);

    // Mostramos los resultados
    printf("%.0lf + %.0lf = %.0lf\n", a_d, b_d, suma); // .0 para mostrar 0 decimales
    printf("%.0lf - %.0lf = %.0lf\n", a_d, b_d, resta);
    printf("%d x %d = %d\n", a_i, b_i, multiplicacion);
    printf("%d ^ %d = %d\n", a_i, b_i, potencia);

    return 0;
}