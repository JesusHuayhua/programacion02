/* 
 * File:   ProductoEntregado.cpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 21 de mayo de 2024, 10:14 PM
 */

#include "ProductoEntregado.hpp"

ProductoEntregado::ProductoEntregado() {
    codigo = nullptr;
    precio = 0.0;
}

ProductoEntregado::ProductoEntregado(const ProductoEntregado& orig) {
}

ProductoEntregado::~ProductoEntregado() {
    delete codigo;
}

void ProductoEntregado::SetPrecio(double precio) {
    this->precio = precio;
}

double ProductoEntregado::GetPrecio() const {
    return precio;
}

void ProductoEntregado::SetCodigo(char* codigo) {
    if(this->codigo != nullptr) delete this->codigo;
    this->codigo = new char[strlen(codigo) + 1];
    strcpy(this->codigo,codigo);
}


void ProductoEntregado::GetCodigo(char *codigo) const {//100
    if(this->codigo == nullptr) codigo[0] = 0;
    else strcpy(codigo,this->codigo);
}
