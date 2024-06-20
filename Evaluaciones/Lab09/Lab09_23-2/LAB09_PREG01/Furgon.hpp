/* 
 * File:   Furgon.hpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 19 de junio de 2024, 12:47 PM
 */

#ifndef FURGON_HPP
#define FURGON_HPP

#include "Utils.hpp"
#include "NPedido.hpp"
#include "Vehiculo.hpp"

class Furgon : public Vehiculo {
public:
    Furgon();
    Furgon(const Furgon& orig);
    virtual ~Furgon();
    void SetPuertas(int puertas);
    int GetPuertas() const;
    void SetFilas(int filas);
    int GetFilas() const;
    void lee(std::ifstream &file);
    void imprime(std::ofstream &file);
private:
    int filas;
    int puertas;
    std::list<NPedido> pdeposito;
};

#endif /* FURGON_HPP */

