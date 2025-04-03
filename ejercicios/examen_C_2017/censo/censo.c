#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "censo.h"

/* Calcula cuantas personas menores de la edad indicada hay
en el array de personas introducido como parámetro, 
se le debe de pasar el tamaño del array.*/
int cuantasPersonas(Persona* ap, int tamanyo, int edad){

    // Variables auxiliares
    int contadorPersonasMenores = 0;

    // Recorremos el array de personas
    for(int i = 0; i < tamanyo; i++){
        // Verificamos si la edad de la persona es menor a la indicada
        if (ap[i].edad < edad){
            // Si la edad es inferior decrementamos el contador
            contadorPersonasMenores++;
        }
    }

    // Devolvemos el valor del contador
    return contadorPersonasMenores;
}

/* Devuevle un 'GrupoPersonas' con aquellas menores de 30 años,
se le debe de pasar el tamaño del array. Devemos liberar la memoria dinámica
del array de personas de la estructura GrupoPersonas al acabar el programa. */
GrupoPersonas recuperarJovenes(Persona* ap, int tamanyo){

    // Variables auxiliares
    int indiceEntrada = 0;
    int edadTotal = 0;

    // Declaramos el grupo de personas menores de 30 años
    GrupoPersonas grupoResultado;

    // Asignamos la memoria dinámica al grupo de personas
    grupoResultado.personas = malloc(sizeof(Persona));
    if (grupoResultado.personas == NULL){
        printf("Error a la hora de asignar memoria dinamica.");
    }

    // Recorremos todas las personas en busca de aquellas menores de 30 años
    for(int i = 0; i < tamanyo; i++){

        // Si la persona es menor de 30 años la introducimos en el grupo
        if (ap[i].edad < 30){

            // Reajustamos el tamaño del array para que entre una persona más
            grupoResultado.personas = realloc(grupoResultado.personas, ( (indiceEntrada + 1) * sizeof(Persona)));
            if (grupoResultado.personas == NULL){
                printf("Error a la hora de asignar memoria dinamica.");
            }

            // Copiamos la persona al grupo
            grupoResultado.personas[indiceEntrada].edad = ap[i].edad;
            grupoResultado.personas[indiceEntrada].nombre = ap[i].nombre;

            // Sumamos su edad al total de edades
            edadTotal = ap[i].edad + edadTotal;

            // Aumentamos el índice, para meter la próxima persona el la próxima posición libre
            indiceEntrada++; 
        }
    }

    // Almacenamos la media de edades
    if (indiceEntrada > 0) {
        grupoResultado.mediaEdad = edadTotal / indiceEntrada;
    } else {
        grupoResultado.mediaEdad = 0;
    }

    // Almacenamos el numero de personas
    grupoResultado.numeroPersonas = indiceEntrada;

    // Devolvemos el grupo de personas menor de 30 años
    return grupoResultado;

}

/* Devuelve la persona de menor edad del array rcibido como parámetro 
(se asume que solo hay una), se le debe de pasar el tamaño del array.*/
Persona recuperarYogurin(Persona* ap, int tamanyo){

    // Declaramos la persona resultado con la primera del array
    Persona resultado = ap[0];

    // Buscamos cual es la persona con menor edad
    for (int i = 0; i < tamanyo; i++){

        // Si la edad de la persona actual de la iteración es menor que nuestra "mejor" persona, rotamos este valor
        if (resultado.edad > ap[i].edad){
            resultado = ap[i];
        }

    }

    // Devolvemos la persona con menor edad
    return resultado;

}

/* Devuelve cuantas personas del array iontroducido como parámetro, 
su nombre empieza por la letra indicada, se le debe de pasar el tamaño del array.*/
int cuantosNombres(Persona* ap, int tamanyo, char letra) {

    // Variables auxiliares
    int numeroPersonas = 0;

    // Recorremos todas las personas del array
    for(int i = 0; i < tamanyo; i++){

        // Comprobamos si la primera letra del nombre de la persona es la deseada
        if (ap[i].nombre[0] == letra){
            numeroPersonas++;
        }
    }

    // Devolvemos el número de personas cuyo nombre empiezan por la letra deseada
    return numeroPersonas;

}

/* Devuelve un listado con los nombres de las personas del array introducido como parámetro
cuyo nombre empieza por la letra indicada, se le debe de pasar el tamaño del array.
Es necesario liberar el array de nombres tras su uso*/
char** listadoNombres(Persona* ap, int tamanyo, char letra){

    // Variables auxiliares
    int numeroPersonas = 0;
    char** listadoNombres_s = malloc(sizeof(char*));
    if(listadoNombres_s == NULL){
        printf("Error a la hora de asignar memoria dinamica.");
    }

    // Recorremos todas las personas del array
    for(int i = 0; i < tamanyo; i++){

        // Comprobamos si la primera letra del nombre de la persona es la deseada
        if (ap[i].nombre[0] == letra){

            // Aumentamos el tamaño del array de nombres
            listadoNombres_s = realloc(listadoNombres_s, (numeroPersonas + 1) * sizeof(char*));
            if(listadoNombres_s == NULL){
                printf("Error a la hora de asignar memoria dinamica.");
                for (int e = 0; e < numeroPersonas; e++){
                    free(listadoNombres_s[e]);
                }
            }

            // Guardamos el tamañao necesario para cada nombre dentro del array de nombres
            listadoNombres_s[numeroPersonas] = malloc(strlen(ap[i].nombre) * sizeof(char) + 1); // Debemos reservar un hueco más para '\0'
            if(listadoNombres_s[numeroPersonas] == NULL){
                printf("Error a la hora de asignar memoria dinamica.");
                for (int e = 0; e < numeroPersonas; e++){
                    free(listadoNombres_s[e]);
                }
                free(listadoNombres_s);
            }

            // Si lo es la añadimos al listado
            strcpy(listadoNombres_s[numeroPersonas], ap[i].nombre);
            numeroPersonas++;

        }
    }

    // Almacenamos la cadeana "FIN" al final
    listadoNombres_s = realloc(listadoNombres_s, (numeroPersonas + 1) * sizeof(char*));
    if(listadoNombres_s == NULL){
        printf("Error a la hora de asignar memoria dinamica.");
        for (int i = 0; i < numeroPersonas; i++){
            free(listadoNombres_s[i]);
        }
    }
    listadoNombres_s[numeroPersonas] = malloc(strlen("FIN") * sizeof(char) + 1); // Debemos reservar un hueco más para '\0'
    if(listadoNombres_s[numeroPersonas] == NULL){
        printf("Error a la hora de asignar memoria dinamica.");
        for (int i = 0; i < numeroPersonas; i++){
            free(listadoNombres_s[i]);
        }
        free(listadoNombres_s);
    }
    strcpy(listadoNombres_s[numeroPersonas], "FIN");

    // Devolvemos el número de personas cuyo nombre empiezan por la letra deseada
    return listadoNombres_s;

}