#include <iostream>
/*Escribir un programa que obtenga por teclado coordenadas de 
dos vectores de 3 coordenadas, devuelva el producto escalar y 
el producto vectorial*/

void pedir_coordenadas(int& alfa, int& beta, int& gamma){
    std::cout << "Ingrese las coordenadas del vector: " << std::endl;
    std::cin >> alfa >> beta >> gamma;
}

void producto_escalar(int x, int y, int z, int a, int b, int c){
    std::cout << "El producto escalar entre: ";
    std::cout << "(" << x << ", " << y << ", " << z << ")" << " y " << "(" << a << ", " << b << ", " << c << ")" <<std::endl;
    int escalar = (x*a) + (y*b) + (z*c);
    std::cout <<"El producto escalar es: " << escalar << std::endl;
}

int cofactor(int& a, int& b, int& c, int d){
    int coordenada = (a*d) - (b*c);
    return coordenada;
}

void producto_vectorial(int x, int y, int z, int a, int b, int c){
    int i = cofactor(y,z,b,c);
    int j = (cofactor(x,y,a,c)) * -1;
    int k = cofactor(x,y,a,b);
    std::cout << "El producto vectorial entre V1 y V2 es: " << "("<< i << ", " << j << ", " << k << ")" << std::endl;
}

int main(){
    int x, y, z, a, b, c;
    pedir_coordenadas(x,y,z);
    pedir_coordenadas(a,b,c);
    producto_escalar(x,y,z,a,b,c);
    producto_vectorial(x,y,z,a,b,c);
    return 0;
}