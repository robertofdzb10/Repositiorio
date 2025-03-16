#ifndef NUMCOMPLEJO_H
#define NUMCOMPLEJO_H

// Declaración de estructuras
typedef struct{
    float r;
    float i;
} Complex;

// Declaración de funciones
void imprimirNumComplejo(Complex a);
Complex sumarNumsComplejos(Complex a, Complex b);
double moduloNumComplejo(Complex a);
long sizeComplejo(Complex a);

#endif