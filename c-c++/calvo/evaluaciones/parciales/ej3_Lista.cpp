#include <iostream>
#include <string>
#include "./structs/Lista.h"
#include "./structs/Pila.h"
using namespace std;
/*IMPLEMENTAR LA CLASE A PARTIR DE LAS SIGUIENTES ESPECIFICACCIONES:*/
class Categoria{
private:
    string nombre;
    string descripcion;
public:
    Categoria(string nombre, string descripcion);
    string getNombre();
    string getDescripcion();
};
Categoria::Categoria(string nombre, string descripcion){
    this->nombre = nombre;
    this->descripcion = descripcion;
}
string Categoria::getNombre(){
    return this->nombre;
}
string Categoria::getDescripcion(){
    return this->descripcion;
}
class Noticia{
private:
    string titulo;
    string cuerpo;
    Lista<Categoria*>* categorias;
public:
    /*Post: Inicializa la noticia con el titulo y el cuerpo indicados
    sin categorias asociadas.*/
    Noticia(string titulo, string cuerpo);
    string getTitulo();
    string getCuerpo();
    Lista<Categoria*>* getCategorias();
};
Noticia::Noticia(string titulo, string cuerpo){
    this->titulo = titulo;
    this->cuerpo = cuerpo;
}
string Noticia::getTitulo(){
    return this->titulo;
}
string Noticia::getCuerpo(){
    return this->cuerpo;
}
Lista<Categoria*>* Noticia::getCategorias(){
    return this->categorias;
}
class FiltroDeNoticias{
private:
    Lista<Noticia*>* noticias;
    Lista<Categoria*>* categorias;
public:
    //CONSIGNA: Devuelve las 5 noticias que tengan asociadas TODAS las categorias y que tengan la mayor cantidad de categorias.
    Lista<Noticia*>* filtrarCategorias(Lista<Noticia*>* noticias, Lista<Categoria*>* categorias);
    Pila<Noticia*>* removerNoticias(Lista<Noticia*>* noticias, Lista<Categoria*>* categorias);
    bool validarCategoria(Noticia* noticia, Lista<Categoria*>* categorias);
    Noticia* mayorCategoria(Lista<Noticia*>* noticias);
};
bool FiltroDeNoticias::validarCategoria(Noticia* noticia, Lista<Categoria*>* categoriasPedidas){
    bool valido = false;
    unsigned int index = 0;
    unsigned int aciertos = 0;
    while(index < categoriasPedidas->getSize()){
        for(unsigned int x = index + 1; x < noticia->getCategorias()->getSize(); x++){
            Categoria* actual = noticia->getCategorias()->get(x);
            Categoria* catListada = categoriasPedidas->get(index);
            if(actual->getNombre() == catListada->getNombre()){
                aciertos++;
            }
        }
        index++;
    }
    if(aciertos == categoriasPedidas->getSize()){
        valido = true;
    }
    return valido;
}
//hay que hacer una funcion que filtre las noticias que tengan todas las categorias.
Lista<Noticia*>* FiltroDeNoticias::filtrarCategorias(Lista<Noticia*>* noticiasPosibles, Lista<Categoria*>* categoriasElegidas){
    Lista<Noticia*>* notiFiltro = NULL;
    while (noticiasPosibles->avanzarCursor())
    {
        Noticia* actual = noticiasPosibles->getCursor();
        if(actual->getCategorias()->getSize() >= categoriasElegidas->getSize()){
            //filtra las noticias que tengan la misma cantidasd de categorias.
            //habria que hacer una funcion para comparar listas.
            if(validarCategoria(actual,categoriasElegidas)){
                notiFiltro->add(actual);
            }
        }
        noticiasPosibles->avanzarCursor();
    }
    return notiFiltro;
}
//Ahora hay que hacer la funcion para que las noticias seleccionadas se filtren segun categorias;
//Hacemos una funcion que filtre la mayor y la repetimos 5 veces
Noticia* FiltroDeNoticias::mayorCategoria(Lista<Noticia*>* noticias){
    unsigned int pos = 0;
    Noticia* maxima = noticias->get(1);
    for(unsigned int x = 1; x < noticias->getSize(); x++){
        if(noticias->get(x)->getCategorias()->getSize() < noticias->get(x+1)->getCategorias()->getSize()){
            maxima = noticias->get(x);
            pos = x;
        }
    }
    noticias->remover(pos);
    return maxima;
}
Pila<Noticia*>* FiltroDeNoticias::removerNoticias(Lista<Noticia*>* noticias, Lista<Categoria*>* categorias){
    Pila<Noticia*>* notiLocas = NULL;
    Lista<Noticia*>* noticiaFiltradas = filtrarCategorias(noticias, categorias);
    Noticia* notActual = NULL;
    for(unsigned int x = 1; x < 6; x++){
        notActual = mayorCategoria(noticiaFiltradas);
        notiLocas->agragarElemento(notActual);
    }
    return notiLocas;
}