#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "argumentos.h"

/* 
Función que recibe una cadena de carácteres e imprime por pantalla:
    - Número de carácteres
    - Cada uno de los carácteres
Devuelve 1 en caso de error, de lo contrario devolverá 0
*/
int impirmeArgumentos(char* a){

    // Imprimimos el número de carácteres de entrada
    int numArgumentos = strlen(a);
    printf("Numero de argumentos recibidos: %d\n", numArgumentos);

    // DEclaramos la cadena auxiliar para imprimir
    char *salida = malloc( (numArgumentos * sizeof(char)) + 1);
    if (salida == NULL){
        printf("Error en la declaracion de la memoria dinamica.");
        return 1;
    }

    // Copiamos el valor de la cadena orginal e imprimimos
    strcpy(salida, a);
    printf("La cadena introducida es: %s\n", salida);

    // Comparamos si la cadena introducida es secreta
    int resultado = strcmp(salida, "Secreto\0");
    if (resultado == 0){
        printf("Has descubierto un secreto!\n");
    } else {}

    // Liberamos memoria dinámica
    free(salida);

    return 0;
}