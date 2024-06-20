/* 
 * File:   NVehiculo.cpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 19 de junio de 2024, 01:42 PM
 */

#include "NVehiculo.hpp"
#include "Flota.hpp"
#include "Furgon.hpp"
#include "Camion.hpp"

NVehiculo::NVehiculo() {
    unidad = nullptr;
}

NVehiculo::NVehiculo(const NVehiculo& orig) {
    this->unidad = orig.unidad;
}

NVehiculo::~NVehiculo() {
}

void NVehiculo::lee_vehiculo(std::ifstream &file){
    char tipo_vehiculo,c;//tipo de vehiculo
    file >> tipo_vehiculo >> c;
    if(file.eof())return;
    switch (tipo_vehiculo){
        case 'F':
            this->unidad = new Furgon;
            break;
        case 'C':
            this->unidad = new Camion;
            break;
    }
    this->unidad->lee(file);
}

void NVehiculo::imprime_vehiculo(std::ofstream &file){
    this->unidad->imprime(file);
}