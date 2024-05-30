#include <iostream>
/*Escriba una funcion que intercambie el valor de dos variables
que se pasen como parametro usando referencias*/

void pedir_valores(int& primer_valor, int& segundo_valor){
    std::cout << "Ingrese el primer valor: " << std::endl;
    std::cin >> primer_valor;
    std::cout << "Ingrese el segundo valor: " << std::endl;
    std::cin >> segundo_valor;
}

void intercambiar_valores(int& primero, int& segundo){
    int aux = segundo;
    segundo = primero;
    primero = aux;
}

int main(){
    int p_valor, s_valor;
    pedir_valores(p_valor,s_valor);
    std::cout << "Primer valor, segundo valor respectivamente: " << p_valor << ", " << s_valor << std::endl;
    intercambiar_valores(p_valor, s_valor);
    std::cout << "Primer valor, segundo valor respectivamente: " << p_valor << ", " << s_valor << std::endl;
    return 0;
}