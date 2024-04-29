/* 
 * File:   main.cpp
 * Author: alulab14
 * Alumno: Jesus Huayhua
 * Codigo: 20196201
 * Created on 25 de abril de 2024, 10:02 AM
 */

#include "PunterosGenericos.hpp"
#include "MuestraPunteros.h"
using namespace std;

int main(int argc, char** argv) {
    void *productos, *clientes;
    cargaproductos(productos);
    cargaclientes(clientes);
    cargapedidos(productos, clientes);
    imprimereporte(clientes);
    return 0;
}
