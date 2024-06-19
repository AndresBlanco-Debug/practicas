#ifndef NODO_H_
#define NODO_H

//template class NODO

template<class T> class Nodo{
private:
    T data;
    Nodo<T>* siguiente;
public:
    Nodo(T);
    bool haySiguiente();
    Nodo<T>* getSiguiente();
    void setSiguiente(Nodo<T>*);
    T getValor();
    void setValor(T);
    ~Nodo();
};


template<class T> Nodo<T>::Nodo(T data){
    this->data = data;
    this->siguiente = NULL;
}

template<class T> bool Nodo<T>::haySiguiente(){
    return (this->siguiente != NULL);
}

template<class T> Nodo<T>* Nodo<T>::getSiguiente(){
    return this->siguiente;
}

template<class T> void Nodo<T>::setSiguiente(Nodo<T>* nuevoNodo){
    this->siguiente = nuevoNodo;
}

template<class T> T Nodo<T>::getValor(){
    return (this->dato);
}

template<class T> void Nodo<T>::setValor(T nuevoValor){
    this->data = nuevoValor;
}

template<class T> Nodo<T>::~Nodo(){}

#endif