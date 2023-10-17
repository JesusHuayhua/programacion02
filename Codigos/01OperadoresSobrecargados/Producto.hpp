#ifndef PRECIO_HPP
#define PRECIO_HPP

#include <string>

struct Productos{
    std::string nombre;
    int stock;
    double precio;

    Productos& operator+=(const Productos& prod);
};

#endif /*PRECIO_HPP*/
