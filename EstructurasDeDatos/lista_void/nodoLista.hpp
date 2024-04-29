/* 
 * File:   nodoLista.hpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 */

#ifndef NODOLISTA_HPP
#define NODOLISTA_HPP

#include "elementoLista.hpp"

typedef struct nodo{
    ElementoLista elemento;
    struct nodo *siguiente;
} Nodo;

#endif /* NODOLISTA_HPP */

