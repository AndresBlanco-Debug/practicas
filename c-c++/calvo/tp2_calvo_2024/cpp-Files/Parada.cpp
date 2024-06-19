#include <iostream>
#include "./Headers/Parada.h"

Parada::Parada(std::string calle, unsigned int altura, unsigned int comuna)
{
    this->calle = calle;
    this->altura = altura;
    this->comuna = comuna;
}

std::string Parada::getCalle()
{
    return (this->calle);
}

unsigned int Parada::getAltura()
{
    return (this->altura);
}

unsigned int Parada::getComuna()
{
    return (this->comuna);
}

void Parada::getDireccion()
{
    std::cout << "La direccion de la parada es: (calle - altura - comuna) " << '\n';
    std::cout << this->calle << ", " << this->altura << ", " << this->comuna << std::endl;
}