#include <iostream>
/*
escriba un programa que lea dos fechas (dia, mes y ano) y diga el numero de dias que hay entre ellas
*/

void ingresar_fecha(int& dia, int& mes, int& ano){
    std::cout << "Ingrese la fecha en formato: dd/mm/yyyy" << std::endl;
    std::cin >> dia >> mes >> ano;
}

int delta_anos(int x, int y){
    return ((x - y)* 365);
}

int mes_a_dias(int mes){
    int cant_dias = 0;
    if ((mes > 0) && (mes < 13))
    {
        if ( (mes < 8) && (mes % 2 != 0))
        {
            cant_dias = 31;
        }
        else if ((mes > 7) && (mes % 2 == 0))
        {
            cant_dias = 31;
        }
        else
        {
            cant_dias = 30;
        }
    }
    return cant_dias;
}

int delta_mes(int x, int y){
    int dias_primer_mes = mes_a_dias(x);
    int dias_segundo_mes = mes_a_dias(y);
    return ((dias_primer_mes - dias_segundo_mes) * 30);
}

int delta_dias(int x, int y){
    return (x - y);
}

int main(){

/*
Este programa es solo un prototipo funcional. Todavia necesita 
mucho trabajo y filtros para ser totalmente funcional. Hay varios casos que faltan considerar
sin mencionar que probablemente la forma de abordar el problema con los meses este mal ejecutada.
*/

    int p_dia, p_mes, p_ano;
    int s_dia, s_mes, s_ano;

    std::cout << "Ingrese la primera fecha." << std::endl;
    ingresar_fecha(p_dia, p_mes, p_ano);
    std::cout << "Ingrese la segunda fecha." << std::endl;
    ingresar_fecha(s_dia, s_mes, s_ano);
    
    int resultante = delta_dias(p_dia, s_dia) + delta_mes(p_mes, s_mes) + delta_anos(p_ano, s_ano);
    std::cout << "dias de por medio: " << resultante << std::endl;

    return 0;
}