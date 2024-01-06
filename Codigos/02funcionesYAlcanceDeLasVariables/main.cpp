#include "funcionesYAlcanceDeLasVariables.hpp"

int main(){
    stComplejo x = {2.0,3.0};
    stComplejo y = {1.0,4.0};
    // Uso del operador de suma sobrecargado (función global)
    stComplejo suma = x + y;
    std::cout << "Suma: " << suma.real << " + " << suma.imaginario << "i" << std::endl;

    // Uso del operador de multiplicación sobrecargado (función global)
    stComplejo multiplicacion = x * y;
    std::cout << "Multiplicacion: " << multiplicacion.real << " + " << multiplicacion.imaginario << "i" << std::endl;

    return 0;
}