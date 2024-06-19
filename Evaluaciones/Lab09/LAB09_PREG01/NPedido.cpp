/* 
 * File:   NPedido.cpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 19 de junio de 2024, 11:47 AM
 */

#include "NPedido.hpp"

NPedido::NPedido() {
    codigo = nullptr;
    cantidad = 0;
    peso = 0.0;
}

NPedido::NPedido(const NPedido& orig) {
    this->codigo = orig.codigo;
    this->cantidad = orig.cantidad;
    this->peso = orig.peso;
}

NPedido::~NPedido() {
    if(codigo != nullptr) delete codigo;
}

void NPedido::SetPeso(double peso) {
    this->peso = peso;
}

double NPedido::GetPeso() const {
    return peso;
}

void NPedido::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int NPedido::GetCantidad() const {
    return cantidad;
}

void NPedido::SetCodigo(const char* codigo) {
    if(this->codigo != nullptr) delete this->codigo;
    this->codigo = new char[strlen(codigo) + 1];
    strcpy(this->codigo, codigo);
}

void NPedido::GetCodigo(char *codigo) const {
    if (this->codigo == nullptr) {
        codigo[0] = 0;
    } else {
        strcpy(codigo,this->codigo);
    }
}

void NPedido::SetCodigo(char* codigo) {
    this->codigo = codigo;
}

char* NPedido::GetCodigo() const {
    return codigo;
}
