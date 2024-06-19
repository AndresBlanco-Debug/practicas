#ifndef PARADA_H_
#define PARADA_H_
#include <string>

/*
el programa tiene que cumplir con:
- listado de paradas por barrio 
- parada mas cercana a unan coordenada
- listado de paradas segun linea de colectivo
- listado de cantidad de paradas por linea de colectivo
- dado un barrio y una linea de colectivo imprimir paradas segun distancia
*/

class Parada
{
private:
    std::string calle;
    //nombre de la calle
    unsigned int altura;
    //altura de la parada
    unsigned int comuna;
    //comuna donde esta la parada.
public:
    Parada(std::string calle, unsigned int altura, unsigned int comuna);
    //se crea la parada
    std::string getCalle();
    //regresa el nombre de la calle
    unsigned int getAltura();
    //regresa la altura
    unsigned int getComuna();
    //regresa la comuna
    void getDireccion();
    //regresa la direccion completa
    ~Parada();
};

#endif