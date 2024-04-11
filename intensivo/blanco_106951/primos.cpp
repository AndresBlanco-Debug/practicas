#include <fstream>
#include <iostream>
#include <ctime>
#include <cmath>

/*Hacer una aplicacion que guarde en un archivo de texto todos los numeros primos desde 2 hasta una constante MAXIMO
(menor o igual a 100 millones) en un tiempo razonable.
La aplicacion debe:
- Guardar cada numero en una linea diferente de forma vertical,
- Imprimir por pantalla la cantidad de numeros primos en el archivo,
- El tiempo empleado en el proceso.
*/

bool es_primo(unsigned int numero){
    //se evaluan los 3 tipos de casos
    if (numero <= 1) return false;
    if (numero == 2) return true;
    if (numero % 2 == 0) return false;
    //
    for(unsigned int x = 3; x <= sqrt(numero); x += 2){
        if(numero % x == 0){
            return false;
        }
    }
    return true;
}

//ingresos iniciales
bool primos_iniciales(unsigned int numero){
    bool filtro = false;
    if((numero == 2) || (numero == 3) || (numero == 5)){
        filtro = true;
    }
    return filtro;
}
//filtro inicial segun los divisores mas comunes
bool primer_filtro(unsigned int numero){
    bool primo = false;
    if((numero == 1) || (numero % 2 == 0) || (numero % 3 == 0) || (numero % 5 == 0)){
        primo = false;
    }
    return primo;
}
//pseudocodigo
void contador_recursivo(unsigned int numero_ingresado){
    //se abre el archivo
    std::ofstream primos;
    primos.open("primos.txt");
    //
    //se declaran las variables
    unsigned int ti = clock();
    unsigned int numero_inicial = 2;
    unsigned int cantidad = 0;
    //
    while(numero_inicial < numero_ingresado){
        if(es_primo(numero_inicial)){
            primos << numero_inicial << '\n';
            ++cantidad;
        }
        ++numero_inicial;
    }
    primos.close();
    unsigned int tf = clock();
    double tiempo_total = (double(tf - ti)) / CLOCKS_PER_SEC;
    //se cierra el archivo y se mide el tiempo
    std::cout << "Cantidad de números primos: " << cantidad << '\n';
    std::cout << "Tiempo empleado: " << tiempo_total << " segundos\n";
}

const unsigned int MAXIMO = 100000000;

int main(){
    contador_recursivo(MAXIMO);
    return 0;
}
