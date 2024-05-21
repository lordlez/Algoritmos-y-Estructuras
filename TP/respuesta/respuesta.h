#ifndef RESPUESTA_H
#define RESPUESTA_H

#define TAM_OPCION 4

typedef struct {
  int id;
  int puntos;
  int correcta;
  int respuestaTiempo;
  char opcion[TAM_OPCION];
}tRespuesta;

#endif // RESPUESTA_H