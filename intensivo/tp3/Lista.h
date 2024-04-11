#ifndef LISTA_H_
#define LISTA_H_
#include <string>
#include <limits>
#include <iostream>
#include "Nodo.h"

template<class T> class Lista{
private:
    unsigned int tamano;
    Nodo<T>* primero;
    Nodo<T>* cursor;
    Nodo<T>* obtener_nodo(unsigned int)const;
public:
    Lista();
    /*Post: Crea una lista vacia*/
    Lista(Lista<T> &);
    /*Post: Se combinan dos listas*/
    bool vacia() const;
    /*Post: booleano dependiendo si hay elementos*/
    unsigned int get_size() const;
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
    void reiniciar_cursor();
    /*Post: reinicia el cursor para una nueva iteracion*/
    bool avanzar_cursor();
    /*Post: avanza el cursor a la siguiente iteracion, el valor de retorno indica si hay elementos bajo el cursor*/
    T obtener_cursor() const;
    /*Post: regresa el elemento bajo el cursor*/
    Lista<T>* interseccion(Lista<T>&);
    /*Post: */
    Lista<T>* union_(Lista<T>&);
    /*Poat: */
    bool buscar(T elemento);
    /*Post: */
    Lista<T>* union_ordenada(Lista<T>&);
    /*Post: */
    Lista<T>* interseccion_ordenada(Lista<T>&);
    ~Lista();
};

template<class T> Lista<T>::Lista(){
    this->tamano = 0;
    this->primero = NULL;
    this->cursor = NULL;
}

template<class T> Lista<T>::Lista(Lista<T> &otra_lista){
    this->primero = NULL;
    this->cursor = NULL;
    this->tamano = 0;
    this->add(otra_lista);
}

template<class T> bool Lista<T>::vacia()const{
    return (this->tamano == 0);
}

template<class T> unsigned int Lista<T>::get_size()const{
    return (this->tamano);
}

template<class T> void Lista<T>::add(T elemento){
    this->add(elemento, this->tamano + 1);
}

template<class T> void Lista<T>::add(T elemento, unsigned int pos){
    //hay que tener la posicion valida.
    if((pos > 0) && (pos < this->tamano + 1)){
        Nodo<T>* nuevo_nodo = new Nodo<T>(elemento);
        if(pos == 1){
            nuevo_nodo->set_siguiente(this->primero);
            this->primero = nuevo_nodo;
        }
        else{
            Nodo<T>* nodoAnterior = this->obtener_nodo(pos - 1);
            nuevo_nodo->set_siguiente(nodoAnterior->get_siguiente());
            nodoAnterior->set_siguiente(nuevo_nodo);
        }
        this->tamano++;
        this->reiniciar_cursor();
    }
}

template<class T> void Lista<T>::add(Lista<T> &otra_lista){
    otra_lista.reiniciar_cursor();
    while(otra_lista.avanzar_cursor()){
        this->add(otra_lista.obtener_cursor());
    }
}

/*Regresa el elemento en la posicion:[pos - 1]*/
template<class T> T Lista<T>::get(unsigned int pos){
    if((pos <= 0) || (pos > this->tamano)){
        throw "Posicion invalida";
    }
    return (this->obtener_nodo(pos)->get_valor());
}

/*Cambia el elemento en la posicion dada.*/
template<class T> void Lista<T>::asignar(T elemento, unsigned int pos){
    if((pos > 0) && (pos <= this->tamano)){
        this->obtener_nodo(pos)->setValor(elemento);
    }
}

/*Elimina el elemento de la posicion*/
template<class T> void Lista<T>::remover(unsigned int pos){
    if((pos > 0) && (pos <= this->tamano)){
        Nodo<T>* nodo_removido;
        if(pos == 1){
            nodo_removido = this->primero;
            this->primero = this->primero->get_siguiente();
            //haciendo esto el primer nodo se pone en el siguiente. si no hay mas se pone en NULL.
        }else{
            Nodo<T>* nodoAnterior = this->obtener_nodo(pos - 1);
            nodo_removido = nodoAnterior->get_siguiente();
            nodoAnterior->set_siguiente(nodo_removido->get_siguiente());
        }
        delete nodo_removido;
        this->tamano--;
        this->reiniciar_cursor();
    }
}

/*Reinicia el cursor para una nueva iteracion*/
template<class T> void Lista<T>::reiniciar_cursor(){
    this->cursor = NULL;
}

/*Avanza el cursor que itera sobre la lista, esto nos indica si hay un elemento en la posicion*/
template<class T> bool Lista<T>::avanzar_cursor(){
    if(this->cursor == NULL){
        this->cursor = this->primero;
    }else{
        this->cursor = this->cursor->get_siguiente();
    }
    return (this->cursor != NULL);
}

/*Nos regresa el elemento donde apunta el cursor*/
template<class T> T Lista<T>::obtener_cursor()const{
    if(this->cursor == NULL){
        throw "Error, el cursor esta en NULL";
    }
    return (this->cursor->get_valor());
}

/*Destructor de la clase*/
template<class T> Lista<T>::~Lista(){
    while(this->primero != NULL){
        Nodo<T>* nodo_removido = this->primero;
        this->primero = this->primero->get_siguiente();
        delete nodo_removido;
    }
}

/*IMPLEMENTACION DE LISTAS EJERCICIO 1 TP3*/

template<class T> Lista<T>* Lista<T>::union_(Lista<T>& lista){
    Lista<T>* resultado = new Lista<T>();
    this->reiniciar_cursor();
    while(this->avanzar_cursor()){
        T elemento = this->obtener_cursor();
        resultado->add(elemento);
    }
    lista.reiniciar_cursor();
    while(lista.avanzar_cursor()){
        T elemento = lista.obtener_cursor();
        if(!resultado->buscar(elemento)){
            resultado->add(elemento);
        }
    }
    resultado->reiniciar_cursor();
    while(resultado->avanzar_cursor()){
        std::cout << "Añadido a la unión: " << resultado->obtener_cursor() << std::endl;
    }
    return resultado;
}

template<class T> Lista<T>* Lista<T>::interseccion(Lista<T>& lista){
    Lista<T>* resultado = new Lista<T>();
    this->reiniciar_cursor();
    while(this->avanzar_cursor()){
        T elemento = this->obtener_cursor();
        if(lista.buscar(elemento)){
            resultado->add(elemento);
        }
    }
    resultado->reiniciar_cursor();
    while(resultado->avanzar_cursor()){
        std::cout << "Añadido a la intersección: " << resultado->obtener_cursor() << std::endl;
    }
    return resultado;
}


template<class T> bool Lista<T>::buscar(T elemento){
    bool encontrado = false;
    if(this->cursor == NULL){
        this->reiniciar_cursor();
    }
    while(this->avanzar_cursor()){
        if(this->obtener_cursor() == elemento){
            encontrado = true;
            break;
        }
    }
    return encontrado;
}

/*Regresa el nodo que esta en la posicion (pointer)*/

template<class T> Nodo<T>* Lista<T>::obtener_nodo(unsigned int pos)const{
    Nodo<T>* nodoActual = this->primero;
    for(unsigned int x = 1; x < pos; x++){
        nodoActual = nodoActual->get_siguiente();
    }
    return nodoActual;
}


#endif