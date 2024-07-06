/* 
 * File:   main.cpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 21 de mayo de 2024, 10:13 PM
 */
#include "Almacen.hpp"

using namespace std;

int main(int argc, char** argv) {
    Almacen almacen;
    almacen.cargar_clientes();
    almacen.cargar_productos();
//    almacen.cargar_pedidos();
//    almacen.mostrar_datos();
    return 0;
}

