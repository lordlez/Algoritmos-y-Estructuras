#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 1000
#define MIN(a,b) (((a<b))?(a):(b))

typedef struct {
    char pila[TAM];
    unsigned tope;
}tPila;

void crear_pila(tPila *pp);
int poner_en_pila(tPila *pp, const void *pd, unsigned tam);
int sacar_de_pila(tPila *pp, void *pd, unsigned tam);
int pila_llena(const tPila *pp, unsigned tam);
int pila_vacia(const tPila *pp);
int validar_cadena(const char *cadena);



#endif