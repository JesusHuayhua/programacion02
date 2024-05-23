/* 
 * File:   Producto.hpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 21 de mayo de 2024, 10:59 PM
 */

#ifndef PRODUCTO_HPP
#define PRODUCTO_HPP

#include "ProductoEntregado.hpp"


class Producto {
public:
    Producto();
    Producto(const Producto& orig);
    virtual ~Producto();
    void SetCantidad_clientes_no_servidos(int cantidad_clientes_no_servidos);
    int GetCantidad_clientes_no_servidos() const;
    void SetCantidad_clientes_servidos(int cantidad_clientes_servidos);
    int GetCantidad_clientes_servidos() const;
    void SetClientes_no_servidos(int[] clientes_no_servidos);
    void SetClientes_servidos(int[] clientes_servidos);
    void SetStock(int stock);
    int GetStock() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetDescripcion(char* descripcion);
    char* GetDescripcion() const;
    void SetCodigo(char* codigo);
    char* GetCodigo() const;
private:
    char *codigo;
    char *descripcion;
    double precio;
    int stock;
    int clientes_servidos[50];
    int clientes_no_servidos[50];
    int cantidad_clientes_servidos;
    int cantidad_clientes_no_servidos;
};

#endif /* PRODUCTO_HPP */

