#include <stdbool.h>
#include "caracter.h"

/* Función que devuelve true si se le introduce una letra mayúscula, en caso contrario devolvera false*/
bool isUpperCase(char c){
    bool resultado = false;
    // Comprobamos que sea una letra mayuscula
    if (c >='A' && c <='Z'){
        resultado = true;
    }
    return resultado;
}

/* Función que devuelve true si se le introduce una letra minúscula, en caso contrario devolvera false*/
bool isLowerCase(char c){
    bool resultado = false;
    // Comprobamos que sea una letra minúscula
    if (c >= 'a' && c <='z'){
        resultado = true;
    }
    return resultado;
}

/* Función que devuelve true si se le introduce una letra, en caso contrario devolvera false*/
bool isLetter(char c){
    bool resultado = false;
    if (isUpperCase(c) || isLowerCase(c)){
        resultado = true;
    }
    return resultado;
}

/* Función que devuelve true si se le introduce un número, en caso contrario devolvera false*/
bool isNumber(char c){
    bool resultado = false;
    if (c >= '0' && c <= '9'){
        resultado = true;
    }
    return resultado;
}

/* Función que devuelve true si se le introduce un enter, en caso contrario devolvera false*/
bool isEnter(int c){
    bool resultado = false;
    if (c == '\n'){
        resultado = true;
    }
    return resultado;
}

/* Función que devuelve true si se le introduce un carácter disntinto de número y una letra, en caso contrario devolvera false*/
bool isOtherCharacter(char c){
    bool resultado = false;
    if (isLetter(c) == false && isNumber(c) == false && isEnter(c) == false){
        resultado = true;
    }
    return resultado;
}

/* Función que convierte la letra que se le introduce a su equivalente mayúscula, en el caso de no poder convertir la letra a mayúscula, devuelve un -1*/
char toUpperCase(char c){
    char resultado = 0;
    if (isLowerCase(c)){
        resultado = c - 32;
    } else{
        resultado = -1;
    }
    return resultado;
}

/* Función que convierte la letra que se le introduce a su equivalente minúscula, en el caso de no poder convertir la letra a minúscula, devuelve un -1*/
int toLowerCase(int c){
    int resultado = 0;
    if (isUpperCase(c)){
        resultado = c + 32;
    } else {
        resultado = -1;
    }
    return resultado;
}
