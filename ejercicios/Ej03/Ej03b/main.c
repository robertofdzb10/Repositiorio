#include <stdio.h>
#include <stdbool.h>
#include "caracter/caracter.h"

int main(void){

    // Declaración de variables auxiliares
    char enter = 0;

    // Le pedimos al usurio que introduzca un carácter
    printf("Introduzca un caracter por favor.\n");
    
    // Almacenamos el caracter introducido por el usuario
    char caracter = getchar();

    // Minetras no introduzcamos la lertra 'e', continua el programa
    while (caracter != 'e'){

        // Aplicamos la lógica de clasificación de carácteres
        if (isLetter(caracter)){
            printf("El caracter '%c', es una letra. ", caracter);
            if (isUpperCase(caracter)){
                printf("Concretamente una letra mayuscula ('%c' en minuscula).\n", toLowerCase((int)caracter)); // Convertimos a int mediante la conversión con los parentesis, y lo pasamos a letra con el %c
            } 
            else if (isLowerCase(caracter)){
                printf("Concretamente una letra minuscula ('%c' en mayuscula).\n", toUpperCase(caracter));    
            }
        } else if (isNumber(caracter)) {
            printf("El caracter '%c', es un numero.\n", caracter);
        }else if(isEnter(caracter)){
            printf("Pedi un caracter, no un enter.\n");
            enter = 1;
        } else if (isOtherCharacter(caracter)){
            printf("El caracter '%c' es un caracter especial.\n", caracter);
        } else {
            printf("Se ha introudcido un carácter desconocido, por favor reinicie el programa.\n");
        }
        
        // Limpiamos el buffer, quedandonos solo con el primer caracter
        if (enter == 0){
            while(getchar() != '\n');
        } else {
            enter = 0;
        }

        // Le pedimos al usurio que introduzca un carácter
        printf("Introduzca un caracter por favor.\n");

        // Pedimos otra letra al usuario
        caracter = getchar();
    }


    return 0;
}