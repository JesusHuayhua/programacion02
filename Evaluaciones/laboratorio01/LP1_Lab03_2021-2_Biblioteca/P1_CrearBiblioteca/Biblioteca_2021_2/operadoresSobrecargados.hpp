/* 
 * File:   operadoresSobrecargados.hpp
 * Author: Jesus Huayhua
 * Codigo: 20196291
 *
 * Created on October 8, 2023, 8:33 AM
 */

#ifndef OPERADORESSOBRECARGADOS_HPP
#define OPERADORESSOBRECARGADOS_HPP
#include "St_Libro.hpp"
#include "St_Usuario.hpp"

bool operator>>(std::ifstream archLibro,St_Libro libro);
bool operator>>(std::ifstream archUsuario, St_Usuario &usuario);
void operator+=(St_Usuario &usuario,const St_LibroPrestado libroPres);A



#endif /* OPERADORESSOBRECARGADOS_HPP */

