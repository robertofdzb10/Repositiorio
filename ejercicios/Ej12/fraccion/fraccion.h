#ifndef FRACCION_H_
#define FRACCION_H_

// Declaración de estructuras
typedef struct{
    int numerador;
    int denominador;
} Fraccion;

// Declaración de funciones
Fraccion sumarFraciones(Fraccion a, Fraccion b);
Fraccion nultiplicarFracciones(Fraccion *a, Fraccion *b);

#endif