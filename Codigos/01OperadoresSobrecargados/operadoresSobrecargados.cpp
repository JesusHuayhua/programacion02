#include <iostream>
#include <iomanip>
#include "operadoresSobrecargados.hpp"


// forma sencilla
/*
std::ostream &operator << (std::ostream &os, const Productos &prod){
	os << prod.nombre << " " << prod.precio << " " << prod.stock;
	return os;
}
*/

std::ostream &operator << (std::ostream &os, const Productos &prod){
    os <<  std::setw(30) << std::left << "Nombre del porducto: " <<  prod.nombre << std::endl
          << std::setw(30) << std::left << "Precio: " << prod.precio << std::endl
           << std::setw(30) << std::left << "Stock: " <<prod.stock;
    return os;
}

std::istream &operator>>(std::istream &is, Productos &prod){
    is >> prod.nombre >> prod.precio >> prod.stock;
    if (!is){
        std::cerr << "No se puedo leer satisfactoriamente el producto " << std::endl;
        prod = Productos();
    }
    return is;
}

Productos operator+(const Productos prod1, const Productos prod2){
    Productos prod = Productos();
    if (prod1.nombre == prod2.nombre){
        prod.nombre = prod1.nombre;
        prod.precio = prod1.precio > prod2.precio ? prod1.precio : prod2.precio;
        prod.stock = prod1.stock + prod2.stock;
    }
    return prod;
}


bool operator==(const Productos &prod1, const Productos &prod2){
    return prod1.nombre == prod2.nombre
        && prod1.precio == prod2.precio
        && prod1.stock == prod2.stock;
}

bool operator!=(const Productos &prod1,const Productos &prod2){
    return !(prod1 == prod2);
}

Productos& Productos::operator+=(const Productos &prod){
    nombre += prod.nombre;
    precio += prod.precio;
    stock += prod.stock;
    return *this;
}
