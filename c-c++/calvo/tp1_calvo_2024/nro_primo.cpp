/*HAY QUE CREAR UN PROGRAMA QUE CALCULE TODOS LOS NUMEROS PRIMOS DEL 1 AL 10,000,000 EN UN TIEMPO RAZONABLE (NO MAYOR A 5 MINUTOS)*/
/*Numero primo: Numeros que solamente son divisibles entre ellos y la unidad*/
/*forma de calcular numeros primos: */
#include <fstream>
#include <iostream>
#include <cmath>

class nro_natural{
private:
    unsigned int nro;
    void vacio_legal(unsigned int numero);
    bool caso_inicial(unsigned int numero);
public:
    nro_natural(unsigned int numero);
    ~nro_natural();
    bool es_primo(unsigned int numero);
    void set_numero(unsigned int numero);
    unsigned int get_numero();
};

void nro_natural::vacio_legal(unsigned int numero){
/*habria que encontrar una manera de hacer la validacion una sola vez*/
    if(numero < 1){
        throw "Error! solo se aceptan numeros naturales";
    }
}

/*funcion solo de prueba*/
bool nro_natural::caso_inicial(unsigned int numero){
    bool val_return = false;
    if(numero == 2){
        val_return = true;
    }
    return val_return;
}

nro_natural::nro_natural(unsigned int numero){
    this->nro = numero;
}

nro_natural::~nro_natural(){}

/*esto esta pensado para usarse de manera recursiva dentro de orta funcion.
Por ende hacer mas de una vez la validacion de "vacio_legal es reduntante"*/
bool nro_natural::es_primo(unsigned int numero){
    bool primo = true;
    //
    vacio_legal(numero);
    //
    caso_inicial(numero);
    //
    for(unsigned int x = 2; x < sqrt(numero); x++){
        if(numero % x == 0){
            primo = false;
            break;
        }
    }
    return primo;
}

void nro_natural::set_numero(unsigned int numero){
    this->nro = numero;
}

unsigned int nro_natural::get_numero(){
    return this->nro;   
}

int main(){

}