/* 
 * File:   AsignacionDinamicaMemoriaExacta.h
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 9 de abril de 2024, 04:42 PM
 */

#ifndef ASIGNACIONDINAMICAMEMORIAEXACTA_H
#define ASIGNACIONDINAMICAMEMORIAEXACTA_H
//Librerias
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
//DEFINE
#define MAX_PRODUCTOS 200
#define MAX_PEDIDOS 200
using namespace std;
// funciones de apertura de archivo
void abrirArchivoLectura(ifstream &file, const char *name);
void abrirArchivoEscritura(ofstream &file, const char *name);
void leerString(ifstream &file, char *&str);
// lectura de productos
void lecturaDeProductos(const char *name, char ***&productos, int *& stock, double *&precios);
void inicializarProductos(int cnt, char ***&productos, int *& stock, double *&precios);
void recortarValoresProductos(int cnt, char ***&productos, int *& stock, double *&precios);
void borrarValoresProductos(char ***&productos, int *& stock, double *&precios);
void pruebaDeLecturaDeProductos(const char *name, char ***productos, int *stock, double *precios);

void pruebaDeLecturaDeProductos(const char *name, char ***productos, int *stock, double *precios);

void lecturaDePedidos(const char *name, int*& fechaPedidos, char ***&codigoPedidos, int ***& dniCantPedidos);


#endif /* ASIGNACIONDINAMICAMEMORIAEXACTA_H */

