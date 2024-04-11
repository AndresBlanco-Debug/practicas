#ifndef PRODUCTO_H
#define PRODUCTO_H
//#include <iostream>
#include <string>

class Producto
{
private:
    std::string nombre_producto;
    double precio;
    bool descuento;
    int cantidad_stock;

public:
    Producto(std::string nombre_producto, double precio, bool descuento, int cantidad_stock);
    ~Producto();
    std::string obtener_nombre();
    double obtener_precio();
    bool tiene_descuento();
    int obtener_stock();
};

Producto::Producto(std::string nombre_producto, double precio, bool descuento, int cantidad_stock)
{
    this->nombre_producto = nombre_producto;
    this-> precio = precio;
    this-> descuento = descuento;
    this-> cantidad_stock = cantidad_stock;
}

Producto::~Producto()
{
}

std::string Producto::obtener_nombre(){
    return this->nombre_producto;
}

double Producto::obtener_precio(){
    return this->precio;
}

bool Producto::tiene_descuento(){
    return this->descuento;
}

int Producto::obtener_stock(){
    return this->cantidad_stock;
}

#endif