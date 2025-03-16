#include <stdio.h>
#include <stdlib.h>
#include "fraccion.h"

/* Función que recibe dos fracciones y efectua su suma,
devolviendo el resultado en una nueva Fraccion */
Fraccion sumarFraciones(Fraccion a, Fraccion b){
    Fraccion resultado;
    if (a.denominador == b.denominador){
        resultado.numerador = a.numerador + b.numerador;
        resultado.denominador = a.denominador;
    } else {
        resultado.numerador = (a.numerador*b.denominador) + (b.numerador*a.denominador);
        resultado.denominador = a.denominador * b.denominador;
    }
    return resultado;
}

/* Función que recibe el puntero dos fracciones y efectua una multiplicación
devolviendo el resultado en una nueva Fraccion*/
Fraccion nultiplicarFracciones(Fraccion *a, Fraccion *b){
    Fraccion resultado = {(a->numerador * b->numerador),(a->denominador * b->denominador)};
    return resultado;
}