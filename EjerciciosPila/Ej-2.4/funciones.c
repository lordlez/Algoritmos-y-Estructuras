#include "header.h"

void crear_pila(tPila *pp){
    *pp = NULL;
}

void vaciar_pila(tPila *pp){
    tNodo *elim;
    while(*pp){
        elim = *pp;
        *pp = elim->sig;
        free(elim->info);
        free(elim);
    }
}

int apilar(tPila *pp, const void *pd, unsigned tam){
    tNodo *nuevo = malloc(sizeof(tNodo));
    void *elemNodo = malloc(tam);
    if(!nuevo || !elemNodo){
        free(nuevo);
        free(elemNodo);
        return 0;
    }

    nuevo->info = elemNodo;
    nuevo->tamInfo = tam;
    memcpy(elemNodo, pd, tam);
    nuevo->sig = *pp;
    *pp = nuevo;

    return 1;
}

int desapilar(tPila *pp, void *pd, unsigned tam){
    tNodo *elim;
    if(*pp == NULL){
        return 0;
    }
    elim = *pp;
    *pp = elim->sig;
    memcpy(pd, elim->info, MIN(tam, elim->tamInfo));
    free(elim->info);
    free(elim);

    return 1;
}

int ver_tope(const tPila *pp, void *pd, unsigned tam){
    if(*pp == NULL){
        return 0;
    }
    memcpy(pd, (*pp)->info, MIN(tam, (*pp)->tamInfo));
    return 1;
}

int pila_llena(const tPila *pp, unsigned tam){
    tNodo *vnodo = malloc(sizeof(tNodo));
    void *velem = malloc(tam);

    free(vnodo);
    free(velem);

    return vnodo == NULL || velem == NULL;
}

int pila_vacia(const tPila *pp){
    if(*pp == NULL){
        return 1;
    }
    return 0;
}

int archivo_a_pila(char *ruta, tPila *pila){
    tProducto producto;
    FILE *pf;
    pf = fopen(ruta, "rb");
    if(pf == NULL){
        return -1;
    }

    crear_pila(pila);

    fread(&producto, sizeof(tProducto), 1, pf);
    while(!feof(pf)){
        if(!pila_llena(pila, sizeof(tProducto))){
            apilar(pila, &producto, sizeof(tProducto));
        }
        fread(&producto, sizeof(tProducto), 1, pf);
    }

    fclose(pf);

    return 1;
}

void menu(tPila *pila){
    int opcion;

    do{
        printf("1 - Agregar a la pila\n");
        printf("2 - Ver tope de pila\n");
        printf("3 - Sacar de la pila\n");
        printf("4 - Salir del menu\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion){
            case 1:
                opcion1(pila);
                break;
            case 2:
                opcion2(pila);
                break;
            case 3:
                opcion3(pila);
                break;
            case 4:
                printf("\nSaliendo...\n");
                break;
            default:
                printf("\nOpcion invalida, vuelva a seleccionar\n");
        }
    }while(opcion != 4);
}

void opcion1(tPila *pila){
    tProducto producto;

    printf("\nIngrese el codigo del producto: ");
    scanf("%s", producto.codProd);
    printf("\nIngrese la descripcion del producto: ");
    scanf("%s", producto.descripcion);
    printf("\nIngrese el proveedor del producto: ");
    scanf("%s", producto.proveedor);
    printf("\nIngrese la fecha de compra del producto dd/mm/aaaa: ");
    scanf("%d/%d/%d", &producto.fCompra.dia, &producto.fCompra.mes, &producto.fCompra.anio);
    printf("\nIngrese la fecha de vencimiento del producto dd/mm/aaaa: ");
    scanf("%d/%d/%d", &producto.fVenta.dia, &producto.fVenta.mes, &producto.fVenta.anio);
    printf("\nIngrese la cantidad del producto: ");
    scanf("%d", &producto.cantidad);
    printf("\nIngrese el precio de compra: ");
    scanf("%f", &producto.compra);
    printf("\nIngrese el precio de venta: ");
    scanf("%f", &producto.venta);

    if(!pila_llena(pila, sizeof(tProducto))){
        apilar(pila, &producto, sizeof(tProducto));
    }
}

void opcion2(tPila *pila){
    tProducto producto;

    if(!pila_vacia(pila)){
        ver_tope(pila, &producto, sizeof(tProducto));
        printf("\nCodigo del producto: %s", producto.codProd);
        printf("\nDescripcion del producto: %s", producto.descripcion);
        printf("\nProveedor del producto: %s", producto.proveedor);
        printf("\nFecha de compra del producto dd/mm/aaaa: %d/%d/%d", producto.fCompra.dia, producto.fCompra.mes, producto.fCompra.anio);
        printf("\nFecha de vencimiento del producto dd/mm/aaaa: %d/%d/%d", producto.fVenta.dia, producto.fVenta.mes, producto.fVenta.anio);
        printf("\nCantidad del producto: %d", producto.cantidad);
        printf("\nPrecio de compra: %.2f", producto.compra);
        printf("\nPrecio de venta: %.2f", producto.venta);
    }
}

void opcion3(tPila *pila){
    tProducto producto;

    if(!pila_vacia(pila)){
        desapilar(pila, &producto, sizeof(tProducto));
    }
}

int comprobar_pila(char *ruta, tPila *pila){

    tProducto producto;
    int noBorra = 0;
    FILE *pf;
    pf = fopen(ruta, "wb");
    if(pf == NULL){
        return -1;
    }
    // Si la pila no esta vacia, saco los productos y los meto en el archivo
    while(!pila_vacia(pila)){
        desapilar(pila, &producto, sizeof(tProducto));
        fwrite(&producto, sizeof(tProducto), 1, pf);
        noBorra = 1;
    }
    // Si el archivo tiene contenido, no lo borro, sino lo elimino
    if(noBorra == 1){
        fclose(pf);
        return 1;
    }else{
        fclose(pf);
        remove(ruta);
        return 1;
    }
}

int leer_archivo(char *ruta){
    tProducto producto;
    FILE *pf;
    pf = fopen(ruta, "rb");
    if(pf == NULL){
        return -1;
    }
    fread(&producto, sizeof(tProducto), 1, pf);
    while(!feof(pf)){
        mostrar_producto(&producto);
        fread(&producto, sizeof(tProducto), 1, pf);
    }

    fclose(pf);

    return 1;
}

void mostrar_producto(tProducto *producto){
    printf("\nCodigo del producto: %s", producto->codProd);
    printf("\nDescripcion del producto: %s", producto->descripcion);
    printf("\nProveedor del producto: %s", producto->proveedor);
    printf("\nFecha de compra del producto dd/mm/aaaa: %d/%d/%d", producto->fCompra.dia, producto->fCompra.mes, producto->fCompra.anio);
    printf("\nFecha de vencimiento del producto dd/mm/aaaa: %d/%d/%d", producto->fVenta.dia, producto->fVenta.mes, producto->fVenta.anio);
    printf("\nCantidad del producto: %d", producto->cantidad);
    printf("\nPrecio de compra: %.2f", producto->compra);
    printf("\nPrecio de venta: %.2f", producto->venta);
}