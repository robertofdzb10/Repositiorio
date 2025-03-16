#include "operaciones.h"

double sumar(double a, double b){
    return a + b;
}

double restar(double a, double b){
    return a - b;
}

int multiplicar(int a, int b){
    int resultado = 0;
    for (int i = 0; i < b; i++){
        resultado = resultado + a;
    }
    return resultado;
}

int elevarNumero(int a, int b){
    int resultado = 1;
    for(int i = 0; i < b; i++){
        resultado = multiplicar(resultado, a); 
    }
    return resultado;
}