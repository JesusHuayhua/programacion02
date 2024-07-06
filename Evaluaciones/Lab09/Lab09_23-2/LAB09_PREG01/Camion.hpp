/* 
 * File:   Camion.hpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 19 de junio de 2024, 12:45 PM
 */

#ifndef CAMION_HPP
#define CAMION_HPP

#include "Utils.hpp"
#include "NPedido.hpp"
#include "Vehiculo.hpp"

class Camion : public Vehiculo {
public:
    Camion();
    Camion(const Camion& orig);
    virtual ~Camion();
    void setLlantas(int llantas);
    int getLlantas() const;
    void setEjes(int ejes);
    int getEjes() const;
    // funciones
    void lee(std::ifstream &file);
    void imprime(std::ofstream &file);
private:
    int ejes;
    int llantas;
    std::map <int,class NPedido> mdeposito;
};

#endif /* CAMION_HPP */

