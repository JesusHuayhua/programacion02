/**
 * Alumno: Jesus Huayhua
 * Codigo: 20196201
*/

#ifndef ASIGNACIONDINAMICAMEMORIAPORINCREMENTOS_2023_2_ASIGNACIONDINAMICAMEMORIAEXACTA_HPP
#define ASIGNACIONDINAMICAMEMORIAPORINCREMENTOS_2023_2_ASIGNACIONDINAMICAMEMORIAEXACTA_HPP
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

#define INCREMENTO 5
using namespace std;
void abrirArchivoLectura(ifstream &file, const char *name);
void abrirArchivoEscritura(ofstream &file, const char* name);
void lecturaDeProductos(const char *name, char ***&productos, int *& stock, double *& precios);
char **leerProductos(ifstream &file);
char *leerString(ifstream &file);
void incrementarMemoriaProductos(char ***&productos, int *& stock, double *& precios,
        int &size, int &capacity);
void pruebaDeLecturaDeProductos(const char *name, char ***productos, int *stock, double * precios);
void lecturaDePedidos(const char *name, int *&fechaPedidos, char ***& codigoPedidos,
        int ***&dniCantPedidos);
int buscarFecha(int *fechaPedidos, int fecha, int size);
void incrementarMemoriaFechas(int *&fechaPedidos, char ***& codigoPedidos,
        int ***&dniCantPedidos, int &size, int & capacity);
void insertarFechaOrdenada(int *&fechaPedidos, char ***&codigoPedidos, int ***&dniCantPedidos,
        int *numSizePedidos, int *numCapacityPedidos, int fecha, int size, int & posicion);
void incrementarMemoriaPedidosFecha(char **&codigoPedidos, int **&dniCantPedidos,
        int &size, int & capacity);
void agregarPedidosFecha(char **&codigoPedidos, int **& dniCantPedidos,int posicion, char*& codigo,
        int dni, int cntPedido);
void pruebaDeLecturaDePedidos(const char *nombArch,int *fechaPedidos,
        char ***codigoPedidos,int ***dniCantPedidos);
void reporteDeEnvioDePedidos(const char *nombArch,char ***productos,int *stock,
        double *precios,int *fechaPedidos,char ***codigoPedidos,int ***dniCantPedidos);
void imprimirProductos(char ***productos,int *stock,double *precios,
        char **codigoPedidos,int **dniCantPedidos,ofstream &arch,double &ingresosPeriodo,
        double &ingresosPerdidos);
void imprimirVerificarProducto(char ***productos,int *stock,double *precios,
        double &totalGanado,double &totalPerdido,char *cod,int cant,ofstream &arch);
void convertirFecha(int fecha,int &dd,int &mm,int &aa);
void imprimeLinea(ofstream &arch,int numcar,char c);
#endif //ASIGNACIONDINAMICAMEMORIAPORINCREMENTOS_2023_2_ASIGNACIONDINAMICAMEMORIAEXACTA_HPP
