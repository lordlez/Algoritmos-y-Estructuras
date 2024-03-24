#include "header.h"


void crear_cola(tCola *pc){
    pc->pri = NULL;
    pc->ult = NULL;
}

void vaciar_cola(tCola *pc){
    tNodo *elim;
    while(pc->pri != NULL){
        elim = pc->pri;
        pc->pri = elim->sig;
        free(elim->info);
        free(elim);
    }
    pc->ult = NULL;
}

int poner_en_cola(tCola *pc, const void *pd, unsigned tam){
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
    nuevo->sig = NULL;
    if(pc->pri == NULL){
        pc->pri = nuevo;
    }else{
        pc->ult->sig = nuevo;
    }
    pc->ult = nuevo;

    return 1;
}

int sacar_de_cola(tCola *pc, void *pd, unsigned tam){
    tNodo *elim;
    if(pc->pri == NULL){
        return 0;
    }
    elim = pc->pri;
    pc->pri = elim->sig;
    memcpy(pd, elim->info, MIN(tam, elim->tamInfo));
    free(elim->info);
    free(elim);
    if(pc->pri == NULL){
        pc->ult = NULL;
    }

    return 1;
}

int ver_primero(const tCola *pc, void *pd, unsigned tam){
    if(pc->pri == NULL){
        return 0;
    }
    memcpy(pd, pc->pri->info, MIN(tam, pc->pri->tamInfo));

    return 1;
}

int cola_llena(const tCola *pc, unsigned tam){
    return 0;
}

int cola_vacia(const tCola *pc){
    if(pc->pri == NULL){
        return 1;
    }
    return 0;
}


int archivo_a_cola(char *ruta, tCola *cola){
    tProducto producto;
    FILE *pf;
    pf = fopen(ruta, "rb");
    if(pf == NULL){
        return -1;
    }

    crear_cola(cola);

    fread(&producto, sizeof(tProducto), 1, pf);
    while(!feof(pf)){
        if(!cola_llena(cola, sizeof(tProducto))){
            poner_en_cola(cola, &producto, sizeof(tProducto));
        }
        fread(&producto, sizeof(tProducto), 1, pf);
    }

    fclose(pf);

    return 1;
}

void menu(tCola *cola){
    int opcion;

    do{
        printf("1 - Agregar a la cola\n");
        printf("2 - Ver primero de cola\n");
        printf("3 - Sacar de la cola\n");
        printf("4 - Salir del menu\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion){
            case 1:
                opcion1(cola);
                break;
            case 2:
                opcion2(cola);
                break;
            case 3:
                opcion3(cola);
                break;
            case 4:
                printf("\nSaliendo...\n");
                break;
            default:
                printf("\nOpcion invalida, vuelva a seleccionar\n");
        }
    }while(opcion != 4);
}

void opcion1(tCola *cola){
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

    if(!cola_llena(cola, sizeof(tProducto))){
        poner_en_cola(cola, &producto, sizeof(tProducto));
    }
}

void opcion2(tCola *cola){
    tProducto producto;

    if(!cola_vacia(cola)){
        ver_primero(cola, &producto, sizeof(tProducto));
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

void opcion3(tCola *cola){
    tProducto producto;

    if(!cola_vacia(cola)){
        sacar_de_cola(cola, &producto, sizeof(tProducto));
    }
}

int comprobar_cola(char *ruta, tCola *cola){

    tProducto producto;
    int noBorra = 0;
    FILE *pf;
    pf = fopen(ruta, "wb");
    if(pf == NULL){
        return -1;
    }
    // Si la pila no esta vacia, saco los productos y los meto en el archivo
    while(!cola_vacia(cola)){
        sacar_de_cola(cola, &producto, sizeof(tProducto));
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