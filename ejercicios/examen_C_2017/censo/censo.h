#ifndef CENSO_H_
#define CENSO_H_
#include "persona/persona.h"

// Definición de estructuras
typedef struct{
    Persona* personas;
    float mediaEdad; 
    int numeroPersonas;

} GrupoPersonas;

// Definición de funciones
int cuantasPersonas(Persona* ap, int tamanyo, int edad);
GrupoPersonas recuperarJovenes(Persona* ap, int tamanyo);
Persona recuperarYogurin(Persona* ap, int tamanyo);

// Definición de otras funciones
int cuantosNombres(Persona* ap, int tamanyo, char letra);
char** listadoNombres(Persona* ap, int tamanyo, char letra);

#endif //CENSO_H_