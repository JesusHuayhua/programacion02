#ifndef OPERADORES_SOBRECARGADOS_HPP
#define OPERADORES_SOBRECARGADOS_HPP

#include "Producto.hpp"

std::ostream &operator << (std::ostream &os, const Productos &prod);
std::istream &operator >>(std::istream &is, Productos &prod);
Productos operator+(const Productos prod1, const Productos prod2);
bool operator==(const Productos &prod1, const Productos &prod2);
bool operator!=(const Productos &prod1,const Productos &prod2);

#endif /*OPERADORES_SOBRECARGADOS_HPP*/