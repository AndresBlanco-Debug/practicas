#include <iostream>
#include <math.h>
/*Escriba una funcion que calcule el area de un circulo dado su radio*/

void nro_natural(int lado){
    if(lado < 0){
        throw "Error! No se admiten lados negativos";
    }
}

//problema presentado: terminate called after throwing an instance of 'char const*'

float calcular_area(unsigned int radio){
    const float pi = 3.14159265358979323846;
    nro_natural(radio);
    return (pi * (pow(radio,2)));
}

int main(){
    std::cout<< calcular_area(3) << std::endl;
    return 0;
}