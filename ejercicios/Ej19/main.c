#include <stdio.h>
#include <stdlib.h>

#define CONSTNUMERO 10

int main(void){

    // Declaramos el archivo
    FILE *archivo;

    // Abrimos el archivo en modo escritura
    archivo = fopen("datos.txt", "w");
    if (archivo == NULL){
        printf("Error en la gestión de archivos.");
        return 1;
    }

    // Escribimos en el archivo
    fprintf(archivo, "Escribiendo %d numeros\n", CONSTNUMERO);
    for (int i = 0; i < CONSTNUMERO; i++){
        fprintf(archivo, "%d\n", i);
    }

    // Cerramos el archivo
    fclose(archivo);

    // Abrimos el archivo en modo lectura
    archivo = fopen("datos.txt", "r");
    if (archivo == NULL){
        printf("Error en la gestión de archivos.");
        return 1;
    }

    // Variables auxiliares para la lectura
    int numTemp = 0;
    int numEscritura = 0;
    int numLineas = 1;

    // Leemos el contenido del archivo y lo imprimimos por consola
    fscanf(archivo, "Escribiendo %d numeros\n", &numEscritura);
    printf("Escribiendo %d numeros\n", numEscritura);
    while(fscanf(archivo, "%d\n", &numTemp) == 1){ // fscanf() devulve el número de elementos que se espera leer (1 en este caso), 0 cuando no hay lectura o esta falla y -1 cuando llega al final
        printf("%d\n", numTemp);    
        numLineas++;
    }
    printf("El fichero tiene %d lineas\n", numLineas);

    // Cerramos el archivo
    fclose(archivo);

    return 0;
}