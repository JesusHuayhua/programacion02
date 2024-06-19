/* 
 * File:   Flota.hpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 19 de junio de 2024, 01:47 PM
 */

#ifndef FLOTA_HPP
#define FLOTA_HPP

#include "NVehiculo.hpp"
#include "Utils.hpp"

class Flota {
public:
    Flota();
    Flota(const Flota& orig);
    virtual ~Flota();
    void cargaflota(void);
private:
    std::vector<NVehiculo> vflota;
};

#endif /* FLOTA_HPP */

