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
    
    std::cout << "\nIgnorando los 10 primeros caracteres del nombre del curso: ";
    std::cin.ignore(10);
    std::cin >> var;
    std::cout << "\nLectura Flatante: " << var << '\n';

    std::cout << "\nIgnorando caracteres hasta que lea un \'P\' o se lea 20 caracteres: ";
    std::cin.ignore(20,'P');
    std::cin >> var;
    std::cout << "\nLectura Flatante: " << var << '\n';

    std::cin.get();// leemos el salto de linea para que no afecte al getline

    char linea[50];
    std::cout << "\nLeyendo hasta el salto de linea:";
    std::cin.getline(linea,50,'\n');
    std::cout << "\nLectura: " << linea << '\n';

    std::cout << "\nLeemmos un caracter: ";
    caracter = std::cin.get();
    std::cout << "\ncaracter leido: " << caracter;
    std::cout << "\nRegresamos un caracter: \n";
    std::cin.unget(); // estariamos regresando la o
    std::cin >> caracter;
    std::cout << "Caracter leido: " << caracter << '\n';
    

    std:: cout << "\nConocer el proximo caracter de lectura:";
    char siguienteCaracter = std::cin.peek();
    std::cout << "\nEl proximo caracter es: " << siguienteCaracter;
    std::cout << "\nLeemos el siguiente caracter: \n";
    std::cin >> caracter;
    std::cout << "Caracter leido: " << caracter << '\n';


    std::cout << "\nDevolvemos un caracer al \'buffer\': ";
    std::cin >> caracter;
    std::cout << "\nEl proximo caracter es: " << siguienteCaracter;
    std::cin >> caracter;
    std::cout << "\nRegresamos \'A\' al buffer: " << caracter << '\n';
    std::cin.putback('A');
    std::cin >> caracter;
    std::cout << "Caracter leido: " << caracter << '\n';

    std::cin.ignore(100,'\n');// vamos a leer todo hasta encontrar un salto de linea
    std::cout << "\nConociendo la cantidad de caracteres leidos: ";
    std::cin.getline(linea,50,'\n');
    std::cout << "La frase: " << std::quoted(linea) << ", tiene: " << std::cin.gcount() << " caracteres\n";

    std::cout << "\nErrores de lectura, vamos a intentar leer una palabra con un \'int\'";
    std::cin >> numero;
    if (std::cin.fail()) {
        std::cerr << "\nError al momento de leer un entero, vamos a limpiar el buffer\n";
        std::cin.clear(); // limpiamoss el buffer
    }

    while (std::cin.get(caracter));// leeremos hasta que no podamos

    if(std::cin.eof()){
        std::cout << "\nLlegamos al final de de la lectura\n";
    }
    return 0;


}
