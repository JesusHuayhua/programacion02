/* 
 * File:   Cliente.hpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 21 de mayo de 2024, 10:39 PM
 */

#ifndef CLIENTE_HPP
#define CLIENTE_HPP

class Cliente {
public:
    Cliente();
    Cliente(const Cliente& orig);
    virtual ~Cliente();
    void SetMonto_total(double monto_total);
    double GetMonto_total() const;
    void SetCantidad_productos_entregados(int cantidad_productos_entregados);
    int GetCantidad_productos_entregados() const;
    void SetTelefono(int telefono);
    int GetTelefono() const;
    void SetNombre(char* nombre);
    char* GetNombre() const;
    void SetDni(int dni);
    int GetDni() const;
private:
    int dni;
    char *nombre;
    int telefono;
    ProductoEntregado productos_entregados[50];
    int cantidad_productos_entregados;
    double monto_total;
};

#endif /* CLIENTE_HPP */

