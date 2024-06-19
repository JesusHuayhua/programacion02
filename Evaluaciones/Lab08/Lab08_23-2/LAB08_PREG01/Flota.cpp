/* 
 * File:   Flota.cpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 13 de junio de 2024, 06:07 PM
 */

#include "Flota.hpp"
#include "Vehiculo.hpp"

using namespace std;

Flota::Flota() {
}

Flota::Flota(const Flota& orig) {
}

Flota::~Flota() {
}

void Flota::cargaflota(void){
    ifstream file("Vehiculos.csv",ios::in);
    if (not file.is_open()) {
        cout << "ERROR: no se puede abrir el archivo Vehiculos.csv" << endl;
        exit(1);
    }
    
    this->lista.leerArchivo(file);
}

void Flota::muestracarga(void){
    ofstream file("Reporte.txt",ios::out);
    if (not file.is_open()) {
        cout << "ERROR: No se puede abir el archivo Reporte.txt" << endl ;
        exit(1);
    }
    this->lista.imprimeLista(file);
}

void Flota::imprime(ofstream &file){
    this->Vehiculo::imprime(file);
}