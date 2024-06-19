/* 
 * File:   Flota.hpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 13 de junio de 2024, 06:07 PM
 */

#ifndef FLOTA_HPP
#define FLOTA_HPP

#include "LVehiculos.hpp"

class Flota {
public:
    Flota();
    Flota(const Flota& orig);
    virtual ~Flota();
    void cargaflota(void);
    void muestracarga(void);
    void imprime(std::ofstream &file);
private:
    class LVehiculos lista;
};

#endif /* FLOTA_HPP */

