#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <string>
/*
nombre del producto
precio del producto
descuento
stock del producto
*/

class Producto
{
    //elementos que componen al objeto
private:
    std::string nombre_producto;
    float precio_unitario;
    bool descuento;
    unsigned int stock;

public:
    //elementos que crean al objeto
    Producto(std::string nombre, float precio, bool descuento, unsigned int cantidad);
    //Se crea el producto
    std::string obneter_nombre();
    //Regresa el nombre del producto
    float obtener_precio();
    //Regresa el precio del producto
    bool hay_descuento();
    //Verifica si hay descuento
    unsigned int cantidad_stock();
    //Revisa la cantidad que hay en stock
    void obtener_detalles();
    //Regresa todos los datos del producto
    ~Producto();
    //Destructor de la clase
};

Producto::Producto(std::string nombre, float precio, bool descuento, unsigned int cantidad)
{
    this->nombre_producto = nombre;
    this->precio_unitario = precio;
    this->descuento = descuento;
    this->stock = cantidad;
}

std::string Producto::obneter_nombre(){
    return this->nombre_producto;
}

float Producto::obtener_precio(){
    return this->precio_unitario;
}

bool Producto::hay_descuento(){
    return this->descuento;
}

unsigned int Producto::cantidad_stock(){
    return this->stock;
}

void Producto::obtener_detalles(){
    obneter_nombre();
    obtener_precio();
    hay_descuento();
    cantidad_stock();
}

Producto::~Producto()
{
}

#endif