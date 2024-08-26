#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DUPLICADO -5
#define MINIMO(a,b) ((a) < (b) ? (a) : (b))

typedef struct{
    int dia;
    int mes;
    int anio;
}tFecha;

typedef struct{
    int codigo;
    char descripcion[20];
    float precio;
    tFecha fechaCompra;
    char proveedor[20];
}tProducto;

typedef struct{
    int codigo; // del producto
    unsigned posicion; // del producto
}tIndice;

typedef struct sNodo{
    void *info;
    struct sNodo *izq, *der;
    unsigned tamInfo;
}tNodo;

typedef tNodo *tArbol;


int cargar_archivo(const char *ruta);
int cargar_indice(const char *rutaBin, const char *rutaIdx);
void crear_arbol(tArbol *pa);
int poner_en_arbol(tArbol *pa, const void *pd, unsigned tam, int(*cmp)(const void*, const void*));
void recorrer_inOrden(const tArbol *pa, void(*accion)(void*, void*), void *param);
int cargar_de_indice_a_arbol(const char *rutaIdx, tArbol *pa);
int comparar_codigo(const void *e1, const void *e2);
int cargar_de_arbol_a_indiceOrd(tArbol *pa, const char *rutaIdx);
void guardar_en_archInd(void *info, void *param);
void vaciar_arbol(tArbol *pa);
int mostrar_archivo(const char *rutaBin);
void mostrar(tProducto *prod);
int cargar_arbol_desde_archivo_ordenado(tArbol *pa, const char *ruta, unsigned tam);
int cargar_desde_datos_ordenados(tArbol *pa, void *ds, unsigned (*leer)(void **, void *, unsigned, void *param), int li, int ls, void *param);
unsigned leer_desde_archivo(void **info, void *pf, unsigned pos, void *param);
int buscar_elemento(const tArbol *pa, void *pd, unsigned tam, int(*cmp)(const void*, const void*));
tNodo **buscar_nodo(const tArbol *pa, void *pd, int(*cmp)(const void*, const void*));
int modificar_proveedor(const char *rutaBin, tArbol *pa, int cod, const char *prov);

#endif // HEADER_H_INCLUDED