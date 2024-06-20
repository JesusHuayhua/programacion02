/* 
 * File:   NPedido.hpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 19 de junio de 2024, 11:47 AM
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
    void GetCodigo(char *) const;
    void SetCodigo(char* codigo);
    char* GetCodigo() const;
private:
    char *codigo;
    int cantidad;
    double peso;
};

#endif /* NPEDIDO_HPP */

