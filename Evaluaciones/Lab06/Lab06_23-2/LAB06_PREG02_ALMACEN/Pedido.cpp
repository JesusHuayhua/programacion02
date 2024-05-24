/* 
 * File:   Pedido.cpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 23 de mayo de 2024, 11:12 PM
 */

#include "Pedido.hpp"
using namespace std;

Pedido::Pedido() {
    codigo = nullptr;
    dni_cliente = 0;
    precio_producto = 0.0;
}

Pedido::~Pedido() {
    delete codigo;
}

void Pedido::SetPrecio_producto(double precio_producto) {
    this->precio_producto = precio_producto;
}

double Pedido::GetPrecio_producto() const {
    return precio_producto;
}

void Pedido::SetDni_cliente(int dni_cliente) {
    this->dni_cliente = dni_cliente;
}

int Pedido::GetDni_cliente() const {
    return dni_cliente;
}

void Pedido::SetCodigo(char* codigo) {
    if (this->codigo != nullptr) delete []this->codigo;
    this->codigo = new char[strlen(codigo) + 1];
    strcpy(this->codigo, codigo);
}

void Pedido::GetCodigo(char *codigo) const {
    if (this->codigo == nullptr) codigo[0] = 0;
    else strcpy(codigo, this->codigo);
}

bool operator>>(ifstream &input, class Pedido &pedido) {
    char codigo[20];
    int dni;
    input.getline(codigo, 20, ',');
    if (input.eof())return false;
    input.get();
    input >> dni;
    input.get();
    pedido.SetDni_cliente(dni);
    pedido.SetCodigo(codigo);
    return true;
}