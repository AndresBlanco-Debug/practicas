#include <iostream>

/*
Escriba una funcion que dado los parametros de esta los ordene en punteros.
*/

void cambiar_posicion(int& a, int& b){
    int aux = b;
    b = a;
    a = aux;
}

void ordenar_v2(int& x, int& y, int& z){
    for (unsigned int  t = 0; t < 3 ; t++)
    {
        if (x < y)
        {
            cambiar_posicion(x,y);
        }
        else if (y < z)
        {
            cambiar_posicion(y,z);
        }
    }
}

void ordenar(int x, int y, int z, int *n1, int *n2, int *n3){
/*
primero hay que hacer un algoritmo para ordenar los valores x, y, z
el problema deja abierto el tipo de ornden, asi que lo abordaremos
de manera ascendente. Usameremos una tertera funcion para la resolucion de este problema/
*/
    ordenar_v2(x,y,z);
    (n1) = &x;
    (n2) = &y;
    (n3) = &z;

    std::cout << "punteros ordenados: " << '\n';
    std::cout << *(n1) << " " << *(n2) << " " << *(n3) << std::endl;
}

int main(){
    int a = 10, b = 17, c = 5;
    int *x = NULL, *y = NULL, *z = NULL;
    std::cout << "valores ordenados (ponele): " << a << ", " << b << ", " << c << std::endl;
    ordenar(a,b,c,x,y,z);
    return 0;
}