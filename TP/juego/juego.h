#ifndef JUEGO_H
#define JUEGO_H

#include "../tdaListaCircular/tdaListaCircular.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FIN "X"
#define SALIR 'B'

#define TAM_NOMBRE 25
#define MAX_ROUND 7

#define TODO_OK 1

#define TAM_PREG 100
#define TAM_RESP 30

#define MIN_RONDAS 10
#define MAX_RONDAS 30
#define MIN_TIEMPO_RONDA 3
#define MAX_PREGUNTAS 99
#define MAX_JUGADORES 5


typedef struct {
  int facil;
  int medio;
  int dificil;
}tDificultad;

typedef struct
{
    int rondas;
    int tiempoPorRonda;
    int cantidadDejugadores;
    int tiempoMenor[MAX_PREGUNTAS];
    tDificultad dificultad;
    tPregunta preguntas[MAX_PREGUNTAS];
    tJugador jugadores[MAX_JUGADORES];  
} tJuego;


char menu(char *msg, char *ops);
void mostrarPregunta(tPregunta *preg, int nroJgr, FILE *output);
void mostrarRespuestas(const char *a, const char *b, const char *c, char *d,
                       FILE *output);

#endif // JUEGO_H