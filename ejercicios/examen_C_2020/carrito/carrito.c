#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "carrito.h"

/* Modifica la compra pasada como primer parámetro, 
asignándole como cantidad el valor del segundo parámetro. */
void modificarCompra(Compra *c, int cantidad){
    c->cantidad = cantidad;
    printf("Nueva cantidad: %d\n", c->cantidad);
}

/* Visualiza por pantalla los datos de la compra pasada como parámetro. */
void imprimirCompra(Compra c){
	printf("Ref.%i  %s \t %.2f x %d kg/ud\n", c.Producto.ref, c.Producto.nombre, c.Producto.precio, c.cantidad);
}

/* Partiendo de los arrays de productos y cantidades recibidos como parámetros, configura el carrito devuelto. Al primer 
producto del array le corresponde la primera cantidad del otro array, al segundo la segunda, y así 
sucesivamente. El cuarto parámetro indica el tamaño de los otros dos arrays. */
void crearCarrito(Carrito *c, Producto **p, int *cats, int tamanyo){

    // Variables auxiliares
    float precioTotal = 0;
    int cantidadCompras = 0;

    // Recorremos cada uno de los campos
    for(int i = 0; i < tamanyo; i++){

        // Pasamos todos los datos al carrito
        c->compra[i].Producto.ref = p[i]->ref;
        strcpy(c->compra[i].Producto.nombre, p[i]->nombre);
        c->compra[i].Producto.precio = p[i]->precio;
        c->compra[i].cantidad = cats[i];

        // Calculamos el precio total
        precioTotal = precioTotal + (p[i]->precio * cats[i]);

        // Aumentamos el número de compras
        cantidadCompras++;
    }

    // Guardamos la cantidad de compras
    c->cantidadCompras = cantidadCompras;

    // Guardamos el precio total
    c->importe = precioTotal;

}

/* Visualiza por pantalla los datos del carrito pasado como parámetro, como si fuese un ticket de compra. */
void imprimirTicket(Carrito c){

    // Variables auxiliares
    int contador = 0;

    // Imprimimos el ticket
    printf("TICKET\n");
    printf("------\n"); 
    for(int i = 0; i < c.cantidadCompras; i++){
        imprimirCompra(c.compra[contador]);
        contador++;
    }
    printf("....................................\n"); 
    printf("TOTAL: %.2f euros \n", c.importe); 

}

/* Libera la memoria dinámica reservada para los 
distintos elementos que componen el carrito.*/
void devolverCarrito(Carrito *c){
    free(c->compra);
}

/* Busca en el carrito pasado como primer parámetro la compra correspondiente al producto con la referencia 
pasada como segundo parámetro y modifica su cantidad, asignándole el valor del tercer 
parámetro. Recuerda que está modificación debe implicar un recalculo del importe total del 
carrito. Si no existiese ninguna compra de ese producto, no se hace nada.*/
void modificarCarrito(Carrito *c, int ref, int cant){
    // Recorremos todo el carrito
    for (int i = 0; i < c->cantidadCompras; i++){
        if (c->compra[i].Producto.ref == ref){
            // Quitamos de importe total el anterior precio de la anterior cantidad de productos
            c->importe = c->importe - (c->compra[i].cantidad * c->compra[i].Producto.precio);
            // Actualizamos la nueva cantidad
            c->compra[i].cantidad = cant;
            // Añadimos al importe total el nuevo precio de la nueva cantidad de productos
            c->importe = c->importe + (c->compra[i].cantidad * c->compra[i].Producto.precio);
        }
    }
}