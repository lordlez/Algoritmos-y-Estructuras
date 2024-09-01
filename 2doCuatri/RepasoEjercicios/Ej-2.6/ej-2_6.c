#include "ej-2_6.h"
#include "../Ej-2.2/pilaDinamica.c"

int ordenar_archivo_con_pilas(const char *ruta, tPila *p1, tPila *p2){
    FILE *pf;
    tProducto prodArch, prodP1, prodP2;

    pf = fopen(ruta, "rb+");
    if(pf == NULL){
        printf("Error al abrir el archivo\n");
        return -1;
    }

    fread(&prodArch, sizeof(tProducto), 1, pf);
    while(!feof(pf) && !pila_llena(p1, sizeof(tProducto)) && !pila_llena(p2, sizeof(tProducto))){
        if(pila_vacia(p1)){ //Si p1 esta vacia
            printf("Pila1 vacia\n");
            apilar(p1, &prodArch, sizeof(tProducto));//meto del archivo a p1
            while(!pila_vacia(p2)){//si hay datos en p2
                printf("Pila2 no vacia\n");
                desapilar(p2, &prodP2, sizeof(tProducto));//saco de p2
                apilar(p1, &prodP2, sizeof(tProducto));// y meto en p1
            }
        }else{//si p1 NO esta vacia
            printf("Pila1 no vacia\n");
            ver_tope(p1, &prodP1, sizeof(tProducto));//veo cual es el tope de p1
            if(strcmp(prodArch.codigo, prodP1.codigo) < 0){//si el dato del arch es menor que tope p1
                printf("dato arch menor que dato p1\n");
                apilar(p1, &prodArch, sizeof(tProducto));//meto en p1
                while(!pila_vacia(p2)){//si hay datos en p2
                    desapilar(p2, &prodP2, sizeof(tProducto));//saco de p2
                    apilar(p1, &prodP2, sizeof(tProducto));//y meto en p1
                }
            }else{//si el dato de arch es mayor a tope p1
                printf("dato arch mayor que p1\n");
                desapilar(p1, &prodP1, sizeof(tProducto));//saco de p1
                fseek(pf, -sizeof(tProducto), SEEK_CUR);//me retraso un registro para volver a leerlo
                apilar(p2, &prodP1, sizeof(tProducto));//meto en p2
                fseek(pf, 0L, SEEK_CUR);//vuelvo al flujo nornal
            }
        }
        fread(&prodArch, sizeof(tProducto), 1, pf);
    }

    fseek(pf, 0, SEEK_SET); //voy al inicio del archivo

    while(!pila_vacia(p1)){
        desapilar(p1, &prodP1, sizeof(tProducto));
        fwrite(&prodP1, sizeof(tProducto), 1, pf);
    }

    fclose(pf);
    return 1;
}

int mostrar_archivo(const char *ruta){
    FILE *pf;
    tProducto prod;
    pf = fopen(ruta, "rb");
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
    printf("Codigo: %s\n", prod->codigo);
    printf("Descipcion: %s\n", prod->descripcion);
    printf("Proveedor: %s\n", prod->proveedor);
    printf("Fecha de compra: %d/%d/%d\n", prod->fCompra.dia, prod->fCompra.mes, prod->fCompra.anio);
    printf("Fecha de vencimiento: %d/%d/%d\n", prod->fVencimiento.dia, prod->fVencimiento.mes, prod->fVencimiento.anio);
    printf("Cantidad: %d\n", prod->cantidad);
    printf("Precio de compra: %.2f\n", prod->pCompra);
    printf("Precio de venta: %.2f\n", prod->pVenta);
    printf("\n");
}