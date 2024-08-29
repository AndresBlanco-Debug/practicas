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

class Coordenada
{
private:
    float x;
    float y;
public:
    Coordenada(float, float);
    float getX();
    float getY();
    ~Coordenada();
};



class Parada
{
private:
    unsigned int linea;

public:
    Parada(/* args */);
    ~Parada();
};


#endif