/* 
 * File:   Camion.cpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 19 de junio de 2024, 12:45 PM
 */

#include "Camion.hpp"

using namespace std;

Camion::Camion() {
    ejes = 0;
    llantas = 0;
}

Camion::Camion(const Camion& orig) {
}

Camion::~Camion() {
}

void Camion::setLlantas(int llantas) {
    this->llantas = llantas;
}

int Camion::getLlantas() const {
    return llantas;
}

void Camion::setEjes(int ejes) {
    this->ejes = ejes;
}

int Camion::getEjes() const {
    return ejes;
}

void Camion::lee(std::ifstream &file){
    this->Vehiculo::lee(file);
    char c;
    int ejes, llantas;
    file >> ejes >> c >> llantas;
    this->setEjes(ejes);
    this->setLlantas(llantas);
}

void Camion::imprime(std::ofstream &file){
    this->Vehiculo::imprime(file);
    file << setw(20) << "#Ejes:" << this->getEjes() << endl; 
    file << setw(20) << "#Llantas:" << this->getLlantas() << endl; 
}