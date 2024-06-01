#include <iostream>
/*
Escriba una funcion que acepte como parametro un 
numero entero N y calcule 1 + 2 + 3 +...+ N
*/


unsigned int calcular(unsigned int numero){
    int resultado = 0;
    int aux = numero;
    for (unsigned int i = 0; i < numero; i++)
    {
        resultado = resultado + aux;
        aux = aux - 1;
    }
    return resultado;
}

int main(){

    std::cout<< "El resultado es: " << calcular(9) << std::endl;

    return 0;
}