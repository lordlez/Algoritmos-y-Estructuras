#include "header_p1.h"

void crear_lista(tLista *pl){
    *pl = NULL;
}

void vaciar_lista(tLista *pl) {
    tNodo *elim;
    while (*pl) {
        elim = *pl;
        *pl = elim->sig;
        free(elim->info);
        free(elim);
    }
}

int poner_orden(tLista *pl, const void *pd, unsigned tam, int(*cmp)(const void*, const void*)){
    tNodo *nuevo;
    while(*pl && cmp(pd, (*pl)->info)>0){
        pl = &(*pl)->sig;
    }
    if(*pl && cmp(pd, (*pl)->info) == 0){
        return DUPLICADO;
    }
    if((nuevo = (tNodo*)malloc(sizeof(tNodo)))==NULL||(nuevo->info = malloc(tam))==NULL){
        free(nuevo);
        return 0;
    }
    memcpy(nuevo->info, pd, tam);
    nuevo->tamInfo = tam;
    nuevo->sig = *pl;
    *pl = nuevo;
    return 1;
}

int leer_archivo(const char *ruta, tLista *lista){
    FILE *txt;
    char linea[MAX_LINEA]; //aca guardo la linea leida del archivo sin normalizar
    char palabras[MAX_LINEA]; //aca guardo la linea normalizada separada por espacio para poder tener mejor visualizacion de las palabras

    txt = fopen(ruta, "rt");
    if(txt == NULL){
        return -1;
    }

    while(fgets(linea, sizeof(linea), txt)){//leo una linea del archivo
        normalizar_linea(linea, palabras); //normalizo la linea, la limpio
        obtener_palabra_insertar(palabras, lista); //obtengo cada palabra de palabras y las inserto en la lista
    }
    fclose(txt);
    return 1;
}


/*
Esta funcion normaliza la linea de texto, es decir, elimina los caracteres especiales
y los pasa a otro lugar llamado palabras, ahi estan las palabras de esa linea
solo separadas por espacio y al final con el caracter fin de linea
*/
void normalizar_linea(char *linea, char *palabras){
    char *inicio = palabras;
    while(*linea != '\0'){
        if(isalnum(*linea) || *linea == ' '){
            *palabras = *linea;
            palabras++;
        }
        linea++;
    }
    *palabras = '\0';
    palabras = inicio;
}


/*
Esta funcion obtiene cada palabra, y la inserta a la lista
*/
void obtener_palabra_insertar(char *palabras, tLista *lista) {
    char palabra[MAX_LINEA];
    int i = 0;
    while (*palabras != '\0') {
        if (*palabras != ' ') {
            palabra[i] = *palabras;
            i++;
        } else {
            palabra[i] = '\0';
            if (i > 0) { // Si la palabra no es vacía
                poner_orden(lista, palabra, strlen(palabra) + 1, cmp_palabras);
            }
            i = 0;
        }
        palabras++;
    }
    if (i > 0) { // Insertar la última palabra si hay alguna
        palabra[i] = '\0';
        poner_orden(lista, palabra, strlen(palabra) + 1, cmp_palabras);
    }
}

int cmp_palabras(const void *s1, const void *s2) {
    const char *p1 = (const char *)s1;
    const char *p2 = (const char *)s2;
    int diferencia = strlen(p2) - strlen(p1);
    if (diferencia != 0) {
        return diferencia;
    }
    return strcmp(p1, p2);
}


void recorrer(tLista *pl, void(*mostrar)(void*)){
    while(*pl){
        mostrar((*pl)->info);
        pl = &(*pl)->sig;
    }
}

void mostrar(void *dato){
    printf("%s\n", (char*)dato);
}


