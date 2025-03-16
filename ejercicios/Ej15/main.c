#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "asignatura/asignatura.h"

int main(void){

    // Declaración de varaibles con memoria dinamica
    Asignatura *almacenAsignaturas = malloc(5 * sizeof(Asignatura));
    if (almacenAsignaturas == NULL){
        printf("Error en la asignación de memoria dinamica.");
        return 1;
    }

    char* entrada = malloc(sizeof(char) + 1);
    if (entrada == NULL){
        printf("Error en la asignación de memoria dinamica.");
        free(almacenAsignaturas);
        return 1;
    }
    
    char* nombreAux = malloc(10 * sizeof(char*)); // El valor 10 es para este
    if (nombreAux == NULL){
        printf("Error en la gestión de la memoria dinamica.");
        free(almacenAsignaturas);
        free(entrada);
    }

    // Variables auxiliares
    int indiceAlmacen = 0;
    float media = 0;   

    // Menú del programa
    imprimirMenu();

    // Almacenamos la entrada del usuario
    scanf("%s", entrada);

    // Búcle principal de programa
    while(strcmp(entrada, "q\0")){

        if ( !strcmp(entrada, "1\0") && indiceAlmacen < 5){

            // Gestión del nombre de asignatura
            printf("Introduzca el nombre de la asignatrua: ");
            scanf("%s", nombreAux);
            almacenAsignaturas[indiceAlmacen].nombre = malloc(strlen(nombreAux) + 1);
            strcpy(almacenAsignaturas[indiceAlmacen].nombre, nombreAux);

            // Introducimos una asignatura nueva
            printf("Introduzca un id para la asignatura: ");
            scanf("%d", &almacenAsignaturas[indiceAlmacen].id);
            printf("Introduzca la nota obtenida en la asignatura: ");
            scanf("%f", &almacenAsignaturas[indiceAlmacen].nota);

            // Le mostramos al usuario la asignatura que cre
            printf("Ha creado la asignatura %s con id %d y nota %.2f.\n", almacenAsignaturas[indiceAlmacen].nombre, almacenAsignaturas[indiceAlmacen].id, almacenAsignaturas[indiceAlmacen].nota);

            // Aumentamos el indice del alamcen
            indiceAlmacen++;

        } else if( !strcmp(entrada, "1\0") && (indiceAlmacen == 5 || indiceAlmacen > 5)){
            // En el caso de haber superardo el almacenamiento máximo de asignaturas se lo indicamos al usuario
            printf("Ha introducido el numero maximo de asignaturas que soporta el sistema.\n");

        } else if ( !strcmp(entrada, "2\0")){
            // Mostramos todas las asignaturas almacenadas
            if (indiceAlmacen == 0){
                printf("Listado vacio.\n");
            } else {
                for(int i = 0; i < indiceAlmacen; i++){
                    printf("Asignatura %s con id %d, y nota %.2f\n", almacenAsignaturas[i].nombre, almacenAsignaturas[i].id, almacenAsignaturas[i].nota);
                }
            }

        } else if ( !strcmp(entrada, "3\0")){
            // Calculamos la media de todas las asignaturas introducidas hasta el momento
            if (indiceAlmacen == 0){
                printf("Listado vacio.\n");
            } else {
                media = 0;
                for(int i = 0; i < indiceAlmacen; i++){
                    media = media + almacenAsignaturas[i].nota;
                }
                media = media / indiceAlmacen;
                printf("La media actual es: %.2f\n", media);
            }

        } else {
            printf("Menu incorrecto.\n");
        }

        // Imprimimos el menú
        printf("\n");
        imprimirMenu();

        // Almacenamos la nueva entrada del usuario
        scanf("%s", entrada);
        
    }
    
    // Liberamos la memoria dinámica
    free(nombreAux);
    free(entrada);
    for (int i = 0; i < indiceAlmacen; i++){
        free(almacenAsignaturas[i].nombre);
    }
    free(almacenAsignaturas);

    return 0;
}