/* 
 * File:   Vehiculo.hpp
 * Author: Jesus Huayhau FLores
 * Codigo: 20196201
 */

#ifndef VEHICULO_HPP
#define VEHICULO_HPP

#include "Utils.hpp"
#include "NPedido.hpp"

class Vehiculo {
public:
    Vehiculo();
    Vehiculo(const Vehiculo& orig);
    virtual ~Vehiculo();
    void SetActcarga(double actcarga);
    double GetActcarga() const;
    void SetMaxcarga(double maxcarga);
    double GetMaxcarga() const;
    void SetPlaca(const char* placa);
    void GetPlaca(char *placa) const;
    void SetCliente(int cliente);
    int GetCliente() const;
private:
    int cliente;
    char *placa;
    double maxcarga;
    double actcarga;
    class NPedido *pedido;
};

#endif /* VEHICULO_HPP */

