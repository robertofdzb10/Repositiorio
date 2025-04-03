#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cadena/cadena.h"

/* Permite crear una nueva estructura Reflejo a partir 
de la cadena de caracteres pasada como parámetro.*/
Reflejo crearEspejo(char *str){

    // Variables auxiliares
    int tamanyoCadena = strlen(str);
    char cadena_aux[tamanyoCadena + 1]; // Añadimos uno para incluir la cadena vacia

    // Variable para el resultado
    Reflejo resultado;
    resultado.cadenaOriginal = malloc( (tamanyoCadena + 1) * sizeof(char)); // Caracter fin de string
    if (resultado.cadenaOriginal == NULL){
        printf("Error en la gestion de la memoria dinamica");
        resultado.cadenaOriginal = NULL;
        return resultado;
    }
    resultado.cadenaReflejada = malloc( (tamanyoCadena + 1) * sizeof(char)); // Caracter fin de string
    if (resultado.cadenaReflejada == NULL){
        printf("Error en la gestion de la memoria dinamica");
        free(resultado.cadenaOriginal);
        resultado.cadenaReflejada = NULL;
        return resultado;
    }

    // Obtenemos el String invertido
    for (int i = 0; i < tamanyoCadena; i++){
        cadena_aux[tamanyoCadena-i-1] = str[i];
    }
    cadena_aux[tamanyoCadena] = '\0'; // Añadimos al final el indicador de fin de String

    // Almacenamos los campos en la varible de salida
    strcpy(resultado.cadenaOriginal, str);
    strcpy(resultado.cadenaReflejada, cadena_aux);

    // Devolvemos la estructura
    return resultado;

}

/* Libera la memoria dinámica de una estructura Reflejo */
void liberarEspejo(Reflejo *r){
    free(r->cadenaOriginal);
    free(r->cadenaReflejada);
}