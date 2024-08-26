#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DUPLICADO -5
#define MIN(A,B)((A<B)? (A) : (B))

typedef struct{
    int dni;
    char apyn[40]; // apellido y nombre
    char estado;
}tAlumno;

typedef struct{
    int dni; // del alumno
    unsigned posicion; // del alumno en el archivo de alumnos
}tIndice;

typedef struct sNodo{
    void *info;
    struct sNodo *izq, *der;
    unsigned tamInfo;
}tNodo;

typedef tNodo *tArbol;

int cargar_archivo_bin(const char *ruta);
int cargar_indice_alumnos(const char *rutaBin, const char *rutaIdx);
void crear_arbol(tArbol *pa);
int poner_en_arbol(tArbol *pa, const void *pd, unsigned tam, int(*cmp)(const void*, const void*));
int comparar_dni(const void*e1, const void*e2);
int cargar_desde_archivoDes_a_arbol(const char *ruta, tArbol *pa);
void recorrer_inOrden(const tArbol *pa, void(*accion)(void*, void*), void *param);
int cargar_desde_arbol_a_archivo(const char *ruta, tArbol *pa);
void guardar_en_archivo(void *info, void *param);
int cargar_arbol_desde_archivo_ordenado(tArbol *pa, const char *ruta, unsigned tam);
int cargar_desde_datos_ordenados(tArbol *pa, void *ds, unsigned(*leer)(void**, void*, unsigned, void*param), int li, int ls, void *param);
unsigned leer_desde_archivo(void **d, void *pf, unsigned pos, void *param);
void vaciar_arbol(tArbol *pa);
void menu();
int buscar_elemento(const tArbol *pa, void *pd, unsigned tam, int(*cmp)(const void*, const void*));
tNodo **buscar_nodo(const tArbol *pa, void *pd, int(*cmp)(const void*, const void*));
int baja_alumno(int *dni, tArbol *pa, const char *rutaBin);
int eliminar_elemento(tArbol *pa, void *pd, unsigned tam, int(*cmp)(const void*, const void*));
int altura(const tArbol *pa);
tNodo **mayor_nodo(const tArbol *pa);
tNodo **menor_nodo(const tArbol *pa);
int eliminar_raiz(tArbol *pa);
int mostrar_archivo(const char *rutaBin);
void mostrar(tAlumno *alu);

#endif // HEADER_H_INCLUDED