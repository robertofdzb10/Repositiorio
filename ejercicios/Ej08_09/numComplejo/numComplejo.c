#include <stdio.h>
#include <math.h>
#include "numComplejo.h"

/* Recibe un número complejo como parámetro e imprime su desglose (Parte real e imaginaria) por consola.*/
void imprimirNumComplejo(Complex a){
    printf("(%.2f, %.2f)\n",a.r, a.i);
}

/* Recibe dos números complejos, y devuelve otro, que representa la suma de los introducidos.*/
Complex sumarNumsComplejos(Complex a, Complex b){
    Complex resultado = {a.r + b.r, a.i + b.i};
    return resultado;
}

/* Recibe un número complejo como parámetro de entrada, y devuelve su módulo.*/
double moduloNumComplejo(Complex a){
    double resultado = sqrt((a.r*a.r) + (a.i*a.i));
    return resultado;
}

/* Recibe un número complejo como parámetro, y devuevle el número de bytes que ocupa.*/
long sizeComplejo(Complex a){
    long resultado = sizeof(a.i) + sizeof(a.r);
    return resultado;
}

/* Introduce dos números complejos como entrada, restandole al primero el segundo.*/
void restarNumsComplejos(Complex c1, Complex c2){
    c1.r = c1.r-c2.r;
    c1.i = c1.i-c2.i;
    printf("Resultado resta deseado:");
    imprimirNumComplejo(c1);
}

/* Introduce dos números complejos como entrada, restandole al primero el segundo.*/
void restarNumsComplejos_p(Complex *c1, Complex *c2){
    c1->r = c1->r-c2->r;
    c1->i = c1->i-c2->i;
}
