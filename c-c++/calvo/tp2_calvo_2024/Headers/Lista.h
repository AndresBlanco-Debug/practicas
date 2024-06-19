#ifndef LISTA_H_
#define LISTA_H_
#include "Nodo.h"

template<class T> class Lista
{
private:
    unsigned int tamano;
    Nodo<T> *primero;
    Nodo<T> *cursor;
    Nodo<T>* obtenerNodo(unsigned int);
    void validarPosicion(unsigned int);
public:
    Lista();
    /*post: crea una lista vacia*/
    Lista(Lista<T> &);
    /*post: se combinan dos listas*/
    bool vacia() const;
    /*post: booleano dependiendo si hay elementos*/
    unsigned int getSize() const;
    /*Regresa la cantidad de elemetos en la lista*/
    void add(T);
    /*post: agrega el elemento en la ultima posicion de la lista*/
    void add(T, unsigned int posicion);
    /*post: agrega el elemento a la lista en la posicion ingresada*/
    void add(Lista<T>&);
    /*post: agrega elementos de una segunda lista a la primera*/
    T get(unsigned int);
    /*post: regresa el elemento en la posicion ingresada*/
    void asignar(T, unsigned int);
    /*post: cambia el elemento a la posicion ingresada*/
    void remover(unsigned int);
    /*post: elimina el elemento en la posicion ingresada*/
    void reiniciarCursor();
    /*post: reinicia el cursor para una nueva iteracion*/
    bool avanzarCursor();
    /*post: avanza el cursor a la siguiente iteracion
    segun lo que devuelva sabemos si hay un elemento o no en la iteracion
    */
   T getCursor() const;
   /*post: regresa el elemento bajo el cursor*/
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

template<class T> bool Lista<T>::vacia() const{
    return (this->tamano == 0);
}

template<class T> unsigned int Lista<T>::getSize() const {
    return (this->tamano);
}

template<class T> void Lista<T>::add(T elemento){
    this->add(elemento, this->tamano + 1);
}

template<class T> void Lista<T>::add(T elemento, unsigned int pos){
    if ((pos > 0) && (pos < this->tamano + 1))
    {
        Nodo<T>* nuevoNodo = new Nodo<T>(elemento);
        if (pos == 1)
        {
            nuevoNodo->setSiguiente(this->primero);
            this->primero = nuevoNodo;
        }else
        {
            Nodo<T>* nodoAnterior = this->getNodo(pos - 1);
            nuevoNodo->setSiguiente(nodoAnterior->getSiguiente());
            nodoAnterior->setSiguiente(nuevoNodo);
        }
        this->tamano++;
        this->reiniciarCursor();
    }
}

template<class T> void Lista<T>::add(Lista<T> &segundaLista){
    segundaLista.reiniciarCursor();
    while (segundaLista.avanzarCursor())
    {
        tihs->add(segundaLista.getCursor();
        )
    }
    
}

/*Regresa el elemento en la posicion:[pos - 1]*/
template<class T> T Lista<T>::get(unsigned int posicion){
    //hay que validar la posicion
    return (this->obtenerNodo(posicion)->getValor())
}

template<class T> void Lista<T>::asignar(T elemento, unsigned int posicion){
    if ((pos > 0) && (pos <= this->tamano))
    {
    this->obtenerNodo(posicion)->setValor(elemento);
    }
}

template<class T> void Lista<T>::remover(unsigned int posicion){
    if ((posicion > 0) && (pos <= this->tamano))
    {
        Nodo<T>* deadNode;
        if (pos == 1)
        {
            deadNode = this->primero;
            this->primero = this->primero->getSiguiente();
        }else
        {
            Nodo<T>* nodoAnterior = this->obtenerNodo(posicion - 1);
            deadNode = nodoAnterior->getSiguiente();
            nodoAnterior->setSiguiente(deadNode->getSiguiente());
        }
        delete deadNode;
        this->tamano--;
        this->reiniciarCursor();
    }
    
}

template<class T> void Lista<T>::reiniciarCursor(){
    this->cursor = NULL;
}

template<class T> bool Lista<T>::avanzarCursor(){
    if (this->cursor == NULL)
    {
        this->cursor = this->primero;
    }else
    {
        this->cursor = this->cursor->getSiguiente();
    }
    return (this->cursor != NULL);
}

template<class T> T Lista<T>::getCursor() const {
    return (this->cursor->getValor());
}

template<class T> Lista<T>::~Lista(){
    while(this->primero != NULL)
    {
        while(this->primero != NULL){
            Nodo<T>* deadNode = this->primero; 
            this->primero = this->primero->getSiguiente();
            delete deadNode;
        }
    }
}

template<class T> Nodo<T>* Lista<T>::obtenerNodo(unsigned int posicion){
    Nodo<T>* nodoActual = this->primero;
    for (unsigned int i = 1; i < posicion; i++)
    {
        nodoActual = nodoActual->getSiguiente();
    }
    return nodoActual;
}

#endif