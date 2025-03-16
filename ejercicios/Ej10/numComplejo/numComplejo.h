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

// Nuevas funciones
void restarNumsComplejos(Complex c1, Complex c2);
void restarNumsComplejos_p(Complex *c1, Complex *c2);

#endif