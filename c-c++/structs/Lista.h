#ifndef LISTA_H_
#define LISTA_H_
#include <string>
#include <limits>
#include "Nodo.h"

template<class T> class Lista{
private:
    unsigned int tamano;
    Nodo<T>* primero;
    Nodo<T>* cursor;
    Nodo<T>* getNodo(unsigned int) const;
public:
    Lista();
    Lista(Lista<T> &);
    bool vacia() const;
    unsigned int getSize() const;
    void add(T);
    void add(T , unsigned int);
    void add(Lista<T>, &);
    T get(unsigned int);
    void asignar(T, unsigned int);
    void remover(unsigned int);
    void reiniciarCursor();
    bool avanzarCursor();
    T getCursor() const;
    Nodo<T>* getNodo(unsigned int)const;
    void mostrarDescripcion();
    ~Lista();
};

template<class T> Lista<T>::Lista(){
    this->tamano = 0;
    this->primero = NULL;
    this->cursor = NULL;
}

template<class T> Lista<T>::Lista(Lista<T> &otraLista){
    this->primero = NULL;
    this->cursor = NULL;
    this->tamano = 0;
    this->add(otraLista);
}

template<class T> bool Lista<T>::vacia()const{
    return (this->tamano == 0);
}

template<class T> unsigned int Lista<T>::getSize()const{
    return (this->tamano);
}

template<class T> void Lista<T>::add(T elemento){
    this->add(elemento, this->tamano + 1);
}

template<class T> void Lista<T>::add(T elemento, unsigned int pos){
    //hay que tener la posicion valida.
    if((pos > 0) && (pos < this->tamano + 1)){
        Nodo<T>* nuevoNodo = new Nodo<T>(elemento);
        if(pos == 1){
            nuevoNodo->setSiguiente(this->primero);
            this->primero = nuevoNodo;
        }
        else{
            Nodo<T>* nodoAnterior = this->getNodo(pos - 1);
            nuevoNodo->setSiguiente(nodoAnterior->getSiguiente());
            nodoAnterior->setSiguiente(nuevoNodo);
        }
        this->tamano++;
        this->reiniciarCursor();
    }
}

/*Regresa el elemento en la posicion:[pos - 1]*/
template<class T> T Lista<T>::get(unsigned int pos){
    if((pos <= 0) || (pos > this->tamano)){
        throw "Posicion invalida";
    }
    return (this->getNodo(pos)->getValor());
}

/*Cambia el elemento en la posicion dada.*/
template<class T> void Lista<T>::asignar(T elemento, unsigned int pos){
    if((pos > 0) && (pos <= this->tamano)){
        this->getNodo(pos)->setValor(elemento);
    }
}

/*Elimina el elemento de la posicion*/
template<class T> void Lista<T>::remover(unsigned int pos){
    if((pos > 0) && (pos <= this->tamano)){
        Nodo<T>* nodoRemovido;
        if(pos == 1){
            nodoRemovido = this->primero;
            this->primero = this->primero->getSiguiente();
            //haciendo esto el primer nodo se pone en el siguiente. si no hay mas se pone en NULL.
        }else{
            Nodo<T>* nodoAnterior = this->getNodo(pos - 1);
            nodoRemovido = nodoAnterior->getSiguiente();
            nodoAnterior->setSiguiente(nodoRemovido->getSiguiente())
        }
        delete nodoRemovido;
        this->tamano--;
        this->reiniciarCursor();
    }
}

/*Reinicia el cursor para una nueva iteracion*/
template<class T> void Lista<T>::reiniciarCursor(){
    this->cursor = NULL;
}

/*Avanza el cursor que itera sobre la lista, esto nos indica si hay un elemento en la posicion*/
template<class T> bool Lista<T>::avanzarCursor(){
    if(this->cursor == NULL){
        this->cursor = this->primero;
    }else{
        this->cursor = this->cursor->getSiguiente();
    }
    return (this->cursor != NULL);
}

/*Nos regresa el elemento donde apunta el cursor*/
template<class T> T Lista<T>::getCursor()const{
    if(this->cursor == NULL){
        throw "Error, el cursor esta en NULL";
    }
    return (this->cursor->getValor());
}

/*Destructor de la clase*/
template<class T> Lista<T>::~Lista(){
    while(this->primero != NULL){
        Nodo<T>* nodoRemovido = this->primero;
        this->primero = this->primero->getSiguiente();
        delete nodoRemovido;
    }
}

/*Regresa el nodo que esta en la posicion (pointer)*/

template<class T> Nodo<T>* Lista<T>::getNodo(unsigned int pos)const{
    Nodo<T>* nodoActual = this->primero;
    for(unsigned int x = 1; x < pos; x++){
        nodoActual = nodoActual->getSiguiente();
    }
    return nodoActual;
}

/*Muestra lo que hace cada cosa*/

template<class T> void Lista<T>::mostrarDescripcion(){
    std::cout << "Se mostrara el metodo y la descripcion de lo que hace" << '\n';
    std::cout << "Hay 13 metodos de la lista sin contar este." << '\n';

    int opcion;
    std::cout << "Seleccione un numero del 1 al 13 para mostrar la descripcion de los metodos." << '\n';
    std::cin >> opcion;

    if (std::cin.fail()) {
        std::cout << "El dato ingresado no es un número entero." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else {
        switch (opcion)
        {
            case 1:
                std::cout << "1. Lista() - Constructor por defecto que inicializa una lista vacía." << '\n';
                break;

            case 2:
                std::cout << "2. Lista(Lista<T>&) - Constructor de copia que crea una nueva lista idéntica a otra." << '\n';
                break;

            case 3:
                std::cout << "3. vacia() const - Verifica si la lista está vacía." << '\n';
                break;

            case 4:
                std::cout << "4. getSize() const - Obtiene el tamaño de la lista." << '\n';
                break;

            case 5:
                std::cout << "5. add(T) - Añade un elemento al final de la lista." << '\n';
                break;

            case 6:
                std::cout << "6. add(T, unsigned int) - Añade un elemento en una posición específica de la lista." << '\n';
                break;

            case 7:
                std::cout << "7. add(Lista<T>&) - Añade los elementos de otra lista al final de la lista actual." << '\n';
                break;

            case 8:
                std::cout << "8. get(unsigned int) - Obtiene el elemento en la posición dada." << '\n';
                break;

            case 9:
                std::cout << "9. asignar(T, unsigned int) - Cambia el elemento en la posición dada." << '\n';
                break;

            case 10:
                std::cout << "10. remover(unsigned int) - Elimina el elemento en la posición dada." << '\n';
                break;

            case 11:
                std::cout << "11. reiniciarCursor() - Reinicia el cursor para una nueva iteración." << '\n';
                break;

            case 12:
                std::cout << "12. avanzarCursor() - Avanza el cursor que itera sobre la lista." << '\n';
                break;

            case 13:
                std::cout << "13. getCursor() const - Obtiene el elemento apuntado por el cursor." << '\n';
                break;

            default:
                std::cout << "Opción no válida." << '\n';
                break;
        }
    }
}


#endif