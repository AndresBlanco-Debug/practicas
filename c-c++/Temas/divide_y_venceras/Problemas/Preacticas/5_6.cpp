#include <iostream>
/*Escriba una funcion que devuelva el resultado de elevar
un nuero real a una determinada potencia*/

void pedir_potencia(int& potencia){
    std::cout << "Ingrese la potencia: " << std::endl;
    std::cin >> potencia;
}

void pedir_numero(int& numero){
    std::cout << "Ingrese el numero base: " << std::endl;
    std::cin >> numero;
}

float potenciar_numero(int numero, int potencia){
    //pensado con for para no usar la libreria <cmath> 
    float resultado;
    for(unsigned int x = 0; x < potencia; x++){
        resultado = numero * numero;
    }
    return resultado;
}

int main(){
    
    int potencia, numero;
    pedir_potencia(potencia);
    pedir_numero(numero);

    float resultado = potenciar_numero(numero, potencia);
    std::cout<< "El numero: " << numero << " elevado a " << potencia << " es : " << resultado << std::endl;

    return 0;
}