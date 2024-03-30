#include "ej_2_4.h"
#include "../Ej-2.1/pila.c"

int cargar_archivo_bin_en_pilaE(const char *ruta, tPila *pp){
    FILE *pf;
    tProducto prod;
    pf = fopen(ruta, "rb");
    if(pf == NULL){
        return -1;
    }

    fread(&prod, sizeof(tProducto), 1, pf);
    while(!feof(pf) && !pila_llena(pp, 0)){
        if(apilar(pp, &prod, sizeof(tProducto))){
            printf("Apilo bien\n");
            mostrar_producto(&prod);
        }
        fread(&prod, sizeof(tProducto), 1, pf);
    }
    fclose(pf);
    return 1;
}

void mostrar_producto(tProducto *prod){
    printf("Codigo: %s\n", prod->codigo);
    printf("Descripcion: %s\n", prod->descripcion);
    printf("Proveedor: %s\n", prod->proveedor);
    printf("Fecha de compra: %d/%d/%d\n", prod->fCompra.dia, prod->fCompra.mes, prod->fCompra.anio);
    printf("Fecha de vencimiento: %d/%d/%d\n", prod->fVencimiento.dia, prod->fVencimiento.mes, prod->fVencimiento.anio);
    printf("Cantidad: %d\n", prod->cantidad);
    printf("Precio de compra: %.2f\n", prod->pCompra);
    printf("Precio de venta: %.2f\n", prod->pVenta);
}

void menu(tPila *pp){
    int opcion;
    do{
        printf("- Menu de opciones -\n");
        printf("1- Cargar en pila\n");
        printf("2- Ver tope de pila\n");
        printf("3- Sacar de pila\n");
        printf("4- Salir del menu\n");
        scanf("%d", &opcion);

        switch(opcion){
            case 1:
                opcion1(pp);
                break;
            case 2:
                opcion2(pp);
                break;
            case 3:
                opcion3(pp);
                break;
            case 4:
                break;
            default: printf("Opcion invalida, vuelva a elegir\n");
        }
    }while(opcion != 4);
}

void opcion1(tPila *pp){
    tProducto prod;
    printf("Ingrese codigo: ");
    scanf("%s", prod.codigo);
    fflush(stdin);
    printf("Ingrese descripcion: ");
    fflush(stdin);
    scanf("%s", prod.descripcion);
    fflush(stdin);
    printf("Ingrese proveedor: ");
    fflush(stdin);
    scanf("%s", prod.proveedor);
    fflush(stdin);
    printf("Ingrese fecha de compra (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &prod.fCompra.dia, &prod.fCompra.mes, &prod.fCompra.anio);
    printf("Ingrese fecha de vencimiento (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &prod.fVencimiento.dia, &prod.fVencimiento.mes, &prod.fVencimiento.anio);
    printf("Ingrese cantidad: ");
    scanf("%d", &prod.cantidad);
    printf("Ingrese precio de compra: ");
    scanf("%f", &prod.pCompra);
    printf("Ingrese previo de venta: ");
    scanf("%f", &prod.pVenta);

    if(!pila_llena(pp, 0)){
        if(apilar(pp, &prod, sizeof(tProducto))){
            printf("Apilo bien (opcion 1)\n");
        }else{
            printf("Error al apilar (opcion 1)");
        }
    }
}

void opcion2(tPila *pp){
    tProducto prod;
    if(!pila_vacia(pp)){
        ver_tope(pp, &prod, sizeof(tProducto));
        printf("Tope: (opcion 2)\n");
        printf("Codigo: %s\n", prod.codigo);
        printf("Descripcion: %s\n", prod.descripcion);
        printf("Proveedor: %s\n", prod.proveedor);
        printf("Fecha de compra: %d/%d/%d\n", prod.fCompra.dia, prod.fCompra.mes, prod.fCompra.anio);
        printf("Fecha de vencimiento: %d/%d/%d\n", prod.fVencimiento.dia, prod.fVencimiento.mes, prod.fVencimiento.anio);
        printf("Cantidad: %d\n", prod.cantidad);
        printf("Precio de compra: %.2f\n", prod.pCompra);
        printf("Precio de venta: %.2f\n", prod.pVenta);
    }
}

void opcion3(tPila *pp){
    tProducto prod;
    if(!pila_vacia(pp)){
        if(desapilar(pp, &prod, sizeof(tProducto))){
            printf("Desapilo bien (opcion 3)\n");
        }else{
            printf("Desapilo mal (opcion 3)\n");
        }
    }
}

int cargar_de_pila_a_archivo(const char *ruta, tPila *pp){
    FILE *pf;
    tProducto prod;
    int existeDato = 0;
    pf = fopen(ruta, "wb");
    if(pf == NULL){
        return -1;
    }
    while(!pila_vacia(pp)){
        desapilar(pp, &prod, sizeof(tProducto));
        existeDato = 1;
        fwrite(&prod, sizeof(tProducto), 1, pf);
    }
    if(existeDato != 1){
        fclose(pf);
        remove(ruta);
    }
    fclose(pf);
    return 1;
}