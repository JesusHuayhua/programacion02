/* 
 * File:   Vehiculo.cpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 13 de junio de 2024, 05:51 PM
 */

#include "Vehiculo.hpp"

using namespace std;

Vehiculo::Vehiculo() {
}

Vehiculo::Vehiculo(const Vehiculo& orig) {
}

Vehiculo::~Vehiculo() {
}

void Vehiculo::SetActcarga(double actcarga) {
    this->actcarga = actcarga;
}

double Vehiculo::GetActcarga() const {
    return actcarga;
}

void Vehiculo::SetMaxcarga(double maxcarga) {
    this->maxcarga = maxcarga;
}

double Vehiculo::GetMaxcarga() const {
    return maxcarga;
}

void Vehiculo::SetPlaca(const char* placa) {
    if(this->placa != nullptr) delete this->placa;
    this->placa = new char[strlen(placa) + 1];
    strcpy(this->placa,placa);
}

void Vehiculo::GetPlaca(char *placa) const {
    if(this->placa == nullptr) delete placa[0] = 0;
    else strcpy(placa,this->placa);
}

void Vehiculo::SetCliente(int cliente) {
    this->cliente = cliente;
}

int Vehiculo::GetCliente() const {
    return cliente;
}

