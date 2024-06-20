/* 
 * File:   Vehiculo.cpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 19 de junio de 2024, 12:10 PM
 */

#include "Vehiculo.hpp"

using namespace std;

Vehiculo::Vehiculo() {
    cliente = 0;
    placa = nullptr;
    maxcarga = 0.0;
    actcarga = 0.0;
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
    if (this->placa != nullptr) delete this->placa;
    this->placa = new char [strlen(placa) + 1];
    strcpy(this->placa, placa);
}

void Vehiculo::GetPlaca(char *placa) const {
    if (this->placa == nullptr) {
        placa[0] = 0;
    } else {
        strcpy(placa, this->placa);
    }
}

void Vehiculo::SetCliente(int cliente) {
    this->cliente = cliente;
}

int Vehiculo::GetCliente() const {
    return cliente;
}

void Vehiculo::lee(std::ifstream &file) {
    int cliente;
    char placa[20],c;
    double maxcarga;
    file >> cliente >> c;
    file.getline(placa,20,',');
    file >> maxcarga >> c;
    this->SetCliente(cliente);
    this->SetPlaca(placa);
    this->SetMaxcarga(maxcarga);
}

void Vehiculo::imprime(std::ofstream &file){
    char placa[20];
    this->GetPlaca(placa);
    file << setw(20) << "Codigo Cliente: " << this->GetCliente() << endl;
    file << setw(20) << "Placa:" << placa << endl;
    file << setw(20) << "Carga Maxima:" << this->GetMaxcarga() << endl;
    file << setw(20) << "Carga Actual:" << this->GetActcarga() << endl;
}
