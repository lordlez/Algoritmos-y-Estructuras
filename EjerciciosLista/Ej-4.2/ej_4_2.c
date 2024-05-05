#include "ej_4_2.h"
#include "../Ej-4.1/lista.c"

int ordenar_archivo_v1(const char *ruta, tLista *pl){
    FILE *pf;
    tProducto prod;
    pf = fopen(ruta, "rb+"); //abro el archivo para leer y escribir

    if(pf == NULL){
        return -1;
    }

    fread(&prod, sizeof(tProducto), 1, pf);

    while(!feof(pf)){
        if(!lista_llena(pl, sizeof(tProducto))){
            poner_ordenado(pl, &prod, sizeof(tProducto), cmp_productos);
        }
        fread(&prod, sizeof(tProducto), 1, pf);
    }

    rewind(pf); //vuelvo al inicio del archivo, para escribir ya ordenado

    while(!lista_vacia(pl)){
        sacar_al_inicio(pl, &prod, sizeof(tProducto));
        fwrite(&prod, sizeof(tProducto), 1, pf);
    }

    fclose(pf);
    return 1;
}

int ordenar_archivo_v2(const char *ruta, tLista *pl){
    FILE *pf;
    tProducto prod;
    pf = fopen(ruta, "rb+"); //abro el archivo para leer y escribir

    if(pf == NULL){
        return -1;
    }

    fread(&prod, sizeof(tProducto), 1, pf);

    while(!feof(pf)){
        if(!lista_llena(pl, sizeof(tProducto))){
            poner_al_inicio(pl, &prod, sizeof(tProducto));
        }
        fread(&prod, sizeof(tProducto), 1, pf);
    }

    ordenar_lista(pl, cmp_productos);

    rewind(pf); //vuelvo al inicio del archivo, para escribir ya ordenado

    while(!lista_vacia(pl)){
        sacar_al_inicio(pl, &prod, sizeof(tProducto));
        fwrite(&prod, sizeof(tProducto), 1, pf);
    }

    fclose(pf);
    return 1;
}

int cmp_productos(const void *e1, const void *e2){
    tProducto *p1 = (tProducto*)e1;
    tProducto *p2 = (tProducto*)e2;
    int cmp;

    if(p1->fVencimiento.anio != p2->fVencimiento.anio){//distinto anio
        return p1->fVencimiento.anio - p2->fVencimiento.anio;//retorno por anio
    }
    if(p1->fVencimiento.mes != p2->fVencimiento.mes){//distinto mes
        return p1->fVencimiento.mes - p2->fVencimiento.mes;//retorno por mes
    }
    if(p1->fVencimiento.dia != p2->fVencimiento.dia){//distinto dia
        return p1->fVencimiento.dia - p2->fVencimiento.dia;//retorno por dia
    }
    //si las fechas son iguales, comparo por proveedor
    if(!(cmp = strcmp(p1->proveedor, p2->proveedor))){//si los proveedores son distintos
        return strcmp(p1->codigo, p2->codigo);//retorno por codigo
    }
    return cmp; //si proveedor distinto, retorno por proveedor
}

int mostrar_archivo(const char *ruta){
    FILE *pf;
    tProducto prod;
    pf = fopen(ruta, "rb");
    if(pf == NULL){
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
    printf("Codigo: %s\n", prod->codigo);
    printf("Descropcion: %s\n", prod->descripcion);
    printf("Proveedor: %s\n", prod->proveedor);
    printf("Fecha de compra: %d/%d/%d\n", prod->fCompra.dia, prod->fCompra.mes, prod->fCompra.anio);
    printf("Fecha de vencimiento: %d/%d/%d\n", prod->fVencimiento.dia, prod->fVencimiento.mes, prod->fVencimiento.anio);
    printf("Precio de compra: %.2f\n", prod->pCompra);
    printf("Precio de venta: %.2f\n", prod->pVenta);
    printf("\n");
}