/* 
 * File:   Almacen.cpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 23 de mayo de 2024, 11:20 PM
 */

#include "Almacen.hpp"

using namespace std;

Almacen::Almacen() {
    cantidad_clientes = 0;
    cantidad_productos = 0;
}

Almacen::Almacen(const Almacen& orig) {
}

Almacen::~Almacen() {
}

void Almacen::SetCantidad_productos(int cantidad_productos) {
    this->cantidad_productos = cantidad_productos;
}

int Almacen::GetCantidad_productos() const {
    return cantidad_productos;
}

void Almacen::SetCantidad_clientes(int cantidad_clientes) {
    this->cantidad_clientes = cantidad_clientes;
}

int Almacen::GetCantidad_clientes() const {
    return cantidad_clientes;
}

void Almacen::cargar_clientes(void){
    ifstream file("Cliente.csv",ios::in);
    if(not file.is_open()){
        cout << "ERROR: No se puedo abrir el archivo Cliente.csv";
        exit(1);
    }
    while(true){
        file >> arreglo_clientes[cantidad_clientes];
        if(file.eof())break;
        cantidad_clientes++;
    }
    file.close();
}

void Almacen::cargar_productos(void){
    ifstream file("Productos.csv",ios::in);
    if(not file.is_open()){
        cout << "ERROR: No se puedo abrir el archivo Productos.csv";
        exit(1);
    }
    while(true){
        file >> arreglo_producto[cantidad_productos];
        if(file.eof())break;
        cantidad_productos++;
    }
    file.close();


}
