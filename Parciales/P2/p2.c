#include "p2.h"


void crear_arbol(tArbol *pa){
    *pa = NULL;
}

void vaciar_arbol(tArbol *pa){
    if(!*pa){
        return;
    }
    vaciar_arbol(&(*pa)->izq);
    vaciar_arbol(&(*pa)->der);
    free((*pa)->info);
    free(*pa);
    *pa = NULL;
}

int poner_arbol(tArbol *pa, const void *pd, unsigned tam, int(*cmp)(const void *, const void *)){
    tNodo *nuevo;
    int comparar;

    while(*pa){
        if((comparar = cmp(pd, (*pa)->info))<0){
            pa = &(*pa)->izq;
        }else if(comparar > 0){
            pa = &(*pa)->der;
    }else{
        return DUPLICADO;
        }
    }
    if((nuevo = (tNodo*)malloc(sizeof(tNodo)))==NULL||(nuevo->info = malloc(tam))==NULL){
        free(nuevo);
        return 0;
    }
    memcpy(nuevo->info, pd, tam);
    nuevo->tamInfo = tam;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    *pa = nuevo;
    return 1;
}

tNodo **buscar_nodo(const tArbol *pa, void *pd, int(*cmp)(const void*, const void*)){
    int comparar;
    while(*pa && (comparar = (cmp(pd, (*pa)->info)))){
        if(comparar<0){
            pa = &(*pa)->izq;
        }else{
            pa = &(*pa)->der;
        }
    }
    if(!*pa){
        return NULL;
    }
    return (tNodo**)pa;
}

void recorrer_in(const tArbol *pa, void(*accion)(void *, void *), void *param){
    if(!*pa){
        return;
    }
    recorrer_in(&(*pa)->izq, accion, param);
    accion((*pa)->info, param);
    recorrer_in(&(*pa)->der, accion, param);
}

void menu(tArbol *pa){
    tPalabra menor;
    tPalabra mayor;
    int opcion;
    printf("\t\t Menu de opciones...\n");
    printf("1 - Palabras con mayor cantidad de repeticiones\n");
    printf("2 - Palabra con mayor cantidad de repeticiones\n");
    printf("3 - Palabra con menor cantidad de repeticiones\n");
    printf("4 - Salir\n");

    do{
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        switch(opcion){
            case 1:
                printf("Opcion 1 - Palabras con mayor cantidad de repeticiones\n");
                recorrer_in(pa, imprimir_palabra, NULL);
                break;
            case 2:
                printf("Opcion 2 - Palabra con mayor cantidad de repeticiones\n");
                palabra_mayor_repeticion(pa, &mayor);
                break;
            case 3:
                printf("Opcion 3 - Palabra con menor cantidad de repeticiones\n");
                palabra_menor_repeticion(pa, &menor);
                break;
            case 4:
                printf("\nSaliendo...\n");
                break;
            default:
                printf("\nOpcion invalida\n");
                printf("Ingrese otra opcion: ");
                scanf("%d", &opcion);
        }
    }while(opcion != 4);
}

int leer_archivo(const char *ruta, tArbol *pa){
    FILE *archivo;
    tPalabra palabra; // estructura para guardar las palabras
    char linea[TAM_LINEA]; // linea para leer el archivo

    archivo = fopen(ruta, "rb");
    if(archivo == NULL){
        printf("Error al abrir el archivo\n");
        return ERROR_ARCHIVO;
    }

    while(fgets(linea, sizeof(linea), archivo)!=NULL){ // leo el archivo mientras no sea el final
        separar_insertar_palabra(linea, pa, &palabra); // separo las palabras y las inserto en el arbol
    }

    fclose(archivo);
    return 1;
}

int separar_insertar_palabra(char *linea, tArbol *pa, tPalabra *palabra){
    char *inicio = linea; // inicio de la palabra
    char *fin; // fin de la palabra
    int longitud; // longitud de la palabra

    while(*inicio != '\0'){
        while(*inicio && !isalpha(*inicio)){ //saltear caracteres que no son letras
            inicio++;
        }

        fin = inicio; // fin de la palabra
        while(*fin && isalpha(*fin)){ // mientras sea una letra
            fin++;
        }

        longitud = fin - inicio; // longitud de la palabra
        if(longitud > 0){
            palabra->palabra = (char*)malloc(longitud+1); // reservo memoria para la palabra
            strncpy(palabra->palabra, inicio, longitud); // copio la palabra
            palabra->palabra[longitud] = '\0'; // agrego el fin de la cadena
            if(poner_arbol(pa, palabra, sizeof(tPalabra), comparar_palabra)==DUPLICADO){
                incrementar_repeticiones(pa, palabra); // si la palabra ya existe en el arbol, incremento las repeticiones
            }else{
                palabra->repeticiones = 1; // si no existe, inicializo las repeticiones
            }

            free(palabra->palabra); // libero la memoria de la palabra
        }

        inicio = fin; // inicio de la proxima palabra
    }
    return 1; // todo salio bien
}

void incrementar_repeticiones(tArbol *pa, tPalabra *palabra) {
    tNodo **encontrado = buscar_nodo(pa, palabra, comparar_palabra); // busco la palabra en el arbol
    if (encontrado != NULL) { // si la palabra fue encontrada
        ((tPalabra *)(*encontrado)->info)->repeticiones++; // incremento las repeticiones
    }
}

int comparar_palabra(const void *p1, const void *p2){
    tPalabra *palabra1 = (tPalabra*)p1;
    tPalabra *palabra2 = (tPalabra*)p2;
    return strcmp(palabra1->palabra, palabra2->palabra);
}

void imprimir_palabra(void *info, void *param){
    tPalabra *palabra = (tPalabra*)info;
    printf("Palabra: %s, Repeticiones: %u", palabra->palabra, palabra->repeticiones);
}

void palabra_mayor_repeticion(const tArbol *pa, tPalabra *mayor) {
    if (!*pa) {
        return;
    }
    tPalabra *actual = (tPalabra *)(*pa)->info;
    if (actual->repeticiones > mayor->repeticiones) {
        mayor->palabra = actual->palabra;
        mayor->repeticiones = actual->repeticiones;
    }
    palabra_mayor_repeticion(&(*pa)->izq, mayor);
    palabra_mayor_repeticion(&(*pa)->der, mayor);
}

void palabra_menor_repeticion(const tArbol *pa, tPalabra *menor) {
    if (!*pa) {
        return;
    }
    tPalabra *actual = (tPalabra *)(*pa)->info;
    if (actual->repeticiones < menor->repeticiones || menor->repeticiones == 0) {
        menor->palabra = actual->palabra;
        menor->repeticiones = actual->repeticiones;
    }
    palabra_menor_repeticion(&(*pa)->izq, menor);
    palabra_menor_repeticion(&(*pa)->der, menor);
}