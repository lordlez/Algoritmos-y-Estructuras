#include "header.h"

int cargar_archivo_bin(const char *ruta){
    FILE *pf;
    tAlumno alumnos[] = {
        {11, "Lezcano Lorenzo", 'A'},
        {22, "Martinez Lautaro", 'A'},
        {33, "Messi Lionel", 'A'},
        {44, "Fernandez Enzo", 'A'},
        {55, "Alvarez Julian", 'A'},
    };
    pf = fopen(ruta, "wb");
    if(pf == NULL){
        printf("Error al abrir el archivo alumnos para escribir\n");
        return -1; //EROR ARCHIVO
    }
    fwrite(alumnos, sizeof(alumnos), 1, pf);
    fclose(pf);
    return 1;
}

int cargar_indice_alumnos(const char *rutaBin, const char *rutaIdx){
    FILE *archivoAlumnos;
    FILE *archivoIndice;
    tAlumno alu;
    tIndice ind;
    int pos = 0;

    archivoAlumnos = fopen(rutaBin, "rb");
    if(archivoAlumnos == NULL){
        printf("Error al abrir el archivo alumnos para leer\n");
        return -1;
    }
    archivoIndice = fopen(rutaIdx, "wb");
    if(archivoIndice == NULL){
        printf("Error al abrir el archivo indice para escribir\n");
        fclose(archivoAlumnos);
        return -2;
    }

    fread(&alu, sizeof(tAlumno), 1, archivoAlumnos);
    while(!feof(archivoAlumnos)){
        ind.dni = alu.dni;
        ind.posicion = pos;
        pos++; // aumento la posicion cada vez que leo un registro
        fwrite(&ind, sizeof(tIndice), 1, archivoIndice); // escribo en el archivo de indices el dni y la pos
        fread(&alu, sizeof(tAlumno), 1, archivoAlumnos); // leo otro registro de alumnos
    }

    fclose(archivoAlumnos);
    fclose(archivoIndice);
    return 1;
}

void crear_arbol(tArbol *pa){
    *pa = NULL;
}

