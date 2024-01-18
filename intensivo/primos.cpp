/*Hacer una aplicacion que guarde en un archivo de texto todos los numeros primos desde 2 hasta una constante MAXIMO
(menor o igual a 100 millones) en un tiempo razonable.
La aplicacion debe:
- Guardar cada numero en una linea diferente de forma vertical,
- Imprimir por pantalla la cantidad de numeros primos en el archivo,
- El tiempo empleado en el proceso.
*/

#include <fstream>
#include <iostream>

//la forma de abordar este problema es divide y venceras, hacerlo todo en una funcion ineficiente.

void es_primo(unsigned int numero){
    bool aux = true;
    for(int x = 2; x < numero - 1; x++){
        if(numero % x == 0){
            std::cout<<"el numero " << numero << " no es primo!" << std::endl;
            aux = false;
            break;
        }
    }
    if(aux){
        std::cout<<"el numero " << numero << " es primo!" << std::endl;
    }
}

void contador_recursivo(unsigned int numero_ingresado){
    unsigned int numero_inicial = 2;
    while(numero_inicial < numero_ingresado){
        es_primo(numero_inicial);
        numero_inicial++;
    }
}

int main(){
    contador_recursivo(10);
    return 0;
}