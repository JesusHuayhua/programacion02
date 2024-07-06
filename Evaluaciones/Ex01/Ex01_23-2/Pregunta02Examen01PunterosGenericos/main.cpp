/**
 * Alumno: Jesus Huayhua
 * Codigo: 20196201
 */
#include "Pregunta02Examen01PunterosGenericos.hpp"

int main(int argc, char** argv) {
    void *productos;
    cargarProductos (productos, "Productos.csv");
    pruebaDeCargaDeProductos (productos);
    return 0;
}