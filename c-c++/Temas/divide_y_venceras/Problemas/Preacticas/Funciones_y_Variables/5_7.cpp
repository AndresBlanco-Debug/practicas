#include <iostream>
/*realice un programa que calcule el maximo 
(por medio de una funcion) dado un numero y su cuadrado*/

float maximo(float a, float b){
    float mayor;
    if(a > b){
        mayor = a;
    }else{
        mayor = b;
    }
    return mayor;
}

int main(){
    float x, y;
    float mayor;
    std::cout << "Introduzca el num: " << std::endl;
    std::cin >> x;
    std::cout << "El maximo es: " << maximo(x,x*x) << std::endl;
    return 0;
}