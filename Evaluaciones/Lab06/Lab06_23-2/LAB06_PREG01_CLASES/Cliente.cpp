/* 
 * File:   Cliente.cpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 21 de mayo de 2024, 10:39 PM
 */

#include "Cliente.hpp"
using namespace std;

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

void Cliente::SetNombre(const char* nombre) {
    if (this->nombre != nullptr) delete this->nombre;
    this->nombre = new char [strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
}

void Cliente::GetNombre(char *nombre) const {
    if (this->nombre != nullptr) strcpy(nombre, this->nombre);
    else nombre[0] = 0; // '\0'
}

void Cliente::SetDni(int dni) {
    this->dni = dni;
}

int Cliente::GetDni() const {
    return dni;
}

void Cliente::operator+=(class Pedido &pedido) {
    char codigo[50];
    pedido.GetCodigo(codigo);
    this->productos_entregados[this->cantidad_productos_entregados].SetCodigo(codigo);
    this->productos_entregados[this->cantidad_productos_entregados].SetPrecio(pedido.GetPrecio_producto());
    this->cantidad_productos_entregados++;
    this->monto_total += pedido.GetPrecio_producto();
}

void Cliente::imprimir_productos_entregados(std::ofstream &output) {
    char codigo[50];
    if (cantidad_productos_entregados == 0) {
        output << "NO SE LE ENTREGARON PRODUCOTOS" << endl;
    } else {
        for (int i = 0; i < cantidad_productos_entregados; i++) {
            productos_entregados[i].GetCodigo(codigo);
            output << codigo << " ";
        }
    }
}

// arch >> cliente

bool operator>>(ifstream &input, class Cliente &cliente) {
    int dni, telefono;
    char nombre[50];
    input >> dni;
    if (input.eof())return false;
    input.get(); //leemos la coma
    input.getline(nombre, 50, ',');
    input >> telefono;
    input.get();
    cliente.SetDni(dni);
    cliente.SetNombre(nombre);
    cliente.SetTelefono(telefono);
    return true;
}

void operator<<(std::ofstream &output, class Cliente &cliente) {
    char nombre[100];
    cliente.GetNombre(nombre);
    output << left;
    output << setw(10) << cliente.GetDni();
    output << setw(50) << nombre;
    output << setw(10) << cliente.GetTelefono();
    cliente.imprimir_productos_entregados(output);
    output << endl;
}
