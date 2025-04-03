#ifndef CARRITO_H_
#define CARRITO_H_
#include "producto/producto.h"

// Definición de estructura Compra
typedef struct {
    Producto Producto;
    int cantidad;
} Compra;

// Definición de estructura Carrito
typedef struct{
    Compra *compra;
    float importe; // Importe total de la compra
    int cantidadCompras; // Número de compras que componen el carrito
} Carrito;


// Definición de funciones para la estructura Compra
void modificarCompra(Compra *c, int cantidad);
void imprimirCompra(Compra c);

// Definición de funciones para la estructura Carrito
void crearCarrito(Carrito *c, Producto **p, int *cats, int tamanyo);
void imprimirTicket(Carrito c);
void devolverCarrito(Carrito *c);

// Definición de las últimas funciones
void modificarCarrito(Carrito *c, int ref, int cant);

#endif /* CARRITO_H_ */