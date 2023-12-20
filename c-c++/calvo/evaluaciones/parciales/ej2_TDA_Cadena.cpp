#include <iostream>
#include "./structs/Vector.h"
/*Disenar la especificacion e implememtar los TDAs modelen una Cadena, cumpliendo las siguientes caracteristicas*/

/*Una cadena esta compuesta por una secuencia de Eslabones. Toda Cadena tiene al menos un eslabon
Cada Eslabon posee largo y ancho. Todos los eslabones de la Cadena deben tener el mismo ancho, pero el largo puede diferir.
Se debe poder agregar o retirar Eslabones de la Cadena
Se requiere conocer la longitud total de la Cadena. Solo se puede utilizar Vectores.*/

class Eslabon{
private:
    float ancho;
    float altura;
public:
    Eslabon(float ancho, float altura);
    ~Eslabon();
    float getAltura();
    float getAncho();
};

Eslabon::Eslabon(float ancho, float altura){
    this->ancho = ancho;
    this->altura = altura;
}

float Eslabon::getAltura(){
    return this->altura;
}

float Eslabon::getAncho(){
    return this->ancho;
}

Eslabon::~Eslabon(){}

class Cadena{
private:
    TDA_Vector<Eslabon*>* eslabones;
    unsigned int cantidad;
    void anchoCorrecto(Eslabon*);
public:
    Cadena(unsigned int cantidad, Eslabon*);
    ~Cadena();
    void agregarEslabon(unsigned int ,Eslabon*);
    void removerEslabon(unsigned int);
    float getTamanoTotal();
};

Cadena::Cadena(unsigned int cantidad, Eslabon* eslabon){
    this->cantidad = cantidad;
    this->eslabones = new TDA_Vector<Eslabon*>(cantidad);
    this->eslabones->agregarElemento(1,eslabon);
}

Cadena::~Cadena(){
    delete this->eslabones;
}

void Cadena::anchoCorrecto(Eslabon* eslabon){
    float anchoCorrecto = this->eslabones->getDato(1)->getAncho();
    if(eslabon->getAncho() != anchoCorrecto){
        throw "Error! el ancho del escalon no es correcto.";
    }
}

void Cadena::agregarEslabon(unsigned int pos, Eslabon* eslabon){
    anchoCorrecto(eslabon);
    this->eslabones->agregarElemento(pos, eslabon);
}

void Cadena::removerEslabon(unsigned int pos){
    this->eslabones->removerElemento(pos);
}

float Cadena::getTamanoTotal(){
    float tamano = 0;
    unsigned int len = this->eslabones->getCapacidad();
    for(int x = 1; x < len; x++){
        float ancho = this->eslabones->getDato(x)->getAncho();
        float alto = this->eslabones->getDato(x)->getAltura();
        tamano += ancho + alto;
    }
    return tamano;
}