#include <iostream>
#include <iomanip>
#include "operadoresSobrecargados.hpp"

int main(){
    Productos producto1,producto2,producto3;
    producto3 = Productos();

    producto1 = {"Aceite",20,9.5};
    producto2 = {"Aceite",10,10.5};
    std::cout << "==============================" << std::endl;
    std::cout << "Impresion de los productos" << std::endl;
    std::cout << producto1 << '\n' << producto2 << std::endl;

    std::cout << "==============================" << std::endl;

    std::cout << "Lectura de un producto" << std::endl;
    std::cin  >> producto3;
    std::cout << producto3 << std::endl;

    std::cout << "==============================" << std::endl;

    std::cout << "Suma de Productos" << std::endl;
    producto3 = producto1 + producto2;
    std::cout << producto3 << std::endl;
    
    std::cout << "==============================" << std::endl;
    return 0;
}
