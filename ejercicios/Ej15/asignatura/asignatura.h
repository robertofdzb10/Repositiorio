#ifndef ASIGNATURA_H
#define ASIGNATURA_H

// Definición de estrcuturas
typedef struct{
    int id;
    char* nombre; // Longitud máxia de 10 carácteres para el nombre
    float nota;
} Asignatura;

// Declaración de funciones
void imprimirMenu();

#endif