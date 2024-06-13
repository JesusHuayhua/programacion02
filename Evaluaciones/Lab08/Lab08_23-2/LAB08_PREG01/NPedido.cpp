/* 
 * File:   NPedido.cpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 13 de junio de 2024, 05:44 PM
 */

#include "NPedido.hpp"

using namespace std;

NPedido::NPedido() {
}

NPedido::NPedido(const NPedido& orig) {
}

NPedido::~NPedido() {
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
    this->codigo = new char [strlen(codigo) + 1];
    strcpy(this->codigo,codigo);
}

void NPedido::GetCodigo(char *codigo) const {
    if(this->codigo == nullptr) codigo[0] = 0;
    else strcpy(codigo,this->codigo);
}

