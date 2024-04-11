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
    Nodo<T>* getNodo(unsigned int)const;
public:
    Lista();
    /*Post: Crea una lista vacia*/
    Lista(Lista<T> &);
    /*Post: Se combinan dos listas*/
    bool vacia() const;
    /*Post: booleano dependiendo si hay elementos*/
    unsigned int getSize() const;
    /*Post: Regresa la cantidad de elementos de la lista*/
    void add(T);
    /*Post: agrega el elemento en la ultima posicion de la lista*/
    void add(T , unsigned int);
    /*Post: asigna el elemento en la posicion ingresada*/
    void add(Lista<T> &);
    /*Post: Agrega los elementos de la segunda lista al final de la primera*/
    T get(unsigned int);
    /*Regresa el elemento en la posicion ingresada*/
    void asignar(T, unsigned int);
    /*post: cambia el elemento a la posicion ingresada*/
    void remover(unsigned int);
    /*Post: elimina el elemento en la posicion ingresada*/
    void reiniciarCursor();
    /*Post: reinicia el cursor para una nueva iteracion*/
    bool avanzarCursor();
    /*Post: avanza el cursor a la siguiente iteracion, el valor de retorno indica si hay elementos bajo el cursor*/
    T getCursor() const;
    /*Post: regresa el elemento bajo el cursor*/
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

template<class T> void Lista<T>::add(Lista<T> &otraLista){
    otraLista.reiniciarCursor();
    while(otraLista.avanzarCursor()){
        this->add(otraLista.getCursor());
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
            nodoAnterior->setSiguiente(nodoRemovido->getSiguiente());
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


#endif