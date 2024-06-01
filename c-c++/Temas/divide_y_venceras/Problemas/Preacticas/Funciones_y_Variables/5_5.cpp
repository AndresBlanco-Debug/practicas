#include <iostream>
/*escriba una funcion que  reciba tres numeros y devuelva
la media de los 3*/

//media = promedio supongo.

void pedir_numeros(int& p_numero, int& s_numero, int& t_numero){
    std::cout << "Ingrese 3 numeros" << std::endl;
    std::cin >> p_numero >> s_numero >> t_numero;
}

float calcular_media(int x, int y, int z){
    float media = x+y+z;
    return (media / 3);
}

int main(){
    int num_1, num_2, num_3;
    pedir_numeros(num_1, num_2, num_3);
    float media = calcular_media(num_1, num_2, num_3);
    std::cout << "La media es: " << media << std::endl;
    return 0;
}