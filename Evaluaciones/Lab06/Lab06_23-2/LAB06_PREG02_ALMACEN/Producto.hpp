/* 
 * File:   Producto.hpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 21 de mayo de 2024, 10:59 PM
 */

#ifndef PRODUCTO_HPP
#define PRODUCTO_HPP

#include "Utils.hpp"
#include "Pedido.hpp"
class Producto {
public:
    Producto();
    virtual ~Producto();
    //getters and setters
    void SetCantidad_clientes_no_servidos(int cantidad_clientes_no_servidos);
    int GetCantidad_clientes_no_servidos() const;
    void SetCantidad_clientes_servidos(int cantidad_clientes_servidos);
    int GetCantidad_clientes_servidos() const;
    void SetStock(int stock);
    int GetStock() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetDescripcion(char* descripcion);
    void GetDescripcion(char *descripcion) const;
    void SetCodigo(char* codigo);
    void GetCodigo(char *codigo) const;
    void SetClientes_no_servidos(int* clientes_no_servidos);
    int GetClientes_no_servidos(int pos) const;
    void SetClientes_servidos(int* clientes_servidos);
    int GetClientes_servidos(int pos) const;
    // funciones adicionales
    bool operator+=(class Pedido &pedido);
    void imprimir_clientes_atendidos(std::ofstream &);
    void imprimir_clientes_no_atendidos(std::ofstream &);
private:
    char *codigo;
    char *descripcion;
    double precio;
    int stock;
    int clientes_servidos[100]{};
    int clientes_no_servidos[100]{};
    int cantidad_clientes_servidos;
    int cantidad_clientes_no_servidos;
};
bool operator>>(std::ifstream &input, class Producto &producto);
void operator<<(std::ofstream &output,class Producto producto);
#endif /* PRODUCTO_HPP */

