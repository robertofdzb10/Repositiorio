#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Recibe un array de caracteres y devuevle su tamaño */
int tamanioArrayCaracteres(char *a){
    return strlen(a);
}

/* Imprime por pantalla el array de carácteres que se le introduce como parámtero*/
void imprimirArrayCaracteres(char *a){
    printf("'%s'\n", a);
}

/* Recibe un array y devuelve otro, con el contenido del primero, 
este tendra tambien el mismo tamaño de memoria dinámica que el primero,
el usuario deberá liberarlo */
char* clonarArrayCaracteres(char *a){
    char* resultado = malloc(strlen(a) + 1); // Obtenemos el tamaño de a y le sumamos uno para '\0'
    strcpy(resultado, a);
    return resultado;
}

/* Recibe dos arrays, devuelve en el primer array el contenido de ambos,
concatenadno el valor original del mismo al del segundo array.  El primer
array debe de tener el tamaño necesario para efectuar tal acción*/
void concatenarArrayCaracteres(char *a, char *b){
    strcat(a,b);
}

/* Recibe dos arrays, aquel donde se desea copiar la cadena y el original,
El array de destino debe tener el tamaño necesario para meter la cadena */
void copiarArrayCaracteres(char *a, char*b){
    strcpy(a, b);
}
