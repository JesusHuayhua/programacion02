/* 
 * File:   Furgon.cpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 19 de junio de 2024, 12:47 PM
 */

#include "Furgon.hpp"
#include "Vehiculo.hpp"

Furgon::Furgon() {
    filas = 0;
    puertas = 0;
}

Furgon::Furgon(const Furgon& orig) {
}

Furgon::~Furgon() {
}

void Furgon::SetPuertas(int puertas) {
    this->puertas = puertas;
}

int Furgon::GetPuertas() const {
    return puertas;
}

void Furgon::SetFilas(int filas) {
    this->filas = filas;
}

int Furgon::GetFilas() const {
    return filas;
}

void Furgon::lee(std::ifstream &file){
    this->Vehiculo::lee(file);
    char c;
    int filas, puertas;
    file >> filas >> c >> puertas;
    file.get();//leemos el salto de linea
}
