/* 
 * File:   main.cpp
 * Author: Jesus Huayhua
 * Codigo: 20196201
 *
 * Created on October 7, 2023, 3:28 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "operadoresSobrecargados.hpp"

/*
 * Alumnos.txt
 * Matricula.txt
 * Cursos.txt
 */

int main(int argc, char** argv) {
//    std::ifstream archAlumnos;
    std::ifstream archCursos;
//    std::ofstream archReporte;
    AperturaDeUnArchivoDeTextosParaLeer(archCursos,"Cursos.txt");
//    AperturaDeUnArchivoDeTextosParaEscribir(archReporte,"Reporte.txt");
    
    
    return 0;
}

