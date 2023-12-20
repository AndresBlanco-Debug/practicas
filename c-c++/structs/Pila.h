#ifndef PILA_H_
#define PILA_H_
#include "Nodo.h"
/*Pila funciona como una pila de platos, se agregan elementos al principio y se eliminan al final.*/

template<class T> class Pila{
private:
    T data;
    unsigned int tamano;
    Nodo<T>* primero;
    Nodo<T>* getTope();
public:
    Pila();
    ~Pila();
    void agragarElemento(T);
    void removerElemento();
    unsigned int getTamano();
    T getElemento(unsigned int);
    T getTope();
};

/*Post crea la Pila con el primer nodo establecido en 0*/
template<class T> Pila<T>::Pila(){
    this->tamano = 0;
    this->primero = NULL;
}

/*Agraga un elemeo al principo de la pila*/
template<class T> void Pila<T>::agragarElemento(T elemento){
    Nodo<T>* nuevoNodo = new Nodo<T>(elemento);
    nuevoNodo->setSiguiente(this->primero);
    this->primero = nuevoNodo;
    this->tamano++;
}

template<class T> Nodo<T>* Pila<T>::getTope(){
    Nodo<T>* elemento = this->primero;;
    for(unsigned int x = 0; x < this->tamano; x++){
        elemento->getSiguiente();
    }
    return elemento;
}

template<class T> void Pila<T>::removerElemento(){
    //siempre se quita el ultimo elemento;
    Nodo<T>* deadNode = getTope();
    delete deadNode;
    tamano--;
}


template<class T> unsigned int Pila<T>::getTamano(){
    return this->tamano;
}

template<class T> T Pila<T>::getElemento(unsigned int posicion){
    if(posicion > this->tamano){
        throw "Error, el indice esta fuera  de rango.";
    }
    Nodo<T>* dato = this->primero;
    for(unsigned int x = 0; x < pos; x++){
        dato = dato->getSiguiente();
    }
    return (dato->getValor());
}

template<class T> Pila<T>::~Pila(){
    while(this->primero != NULL){
        Nodo<T>* deadNode = this->primero;
        this->primero = this->primero->getSiguiente();
        delete deadNode;
    }
}

#endif