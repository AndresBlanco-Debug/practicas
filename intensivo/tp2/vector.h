#ifndef VECTOR_H_
#define VECTOR_H_

template<class T> class Vector{
private:
    T* dato;
    unsigned int capacidad;
    //asigna la capacidad al vector.
    void pos_en_rango(unsigned int);
    void espacio_disponible(unsigned int);
    void retornar_valor(unsigned int);
public:
    Vector(unsigned int capacidad);
    ~Vector();
    unsigned int get_capacidad();
    void agregar_elemento(unsigned int pos, T dato);
    void eliminar_elemento(unsigned int pos);
    T& obtener_dato(unsigned int pos);
};

template<class T> Vector<T>::Vector(unsigned int capacidad){
    if (capacidad <= 0)
    {
        throw "Error, la capacidad debe ser igual o mayor a 1";
    }
    this->dato = new T[capacidad];
    this->capacidad = capacidad;
    for(int x = 0; x < capacidad; x++){
        this->dato[x] = NULL;
    }
}

template<class T>Vector<T>::~Vector(){
    delete[] this->dato;
}

template<class T> void Vector<T>::pos_en_rango(unsigned int pos){
    if(this->capacidad < pos){
        throw "Error, al posicion esta fuera de rango";
    }
}

template<class T> void Vector<T>::espacio_disponible(unsigned int pos){
    if(this->dato[ pos - 1] != NULL){
        throw "Error, la posicion ya esta ocupada";
    }
}

template<class T> void Vector<T>::retornar_valor(unsigned int pos){
    if(this->dato[pos - 1] == NULL){
        throw "Error, posicion vacia.";
    }
}

template<class T> unsigned int Vector<T>::get_capacidad(){
    return this->capacidad;   
}

template<class T> void Vector<T>::agregar_elemento(unsigned int pos, T dato){
    pos_en_rango(pos);
    //retornar_valor(pos);
    this->dato[pos - 1] = dato;
}

template<class T> void Vector<T>::eliminar_elemento(unsigned int pos){
    pos_en_rango(pos);
    retornar_valor(pos);
    delete this->data[pos - 1];
    this->dato[pos - 1] = NULL;
}

template<class T> T& Vector<T>::obtener_dato(unsigned int pos){
    pos_en_rango(pos);
    retornar_valor(pos);
    return this->dato[pos - 1];
}

#endif