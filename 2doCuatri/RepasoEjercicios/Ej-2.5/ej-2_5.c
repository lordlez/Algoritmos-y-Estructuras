#include "ej-2_5.h"
#include "../Ej-2.2/pilaDinamica.c"

int cargar_pila_con_archivo(tPila *pp, const char *ruta){
    FILE *pf;
    tProducto prod;

    pf = fopen(ruta, "rb");
    if(pf == NULL){
        printf("Error al abrir el archivo");
        return -1;
    }

    fread(&prod, sizeof(tProducto), 1, pf);
    while(!feof(pf) && !pila_llena(pp, sizeof(tProducto))){
        if(apilar(pp, &prod, sizeof(tProducto))){
            printf("Apilo bien\n");
        }else{
            printf("Error al apilar\n");
        }
        fread(&prod, sizeof(tProducto), 1, pf);
    }

    fclose(pf);
    return 1;
}

void menu(tPila *pp, const char *ruta){
    int opcion;
    do{
        printf("\t\tOperaciones de pila\n");
        printf("1 - Cargar en pila\n");
        printf("2 - Sacar de pila\n");
        printf("3 - Ver tope de pila\n");
        printf("4 - Salir\n");
        printf("Elija una opcion: ");
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
                printf("Saliendo...\n");
                opcion4(pp, ruta);
                break;
            default:
                printf("Opcion invalida, vuelva a elegir\n");
        }

    }while(opcion != 4);
}

void opcion1(tPila *pp){
    tProducto prod;

    printf("Ingrese codigo: ");
    scanf("%s", prod.codigo);
    printf("\n");
    printf("Ingrese descripcion: ");
    scanf("%s", prod.descripcion);
    printf("\n");
    printf("Ingrese proveedor: ");
    scanf("%s", prod.proveedor);
    printf("\n");
    fflush(stdin);
    printf("Ingrese fecha de compra (dd/mm/aaa): ");
    scanf("%d/%d/%d", &prod.fCompra.dia, &prod.fCompra.mes, &prod.fCompra.anio);
    printf("\n");
    printf("Ingrese fecha de vencimiento (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &prod.fVencimiento.dia, &prod.fVencimiento.mes, &prod.fVencimiento.anio);
    printf("\n");
    printf("Ingrese cantidad: ");
    scanf("%d", &prod.cantidad);
    printf("\n");
    printf("Ingrese preciod de compra: ");
    scanf("%f", &prod.pCompra);
    printf("\n");
    printf("Ingrese precio de venta: ");
    scanf("%f", &prod.pVenta);
    printf("\n");


    if(!pila_llena(pp, sizeof(tProducto))){
        if(apilar(pp, &prod, sizeof(tProducto))){
            printf("Producto agregado\n");
        }else{
            printf("Error al agregar producto\n");
        }
    }
}

void opcion2(tPila *pp){
    tProducto prod;

    if(!pila_vacia(pp)){
        if(desapilar(pp, &prod, sizeof(tProducto))){
            printf("Producto eliminado\n");
        }else{
            printf("Error al eliminar producto\n");
        }
    }
}

void opcion3(tPila *pp){
    tProducto prod;

    if(ver_tope(pp, &prod, sizeof(tProducto))){
        printf("El tope es: \n");
        printf("Codigo: %s", prod.codigo);
        printf("\n");
        printf("Descripcion: %s", prod.descripcion);
        printf("\n");
        printf("Proveedor: %s", prod.proveedor);
        printf("\n");
        printf("Fecha de compra: %d/%d/%d", prod.fCompra.dia, prod.fCompra.mes, prod.fCompra.anio);
        printf("\n");
        printf("Fecha de vencimiento: %d/%d/%d", prod.fVencimiento.dia, prod.fVencimiento.mes, prod.fVencimiento.anio);
        printf("\n");
        printf("Cantidad: %d", prod.cantidad);
        printf("\n");
        printf("Precio de compra: %.2f", prod.pCompra);
        printf("\n");
        printf("Precio de venta: %.2f", prod.pVenta);
        printf("\n");
    }else{
        printf("No hay tope\n");
    }
}

int opcion4(tPila *pp, const char *ruta){
    FILE *pf;
    tProducto prod;
    int existeDato = 0;

    pf = fopen(ruta, "wb");
    if(pf == NULL){
        printf("Error al abrir el archivo\n");
        return -1;
    }

    while(!pila_vacia(pp)){
        if(desapilar(pp, &prod, sizeof(tProducto))){
            existeDato = 1;
            fwrite(&prod, sizeof(tProducto), 1, pf);
        }
    }

    if(existeDato != 1){
        fclose(pf);
        remove(ruta);
    }

    fclose(pf);
    return 1;
}