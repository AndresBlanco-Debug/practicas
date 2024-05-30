#include <iostream>
/*esciba una funcion que dado un numero imprima cifra por cifra*/

void imprimir_digito(int numero){
    unsigned int divisor = 10;
    while(numero != 0){
        std::cout << numero % divisor << std::endl;
        numero = numero / divisor;
    }
}

int main(){
    imprimir_digito(123456879);
    return 0;
}