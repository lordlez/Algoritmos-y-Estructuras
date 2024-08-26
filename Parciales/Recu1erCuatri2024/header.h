#ifndef PARCIAL_H_INCLUDED
#define PARCIAL_H_INCLUDED
// 38929303_Lezcano_Lorenzo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(A,B)((A<B)?(A):(B))
typedef struct sNodo{
    void *info;
    struct sNodo *sig;
    unsigned tamInfo;
}tNodo;

typedef tNodo *tPila;

typedef struct{
    int dia;
    int mes;
    int anio;
}tFecha;


typedef struct{
    char codProd[6];
    char descripcion[25];
    int lote;
    tFecha fechaVencimiento;
    int cantidad;
}tProducto;




void crear_pila(tPila *pp);
void vaciar_pila(tPila *pp);
int poner_en_pila(tPila *pp, const void *pd, unsigned tam);
int sacar_de_pila(tPila *pp, void *pd, unsigned tam);
int cargar_archivo_stock(const char *rutaStock);
void menu(const char *rutaStock, int mes, const char *rutaProdAVencer, const char *rutaProdOk, tPila *pp);
int vencimiento_n_meses(const char *rutaStock, int mes, const char *rutaProdAVencer, const char *rutaProdOk, tPila *pp);
int pila_vacia(const tPila *pp);
int mostrar_archivo(const char *ruta, void(*mostrar)(void*));
void mostrar_producto(void *el);
int mostrar_archivo_txt(const char *rutaProdAVencer);



#endif // PARCIAL_H_INCLUDED


