/* 
 * File:   Pregunta01Examen01PunterosMultiples.hpp
 * Author: alulab14
 * Alumno: Jesus Huayhua
 * Codigo: 20196201
 * Created on 7 de mayo de 2024, 10:34 AM
 */

#ifndef PREGUNTA01EXAMEN01PUNTEROSMULTIPLES_HPP
#define PREGUNTA01EXAMEN01PUNTEROSMULTIPLES_HPP

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

#define  INCREMENTO 5
using namespace std;

void cargarPedidos(int **&fechaClienteCantidad, char **& codigoDelProducto, const char *name);
char *leerString(ifstream &file);
void incrementarMemoria(int &size, int &capacity, int **&fechaClienteCantidad,
        char **&codigoDelProducto);
void insertarFechaClienteCantidad(int *&fechaClienteCantidad, int fecha, int dni, int cntSolicitada);

void qsort(int **&fechaClienteCantidad, char **&codigoDelProducto, int izq, int der);
void cambiar(int *&fechaIzq, int *&fechaDer, char *&codigoIzq, char *&codigoDer);
bool comparar(int *&fechaI, int *&fechaIzq);

void pruebaDeCargaDePedidos(int **fechaClienteCantidad, char **codigoDelProducto,
        const char *name);




#endif /* PREGUNTA01EXAMEN01PUNTEROSMULTIPLES_HPP */

