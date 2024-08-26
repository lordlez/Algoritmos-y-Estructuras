#ifndef P2_H
#define P2_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ERROR_ARCHIVO -1
#define TAM_LINEA 100
#define DUPLICADO -2

// estructura de mi arbol
typedef struct sNodo{
    void *info;
    struct sNodo *izq, *der;
    unsigned tamInfo;
}tNodo;

typedef tNodo *tArbol;


// estructura para mis palabras
typedef struct{
    char *palabra;
    unsigned repeticiones;
}tPalabra;



void menu(tArbol *pa);
void crear_arbol(tArbol *pa);
void vaciar_arbol(tArbol *pa);
int poner_arbol(tArbol *pa, const void *pd, unsigned tam, int(*cmp)(const void *, const void *));
tNodo **buscar_nodo(const tArbol *pa, void *pd, int(*cmp)(const void*, const void*));
int leer_archivo(const char *ruta, tArbol *pa);
int separar_insertar_palabra(char *linea, tArbol *pa, tPalabra *palabra);
void incrementar_repeticiones(tArbol *pa, tPalabra *palabra);
int comparar_palabra(const void *p1, const void *p2);
void imprimir_palabra(void *info, void *param);
void palabra_mayor_repeticion(const tArbol *pa, tPalabra *mayor);
void palabra_menor_repeticion(const tArbol *pa, tPalabra *menor);


#endif // P2_H