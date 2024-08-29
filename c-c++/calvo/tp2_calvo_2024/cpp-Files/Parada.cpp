#include <iostream>
#include <fstream>
#include <string>


class Coordenada
{
private:
    float x;
    float y;
public:
    //se crea la coordenada: 
    Coordenada(float, float);
    //getters:
    float getX();
    float getY();
    //setters:
    void setX(float);
    void setY(float);
    //obtener la coordenada:
    Coordenada* obtenerCoordenada();
    ~Coordenada();
};


class Parada
{
private:
    unsigned int linea;
    //linea de colectivo
    Coordenada ubicacion;
    //ubicacion de la parada (x,y)
public:
    //se crea la parada
    Parada(unsigned int, Coordenada);
    ~Parada();
};


//funcion para leer el csv

int main()
{
    std::ifstream archivo("/home/jose/Desktop/MainRepo/practicas/c-c++/calvo/tp2_calvo_2024/paradas_de_colectivo.csv");
    
    //verificamos que el archivo abre bien:
    if (!archivo.is_open())
    {
        std::cerr << "Error al abrir el archivo" << std::endl;
        return 1;
    }
    std::string linea;
    while (std::getline(archivo, linea))
    {
        std::cout << linea << std::endl;
    }
    archivo.close();
    return 0;
}