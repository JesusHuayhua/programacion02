/* 
 * File:   PunterosGenericos.hpp
 * Author: alulab14
 *
 * Created on 25 de abril de 2024, 10:03 AM
 */

#ifndef PUNTEROSGENERICOS_HPP
#define PUNTEROSGENERICOS_HPP

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;
//enums

enum {
    CODIGO, DESCRIP, PRECIO, TLINEA
};

enum {
    DNI, NOMBRE, PEDIDOS, CREDITO
};

enum {
    CODIGOPEDIDO, CNTPEDIDO, MONTOPEDIDO
};
void cargaproductos(void *&productos);
void *leerProducto(ifstream &file);
char *leerString(ifstream &file);
void cargaclientes(void *&clientes);
void * leerCliente(ifstream &file);

void cargapedidos(void *productos, void *&clientes);
void agregarPedidoCliente(void *productos, void *clientes, char *codigo, int dni, int cntPedido);
bool verificarLineaCredito(void *p, char *codigo, double &precio);
bool verificarLineaDeCreditoCliente(void *c, double precio, int cntPedido, int dni);
void agregarPedidoCliente(void *c, double precio, int cnt, char* codigo, int dni);
void insertarPedidoCliente(void *&p, char *codigo, double monto, int cnt);
void recortarMemoriaCliente(void *&cliente);
void imprimereporte(void *c);
void imprimirLinea(ofstream &file, char c);
void imprimiCabecera(ofstream &file, void * lclientes);
void imprimirCodigo(ofstream &file, void *lclientes);


#endif /* PUNTEROSGENERICOS_HPP */

