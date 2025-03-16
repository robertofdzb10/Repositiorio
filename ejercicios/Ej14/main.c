#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "argumentos/argumentos.h"

int main(void){

    // Declaración de variables
    char *cadena = malloc(8*sizeof(char));
    if (cadena == NULL){
        printf("Error en la declaracion de la memoria dinamica.");
        return 1;
    }
    
    // Asiggnamos un valor a la variable de prueba
    strcpy(cadena, "Secreto");

    // Llamamos a la función, y gestionamos la opción de error
    int depuracion = impirmeArgumentos(cadena);
    if (depuracion == 1){ 
        return 1; 
    } else { }

    return 0;
}