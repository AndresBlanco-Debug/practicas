#ifndef NODO_H_
#define NODO_H_

template<class T> class Nodo{
private:
    T data;
    /*se crean los enlaces de los nodos*/
    Nodo<T>* siguiente;
    Nodo<T>* anterior;
public:
    Nodo(T);
    /*Pre*/
    bool hay_siguiente();
    /*Post: regresa verdadero si hay un nodo siguiente*/
    bool hay_anterior();
    /*Post: regresa verdadero si hay nodo anterior*/
    Nodo<T>* get_siguiente();
    /*Post: obtiene el proximo nodo*/
    Nodo<T>* get_anterior();
    /*Post: obtiene el nodo anterior*/
    void set_siguiente(Nodo<T>*);
    /*Post: enlaza el nodo con el siguiente*/
    void set_anterior(Nodo<T>*);
    /*Post: enlaza el nodo con el anterior*/
    T get_valor();
    /*Post: regresa el valor del  nodo*/
    void set_valor(T);
    /*Post: asigna el valor al nodo*/
    ~Nodo();
    /*Post: destructor de la clase*/
};

template<class T> Nodo<T>::Nodo(T valor){
    this->data = valor;
    this->siguiente = NULL;
    this->anterior = NULL;
}

template<class T> bool Nodo<T>::hay_siguiente(){
    bool proximo = false;
    if(this->siguiente != NULL){
        proximo = true;
    }
    return proximo;
}

template<class T> bool Nodo<T>::hay_anterior(){
    anterior = false;
    if(this->anterior != NULL){
        anterior = true;
    }
    return anterior;
}

template<class T> Nodo<T>* Nodo<T>::get_siguiente(){
    if(this->hay_siguiente()){
        return this->siguiente;
    }
    return NULL;
}

template<class T> Nodo<T>* Nodo<T>::get_anterior(){
    if(this->hay_anterior()){
        return (this->anterior);
    }
    return NULL;
}

template<class T> void Nodo<T>::set_siguiente(Nodo<T>* proximo){
    if(!this->hay_siguiente()){
        this->siguiente = proximo;
    }
}

template<class T> void Nodo<T>::set_anterior(Nodo<T>* previo){
    if(this->hay_anterior()){
        this->anterior = previo;
    }
}

template<class T> T Nodo<T>::get_valor(){
    return this->data;
}

template<class T> void Nodo<T>::set_valor(T nuevoValor){
    this->data = nuevoValor;
}

template<class T> Nodo<T>::~Nodo(){}



#endif