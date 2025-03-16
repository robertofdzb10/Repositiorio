#include <stdio.h>
#include "caracter/caracter.h"

int main(void){

    // Le pedimos al usurio que introduzca un carácter
    printf("Introduzca la letra 'q' por favor.\n");
    
    // Alamcenamos el carácter introducido por el usuario
    char caracter;
    caracter = getchar();

    // Comprobamos si el usuario ha introducido el carácter deseado
    while(caracter != 'q'){

        // Limpiamos todo el buffer (leyendo todos los caracteres hasta el final)
        while (getchar()!= '\n');

        // En caso contrario repetimos el proceso hasta que el usuario introduzca el carácter requerido
        printf("Ha introducido el caracter '%c' (ASCII = %d) (Mayuscula = '%c'), por favor introduzca la letra 'q'.\n", caracter, caracter, upper(caracter));
        caracter = getchar();
    }

    // El usuario ha introducido correctamente el carácter demenandado
    printf("El caracter introducido ha sido el solicitado, gracias.");

    return 0;
}