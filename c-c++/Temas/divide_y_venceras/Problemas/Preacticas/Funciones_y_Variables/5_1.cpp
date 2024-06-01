#include <iostream>

//hace falta produnfizar en el iostream y todos sus componentes

/*Escribir una funcion que imprima por pantalla
el doble del numero que recibe como parametro*/

int main(){
    int numero;
    std::cout << "Ingrese un numero real "<< std::endl;
    std::cin >> numero;

    std::cout << (numero * 2) << std::endl; 

    return 0;
}