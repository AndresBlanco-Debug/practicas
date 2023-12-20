#ifndef NODO_H_
#define NODO_H_

/*Implementacion modificada para listas doblemente enlazadas.*/

template<class T> class Nodo{
private:
    T data;
    Nodo<T>* siguiente;
    Nodo<T>* anterior;
public:
    Nodo(T);
    bool haySiguiente();
    bool hayAnterior();
    Nodo<T>* getSiguiente();
    Nodo<T>* getAnterior();
    void setSiguiente(Nodo<T>*);
    void setAnterior(Nodo<T>*);
    T getValor();
    void setValor(T);
    ~Nodo();

};

template<class T> Nodo<T>::Nodo(T valor){
    this->data = valor;
    this->siguiente = NULL;
    this->anterior = NULL;
}

template<class T> bool Nodo<T>::haySiguiente(){
    proximo = false;
    if(this->siguiente != NULL){
        proximo = true;
    }
    return proximo;
}

template<class T> bool Nodo<T>::hayAnterior(){
    anterior = false;
    if(this->anterior != NULL){
        anterior = true;
    }
    return anterior;
}

template<class T> Nodo<T>*::getSiguiente(){
    if(this->haySiguiente()){
        return this->siguiente;
    }
    return NULL;
}

template<class T> Nodo<T>*::getAnterior(){
    if(this->hayAnterior()){
        return this->anterior;
    }
    return NULL;
}

template<class T> void Nodo<T>::setSiguiente(Nodo<T>* proximo){
    if(!this->haySiguiente()){
        this->siguiente = proximo;
    }
}

template<class T> void Nodo<T>::setAnterior(Nodo<T>* previo){
    if(this->hayAnterior()){
        this->anterior = previo;
    }
}

template<class T> T Nodo<T>::getValor(){
    return this->data;
}

template<class T> void Nodo<T>::setValor(T nuevoValor){
    this->data = nuevoValor;
}

template<class T> Nodo<T>::~Nodo(){}

#endif