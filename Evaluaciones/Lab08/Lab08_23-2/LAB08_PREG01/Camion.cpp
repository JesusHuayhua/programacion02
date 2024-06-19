/* 
 * File:   Camion.cpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 13 de junio de 2024, 06:00 PM
 */

#include "Camion.hpp"

Camion::Camion() {
}

Camion::Camion(const Camion& orig) {
}

Camion::~Camion() {
}

void Camion::SetLlantas(int llantas) {
    this->llantas = llantas;
}

int Camion::GetLlantas() const {
    return llantas;
}

void Camion::SetEjes(int ejes) {
    this->ejes = ejes;
}

int Camion::GetEjes() const {
    return ejes;
}

//int cliente;
//    char *placa;
//    double maxcarga;
//    double actcarga;
void Camion::lee(std::ifstream &file){
    char placa[40],c;
    int cliente,ejes,llantas;
    double maxcarga;
    file >> cliente >> c;
    file.getline(placa,40,',');
    file >> maxcarga >> c >> ejes >> c >> llantas;
    this->SetCliente(cliente);
    this->SetPlaca(placa);
    this->SetMaxcarga(maxcarga);
    this->SetEjes(ejes);
    this->SetLlantas(llantas);
}