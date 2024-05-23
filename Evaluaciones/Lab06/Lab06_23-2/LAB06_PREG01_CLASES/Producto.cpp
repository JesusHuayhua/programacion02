/* 
 * File:   Producto.cpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 21 de mayo de 2024, 10:59 PM
 */

#include "Producto.hpp"

Producto::Producto() {
    codigo = nullptr;
    descripcion = nullptr;
    precio = 0.0;
    stock = 0;
    cantidad_clientes_servidos = 0;
    cantidad_clientes_no_servidos = 0;
}

Producto::Producto(const Producto& orig) {
}

Producto::~Producto() {
}

void Producto::SetCantidad_clientes_no_servidos(int cantidad_clientes_no_servidos) {
    this->cantidad_clientes_no_servidos = cantidad_clientes_no_servidos;
}

int Producto::GetCantidad_clientes_no_servidos() const {
    return cantidad_clientes_no_servidos;
}

void Producto::SetCantidad_clientes_servidos(int cantidad_clientes_servidos) {
    this->cantidad_clientes_servidos = cantidad_clientes_servidos;
}

int Producto::GetCantidad_clientes_servidos() const {
    return cantidad_clientes_servidos;
}

void Producto::SetStock(int stock) {
    this->stock = stock;
}

int Producto::GetStock() const {
    return stock;
}

void Producto::SetPrecio(double precio) {
    this->precio = precio;
}

double Producto::GetPrecio() const {
    return precio;
}

void Producto::SetDescripcion(char* descripcion) {
    if(this->descripcion != nullptr) delete this->descripcion;
    this->descripcion = new char [strlen(descripcion) + 1];
    strcpy(this->descripcion,descripcion);
}

char* Producto::GetDescripcion(const char *descripcion) const {
    return descripcion;
}

void Producto::SetCodigo(char* codigo) {
    this->codigo = codigo;
}

char* Producto::GetCodigo() const {
    return codigo;
}
