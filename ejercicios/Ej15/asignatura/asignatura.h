#ifndef ASIGNATURA_H_
#define ASIGNATURA_H_

// Definición de estrcuturas
typedef struct{
    int id;
    char* nombre; // Longitud máxia de 10 carácteres para el nombre
    float nota;
} Asignatura;

// Declaración de funciones
void imprimirMenu();

#endif