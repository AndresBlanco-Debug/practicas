#ifndef GONDOLA_H
#define GONDOLA_H
//includes
#include "vector.h"
#include "producto.h"
/*
Un vector de productos que tiene que cumplir con lo siguiente:
Leyendo el archivo productos, generar un vector dinámico, Gondola. Este
vector comenzará con un tamaño de 5, en caso de llenarse, deben duplicar el tamaño.
En caso de vaciarse en más de la mitad, deben achicar el tamaño del vector a la mitad.
*/

class Gondola
{
private:
    Vector<Producto*>* productos;
    //vector de puntero a puntero
    unsigned int cantidad_inicial;
    //cantidad inicial de productos
public:
    Gondola(Producto* producto);
    //Crea el objeto condola, con la cantidad de objetos en 5
    void ajuste_gondola();
    //ajustar el tamano de la gondola
    void limpiar_gondola();
    ~Gondola();
    //destructor de la clase
};

Gondola::Gondola(Producto* producto)
{
    this->productos = new Vector<Producto*>(5);
}

Gondola::~Gondola()
{
}


#endif