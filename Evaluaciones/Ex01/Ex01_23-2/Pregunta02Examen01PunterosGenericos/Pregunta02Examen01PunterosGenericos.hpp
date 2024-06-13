/**
 * Alumno: Jesus Huayhua
 * Codigo: 20196201
 */
#ifndef PREGUNTA02EXAMEN01PUNTEROSGENERICOS_PREGUNTA02EXAMEN01PUNTEROSGENERICOS_HPP
#define PREGUNTA02EXAMEN01PUNTEROSGENERICOS_PREGUNTA02EXAMEN01PUNTEROSGENERICOS_HPP
//librerias
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#define  INCREMENTO 5

enum {
    CODIGO, DESCRIPCION,PRECIO,STOCK
};

using namespace std;

void cargarProductos (void *&productos,const char *name);
void *leerRegistro(ifstream &file);
char *leerString(ifstream &file);
void incrementarMemoriaProductos(void **&productos,int &size,int & capacity);

void pruebaDeCargaDeProductos (void *p);


















#endif //PREGUNTA02EXAMEN01PUNTEROSGENERICOS_PREGUNTA02EXAMEN01PUNTEROSGENERICOS_HPP
