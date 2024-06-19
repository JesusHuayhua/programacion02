/* 
 * File:   NodoLista.hpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 13 de junio de 2024, 06:02 PM
 */

#ifndef NODOLISTA_HPP
#define NODOLISTA_HPP

#include "Vehiculo.hpp"

class NodoLista {
public:
    NodoLista();
    NodoLista(const NodoLista& orig);
    virtual ~NodoLista();
    friend class LVehiculos;
private:
    class Vehiculo unidad;
    class NodoLista *sig;
};

#endif /* NODOLISTA_HPP */

