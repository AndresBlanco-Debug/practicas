/*Parte 1. Desarrollo.
Hacer una aplicación en C++ que guarde en un archivo de texto (“primos.txt”) todos los números primos
desde 2 hasta una constante MAXIMO (menor o igual que 100 millones) en un tiempo razonable
(razonable es el tiempo que una persona tarda en tomar un café).
Está permitido cualquier algoritmo salvo, por supuesto, el de copiar los números primos de otro archivo
que ya los tiene cargados.
Los números primos deben estar listados uno debajo del otro. Además de guardar los números primos
en el archivo, la aplicación tiene que imprimir por pantalla: “cantidad de números primos guardados: “
y “tiempo empleado: ”, con sus respectivos valores.
El código, además de estar correctamente modularizado y contemplar las buenas prácticas de
programación debe tener una constante MAXIMO antes del main.
const unsigned int MAXIMO = 100000000;
Para la escritura del archivo utilicen la librería fstream. Ejemplo de uso:
#include <fstream>
…
ofstream archivo(“primos.txt”); // apertura de archivo para escritura, la o es por out (salida)
archivo >> x >> endl; // guarda la variable x en el archivo y un fin de línea
archivo.close(); // cierre al finalizar la escritura
Para tomar los tiempos usen la librería ctime.
#include <ctime>
unsigned int ti = clock(); // debe ser la primera línea que se ejecute
…
unsigned int tf = clock(); // debe estar después del cierre del archivo
double tiempo_total = (double(tf – ti)) / CLOCKS_PER_SEC; // calcula el tiempo en segundos*/
#include <fstream>
#include <iostream>
#include <cmath>
#include <ctime>

const unsigned int MAXIMO = 100000000;

bool es_primo(unsigned int numero){
    if(numero < 2) return false;
    for(unsigned int x = 2; x <= sqrt(numero); x++){
        if(numero % x == 0){
            return false;
        }
    }
    return true;
}

int main(){
    unsigned int ti = clock();
    std::ofstream output_file("primos.txt");
    unsigned int contador = 0;

    for(unsigned int i = 2; i <= MAXIMO; i++){
        if(es_primo(i)){
            output_file << i << std::endl;
            contador++;
        }
    }

    output_file.close();

    std::cout << "Cantidad de numeros primos guardados: " << contador << std::endl;

    unsigned int tf = clock();
    double tiempo_total = (double(tf - ti)) / CLOCKS_PER_SEC;
    std::cout << "Tiempo empleado: " << tiempo_total << " segundos" << std::endl;

    return 0;
}
