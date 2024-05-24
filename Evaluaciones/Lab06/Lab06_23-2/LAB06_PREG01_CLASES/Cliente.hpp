/* 
 * File:   Cliente.hpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 21 de mayo de 2024, 10:39 PM
 */

#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include "ProductoEntregado.hpp"
#include "Pedido.hpp"

class Cliente {
public:
    Cliente();
    Cliente(const Cliente& orig);
    virtual ~Cliente();
    // Getters and Setter
    void SetMonto_total(double monto_total);
    double GetMonto_total() const;
    void SetCantidad_productos_entregados(int cantidad_productos_entregados);
    int GetCantidad_productos_entregados() const;
    void SetTelefono(int telefono);
    int GetTelefono() const;
    void SetNombre(const char* nombre);
    void GetNombre(char *nombre) const;
    void SetDni(int dni);
    int GetDni() const;
    // Funciones miembro adicionales
    void operator+=(class Pedido &pedido);
    void imprimir_productos_entregados(std::ofstream  &);
private:
    int dni;
    char *nombre;
    int telefono;
    ProductoEntregado productos_entregados[100];
    int cantidad_productos_entregados;
    double monto_total;
};
bool operator>>(std::ifstream &input, class Cliente &cliente);
void operator<<(std::ofstream &output, class Cliente &cliente);
#endif /* CLIENTE_HPP */

