// EJERCICIO 1
/*
Cree un TDA Pila genérica implementada sobre un vector estático.
Implemente las primitivas: 
crear_pila, poner_en_pila, sacar_de_pila, pila_llena y pila_vacia.
*/

// EJERCICIO 2
/*
Ejercicio  2:  Una  expresión  está  bien  parentizada  cuando  para  cada  paréntesis  “(“,
corchete  “[“ o  llave  ”{“ abierto, existe uno que lo cierra luego en el orden correspondiente.  
Implemente una función que valide si una cadena que solo puede contener los caracteres “{[(}])”
está bien parentizada.  
Por ejemplo “{}[]()” y “{[()]}” están bien parentizadas, pero “{([])” no. 
Utilice el TDA pila creado en el ejercicio 1.  
Cree un lote de pruebas que tenga en cuenta la mayor cantidad de casos posibles.
*/

#include "header.h"

int main() {
    // Lote de pruebas
    //char cadena1[] = "{}[]()";      // Bien parentizada
    // char cadena2[] = "{[()]}";      // Bien parentizada
    // char cadena3[] = "{([])";       // Mal parentizada (falta cerrar)
    // char cadena4[] = "[{]}";        // Mal parentizada (orden incorrecto)
    // char cadena5[] = "";            // Bien parentizada (vacía)
    // char cadena6[] = "((()))";      // Bien parentizada
     char cadena7[] = "(()))";       // Mal parentizada (desbalanceada)
    // char cadena8[] = "{[]({})}";    // Bien parentizada
    // char cadena9[] = "{[]({)}]";    // Mal parentizada
    
    printf("Validando cadenas:\n");
    
    // Validar cadena1
    if(validar_cadena(cadena7)) {
        printf("La cadena 1 esta bien parentizada\n");
    } else {
        printf("La cadena 1 esta mal parentizada\n");
    }

    return 0;
}