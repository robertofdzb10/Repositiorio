#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadena/cadena.h"

int main(void){

    // Declaración de arrays de caracteres
    char* aC1 = malloc(5 * sizeof(char));
    if (aC1 == NULL){
        printf("Error en la gestión de la memoria dinámcia.");
        return 1;
    }
    char* aC2 = malloc(5 * sizeof(char));
    if (aC2 == NULL){
        printf("Error en la gestión de la memoria dinámcia.");
        free(aC1);
        return 1;
    }
    char* aC4 = malloc(10 * sizeof(char));
    if (aC4 == NULL){
        printf("Error en la gestión de la memoria dinámcia.");
        free(aC1);
        free(aC2);
        return 1;
    };

    // Asignación de valores a los arrays
    strcpy(aC1, "Hola");
    strcpy(aC4, "Adios");

    // Probamos la función para obtener el tamaño de un array de caracteres
    printf("El size del array es: %d\n", tamanioArrayCaracteres(aC1));

    // Probamos la función para imprimir el array de caracteres
    printf("El array de caracteres es: ");
    imprimirArrayCaracteres(aC1);

    // Probamos la función para clonar arrays de carácteres
    char* aC3 = clonarArrayCaracteres(aC1);
    printf("El array de caracteres clonado es:");
    imprimirArrayCaracteres(aC3);

    // Probamos la función para concatenar arrays de carácteres
    concatenarArrayCaracteres(aC4, aC1); //
    printf("El array de caracteres concatenado es:");
    imprimirArrayCaracteres(aC4);

    // Probamos la función para copiar arrays de carácteres
    printf("El array de caracteres antes de la copia es: ");
    imprimirArrayCaracteres(aC2);
    copiarArrayCaracteres(aC2, aC1);
    printf("El array de caracteres despues de la copia es: ");
    imprimirArrayCaracteres(aC2);

    // Liberamos la memoria dinámica
    free(aC1);
    free(aC2);
    free(aC3);
    free(aC4);

    return 0;
}