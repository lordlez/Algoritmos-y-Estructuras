#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>

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

int crear_archivo(char *ruta);


#endif