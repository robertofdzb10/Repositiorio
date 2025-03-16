#ifndef FRACCION_H
#define FRACCION_H

// Declaración de estructuras
typedef struct{
    int numerador;
    int denominador;
} Fraccion;

// Declaración de funciones
Fraccion sumarFraciones(Fraccion a, Fraccion b);
Fraccion nultiplicarFracciones(Fraccion *a, Fraccion *b);

#endif