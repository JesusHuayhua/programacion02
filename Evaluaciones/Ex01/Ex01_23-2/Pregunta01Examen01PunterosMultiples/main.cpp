/* 
 * File:   main.cpp
 * Author: alulab14
 * Alumno: Jesus Huayhua
 * Codigo: 20196201
 * Created on 7 de mayo de 2024, 10:31 AM
 */

#include "Pregunta01Examen01PunterosMultiples.hpp"

int main(int argc, char** argv) {
    char **codigoDelProducto;
    int **fechaClienteCantidad;
    cargarPedidos(fechaClienteCantidad, codigoDelProducto, "Pedidos.csv");
    pruebaDeCargaDePedidos(fechaClienteCantidad, codigoDelProducto, "PruebaPedidos.txt");
    return 0;
}

