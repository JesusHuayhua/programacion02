#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Estructuras.h"
#include "operadoresSobrecargados.hpp"

    /*INF263   Algoritmia   3.75   35030611   INGA_FLORES_CESAR_ADOLFO*/
bool operator>>(std::ifstream archCursos,struct StCurso curso){
    char codigoCurso[7], nombreCurso[60],nombreProfesor[60];
    double creditos;
    int codigoProfesor;
    archCursos >> codigoCurso;
    // No se pudo leer el archivo
    if (archCursos.eof()) {
        return false;
    }
    archCursos >> nombreCurso >> creditos >> codigoProfesor >> nombreProfesor;
    strcpy(curso.codigoDelCurso, codigoCurso);
    strcpy(curso.nombreDelCurso,nombreCurso);
    curso.codigoDelProfesor= codigoProfesor;
    strcpy(curso.nombreDelProfesor, nombreProfesor);
    curso.creditos = creditos;
    return true;
}
