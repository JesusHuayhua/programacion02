/* 
 * File:   LVehiculos.hpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 13 de junio de 2024, 06:06 PM
 */

#ifndef LVEHICULOS_HPP
#define LVEHICULOS_HPP

#include "NodoLista.hpp"

class LVehiculos {
public:
    LVehiculos();
    LVehiculos(const LVehiculos& orig);
    virtual ~LVehiculos();
private:
    class NodoLista *lini;
    class NodoLista *lfin;
};

#endif /* LVEHICULOS_HPP */

