#ifndef PREGUNTA_H
#define PREGUNTA_H


#define TAM_ID 4
#define TAM_PREGUNTA 300
#define TAM_OPCION 4

typedef struct {
  int facil;
  int medio;
  int dificil;
}tDificultad;

typedef struct
{
    char id[TAM_ID];
    char pregunta[TAM_PREGUNTA];
    char resp_correcta[TAM_OPCION];
    char opcion_1[TAM_OPCION];
    char opcion_2[TAM_OPCION];
    char opcion_3[TAM_OPCION];
    tDificultad dificultad;
} tPregunta;

#endif // PREGUNTA_H