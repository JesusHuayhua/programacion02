/* 
 * File:   NPedido.hpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 */

#ifndef NPEDIDO_HPP
#define NPEDIDO_HPP

#include "Utils.hpp"

class NPedido {
public:
    NPedido();
    NPedido(const NPedido& orig);
    virtual ~NPedido();
    void SetPeso(double peso);
    double GetPeso() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(const char* codigo);
    void GetCodigo(char *codigo) const;
private:
    char *codigo;
    int cantidad;
    double peso;
    class NPedido *siguiente;
};

#endif /* NPEDIDO_HPP */

