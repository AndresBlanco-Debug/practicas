#include <iostream>
#include "vector.h"
#include "producto.h"

/*Se debe crear un vector dinamico Gondola
- comienza con un tamano de 5
- cuando se llena se dplica el tamano
- si se vacia la mitad, el vector debe achicarse hasta la mitad.*/

class Gondola{
private:
    Vector<Producto*>* productos;
    void aplicar_descuento();
    
    
};