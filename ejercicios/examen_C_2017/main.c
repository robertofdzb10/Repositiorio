#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "persona/persona.h"
#include "censo/censo.h"

// Declaración de funciones
void crearInforme(GrupoPersonas gp, char* fichero){

	// Declaramos el archivo de texto
	FILE* fichero_a = fopen(fichero, "w");
	if (fichero_a == NULL){
		printf("Error en la gestión de archivos.");
	}

	// Escribimos en el archivo
	fprintf(fichero_a, "CENSO DE JOVENES\n");
	fprintf(fichero_a, "---------------- \n");
	for (int i = 0; i < gp.numeroPersonas; i++){
		fprintf(fichero_a, "[Nombre: %s, Edad: %d]\n", gp.personas[i].nombre, gp.personas[i].edad);
	}
	fprintf(fichero_a, "Media %.2f", gp.mediaEdad);

	// Cerramos el archivo
	fclose(fichero_a);

}

int main(int argc, char *argv[]){

	// Verificamos que se haya pasado un argumento para la edad
	if (argc < 2) {
		printf("Uso: %s <edad>\n", argv[0]);
		return 1;
	}

	// Convertimos el argumento a entero
	int edadMinima = atoi(argv[1]);
	if (edadMinima <= 0) {
		printf("Por favor, introduce una edad válida.\n");
		return 1;
	}

	// Declaramos un array de 5 personas
	Persona personas[5];

	// Inicializamos el array
	personas[0].nombre="Hodei"; personas[0].edad=6;
	personas[1].nombre="Anita"; personas[1].edad=41;
	personas[2].nombre="Aitor"; personas[2].edad=12;
	personas[3].nombre="Idoia"; personas[3].edad=31;
	personas[4].nombre="Maite"; personas[4].edad=24;

	// Visualizamos una de las personas del array
	imprimirPersona(personas[0]);

	// Declaramos las variables auxiliares para la primera función
	int peronasMenoresQuince = 0;
	
	// Probamos la primera función 
	peronasMenoresQuince = cuantasPersonas(personas, 5, edadMinima);
	printf("Personas menores de %d = %d\n", edadMinima, peronasMenoresQuince);

	// Declaramos las variables auxiliares para la segunda función
	GrupoPersonas personasMenoresTreinta = recuperarJovenes(personas, 5);

	// Probamos la segunda función
	printf("Grupo de personas menores de 30:\n");
	for (int i = 0; i < personasMenoresTreinta.numeroPersonas; i++){
		printf("[Nombre: %s, Edad: %d]\n", personasMenoresTreinta.personas[i].nombre, personasMenoresTreinta.personas[i].edad);
	}
	printf("Media: %.2f\n", personasMenoresTreinta.mediaEdad);
	
	// Declaramos las variables auxiliares para la tercera función
	Persona personaMenor;

	// Probamos la tercera función
	personaMenor = recuperarYogurin(personas, 5);
	printf("La persona mas joven es:\n[Nombre: %s, Edad: %d]", personaMenor.nombre, personaMenor.edad);

	// Porbamos la función de escritura en un archivo
	crearInforme(personasMenoresTreinta, "datos.txt");

	// Variables auxiliares para la cuarta función
	int numeroNombres = 0;

	// Probamos la cuarta función
	numeroNombres = cuantosNombres(personas, 5, 'A');
	printf("\nNombres con la inical 'A': %d\n", numeroNombres);

	// Variables auxiliares para la quinta función
	int indiceListadoNombres = 0;
	char** listadoNombres_s;

	// Probamos la quinta función
	listadoNombres_s = listadoNombres(personas, 5, 'A');
	while(strcmp(listadoNombres_s[indiceListadoNombres],"FIN")){
		printf("%s\n", listadoNombres_s[indiceListadoNombres]);
		indiceListadoNombres++;
	}

	// Liberamos la memoria dinámica
	free(personasMenoresTreinta.personas);
	for (int i = 0; i < indiceListadoNombres + 1; i++){
		free(listadoNombres_s[i]);
	}
	free(listadoNombres_s);


	return 0;
}
