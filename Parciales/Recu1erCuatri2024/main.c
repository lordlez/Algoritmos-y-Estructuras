#include "parcial.h"
// 38929303_Lezcano_Lorenzo

int main()
{
    char rutaStock[] = "stock.dat";
    char rutaProdOk[] = "prod_ok.dat";
    char rutaProdAVencer[] = "prod_a_vencer.txt";
    int mes = 4;
    tPila pila;

    cargar_archivo_stock(rutaStock);
    menu(rutaStock, mes, rutaProdAVencer, rutaProdOk, &pila);

    if(!pila_vacia(&pila)){
        vaciar_pila(&pila);
    }

    return 0;
}
