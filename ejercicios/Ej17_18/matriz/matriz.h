#ifndef MATRIZ_H
#define MATRIZ_H

// Declaración de variables globales
#define X 5
#define Y 5

// Declaración de funciones
void f1(int a[X][Y]);
void f2(int **b); // El compilador lo convierte autmoaticamente en un array a punteros, por lo que es mejor convertirlo explicitamente
void f3(int **c);
void f4(int (*d)[Y]);

#endif