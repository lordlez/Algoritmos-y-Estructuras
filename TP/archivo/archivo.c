#include "archivo.h"

/*
En tJuego tengo datos relacionados con el juego en si, como la cantidad de rondas,
el tiempo por ronda, la cantidad de jugadores, las preguntas y los jugadores.
Por lo tanto cuando quiero abrir el archivo debo pasarle por parametro un 
puntero a tJuego para que pueda cargar los datos leidos del archivo.
*/
int leerArchivo(tJuego *juego)
{
    FILE *archivoConfiguracion;
    char linea[MAX_LINEA];

    archivoConfiguracion = fopen("config.txt", "rt");
    if(archivoConfiguracion == NULL)
    {
        printf("Error de archivo");
        return -1; // ERROR
    }

    // leo la cantidad de preguntas (rondas) del archivo
    if(fgets(linea, MAX_LINEA, archivoConfiguracion))
        sscanf(linea, "Rounds: %d", &juego->rondas);

    // leo la cantidad de tiempo por ronda del archivo
    if(fgets(linea, MAX_LINEA, archivoConfiguracion))
        sscanf(linea, "Tiempo por round: %d", &juego->tiempoPorRonda);

    fclose(archivoConfiguracion);

    // verifico que los datos leidos sean correctos
    if(juego->rondas < MIN_RONDAS || juego->rondas > MAX_RONDAS || juego->tiempoPorRonda < MIN_TIEMPO_RONDA){
        printf("Error en los datos del archivo de configuracion");
        return -1; // ERROR
    }

    return 1; // TODO_OK
}


/*
Esta funcion recibe un puntero a un juego.
Imprime en la consola las preguntas, las respuestas y los puntajes de los jugadores.
Ademas, genera un archivo de informe con los resultados del juego.
*/
int imprimir(tJuego *juego)
{
    FILE *archivoInforme;
    time_t tiempoQuePaso;
    struct tm* fechaYHora; // doc -> https://www.cplusplus.com/reference/ctime/tm/
    char nombreDelInforme[TAM_INFORME];

    imprimirResultadosJuego(stdout, juego); // imprimo en la consola

    // obtengo la fecha y hora actual
    tiempoQuePaso = time(NULL);

    // convierto la fecha y hora a una estructura tm
    fechaYHora = localtime(&tiempoQuePaso);

    // genero el nombre del archivo de informe
    sprintf(nombreDelInforme, "informe-juego_%4d-%02d-%02d-%02d-%02d.txt", fechaYHora->tm_year + 1900, fechaYHora->tm_mon + 1, fechaYHora->tm_mday, fechaYHora->tm_hour, fechaYHora->tm_min);

    // abro el archivo de informe
    archivoInforme = fopen(nombreDelInforme, "wt");
    if(archivoInforme == NULL)
    {
        printf("Error al abrir el archivo de informe");
        return -1; // ERROR
    }

    // genero el informe
    imprimirResultadosJuego(archivoInforme, juego);

    // cierro el archivo de informe
    fclose(archivoInforme);

    return 1; // TODO_OK
}

