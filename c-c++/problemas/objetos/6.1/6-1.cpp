#include <iostream>
#include <string>
#include "./structs/Lista.h"

/*Desarollar una aplicacion que permita a un usuario llevar informacion sobre los gastos del hogar que realiza.
Debe perimir:
1. Gastos de alimentacion
2. Gastos de Transporte
3. Gastos de Vivienda
4. Debe poder trabajar con euros y dolares*/

struct Divisa
{
    unsigned int dolar = 1;
    float euro = 3.95;
};


class Factura{
private:
    float alimentacion;
    float transporte;
    float vivienda;
public:
    Factura(float alimentacion, float transporte, float vivienda);
    //Getters:
    float getAlimentacion();
    float getTransporte();
    float getVivienda();
    //Setters:
    void setAlimentacion(float);
    void setTransporte(float);
    void setVivienda(float);
    //
    Factura nuevaFactura();
    ~Factura();
};

Factura::Factura(float alimentacion, float transporte, float vivienda){
    alimentacion = this->alimentacion;
    transporte = this->transporte;
    vivienda = this->vivienda;
}

float Factura::getAlimentacion(){
    return this->alimentacion;
}

float Factura::getTransporte(){
    return this->transporte;
}

float Factura::getVivienda(){
    return this->vivienda;
}

void Factura::setAlimentacion(float nuevoPrecio){
    this->alimentacion = nuevoPrecio;
}

void Factura::setTransporte(float nuevoPrecio){
    this->transporte = nuevoPrecio;
}

void Factura::setVivienda(float nuevoPrecio){
    this->vivienda = nuevoPrecio;
}

class Cuenta{
private:
    Divisa moneda;
    Lista<Factura*>* facturas;
public:
    Cuenta(Divisa moneda, Lista<Factura*>* facturas);
    void agregarFactura();
    void agregarFactura(Factura*);
    void agregarFactura(Factura*, unsigned int);
    void removerFactura(Factura*);
    void removerFactura(unsigned int);
    float getTotalAlimentos(Divisa);
};

Cuenta::Cuenta(Divisa moneda, Lista<Factura*>* facturas){
    this->moneda = moneda;
    this->facturas = NULL;
}

void Cuenta::agregarFactura(){
    float nuevaComida, nuevoTransporte, nuevaVivienda;
    std::cout << "Ingrese los detalles de la factura de la siguiente forma: $comida, $transporte, $vivienda" << std::endl;
    std::cin >> nuevaComida >> nuevoTransporte >> nuevaVivienda;
    Factura* nueva = new Factura(nuevaComida, nuevoTransporte, nuevaVivienda);
    this->facturas->add(nueva);
}

void Cuenta::agregarFactura(Factura* nuevaFactura){
    this->facturas->add(nuevaFactura);
}

void Cuenta::agregarFactura(Factura* nuevaFactura, unsigned int dia){
    this->facturas->add(nuevaFactura, dia);
}

void Cuenta::removerFactura(Factura* deadFactura){
    //se trabaja en esta.
    unsigned int posicion = 1;
    while(this->facturas->avanzarCursor() != NULL){
        if(this->facturas->getCursor()->getAlimentacion() == deadFactura->getAlimentacion() &&
            this->facturas->getCursor()->getTransporte() == deadFactura->getTransporte() &&
            this->facturas->getCursor()->getVivienda() == deadFactura->getVivienda()
        ){ break; }
        posicion++;
        this->facturas->avanzarCursor();
    }
    this->facturas->remover(posicion);
}

void Cuenta::removerFactura(unsigned int dia){
    this->facturas->remover(dia);
}

int main(){
    
}