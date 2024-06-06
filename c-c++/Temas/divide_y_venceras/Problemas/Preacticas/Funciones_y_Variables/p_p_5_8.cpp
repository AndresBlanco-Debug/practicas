#include <iostream>
#include <cmath>
/*
escribir un programa que calcule las raices reales de la ecuacion de segundo grado
ax^2 + bx + c
*/
//menciona calcular solo las raices reales.

void ingresar_datos(int& t_cuadrado, int& t_lineal, int& t_independiente){
    std::cout << "Ingrese el termino cuadrado: " << '\n';
    std::cin >> t_cuadrado;
    std::cout << "Ingrese el termino lineal: " << '\n';
    std::cin >> t_lineal;
    std::cout << "Ingrese el termino independiente: " << std::endl;
    std::cin >> t_independiente; 
}


bool validar_datos(int t_cuadrado, int t_lineal, int t_independiente){
    bool datos_validos = false;
    float discriminante = (pow(t_lineal, 2) - 4*(t_cuadrado * t_independiente));
    if ((t_cuadrado != 0) && (discriminante > 0))
    {
        datos_validos = true;
    }
    return datos_validos;
}

void cuadratica(int t_cuadrado, int t_lineal, int t_independiente, float& p_raiz,
 float& s_raiz){
    if(validar_datos(t_cuadrado, t_lineal, t_independiente)){
        float discriminante = (pow(t_lineal, 2) - 4*(t_cuadrado * t_independiente));
        p_raiz = (((-1*t_lineal) + discriminante)/(2*t_cuadrado));
        s_raiz = (((-1*t_lineal) - discriminante)/(2*t_cuadrado));
    }
}

int main(){
    int p_termino, s_termino, t_termino;
    float p_raiz, s_raiz;
    ingresar_datos(p_termino, s_termino, t_termino);
    cuadratica(p_termino, s_termino, t_termino, p_raiz, s_raiz);
    std::cout<< "Primera raiz: " << p_raiz  << ", "<< "Segunda raiz: " << s_raiz << std::endl;
    return 0;
}