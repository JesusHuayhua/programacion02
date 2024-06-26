/* 
 * File:   Flota.cpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 19 de junio de 2024, 01:47 PM
 */

#include "Flota.hpp"

using namespace std;

Flota::Flota() {
}

Flota::Flota(const Flota& orig) {
}

Flota::~Flota() {
}

void Flota::cargaflota(void) {
    ifstream file("Vehiculos.csv", ios::in);
    if (not file.is_open()) {
        cout << "ERROR: No se puede abrir el archivo Vehiculos.csv" << endl;
        exit(1);
    }
    NVehiculo flota;
    while (true) {
        flota.lee_vehiculo(file);
        if (file.eof()) break;
        this->vflota.push_back(flota);
    }
}

void Flota::muestracarga(void) {
    ofstream file("reporte.txt", ios::out);
    if (not file.is_open()) {
        cout << "ERROR: No se puede abrir el archivo reporte.txt" << endl;
        exit(1);
    }
    file << left << fixed << setprecision(2) << endl;
    file << setw(40) << "REPORTE DE FLOTA" << endl;
    file << setw(50) << setfill('=') << '=' << endl << setfill(' ') << endl;
    for (NVehiculo flota : vflota) {
        flota.imprime_vehiculo(file);
    }
}
