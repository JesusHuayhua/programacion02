/* 
 * File:   Pedido.hpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 23 de mayo de 2024, 11:12 PM
 */

#ifndef PEDIDO_HPP
#define PEDIDO_HPP
#include "Utils.hpp"

class Pedido {
public:
    Pedido();
    Pedido(const Pedido& orig);
    virtual ~Pedido();
    void SetPrecio_producto(double precio_producto);
    double GetPrecio_producto() const;
    void SetDni_cliente(int dni_cliente);
    int GetDni_cliente() const;
    void SetCodigo(char* codigo);
    void GetCodigo(char *codigo) const;
private:
    char *codigo;
    int dni_cliente;
    double precio_producto;
};
bool operator>>(std::ifstream &input, class Pedido &pedido);
#endif /* PEDIDO_HPP */

