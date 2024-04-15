#include "ej_3_3.h"
#include "../Ej-3.1/colaE.c"

int cargar_archivo_bin_en_colaE(const char *ruta, tCola *pc){
    FILE *pf;
    tProducto prod;
    pf = fopen(ruta, "rb");
    if(pf == NULL){
        return -1;
    }

    fread(&prod, sizeof(tProducto), 1, pf);
    while(!feof(pf) && !cola_llena(pc, sizeof(tProducto))){
        if(encolar(pc, &prod, sizeof(tProducto))){
            printf("Encolo bien\n");
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


void menu(tCola *pc){
    int opcion;
    do{
        printf("- Menu de opciones -\n");
        printf("1- Cargar en cola\n");
        printf("2- Ver primero de cola\n");
        printf("3- Sacar de cola\n");
        printf("4- Salir del menu\n");
        scanf("%d", &opcion);

        switch(opcion){
            case 1:
                opcion1(pc);
                break;
            case 2:
                opcion2(pc);
                break;
            case 3:
                opcion3(pc);
                break;
            case 4:
                break;
            default: printf("Opcion invalida, vuelva a elegir\n");
        }
    }while(opcion != 4);
}

void opcion1(tCola *pc){
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

    if(!cola_llena(pc, sizeof(tProducto))){
        if(encolar(pc, &prod, sizeof(tProducto))){
            printf("Encolo bien (opcion 1)\n");
        }else{
            printf("Error al encolar (opcion 1)");
        }
    }
}

void opcion2(tCola *pc){
    tProducto prod;
    if(!cola_vacia(pc)){
        ver_primero(pc, &prod, sizeof(tProducto));
        printf("Primero: (opcion 2)\n");
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

void opcion3(tCola *pc){
    tProducto prod;
    if(!cola_vacia(pc)){
        if(desencolar(pc, &prod, sizeof(tProducto))){
            printf("Desencolo bien (opcion 3)\n");
        }else{
            printf("Desencolo mal (opcion 3)\n");
        }
    }
}

int cargar_de_cola_a_archivo(const char *ruta, tCola *pc){
    FILE *pf;
    tProducto prod;
    int existeDato = 0;
    pf = fopen(ruta, "wb");
    if(pf == NULL){
        return -1;
    }
    while(!cola_vacia(pc)){
        desencolar(pc, &prod, sizeof(tProducto));
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