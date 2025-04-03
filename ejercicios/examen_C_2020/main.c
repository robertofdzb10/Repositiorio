#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "producto/producto.h"
#include "carrito/carrito.h"

#define TAMANYO 5
#define PRODUCTOS_FICHERO 5

// Definición de funciones auxiliars
void leerProductos(Producto* productos[], char* fichero){

	// Abrimos el archivo
	FILE* fichero_a = fopen(fichero, "r");
	if (fichero_a == NULL){
		printf("Error en la gestión de ficheros");
	}

	// Recorremos todos los productos del archivo y los almacenamos en el array
	for(int i = 0; i < PRODUCTOS_FICHERO; i++){
		fscanf(fichero_a, "%d%s  %f", &productos[i]->ref, productos[i]->nombre, &productos[i]->precio);
		strcat(productos[i]->nombre, " (f)");
		printf("Ref.%i  %s \t %.2f\n", productos[i]->ref, productos[i]->nombre, productos[i]->precio);
	}

	// Cerramos elcl archivo
	fclose(fichero_a);

}

// Programa principal
int main(void) {
	Producto p1; p1.ref=1; strcpy(p1.nombre,"Platanos"); p1.precio=12.0;
	Producto p2; p2.ref=2; strcpy(p2.nombre,"Solomillo"); p2.precio=32.2;
	Producto p3; p3.ref=3; strcpy(p3.nombre,"Chocolate"); p3.precio=25.5;
	Producto p4; p4.ref=4; strcpy(p4.nombre,"Rodaballo"); p4.precio=35.4;
	Producto p5; p5.ref=5; strcpy(p5.nombre,"Cereales"); p5.precio=10.5;

	imprimirProducto(p1);
	printf("\n");

	Producto* comprados[] = {&p1, &p2, &p3, &p4, &p5};

	// Llamamos a la función de lectura del archivo
	leerProductos(comprados, "productos.txt");

	// Creamos una compra
	Compra c1; c1.Producto = p2; c1.cantidad = 3;

	// Probamos las funciones de compra
	printf("ANTES de la modificacion de la compra...\n");
	imprimirCompra(c1);
	modificarCompra(&c1, 0);
	printf("DESPUES de la modificacion de la compra...\n");
	imprimirCompra(c1);
	printf("\n");

	// Variables auxiliares para probar la parte de compra
	int cantidades[TAMANYO] = {1, 3, 5, 7, 9};

	// Declaramos un carrito
	Carrito carrito1;
	carrito1.compra = malloc(TAMANYO * sizeof(Compra));
	if (carrito1.compra == NULL){
		printf("Error en la gestión de la memoria dinámica.");
		return 1;
	}
	
	// Creamos un carrito y lo imprimimos
	crearCarrito(&carrito1, comprados, cantidades, TAMANYO);
	imprimirTicket(carrito1);
	printf("\n");

	// Cambiamos la cantidad del producto con ref.3 e imprimimos el carrito
	modificarCarrito(&carrito1, 3, 0);
	imprimirTicket(carrito1);

	// Liberamos la memoria dinámica
	devolverCarrito(&carrito1);

	return 0;
}
