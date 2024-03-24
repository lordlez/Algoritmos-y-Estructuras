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

typedef struct{
    tNodo *pri;
    tNodo *ult;
}tCola;

void crear_cola(tCola *pc);
void vaciar_cola(tCola *pc);
int poner_en_cola(tCola *pc, const void *pd, unsigned tam);
int sacar_de_cola(tCola *pc, void *pd, unsigned tam);
int ver_primero(const tCola *pc, void *pd, unsigned tam);
int cola_llena(const tCola *pc, unsigned tam);
int cola_vacia(const tCola *pc);


int archivo_a_cola(char *ruta, tCola *cola);
void menu(tCola *cola);
void opcion1(tCola *cola);
void opcion2(tCola *cola);
void opcion3(tCola *cola);
int comprobar_cola(char *ruta, tCola *cola);
int leer_archivo(char *ruta);
void mostrar_producto(tProducto *producto);



#endif