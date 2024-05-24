/* 
 * File:   main.cpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 21 de mayo de 2024, 10:13 PM
 */

#include "ProductoEntregado.hpp"
#include "Almacen.hpp"
#include "Cliente.hpp"
#include "Producto.hpp"
#include "Utils.hpp"

using namespace std;

int main(int argc, char** argv) {
    ifstream arch_clientes("Clientes.csv", ios::in);
    if (not arch_clientes.is_open()) {
        cout << "No se pudo abrir Clientes.csv" << endl;
        exit(1);
    }
    ifstream arch_pedidos("Pedidos.csv", ios::in);
    if (not arch_pedidos.is_open()) {
        cout << "No se pudo abrir pedidos.csv" << endl;
        exit(1);
    }
    ifstream arch_productos("Productos.csv", ios::in);
    if (not arch_productos.is_open()) {
        cout << "No se pudo abrir productos.csv" << endl;
        exit(1);
    }

    ofstream arch_reporte("Reporte_Prueba.txt", ios::out);

    class Cliente cliente;
    class Pedido pedido;
    class Producto producto;

    arch_clientes>>cliente;
    arch_pedidos>>pedido;
    arch_productos>>producto;

    producto += pedido;
    cliente += pedido;

    arch_reporte << cliente;
    arch_reporte << endl;
    arch_reporte << producto;

    arch_clientes.close();
    arch_pedidos.close();
    arch_productos.close();
    arch_reporte.close();
    return 0;
}

