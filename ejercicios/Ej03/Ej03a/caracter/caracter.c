#include "caracter.h"

char upper(char a){
    char resultado;

    // Comprobamos que sea una letra minúscula
    if (a >= 'a' && a <= 'z'){
        resultado = a - 32;
    // Sino lo es, devolvemos el caracter de entrada sin modificar
    } else {
        resultado = a;
    }

    return resultado;
}