/*
Esta funcion recibe un puntero a un archivo y un puntero a un juego.
Imprime en el archivo las preguntas, las respuestas y los puntajes de los jugadores.
Ademas imprime el puntaje maximo y el ganador o ganadores del juego.
*/
void imprimirResultadosJuego(FILE *archivoInforme, tJuego *juego)
{
    int ronda, jugador, puntajeMaximo;
    const char* respuesta;
    int tiempoRespuesta, puntaje;

    obtenerPuntajeMaximo(juego->jugadores, &puntajeMaximo, juego->cantidadDejugadores);

    // Imprimo las preguntas, las respuestas y los puntajes de los jugadores
    for (ronda = 0; ronda < juego->rondas; ronda++)
    {
        // imprimo la pregunta y las opciones
        fprintf(archivoInforme, "%d- %s\n"
                                "A.- %s\n"
                                "B.- %s\n"
                                "C.- %s\n"
                                "D.- %s (Correcta)\n"
                                "Respuestas:\n",
                // por que ronda + 1? porque las rondas empiezan en 0
                ronda + 1, juego->preguntas[ronda].pregunta,
                juego->preguntas[ronda].opcion_1,
                juego->preguntas[ronda].opcion_2,
                juego->preguntas[ronda].opcion_3,
                juego->preguntas[ronda].resp_correcta);

        for (jugador = 0; jugador < juego->cantidadDejugadores; jugador++)
        {
            // obtengo la respuesta, el tiempo de respuesta y el puntaje del jugador
            respuesta = juego->jugadores[jugador].respuestas[ronda].opcion;
            tiempoRespuesta = juego->jugadores[jugador].respuestas[ronda].tiempoDeRespuesta;
            puntaje = juego->jugadores[jugador].respuestas[ronda].puntaje;

            // si el jugador contesto la pregunta
            if (strcmp(respuesta, "") != 0)
            {
                // imprimo el nombre del jugador, el tiempo de respuesta, la respuesta y el puntaje
                fprintf(archivoInforme, "%s: %d (tiempo)segundos en contestar %c (%+d)\n",
                        juego->jugadores[jugador].nombre,
                        tiempoRespuesta,
                        laLetraEs(respuesta, juego->preguntas),
                        puntaje);
            }
            // si el jugador no contesto la pregunta
            else
            {
                // imprimo el nombre del jugador y 0 puntos
                fprintf(archivoInforme, "%s: Sin contestar, por lo tanto 0 puntos\n",
                        juego->jugadores[jugador].nombre);
            }
        }
        // imprimo un salto de linea
        fprintf(archivoInforme, "\n");
    }

    // Imprimo el puntaje maximo y el ganador o ganadores del juego
    fprintf(archivoInforme, "Total\n");
    for (jugador = 0; jugador < juego->cantidadDejugadores; jugador++)
    {
        fprintf(archivoInforme, "\t%s:\t%4d puntos\n",
                juego->jugadores[jugador].nombre,
                juego->jugadores[jugador].puntaje);
    }

    fprintf(archivoInforme, "Ganador(o ganadores):\n");
    for (jugador = 0; jugador < juego->cantidadDejugadores; jugador++)
    {
        if (juego->jugadores[jugador].puntaje == puntajeMaximo)
        {
            fprintf(archivoInforme, "%s\n", juego->jugadores[jugador].nombre);
        }
    }
}


/*
En esta funcion recorro el array de jugadores buscando el puntaje maximo.
*/
void obtenerPuntajeMaximo(tJugador *jugadores, int *puntajeMaximo, int cantidadDejugadores)
{
    // Inicializo el puntaje maximo con el puntaje del primer jugador
    *puntajeMaximo = jugadores[0].puntos;
    int i;

    // Recorro el array de jugadores buscando el puntaje maximo
    // por que empiezo en 1? porque ya inicialice el puntaje maximo con el puntaje del primer jugador
    for (i = 1; i < cantidadDejugadores; i++)
    {
        // Si el puntaje del jugador actual es mayor al puntaje maximo
        if (jugadores[i].puntos > *puntajeMaximo)
        {
            // Actualizo el puntaje maximo
            *puntajeMaximo = jugadores[i].puntos;
        }
    }
}

char laLetraEs(char *letra, tPregunta* pregunta)
{
    int opcion = -1;

    if (strcmp(letra, pregunta->opcion_1) == 0)
        opcion = 0;
    else if (strcmp(letra, pregunta->opcion_2) == 0)
        opcion = 1;
    else if (strcmp(letra, pregunta->opcion_3) == 0)
        opcion = 2;

    switch (opcion)
    {
        case 0:
            return 'A';
        case 1:
            return 'B';
        case 2:
            return 'C';
        default:
            return 'D';
    }
}
