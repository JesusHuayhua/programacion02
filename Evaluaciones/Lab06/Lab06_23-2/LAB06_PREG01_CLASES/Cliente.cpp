/* 
 * File:   Cliente.cpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 21 de mayo de 2024, 10:39 PM
 */

#include "Cliente.hpp"

Cliente::Cliente() {
    dni = 0;
    nombre = nullptr;
    telefono = 0;
    cantidad_productos_entregados = 0;
    monto_total = 0.0;
}

Cliente::Cliente(const Cliente& orig) {
}

Cliente::~Cliente() {
    delete nombre;
}

void Cliente::SetMonto_total(double monto_total) {
    this->monto_total = monto_total;
}

double Cliente::GetMonto_total() const {
    return monto_total;
}

void Cliente::SetCantidad_productos_entregados(int cantidad_productos_entregados) {
    this->cantidad_productos_entregados = cantidad_productos_entregados;
}

int Cliente::GetCantidad_productos_entregados() const {
    return cantidad_productos_entregados;
}

void Cliente::SetTelefono(int telefono) {
    this->telefono = telefono;
}

int Cliente::GetTelefono() const {
    return telefono;
}

void Cliente::SetNombre(char* nombre) {
    if(this->nombre != nullptr) delete this->nombre;
    this->nombre = new char [strlen(nombre) + 1];
    strcpy(this->nombre,nombre);
}

void Cliente::GetNombre(char *nombre) const {
    if(this->nombre != nullptr) strcpy(nombre,this->nombre);
    else nombre[0] = 0;// '\0'
}

void Cliente::SetDni(int dni) {
    this->dni = dni;
}

int Cliente::GetDni() const {
    return dni;
}

