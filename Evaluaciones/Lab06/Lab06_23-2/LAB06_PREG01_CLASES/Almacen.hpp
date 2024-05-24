/* 
 * File:   Almacen.hpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 23 de mayo de 2024, 11:20 PM
 */

#ifndef ALMACEN_HPP
#define ALMACEN_HPP

#include "Utils.hpp"
#include "Producto.hpp"
#include "Cliente.hpp"

class Almacen {
public:
    Almacen();
    Almacen(const Almacen& orig);
    virtual ~Almacen();
    void SetCantidad_productos(int cantidad_productos);
    int GetCantidad_productos() const;
    void SetCantidad_clientes(int cantidad_clientes);
    int GetCantidad_clientes() const;
private:
    class Cliente arreglo_clientes[50];
    int cantidad_clientes;
    class Producto arreglo_producto[50];
    int cantidad_productos;
};

#endif /* ALMACEN_HPP */

