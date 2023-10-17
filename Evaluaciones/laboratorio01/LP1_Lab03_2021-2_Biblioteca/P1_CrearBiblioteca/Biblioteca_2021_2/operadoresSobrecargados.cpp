#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "operadoresSobrecargados.hpp"


bool operator>>(std::ifstream archLibro,St_Libro &libro){
    char codigo[20],titulo[50];
    int stock;
    double precio;
    archLibro >> codigo;
    if (archLibro.eof()) {
        return false;
    }
    archLibro >> titulo >> stock >> precio;
    strcpy(libro.codigo, codigo);
    strcpy(libro.titulo,titulo);
    libro.stock = stock;
    libro.precio = precio;
    return true;
}

bool operator>>(std::ifstream archUsuario, St_Usuario &usuario){
    int carne,nombre[60];
    char tipo;
    archUsuario >> carne;
    if (archUsuario.eof()) {
        return false;
    }
    archUsuario >> tipo >> nombre;
    usuario.carne = carne;
    strcpy(usuario.nombre,nombre);
    if (tipo == 'A') {
        strcpy(usuario.tipo,"ADMINISTRATIVO");
    }else if (tipo == 'E') {
        strcpy(usuario.tipo,"ESTUDIANTE");
    } else {
        strcpy(usuario.tipo,"DOCENTE");
    }
    return true;
}

void operator+=(St_Usuario &usuario,const St_LibroPrestado libroPres){
    usuario.libPrest[usuario.numLibPrest] = libroPres;
    usuario.numLibPrest++;
}

void operator+=(St_Libro &libro,const St_UsuarioPrestamo usuario ){
    if (usuario.tipo == 'A') {
        libro.administativos[libro.cantAdm++] = usuario; 
    }else if (usuario.tipo == 'E') {
        libro.administativos[libro.estudiantes++] = usuario; 
    } else {
        libro.administativos[libro.docentes++] = usuario; 
    }
}








