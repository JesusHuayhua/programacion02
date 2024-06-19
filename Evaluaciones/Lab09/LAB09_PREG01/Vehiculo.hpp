/* 
 * File:   Vehiculo.hpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 19 de junio de 2024, 12:10 PM
 */

#ifndef VEHICULO_HPP
#define VEHICULO_HPP

#include "Utils.hpp"

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
    // Funciones
    virtual void lee(std::ifstream &file);
private:
    int cliente;
    char *placa;
    double maxcarga;
    double actcarga;
};

#endif /* VEHICULO_HPP */

