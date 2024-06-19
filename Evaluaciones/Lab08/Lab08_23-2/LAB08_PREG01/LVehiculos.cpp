/* 
 * File:   LVehiculos.cpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20196201
 * Created on 13 de junio de 2024, 06:06 PM
 */

#include "LVehiculos.hpp"
#include "Furgon.hpp"

using namespace std;

LVehiculos::LVehiculos() {
    lini = nullptr;
    lfin = nullptr;
}

LVehiculos::LVehiculos(const LVehiculos& orig) {
}

LVehiculos::~LVehiculos() {
}


void LVehiculos::leerArchivo(std::ifstream &file){
    char tipo_vehiculo,c;
    NodoLista *nuevo = new NodoLista;
    while(true){
        file >> tipo_vehiculo >> c;
        if(file.eof()) break;
        if (tipo_vehiculo == 'F') { // furgoneta
            nuevo->unidad = new Furgon;
        }else{//camion
            nuevo->unidad = new Camion;
        }
        nuevo.unidad.lee();//va a leer los datos dependiendo del tip de heviculo
        //insertar el nodo
        insertarNodo(nuevo);
    }
}

void LVehiculos::insertarNodo(NodoLista *nuevo){
    if (this->lini == nullptr) {
        lini = nuevo;
        lfin = nuevo;
    }else{
        lfin->sig = nuevo;
        lfin = nuevo;
    }
}

void LVehiculos::imprimeLista(std::ofstream &file){
    NodoLista *rec = this->lini;
    while (rec != nullptr) {
        rec->unidad.imprime(file);
        rec = rec->sig;
    }
}


