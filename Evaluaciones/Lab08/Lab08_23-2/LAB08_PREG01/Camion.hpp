/* 
 * File:   Camion.hpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 */

#ifndef CAMION_HPP
#define CAMION_HPP

#include "Vehiculo.hpp"
#include "Utils.hpp"

class Camion : public Vehiculo{
public:
    Camion();
    Camion(const Camion& orig);
    virtual ~Camion();
    void SetLlantas(int llantas);
    int GetLlantas() const;
    void SetEjes(int ejes);
    int GetEjes() const;
    void lee(std::ifstream &file);
private:
    int ejes;
    int llantas;
};

#endif /* CAMION_HPP */

