#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadena/cadena.h"

#define NUMERO_CADENAS 1

int main(){

    // Declaración del array de reflejos
    Reflejo *reflejo = malloc(NUMERO_CADENAS * sizeof(Reflejo));
    if (reflejo == NULL){
        printf("Error en la gestion de la memoria dinamica");
        return 1;
    }

    // Variables auxiliares
    char **cadena_t = malloc(NUMERO_CADENAS * sizeof(char*));
    if (cadena_t == NULL){
        printf("Error en la gestion de la memoria dinamica");
        free(reflejo);
        return 1;
    }

    // Creamos y almacenamos todos los reflejos
    for (int i = 0; i < NUMERO_CADENAS; i++){

        // Asignamos un espacio muy grande para lectura
        cadena_t[i] = malloc(100 * sizeof(char));
        if (cadena_t[i] == NULL){
            printf("Error en la gestion de la memoria dinamica");
            for (int e = 0; e < i; e++){
                free(cadena_t[e]);
            }
            free(cadena_t);
            free(reflejo);
            return 1;
        }

        // Lectura de cadena
        printf("Escriba una cadena: ");
        scanf("%s", cadena_t[i]);

        // Creación de reflejo
        reflejo[i] = crearEspejo(cadena_t[i]);
        if (reflejo[i].cadenaOriginal == NULL || reflejo[i].cadenaReflejada == NULL){
            for (int e = 0; e < i; e++){
                free(cadena_t[e]);
            }
            free(cadena_t);
            free(reflejo);
            return 1;
        }

    }

    // Declaración y apertura del fichero de texto
    FILE* fichero = fopen("SALIDA.TXT", "w");
    if (fichero == NULL){
        printf("Error en la gestión de archivos.");
        return 1;
    }

    // Escribimos en un fichero de texto
    for (int i = 0; i < NUMERO_CADENAS; i++){
        fprintf(fichero, "%s%s\n", reflejo[i].cadenaReflejada, reflejo[i].cadenaOriginal);
    }

    // Cerramos el fichero
    fclose(fichero);

    // Liberamos la memoria dinámica
    for (int i = 0; i < NUMERO_CADENAS; i++){
        free(cadena_t[i]);
        liberarEspejo(&reflejo[i]);
    }
    free(cadena_t);

    return 0;
}