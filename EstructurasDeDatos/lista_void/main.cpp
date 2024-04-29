/* 
 * File:   main.cpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 */

#include "lista.hpp"
#include "funcionesLista.hpp"
#include "funciones.hpp"
using namespace std;

int main(int argc, char** argv) {
    Lista lista;
    construir_lista(lista);
    ifstream archivo;
    apertura_de_archivo_para_leer(archivo, "productos2.csv");
    leer_archivo_productos(lista, archivo);
    imprime(lista);

    cout << setfill('=') << setw(50) << "=" << endl;
    cout << "ELIMINA CABEZA" << endl;
    cout << setfill('=') << setw(50) << "=" << endl << setfill(' ');
    elimina_cabeza(lista);
    imprime(lista);

    cout << setfill('=') << setw(50) << "=" << endl;
    cout << "ELIMINA COLA" << endl;
    cout << setfill('=') << setw(50) << "=" << endl << setfill(' ');
    elimina_cola(lista);
    imprime(lista);

    cout << setfill('=') << setw(50) << "=" << endl;
    cout << "ELIMINA NODO" << endl;
    cout << setfill('=') << setw(50) << "=" << endl << setfill(' ');
    void *buffer[4];
    int *id = new int;
    *id = 77;
    buffer[ID] = id;
    elimina_nodo(lista, buffer);
    imprime(lista);
    
    
    eliminar_lista(lista);
    
    
    return 0;
}

