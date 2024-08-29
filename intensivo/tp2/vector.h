#ifndef VECTOR_H_
#define VECTOR_H_

template<class T> class Vector{
    //TEMPLATE DE CLASE VECTOR
private:
    T* dato;
    /*
    -Puntero al dato que almacena el vector
    */
    unsigned int capacidad;
    /*
    -Capacidad inicial del vector
    */
    void pos_en_rango(unsigned int);
    /*
    -Verifica qe la posicion ingresada este en rango
    */
    void espacio_disponible(unsigned int);
    /*
    -Espacio disponible del vector a partit de la capacidad inicial
    */
    void retornar_valor(unsigned int);
    /*
    -Regresa el valor almacenado en la posicion ingresada
    */
public:
    Vector(unsigned int capacidad);
    /*
    -Se crea el vector con la capacidad inicial
    */
    ~Vector();
    /*
    -Destructor de la clase
    */
    unsigned int get_capacidad();
    /*
    -Regresa la capacidad actual
    */
    void agregar_elemento(unsigned int pos, T dato);
    /*
    -Agrega un elemento del tipo T en la posicion ingresada
    */
    void eliminar_elemento(unsigned int pos);
    /*
    -Elimina el elemento en la posicion ingresada
    */
    T& obtener_dato(unsigned int pos);
    /*
    Regresa la el dato que hay en la posicion de memoria ingresada
    */
};

template<class T> Vector<T>::Vector(unsigned int capacidad){
    /*
    (Hay que corregir la manera en la que manejamos el error)
    -Maneja el caso en que hay capacidad nula o negativa
    */
    if (capacidad <= 0)
    {
        throw "Error, la capacidad debe ser igual o mayor a 1";
    }
    this->dato = new T[capacidad];
    /*
    Se crea el vector para almacenar el tipo de dato T
    reservando memoria segun la capacidad inicial
    */
    this->capacidad = capacidad;
    /*
    Se asigna la capacidad inicial (porque se esta creando el vector)
    */
    for(int x = 0; x < capacidad; x++){
        this->dato[x] = NULL;
    }
    /*
    Se reserva la memoria hasta la capacidad inicial
    asignando los espacios como NULL para conservar memoria sin utilizarla
    */
}

//*Destructor de la clase, se usa el [] para indicar que es un array
template<class T>Vector<T>::~Vector(){
    delete[] this->dato;
}

//*Valida que la pocision este en rango
template<class T> void Vector<T>::pos_en_rango(unsigned int pos){
    if(this->capacidad < pos){
        throw "Error, al posicion esta fuera de rango";
    }
    //!La forma de usar el throw no es la correcta. esta funcion necesita arreglo
}

//*Valida que la posicion ingresada este libre, de no ser asi se hace una funcion throw
template<class T> void Vector<T>::espacio_disponible(unsigned int pos){
    if(this->dato[ pos - 1] != NULL){
        throw "Error, la posicion ya esta ocupada";
    }
    //!Necesita arreglo
}

//*Retorna el vallor que hay en la posicion
template<class T> void Vector<T>::retornar_valor(unsigned int pos){
    if(this->dato[pos - 1] == NULL){
        throw "Error, posicion vacia.";
    }
    //!Necesita arreglo
}

//*Regresa la capacidad del vector
template<class T> unsigned int Vector<T>::get_capacidad(){
    return this->capacidad;   
}

//*Agrega elemento en la posicion deseada
template<class T> void Vector<T>::agregar_elemento(unsigned int pos, T dato){
    pos_en_rango(pos);
    //retornar_valor(pos);
    this->dato[pos - 1] = dato;
}

//*Elimina el elemento en la posicion ingresada
template<class T> void Vector<T>::eliminar_elemento(unsigned int pos){
    //*Se valida si la posicion esta en rango
    pos_en_rango(pos);
    //*Se regresa el valor almacenado
    retornar_valor(pos);
    //*Se elimina el elemeto en la posicion ingresada
    delete this->data[pos - 1];
    //*Se le asigna NULL a la posicion ingresada, asi se puede almacenar otro dato de ser necesario
    this->dato[pos - 1] = NULL;
}

//*Se regresa el dato que hay en la posicion ingresada.
template<class T> T& Vector<T>::obtener_dato(unsigned int pos){
    pos_en_rango(pos);
    retornar_valor(pos);
    return this->dato[pos - 1];
}

#endif