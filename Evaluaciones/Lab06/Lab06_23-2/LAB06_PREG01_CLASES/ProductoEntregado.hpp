/* 
 * File:   ProductoEntregado.hpp
 * Alumno: Jesus Huayhua Flores
 * Codigo: 20196201
 *
 * Created on 21 de mayo de 2024, 10:14 PM
 */

#ifndef PRODUCTOENTREGADO_HPP
#define PRODUCTOENTREGADO_HPP

#include "Utils.hpp"

class ProductoEntregado {
public:
    ProductoEntregado();
    ProductoEntregado(const ProductoEntregado& orig);
    virtual ~ProductoEntregado();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCodigo(char* codigo);
    void ProductoEntregado::GetCodigo(char *codigo) const;
private:
    char *codigo;
    double precio;
};

#endif /* PRODUCTOENTREGADO_HPP */

