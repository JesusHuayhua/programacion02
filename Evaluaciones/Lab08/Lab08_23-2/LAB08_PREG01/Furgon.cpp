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
//int cliente;
//    char *placa;
//    double maxcarga;
//    double actcarga;
void Furgon::lee(std::ifstream &file){
    char placa[40],c;
    int cliente,filas, puertas;
    double maxcarga;
    file >> cliente >> c;
    file.getline(placa,40,',');
    file >> maxcarga >> c >> filas >> c >> puertas;
    this->SetCliente(cliente);
    this->SetPlaca(placa);
    this->SetMaxcarga(maxcarga);
    this->SetFilas(filas);
    this->SetPuertas(puertas);
}
