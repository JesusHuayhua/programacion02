/* 
 * File:   operadores_sobrecargados.hpp
 * Author: Jesus Huayhua
 * Codigo: 20196201
 *
 * Created on 3 de abril de 2024, 09:35 AM
 */

#ifndef OPERADORES_SOBRECARGADOS_HPP
#define OPERADORES_SOBRECARGADOS_HPP

#include "Utils.hpp"

bool operator>>(ifstream &arch, struct Cliente &cliente);
bool operator>>(istream &arch, struct Producto &producto);
bool operator>>(ifstream &arch, struct Pedido &pedido);


void operator+=(struct Cliente *arregloCliente, const struct Pedido pedido);
bool operator+=(struct Producto *arregloProducto, struct Pedido &pedido);

ofstream & operator<<(ofstream &arch, const struct Cliente cliente);
ofstream& operator<<(ofstream &arch, const struct Producto producto);
#endif /* OPERADORES_SOBRECARGADOS_HPP */

