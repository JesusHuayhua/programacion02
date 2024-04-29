/* 
 * File:   funciones.hpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

#include "lista.hpp"

using namespace std;
void apertura_de_archivo_para_leer(ifstream &file, const char *name);
void apertura_de_archivo_para_escribir(ofstream &file, const char *name);

void leer_archivo_productos(Lista &lista, ifstream &archivo);
ElementoLista leer_producto(ifstream &archivo);
char *leerString(ifstream &file);

#endif /* FUNCIONES_HPP */

