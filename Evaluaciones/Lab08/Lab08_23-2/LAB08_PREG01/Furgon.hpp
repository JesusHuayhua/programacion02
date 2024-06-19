/* 
 * File:   Furgon.hpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 13 de junio de 2024, 06:01 PM
 */

#ifndef FURGON_HPP
#define FURGON_HPP

#include "Vehiculo.hpp"
#include "Utils.hpp"

class Furgon : public Vehiculo {
public:
    Furgon();
    Furgon(const Furgon& orig);
    virtual ~Furgon();
    void SetPuertas(int puertas);
    int GetPuertas() const;
    void SetFilas(int filas);
    int GetFilas() const;
    void lee(std::ifstream &);
private:
    int filas;
    int puertas;
};

#endif /* FURGON_HPP */