int poner_en_arbol(tArbol *pa, const void *pd, unsigned tam, int(*cmp)(const void*, const void*)){
    tNodo *nuevo;
    int comparar;

    while(*pa){
        if((comparar = cmp(pd, (*pa)->info))<0){
            pa = &(*pa)->izq;
        }else if(comparar>0){
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

int comparar_dni(const void*e1, const void*e2){
    const int *dni1 = (const int*)e1;
    const int *dni2 = (const int*)e2;
    return *dni1-*dni2;
}

int cargar_desde_archivoDes_a_arbol(const char *ruta, tArbol *pa){
    FILE *pf;
    tIndice ind;

    pf = fopen(ruta, "rb");
    if(pf == NULL){
        printf("Error al abrir el archivo indice para leer\n");
        return -1; // ERROR DE ARCHIVO
    }

    fread(&ind, sizeof(tIndice), 1, pf);
    while(!feof(pf)){
        poner_en_arbol(pa, &ind, sizeof(tIndice), comparar_dni);
        fread(&ind, sizeof(tIndice), 1, pf);
    }

    fclose(pf);
    return 1;
}

void recorrer_inOrden(const tArbol *pa, void(*accion)(void*, void*), void *param){
    if(!*pa){
        return;
    }
    recorrer_inOrden(&(*pa)->izq, accion, param);
    accion((*pa)->info, param);
    recorrer_inOrden(&(*pa)->der, accion, param);
}

int cargar_desde_arbol_a_archivo(const char *ruta, tArbol *pa){
    FILE *pf;


    pf = fopen(ruta, "wb");
    if(pf == NULL){
        printf("Error al abrir el archivo de indice para escribir\n");
        return -1; // ERROR DE ARCHIVO
    }

    recorrer_inOrden(pa, guardar_en_archivo, pf); //recorro el arbol y lo guardo en el archivo indice

    fclose(pf);
    return 1;
}

void guardar_en_archivo(void *info, void *param){
    tIndice *registro = (tIndice*)info;
    FILE *pf = (FILE*)param;
    fwrite(registro, sizeof(tIndice), 1, pf);
}

int cargar_arbol_desde_archivo_ordenado(tArbol *pa, const char *ruta, unsigned tam){
    int cantReg, r;
    FILE *pf;

    if(*pa){
        return 0;
    }

    pf = fopen(ruta, "rb");
    if(pf == NULL){
        printf("Error al abrir el archivo indice para leer\n");
        return -1; // ERROR DE ARCHIVO
    }

    fseek(pf, 0L, SEEK_END);
    cantReg = ftell(pf)/tam;
    r = cargar_desde_datos_ordenados(pa, pf, leer_desde_archivo, 0, cantReg-1, &tam);
    fclose(pf);
    return r;
}

int cargar_desde_datos_ordenados(tArbol *pa, void *ds, unsigned(*leer)(void**, void*, unsigned, void*param), int li, int ls, void *param){
    int m = (li+ls)/2;
    int r;

    if(li>ls){
        return 1;
    }
    (*pa) = (tNodo*)malloc(sizeof(tNodo));
    if(!*pa || !((*pa)->tamInfo = leer(&(*pa)->info, ds, m, param))){
        free(*pa);
        return 0;
    }
    (*pa)->izq = NULL;
    (*pa)->der = NULL;
    if((r = cargar_desde_datos_ordenados(&(*pa)->izq, ds, leer, li, m-1, param))!=1){
        return r;
    }
    return cargar_desde_datos_ordenados(&(*pa)->der, ds, leer, m+1, ls, param);
}

unsigned leer_desde_archivo(void **d, void *pf, unsigned pos, void *param){
    unsigned tam = *((int*)param);
    *d = malloc(tam);
    if(!*d){
        return 0;
    }
    fseek((FILE*)pf, pos*tam, SEEK_SET);
    return fread(*d, tam, 1, (FILE*)pf);
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

void menu(tArbol *pa, int *dni, const char *rutaBin, const char *rutaIdx){

    int opcion;
    printf("Bienvenido/a! al SISTEMA DE BAJAS\n");
    printf("---------------------------------\n");
    printf("Elija una opcion\n");

    do{
        printf("1 - Cambiar estado de alumno a B\n");
        printf("2 - Grabar arbol en archivo binario de indice\n");
        printf("3 - Vaciar arbol\n");
        printf("4 - Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);
        switch(opcion){
            case 1:
                printf("Opcion 1 - Dando de baja a un alumno...\n");
                baja_alumno(dni, pa, rutaBin);
                break;
            case 2:
                printf("Opcion 2 - Guardando arbol en archivo de indice...\n");
                cargar_desde_arbol_a_archivo(rutaIdx, pa);
                break;
            case 3:
                printf("Opcion 3 - Vaciando el arbol...\n");
                vaciar_arbol(pa);
                break;
            case 4:
                printf("Saliendo...\n");
                break;
            default: printf("Opcion incorrecta, vuelva a elegir: \n");
        }
    }while(opcion != 4);
}

int buscar_elemento(const tArbol *pa, void *pd, unsigned tam, int(*cmp)(const void*, const void*)){
    if(!(pa = buscar_nodo(pa, pd, cmp))){
        return 0;
    }
    memcpy(pd, (*pa)->info, MIN(tam, (*pa)->tamInfo));
    return 1;
}

tNodo **buscar_nodo(const tArbol *pa, void *pd, int(*cmp)(const void*, const void*)){
    int comparar;

    while(*pa && (comparar = cmp(pd, (*pa)->info))){
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

int eliminar_elemento(tArbol *pa, void *pd, unsigned tam, int(*cmp)(const void*, const void*)){
    if(!(pa = buscar_nodo(pa, pd, cmp))){
        return 0;
    }
    memcpy(pd, (*pa)->info, MIN(tam, (*pa)->tamInfo));
    return eliminar_raiz(pa);
}

int altura(const tArbol *pa){
    int hizq, hder;
    if(!*pa){
        return 0;
    }
    hizq = altura(&(*pa)->izq);
    hder = altura(&(*pa)->der);
    return (hizq>hder?hizq:hder)+1;
}

tNodo **mayor_nodo(const tArbol *pa){
    if(!*pa){
        return NULL;
    }
    while((*pa)->der){
        pa = &(*pa)->der;
    }
    return (tNodo**)pa;
}

tNodo **menor_nodo(const tArbol *pa){
    if(!*pa){
        return NULL;
    }
    while((*pa)->izq){
        pa = &(*pa)->izq;
    }
    return (tNodo**)pa;
}

int eliminar_raiz(tArbol *pa){
    tNodo **remp, *elim;
    if(!*pa){
        return 0;
    }
    free((*pa)->info);
    if(!(*pa)->izq && !(*pa)->der){
        free(*pa);
        *pa = NULL;
        return 1;
    }
    remp = altura(&(*pa)->izq)>altura(&(*pa)->der)?mayor_nodo(&(*pa)->izq):menor_nodo(&(*pa)->der);
    elim = *remp;
    (*pa)->info = elim->info;
    (*pa)->tamInfo = elim->tamInfo;
    *remp = elim->izq?elim->izq:elim->der;
    free(elim);
    return 1;
}

int baja_alumno(int *dni, tArbol *pa, const char *rutaBin){
    FILE *pf;
    tAlumno alu;
    tIndice ind;
    tNodo **nodo;

    pf = fopen(rutaBin, "r+b");
    if(pf == NULL){
        printf("Error al abrir el archivo de alumnos para editar\n");
        return -1; // ERROR DE ARCHIVO
    }

    // Buscar el índice en el árbol
    nodo = buscar_nodo(pa, dni, comparar_dni);
    if (!nodo) {
        printf("Alumno no encontrado en el indice\n");
        return 0;
    }else{
        printf("Alumno encontrado en el indice\n");
    }

    // Obtener la posición del registro en el archivo de alumnos
    memcpy(&ind, (*nodo)->info, sizeof(tIndice));

    // Moverse directamente a la posición del registro en el archivo
    fseek(pf, ind.posicion * sizeof(tAlumno), SEEK_SET);

    // Leer el registro del archivo
    fread(&alu, sizeof(tAlumno), 1, pf);

    // Cambiar el estado del alumno a 'B'
    alu.estado = 'B';

    // Moverse de nuevo a la posición del registro en el archivo
    fseek(pf, ind.posicion * sizeof(tAlumno), SEEK_SET);

    // Escribir el registro actualizado de nuevo en el archivo
    fwrite(&alu, sizeof(tAlumno), 1, pf);

    // Cerrar el archivo de alumnos
    fclose(pf);

    // Eliminar el índice del árbol
    if(eliminar_elemento(pa, dni, sizeof(int), comparar_dni)){
        printf("Elemento eliminado del indice\n");
    }else{
        printf("Error al eliminar elemento\n");
    }

    return 1;
}

int mostrar_archivo(const char *rutaBin){
    FILE *pf;
    tAlumno alu;
    pf = fopen(rutaBin, "rb");
    if(pf == NULL){
        printf("Error al abrir el archivo alumnos para leer\n");
        return -1; //ERROR ARCHIVO
    }
    fread(&alu, sizeof(tAlumno), 1, pf);
    while(!feof(pf)){
        mostrar(&alu);
        fread(&alu, sizeof(tAlumno), 1, pf);
    }
    fclose(pf);
    return 1;
}

void mostrar(tAlumno *alu){
    printf("DNI: %d\n", alu->dni);
    printf("Apellido y Nombre: %s\n", alu->apyn);
    printf("Estado: %c\n", alu->estado);
    printf("\n");
}
