/* 
 * File:   Furgon.cpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 13 de junio de 2024, 06:01 PM
 */

#include "Furgon.hpp"

Furgon::Furgon() {
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

