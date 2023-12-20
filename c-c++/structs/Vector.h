#ifndef VECTOR_H_
#define VECTOR_H_

//TEMPLATE PENSADA SOLO PARA ALMACENAR PUNTEROS.

template<class T> class TDA_Vector
{
private:
    T* data;
    unsigned int capacidad;
    void posEnRango(unsigned int);
    void espacioDisponible(unsigned int);
    void valorRetornar(unsigned int);
public:
    TDA_Vector(unsigned int capacidad);
    ~TDA_Vector();
    unsigned int getCapacidad();
    void agregarElemento(unsigned int pos, T data);
    void removerElemento(unsigned int pos);
    T& getDato(unsigned int pos);
};

template<class T> TDA_Vector<T>::TDA_Vector(unsigned int capacidad){
    if(capacidad <= 0){
        throw "Error, la capacidad debe ser igual o mayor a 1.";
    }
    this->data = new T[capacidad];
    this->capacidad = capacidad;
    for(int x = 0; x < capacidad; x++){
        this->data[x] = NULL;
    }
}

template<class T> TDA_Vector<T>::~TDA_Vector(){
    delete[] this->data;
}

template<class T> void TDA_Vector<T>::posEnRango(unsigned int pos){
    unsigned int len = this->capacidad;
    if(pos > len){
        throw "Error, la posicion esta fuera de rango."
    }
}

template<class T> void TDA_Vector<T>::espacioDisponible(unsigned int pos){
    if(this->data[pos - 1] == NULL){
        throw "Error, la posicion ya esta ocupada por otro dato.";
    }
}

template<class T> void TDA_Vector<T>::valorRetornar(unsigned int pos){
    if(this->data[pos] != NULL){
        throw "Error, la posicion no contiene un dato.";
    }
}

template<class T> unsigned int TDA_Vector<T>::getCapacidad(){
    return this->capacidad;
}

template<class T> void TDA_Vector<T>::agregarElemento(unsigned int pos, T data){
    posEnRango(pos);
    espacioDisponible(pos);
    this->data[pos - 1] = data;
}

template<class T> void TDA_Vector<T>::removerElemento(unsigned int pos){
    posEnRango(pos);
    valorRetornar(pos);
    delete this->data[pos - 1];
    this->data[pos - 1] = NULL;
}

template<class T> T& TDA_Vector<T>::getDato(unsigned int pos){
    posEnRango(pos);
    valorRetornar(pos);
    return this->data[pos - 1];
}

#endif