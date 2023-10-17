/* 
 * File:   St_Usuario.hpp
 * Author: Jesus Huayhua
 * Codigo: 20196291
 *
 * Created on October 8, 2023, 8:23 AM
 */

#ifndef ST_USUARIO_HPP
#define ST_USUARIO_HPP

#include "St_LibroPrestado.hpp"

struct St_Usuario{
    int carne;
    char tipo[20];
    char nombre[60];
    struct St_LibroPrestado libPrest[20];
    int numLibPrest;// cuenta de libro que se lleva prestado el usuario
    char condicion[20];
};

#endif /* ST_USUARIO_HPP */

