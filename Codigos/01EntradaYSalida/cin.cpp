#include <iostream>
#include <iomanip>
#include <string>

int main(){
    int numero;
    char caracter;
    double flotante;
    std::cin >> numero >> caracter >> flotante;
    std::cout << numero << ' ' << caracter << ' ' << flotante << '\n';
    // Los numeros ingresados en otra base, se van a guardar en la variable de forma decimal
    std::cin >> std::hex >> numero;
    std::cout << "Numero ingresado de forma hexadecimal: " << numero << '\n';
    std::cin >> std::oct >> numero;
    std::cout << "Numero ingresado de forma octal: " << numero << '\n';
    std::cin >> std::dec; // regresamos al flujo normal

    std::string curso;
    std::cin >> std::quoted(curso);
    std::cout << "\nLeyendo el curso entre comillas: " << curso << '\n';
    char var[20];
    std::cin >> std::setw(10) >> var; 
    std::cout << "\nLeyendo un determinado ancho del \'buffer\': " << var << '\n';
    std::cin >> var;  // leemos lo que falta para que no interrumpa en los enunciados
    std::cin >> std::setw(20) >> std::setfill('*') >> var; 
    std::cout << "\nLeyendo un determinado ancho del \'buffer\' y con cierto relleno: " << var << '\n';
    return 0;
}
