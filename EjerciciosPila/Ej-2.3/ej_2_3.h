#ifndef EJ2_3_H
#define EJ2_3_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int dia;
    int mes;
    int anio;
}tFecha;

typedef struct{
    char codigo[7];
    char descripcion[15];
    char proveedor[15];
    tFecha fCompra;
    tFecha fVencimiento;
    int cantidad;
    float pCompra;
    float pVenta;
}tProducto;





#endif