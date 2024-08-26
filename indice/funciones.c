#include "header.h"

int cargar_archivo(const char *ruta){
    FILE *pf;
    tProducto productos[] = {
        {55, "Manzana", 5.50, {12,05,2024}, "Apple"},
        {10, "Pera", 6.20, {15,01,2024}, "Esperar"},
        {34, "Limon", 4.50, {04,07,2024}, "Lilimomones"},
        {7, "Sandia", 16.30, {25,01,2024}, "Tropical"},
        {100, "Melon", 24.10, {13,06,2024}, "Esperar"},
        {75, "Kiwi", 7.25, {10,10,2024}, "Fruti"},
        {60, "Durazno", 5.50, {28,03,2024}, "Fruti"},
        {50, "Pomelo", 18.50, {17,02,2024}, "Tropical"},
        {12, "Frutilla", 6.30, {15,9,2024}, "Tropical"},
        {25, "Banana", 6, {16,05,2024}, "Apple"},
    };

    pf = fopen(ruta, "wb");
    if(pf == NULL){
        printf("Error al abrir el archivo\n");
        return -1; //ERROR DE ARCHIVO
    }
    fwrite(productos, sizeof(productos), 1, pf);
    fclose(pf);
    return 1; //TODO OK
}

int cargar_indice(const char *rutaBin, const char *rutaIdx){
    FILE *archivoProd;
    FILE *archivoInd;
    tProducto prod;
    tIndice ind;
    int pos = 0;

    // abro para leer el archivo de productos
    archivoProd = fopen(rutaBin, "rb");
    if(archivoProd == NULL){
        printf("Error al abrir archivo productos\n");
        return -1;
    }

    // abro para escribir el archivo de indice
    archivoInd = fopen(rutaIdx, "wb");
    if(archivoInd == NULL){
        printf("Error al abrir el indice\n");
        fclose(archivoProd);
        return -2;
    }

    fread(&prod, sizeof(tProducto), 1, archivoProd); // leo el primer registro de productos
    while(!feof(archivoProd)){ // mientras no llegue al fin del archivo de productos
        //tengo que escribir solo el codigo y la posicion
        ind.codigo = prod.codigo;
        ind.posicion = pos;
        pos++; // aumento la posicion despues de cada lectura
        fwrite(&ind, sizeof(tIndice), 1, archivoInd); // escribo el indice
        fread(&prod, sizeof(tProducto), 1, archivoProd); // leo el siguiente registro de productos
    }

    fclose(archivoProd);
    fclose(archivoInd);
    return 1; // TODO OK
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

void recorrer_inOrden(const tArbol *pa, void(*accion)(void*, void*), void *param){
    if(!*pa){
        return;
    }
    recorrer_inOrden(&(*pa)->izq, accion, param);
    accion((*pa)->info, param);
    recorrer_inOrden(&(*pa)->der, accion, param);
}

int cargar_de_indice_a_arbol(const char *rutaIdx, tArbol *pa){
    FILE *archivoInd;
    tIndice ind;

    archivoInd = fopen(rutaIdx, "rb");
    if(archivoInd == NULL){
        printf("Error al abrir el archivo de indice\n");
        return -1;
    }

    fread(&ind, sizeof(tIndice), 1, archivoInd); // leo el primer registro del archivo de indice
    while(!feof(archivoInd)){
        // leo cada registro y guado el registro en un arbol
        poner_en_arbol(pa, &ind, sizeof(tIndice), comparar_codigo); // guardo el indice en el arbol
        fread(&ind, sizeof(tIndice), 1, archivoInd); // leo el siguiente registro del archivo de indice
    }

    fclose(archivoInd);
    return 1;
}

int comparar_codigo(const void *e1, const void *e2){
    const int *cod1 = (const int*)e1;
    const int *cod2 = (const int*)e2;
    return *cod1-*cod2;
}

int cargar_de_arbol_a_indiceOrd(tArbol *pa, const char *rutaIdx){
    FILE *archivoInd;

    archivoInd = fopen(rutaIdx, "wb");
    if(archivoInd == NULL){
        printf("Error al abrir el archivo de indice\n");
        return -1;
    }
    // voy a recorrer el arbol y como accion hago que guarde el arbol en el archivo de indice
    recorrer_inOrden(pa, guardar_en_archInd, archivoInd);

    fclose(archivoInd);
    return 1;
}

// recibo el dato a guardar y la ruta del archivo indice
void guardar_en_archInd(void *info, void *param){
    const tIndice *registro = (const tIndice*)info; // casteo el dato a guardar
    FILE *pf = (FILE*)param; // casteo el archivo de indice
    fwrite(registro, sizeof(tIndice), 1, pf); // guardo el dato en el archivo de indice
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

int mostrar_archivo(const char *rutaBin){
    FILE *pf;
    tProducto prod;
    pf = fopen(rutaBin, "rb");
    if(pf == NULL){
        printf("Error al abrir el archivo\n");
        return -1;
    }
    fread(&prod, sizeof(tProducto), 1, pf);
    while(!feof(pf)){
        mostrar(&prod);
        fread(&prod, sizeof(tProducto), 1, pf);
    }
    fclose(pf);
    return 1;
}

void mostrar(tProducto *prod){
    printf("Codigo: %d\n", prod->codigo);
    printf("Descripcion: %s\n", prod->descripcion);
    printf("Precio: %.2f\n", prod->precio);
    printf("Fecha de compra: %d/%d/%d\n", prod->fechaCompra.dia, prod->fechaCompra.mes, prod->fechaCompra.anio);
    printf("Proveedor: %s\n", prod->proveedor);
    printf("\n");
}

int cargar_arbol_desde_archivo_ordenado(tArbol *pa, const char *ruta, unsigned tam){
    int cantReg, r;
    FILE *pf;
    if(*pa){
        return 0;
    }
    pf = fopen(ruta, "rb");
    if(pf == NULL){
        return -1;
    }
    fseek(pf, 0L, SEEK_END);
    cantReg = ftell(pf)/tam;
    r = cargar_desde_datos_ordenados(pa, pf, leer_desde_archivo, 0, cantReg-1, &tam);
    fclose(pf);
    return r;
}

int cargar_desde_datos_ordenados(tArbol *pa, void *ds, unsigned (*leer)(void **, void *, unsigned, void *param),
                                 int li, int ls, void *param){
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

int buscar_elemento(const tArbol *pa, void *pd, unsigned tam, int(*cmp)(const void*, const void*)){
    if(!(pa = buscar_nodo(pa, pd, cmp))){
        return 0;
    }
    memcpy(pd, (*pa)->info, MINIMO(tam, (*pa)->tamInfo));
    return 1;
}

int modificar_proveedor(const char *rutaBin, tArbol *pa, int cod, const char *prov){
    FILE *pf;
    tProducto prod;
    tIndice ind;
    tNodo **nodo;

    pf = fopen(rutaBin, "r+b"); // abro el archivo en modo lectura y escritura
    if(pf == NULL){
        return -1;
    }

    //busco el nodo en el arbol
    nodo = buscar_nodo(pa, &cod, comparar_codigo);
    if(!nodo){
        printf("Producto no encontrado en el arbol\n");
        fclose(pf);
        return 0;
    }else {
        printf("Producto encontrado\n");
    }

    //copio el nodo para tener la info
    memcpy(&ind, (*nodo)->info, sizeof(tIndice));

    //me ubico en el archivo en la posicion del registro que quiero
    fseek(pf, ind.posicion*sizeof(tProducto), SEEK_SET);

    //leo el registro
    fread(&prod, sizeof(tProducto), 1, pf);

    //realizo el cambio
    strcpy(prod.proveedor, prov);

    //vuelvo atras para poder escribir el registro
    fseek(pf, ind.posicion*sizeof(tProducto), SEEK_SET);

    //escribo el registro con la modificacion
    fwrite(&prod, sizeof(tProducto), 1, pf);

    fclose(pf);
    return 1;
}