/* 
 * File:   Almacen.cpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 23 de mayo de 2024, 11:20 PM
 */

#include "Almacen.hpp"

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

