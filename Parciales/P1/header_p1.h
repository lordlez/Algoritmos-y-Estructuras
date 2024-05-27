#ifndef HEADER_P1_H
#define HEADER_P1_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINEA 81
#define DUPLICADO -2

typedef struct sNodo {
    void *info;
    struct sNodo *sig;
    unsigned tamInfo;
} tNodo;

typedef tNodo *tLista;

void crear_lista(tLista *pl);
void vaciar_lista(tLista *pl);
int poner_orden(tLista *pl, const void *pd, unsigned tam, int (*cmp)(const void*, const void*));
int leer_archivo(const char *ruta, tLista *lista);
int cmp_palabras(const void *s1, const void *s2);
void recorrer(tLista *pl, void(*mostrar)(void*));
void mostrar(void *dato);
void normalizar_linea(char *linea, char *palabras);
void obtener_palabra_insertar(char *palabras, tLista *lista);

#endif // HEADER_P1_H
