# include <stdio.h>
# include <stdlib.h>
# include "fraccion/fraccion.h"

int main(void){

    // Declaración de variables
    int a = 33;

    // Declaración de arrays estáticos
    int arrayEnteros[5];

    // Declaración de estructuras
    Fraccion f1;
    f1.numerador = 1;
    f1.denominador = 2;

    // Declaración de punteros
    int *p1;
    int *parrayEnteros;
    int *pp1;
    Fraccion *pf2;
    Fraccion *parrayFracciones;
    Fraccion *f2 = malloc(sizeof(Fraccion));
    if (f2 == NULL){
        printf("Error en la asignacion de memoria dinamica.");
        return 1;
    }

    // Declaración de arrays dinámicos
    Fraccion *arrayFracciones = malloc(5*sizeof(Fraccion)); // Se puede acceder tal que así arrayFraccion[0].x
    if (arrayFracciones == NULL){
        printf("Error en la asignación de memoria dinámcia");
        return 1;
    }

    // Asociación de variables
    p1 = &a;
    printf("El contenido de a es %d\n", *p1);
    printf("El contenido de f2 por defecto es %d/%d\n", f2->numerador, f2->denominador);

    // Edición del valor de la fracción
    printf("Valor de la fraccion antes del cambio %d/%d\n", f1.numerador, f1.denominador);
    f1.numerador = 3;
    f1.denominador = 4;
    printf("Valor de la fraccion despues del cambio %d/%d\n", f1.numerador, f1.denominador);

    // Edición de la fracción con memoria dinámica
    printf("Valor de la fraccion antes del cambio %d/%d\n", f2->numerador, f2->denominador);
    f2->numerador = 3;
    f2->denominador = 4;
    printf("Valor de la fraccion despues del cambio %d/%d\n", f2->numerador, f2->denominador);

    // Edición del valor de a mediante punteros
    *p1 = 3;
    printf("Nuevo valor de a %d\n", a);

    // Sumamos fracciones
    Fraccion resultadoSuma = sumarFraciones(f1, *f2);
    printf("(%d/%d) + (%d/%d) = (%d/%d)\n", f1.numerador, f1.denominador, f2->numerador, f2->denominador, resultadoSuma.numerador, resultadoSuma.denominador);

    // Sumamos fracciones
    Fraccion resultadoMultiplicacion = nultiplicarFracciones(&f1, f2);
    printf("(%d/%d) * (%d/%d) = (%d/%d)\n", f1.numerador, f1.denominador, f2->numerador, f2->denominador, resultadoMultiplicacion.numerador, resultadoMultiplicacion.denominador);

    // Editamos el tercer valor del array dinámico y estático
    arrayEnteros[2] = 2;
    arrayFracciones[2].numerador = 2;
    arrayFracciones[2].denominador = 3;
    printf("Nuevo valor de la posicion 3 del array de enteros (%d) y del array de Fracciones (%d/%d)\n", arrayEnteros[2], arrayFracciones[2].numerador, arrayFracciones[2].denominador);

    // Modificación del segundo valor de los array dinámcios y estáticos con punteros
    parrayEnteros = arrayEnteros;
    parrayEnteros[1] = 1;
    parrayFracciones = arrayFracciones;
    parrayFracciones[1].numerador = 1;
    parrayFracciones[1].denominador = 2;
    printf("Nuevo valor de la posicion 3 del array de enteros (%d) y del array de Fracciones (%d/%d)\n", arrayEnteros[1], arrayFracciones[1].numerador, arrayFracciones[1].denominador);

    // Imprimimos por pantalla la dirección de memoria del ultimo entero del array estático
    printf("Direccion de memoria del ultimo entero del array estatico (%p)\n", &arrayEnteros[4]);

    // Cambiuo de valor de una variable a traves de un puntero que apunta a un puntero
    printf("Valor original de a: %d\n", a);
    pp1 = p1;
    *pp1 = 5;
    printf("Nuevo valor de la variable orignal, a traves de un puntero que apunta a un puntero: %d\n", a);

    // Cambiuo de valor de una estructura a traves de un puntero que apunta a un puntero
    printf("Valor original de la fraccion: (%d,%d)\n", f2->numerador, f2->denominador);
    pf2 = f2;
    pf2->numerador = 5;
    pf2->denominador = 5;    
    printf("Nuevo valor de la fraccion, a traves de un puntero que apunta a un puntero: (%d,%d)\n", f2->numerador, f2->denominador);
    
    // Liberación de memoria dinámica
    free(f2);
    free(arrayFracciones);

    return 0;

}
