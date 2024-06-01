#include <iostream>
/*Escriba un programa que dadas dos circunferencias, mediante su centro y su radio,
calcule cuantos puntos tienen en comun dichas circunferencias (cero, uno, dos o infinitos)*/

/*la clave para resolver este problema es la relacion entre el centro de 
la circunferencia y el radio de esta*/

/*
Hay que tener en cuenta algunos casos antes de seguir analizando el problema
1. Un circulo esta dentro de otro
2. Un circulo es igual al otro
3. Los circulos comparten al menos un punto en comun
4. Los circulos no estan conectados

Si ambos circulos tienen el mismo centro y radio igual, son el mismo circulo
Si tienen el mismo centro pero radio diferente, uno esta incluido en otro
Si 

En si hay muchos problemas y detalles a tomar en cuenta con este problema y lo abierto
del enunciado deja mucha ambiguedad a la resolucion, pero ahi esta el encanto.

*/

void mensaje_inicial(){
    std::cout << "Por el momento solo se aceptan numeros enteros. " << std::endl;
}

void ingresar_centro(int& x, int& y){
    std::cout << "Ingrese el centro de la circunferencia en formato (x,y): " << std::endl;
    std::cin >> x >> y;
}

void ingresar_radio(int& radio){
    std::cout << "Ingrese el radio de la circunferencia: " << std::endl;
    std::cin >> radio;
}

/*
Esta funcion esta pensada como dice el nombre, calcular los bordes de la circunferencia
si el centro esta en (0,0) y el radio = 3, entonces los bordes del circulo son (3,0); (0,3) y 
el punto resultante de sacar la hipotenusa en (3,3). h^2 = a^2 + b^2
*/

bool comparar_centros(int x, int y, int alfa, int beta){
    bool centro_igual = false;
    if((x == alfa) && (y == beta)){
        centro_igual = true;
    }
    return centro_igual;
}

void bordes_primer_cuadrante(int x, int y, int radio){
    //funcion para obtener los bordes
}

//una forma amplia de abordar el programa. Pero hay otra manera de hacerlo. Calculando la distancia entre los centros y la suma de los radios

