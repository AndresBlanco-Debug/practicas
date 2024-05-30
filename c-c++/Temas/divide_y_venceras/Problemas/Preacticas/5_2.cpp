#include <iostream>
/*Modifique la funcion del problema anterior para que devuelva como 
retorno el doble del numero que recibe como parametro*/

int duplicador(int numero){
    int nro_duplicado;
    nro_duplicado = numero * 2;
    return nro_duplicado;
}

int main(){
    int numero;
    std::cout << "Ingrese el numero: ";
    std::cin >> numero;
    int resultado = duplicador(numero);
    std::cout<< "El duplicado del numero: " << numero << " es : " << resultado << std::endl;
    return 0;
}