#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(A,B) (((A) < (B)) ? (A) : (B))



typedef struct{
    int dia;
    int mes;
    int anio;
}tFecha;

typedef struct{
    char codProd[7];
    char descripcion[15];
    char proveedor[15];
    tFecha fCompra;
    tFecha fVenta;
    int cantidad;
    float compra;
    float venta;
}tProducto;


typedef struct sNodo{
    void *info;
    struct sNodo *sig;
    unsigned tamInfo;
}tNodo;

typedef tNodo *tPila;

void crear_pila(tPila *pp);
void vaciar_pila(tPila *pp);
int apilar(tPila *pp, const void *pd, unsigned tam);
int desapilar(tPila *pp, void *pd, unsigned tam);
int ver_tope(const tPila *pp, void *pd, unsigned tam);
int pila_llena(const tPila *pp, unsigned tam);
int pila_vacia(const tPila *pp);


int archivo_a_pila(char *ruta, tPila *pila);
void menu(tPila *pila);
void opcion1(tPila *pila);
void opcion2(tPila *pila);
void opcion3(tPila *pila);
int comprobar_pila(char *ruta, tPila *pila);
int leer_archivo(char *ruta);
void mostrar_producto(tProducto *producto);



#endif