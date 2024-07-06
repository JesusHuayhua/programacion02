/* 
 * File:   NVehiculo.hpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 19 de junio de 2024, 01:42 PM
 */

#ifndef NVEHICULO_HPP
#define NVEHICULO_HPP

#include "Vehiculo.hpp"
#include "Utils.hpp"

class NVehiculo {
public:
    NVehiculo();
    NVehiculo(const NVehiculo& orig);
    virtual ~NVehiculo();
    void lee_vehiculo(std::ifstream &file);
    void imprime_vehiculo(std::ofstream &file);
private:
    Vehiculo *unidad;
};


#endif /* NVEHICULO_HPP */

