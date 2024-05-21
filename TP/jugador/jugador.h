#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

#include "../respuesta/respuesta.h"

#define TAM_NOMBRE 30
#define MAX_PREGUNTAS 99

typedef struct {
  char nombre[TAM_NOMBRE];
  int turno;
  int puntos;
  tRespuesta respuestas[MAX_PREGUNTAS];
} tJugador;

#endif // JUGADOR_H_INCLUDED