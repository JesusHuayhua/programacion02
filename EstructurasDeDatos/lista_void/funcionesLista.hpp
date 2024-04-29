/* 
 * File:   funcionesLista.hpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 */

#ifndef FUNCIONESLISTA_HPP
#define FUNCIONESLISTA_HPP

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

#include "lista.hpp"

// Esto de acuerdo a los datos que vamos a leer

enum {
    ID, NOMBRE, PRECIO, STOCK
};

using namespace std;

void construir_lista(Lista &lista);
int es_lista_vacia(Lista lista);
int longitud(Lista lista);
Nodo *crear_nuevo_nodo(ElementoLista elemento, Nodo *siguiente);
Nodo *obtener_ultimo_nodo(Lista lista);
Nodo *obtener_nodo_anterior(Lista lista, ElementoLista elemento);
bool comparar_elemento(ElementoLista e, ElementoLista d);
// funciones de impresion
void imprime(Lista lista);
void imprimir_elemento(void *elemento);
// funciones de eliminacion
void eliminar_lista(Lista &lista);
void eliminar_elemento_lista(ElementoLista &e);
// Funciones de insercion
void insertar_al_inicio(Lista &lista, ElementoLista elemento);
void insertar_al_final(Lista &lista, ElementoLista elemento);
void insertar_en_orden(Lista &lista, ElementoLista elemento);


Nodo *se_encuentra(Lista lista, ElementoLista dato);

void elimina_cabeza(Lista &lista);
void elimina_cola(Lista &lista);
void elimina_nodo(Lista &lista, ElementoLista e);










#endif /* FUNCIONESLISTA_HPP */

