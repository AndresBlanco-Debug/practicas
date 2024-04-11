#include "Lista.h"
#include <iostream>

int main() {
    // Crear dos listas para probar
    Lista<int> lista1;
    lista1.add(1);
    lista1.add(2);
    lista1.add(3);

    Lista<int> lista2;
    lista2.add(2);
    lista2.add(3);
    lista2.add(4);

    // Prueba de intersección
    Lista<int>* interseccionLista = lista1.interseccion(lista2);
    std::cout << "Intersección: ";
    interseccionLista->reiniciar_cursor();
    while (interseccionLista->avanzar_cursor()) {
        std::cout << interseccionLista->obtener_cursor() << " ";
    }
    std::cout << std::endl;
    delete interseccionLista;

    // Prueba de unión
    Lista<int>* unionLista = lista1.union_(lista2);
    std::cout << "Unión: ";
    unionLista->reiniciar_cursor();
    while (unionLista->avanzar_cursor()) {
        std::cout << unionLista->obtener_cursor() << " ";
    }
    std::cout << std::endl;
    delete unionLista;


    return 0;
}
