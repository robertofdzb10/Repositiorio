#ifndef CADENA_H
#define CADENA_H

// Definición de estructuras
typedef struct{
    char* cadenaOriginal;
    char* cadenaReflejada;
} Reflejo;

// Definición de funciones
Reflejo crearEspejo(char *str);
void liberarEspejo(Reflejo *r);

#endif /* CADENA_H */