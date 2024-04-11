#include <iostream>
#include <fstream>
#include <cmath>

bool es_primo(unsigned int numero){
    bool numero_primo = true;
    if(numero > 1){
        for(unsigned int x = 2; x <= sqrt(numero); x++){
            if(numero % x == 0){
                numero_primo = false;
                break;
            }
        }
    }
    return numero_primo;
}

unsigned int valor_primo(unsigned int numero){
    unsigned int aux = 0;
    if(es_primo(numero)){
        aux = numero;
    }
    
}

void contador(unsigned int numero_ingresado){
    unsigned int inicial = 2;
    while(inicial < numero_ingresado){
        if(es_primo(inicial)){
            std::cout<< "el numero: " << inicial << " es primo!" << std::endl;
        }
        inicial++;
    }
}

int main(){
    contador(100000000);
    return 0;
}