#include "intercambios.h"

void intercambiar_int(int valor_1, int valor_2){
    int aux = valor_2;
    valor_2 = valor_1;
    valor_1 = aux;
}

void intercambiar_int_con_referencia(int& referencia_1, int& referencia_2){
    int aux = referencia_2;
    referencia_2 = referencia_1;
    referencia_1 = aux;
}

void intercambiar_puntero(int* puntero_1, int* puntero_2){
    int* aux = puntero_2;
    puntero_2 = puntero_1;
    puntero_1 = aux;
}