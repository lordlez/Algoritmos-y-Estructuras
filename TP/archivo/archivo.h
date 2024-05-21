#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED

#include "juego.h"
#include "jugador.h"
#include "pregunta.h"

#define MAX_LINEA 300
#define TAM_INFORME 200

int leerArchivo(tJuego *juego);
int imprimir(tJuego *juego);
void imprimirResultadosJuego(FILE *archivoInforme, tJuego* juego);
void obtenerPuntajeMaximo(tJugador* jugadores, int* puntajeMaximo, int cantidadJugadores);
char laLetraEs(char *letra, tPregunta* pregunta);

#endif // ARCHIVO_H_INCLUDED