/* 
 * File:   St_Libro.hpp
 * Author: Jesus Huayhua
 * Codigo: 20196291
 *
 * Created on October 8, 2023, 8:28 AM
 */

#ifndef ST_LIBRO_HPP
#define ST_LIBRO_HPP
#include "St_UsuarioPrestamo.hpp"

struct St_Libro{
    char codigo[20];
    char titulo[50];
    int stock;
    double precio;
    int prestados;
    struct St_UsuarioPrestamo estudiantes;
    struct St_UsuarioPrestamo docentes;
    struct St_UsuarioPrestamo administativos;
    int cantEst;
    int cantDoc;
    int cantAdm;
};

#endif /* ST_LIBRO_HPP */

