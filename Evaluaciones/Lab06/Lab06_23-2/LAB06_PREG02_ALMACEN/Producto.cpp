/* 
 * File:   Producto.cpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 21 de mayo de 2024, 10:59 PM
 */

#include "Producto.hpp"
#include "ProductoEntregado.hpp"

using namespace std;

Producto::Producto() {
    codigo = nullptr;
    descripcion = nullptr;
    precio = 0.0;
    stock = 0;
    cantidad_clientes_servidos = 0;
    cantidad_clientes_no_servidos = 0;
}

Producto::~Producto() {
    // prueba de linux
//    if(codigo != nullptr) delete codigo;
//    if(descripcion != nullptr) delete descripcion;
    delete codigo;
    delete descripcion;
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
    if (this->descripcion != nullptr) delete this->descripcion;
    this->descripcion = new char [strlen(descripcion) + 1];
    strcpy(this->descripcion, descripcion);
}

void Producto::GetDescripcion(char *descripcion) const {
    if (this->descripcion != nullptr) strcpy(descripcion, this->descripcion);
    else descripcion[0] = 0;
}

void Producto::SetCodigo(char* codigo) {
    if (this->codigo != nullptr) delete this->codigo;
    this->codigo = new char [strlen(codigo) + 1];
    strcpy(this->codigo, codigo);
}

void Producto::GetCodigo(char *codigo) const {
    if (this->codigo != nullptr) strcpy(codigo,this->codigo);
    else codigo[0] = 0;
}

void Producto::SetClientes_no_servidos(int *clientes_no_servidos) {

}

int Producto::GetClientes_no_servidos(int pos) const {
    return clientes_no_servidos[pos];
}

void Producto::SetClientes_servidos(int* clientes_servidos) {

}

int Producto::GetClientes_servidos(int pos) const {
    return clientes_servidos[pos];
}

void Producto::imprimir_clientes_atendidos(std::ofstream &arch) {
    arch << "Clientes Atendidos: ";
    if (cantidad_clientes_servidos == 0) {
        arch << "NO SE ATENDIERON PEDIDOS" << endl;
    } else {
        for (int i = 0; i < cantidad_clientes_servidos; i++) {
            arch << left << setw(10) << clientes_servidos[i] << " ";
        }
        arch << endl;
    }
}

void Producto::imprimir_clientes_no_atendidos(std::ofstream &arch) {
    arch << "Clientes NO Atendidos: ";
    if (cantidad_clientes_no_servidos == 0) {
        arch << "NO HAY CLIENTES SIN ATENDER" << endl;
    } else {
        for (int i = 0; i < cantidad_clientes_no_servidos; i++) {
            arch << left << setw(10) << clientes_no_servidos[i] << " ";
        }
        arch << endl;
    }
}

bool Producto::operator+=(class Pedido &pedido) {
    pedido.SetPrecio_producto(precio); //le damos el precio del producto
    if (this->stock > 0) {
        clientes_servidos[cantidad_clientes_servidos] = pedido.GetDni_cliente();
        stock--;
        cantidad_clientes_servidos++;
        return true;
    } else {
        clientes_no_servidos[cantidad_clientes_no_servidos] = pedido.GetDni_cliente();
        cantidad_clientes_no_servidos++;
        return false;
    }
}

bool operator>>(ifstream &input, class Producto &producto) {
    char codigo[50], descripcion[100], c;
    double precio;
    int stock;
    input.getline(codigo, 20, ',');
    if (input.eof())return false;
    input.getline(descripcion, 100, ',');
    input >> precio >> c >> stock;
    input.get();
    producto.SetCodigo(codigo);
    producto.SetDescripcion(descripcion);
    producto.SetPrecio(precio);
    producto.SetStock(stock);
    return true;
}

void operator<<(std::ofstream &arch, class Producto producto) {
    char codigo[20], descripcion[100];
    producto.GetCodigo(codigo);
    producto.GetDescripcion(descripcion);
    arch << left << fixed << setprecision(2);
    arch << setw(15) << codigo
            << setw(50) << descripcion
            << setw(10) << producto.GetPrecio()
            << producto.GetStock() << endl;
    producto.imprimir_clientes_atendidos(arch);
    producto.imprimir_clientes_no_atendidos(arch);
}
