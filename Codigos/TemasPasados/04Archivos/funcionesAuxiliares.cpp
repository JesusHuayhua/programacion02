#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "funcionesAuxiliares.hpp"

/**
 * Convierte la fecha a una unidad standar, para facilitar las compraciones
 * @param dia
 * @param mes
 * @param anho
 * @return -> int
 */
int fecha(int dia, int mes, int anho) {
    return anho * 10000 + mes * 100 + dia;
}

/**
 * Separamos la especialidad del doctor de su nombre
 * @param nombreDoctor
 * @param especialidadDoctor
 */
void especialidadDelDoctor(char *nombreDoctor, char *especialidadDoctor,char *especialidadMayusculaDoc) {
    int i = 0, j = 0, aux;
    while (nombreDoctor[i++] != '\0');
    while (nombreDoctor[i--] != '_');
    aux = i;
    i += 2;
    while (nombreDoctor[i] != '\0') {
        especialidadDoctor[j] = nombreDoctor[i];
        if(nombreDoctor[i] >= 'a' and nombreDoctor[i] <= 'z'){
            especialidadMayusculaDoc[j] = nombreDoctor[i] - 'a' + 'A';
        }else{
            especialidadMayusculaDoc[j] = nombreDoctor[i];
        }
        i++;
        j++;
    }
    nombreDoctor[aux] = '\0';
    especialidadDoctor[j] = '\0';
    especialidadMayusculaDoc[j] = '\0';
}

/**
 * Impresion de la cebecera del reporte
 * @param especialidad1
 * @param especialidad2
 * @param dia
 * @param mes
 * @param anho
 */
void imprirCabeceraReporte(std::ofstream &Reporte,char *especialidad1, char *especialidad2, int dia, int mes, int anho) {
    Reporte << std::right << std::setw(75) << "EMPRESA PRESTADORA DE SALUD\n";
    Reporte << std::left;
    imprimeLinea(Reporte,'=');
    Reporte << "ESPECIALIDADES A VERIFICAR: " << especialidad1 << " y " << especialidad2 << '\n'
            << "FECHA DEL PROCESO: " << dia << '/' << mes << '/' << anho << std::endl;
}

void imprimeDoctor(std::ofstream &Reporte,char *codigoDoctor, char *nombreDoctor, char *especialidadDoctor) {
    Reporte << "Medico: " << nombreDoctor << " [" << codigoDoctor << "] ";
    Reporte << std::setw(30) << std::setfill(' ') << std::right << ' ' << " Especialidad: " << especialidadDoctor << "\n";
    imprimeLinea(Reporte,'-');
    Reporte << std::setw(29) << std::setfill(' ') << std::right << "Pacientes Atendidos";
    Reporte << std::setw(49) << std::setfill(' ') << std::right << "Medicinas Recibidas\n";
    imprimeLinea(Reporte,'-');
    Reporte << std::setw(6) << std::right << "DNI"
            << std::setw(14) << std::right << "Nombre"
            << std::setw(38) << std::right << "Cantidad"
            << std::setw(13) << std::right << "Codigo"
            << std::setw(19) << std::right << "Descripcion"
            << std::setw(46) << std::right << "F. de V"
            << std::setw(15) << std::right << "Obervacion\n";
}

void imprimirPaciente(std::ofstream &Reporte,int cntPaciente, int dniPaciente, char *nombrePaciente) {
    Reporte << std::setw(2) << std::setfill('0') << std::right << cntPaciente << ")";
    Reporte << std::setfill(' ');
    Reporte << ' ' << dniPaciente << ' ';
    Reporte << std::setw(40) << std::left << nombrePaciente;
}

void imprimeMedicamento(std::ofstream &Reporte,int i, int cnt, int codigo, char *nombre, int dia, int mes, int anho) {
    if (i == 0) {
        Reporte << cnt;
        Reporte << std::setw(16) << std::right << codigo;
        Reporte << std::setw(9) << ' ';
        Reporte << std::setw(39) << std::left << nombre;
        Reporte << std::setw(10) << ' ';
        Reporte << std::setw(2) << std::setfill('0') << std::right << dia << '/'
                << std::setw(2) << std::setfill('0') << std::right << mes << '/';
        Reporte << std::setfill(' ') << anho;
    } else {
        Reporte << std::setw(54) << std::setfill(' ') << ' ';
        Reporte << std::setw(16) << std::right << codigo;
        Reporte << std::setw(9) << ' ';
        Reporte << std::setw(39) << std::left << nombre;
        Reporte << std::setw(10) << ' ';
        Reporte << std::setw(2) << std::setfill('0') << std::right << dia << '/'
                << std::setw(2) << std::setfill('0') << std::right << mes << '/';
        Reporte << std::setfill(' ') << anho;
    }
}

/**
 * Linea divisora para mayor orden en el inform
 * @param c: caracter que se va a imprimir como linea divisoria
 */
void imprimeLinea(std::ofstream &Reporte,char c) {
    Reporte << std::setfill(c) << std::setw(150) << c << std::endl;
    Reporte << std::setfill(' ');
}

bool compararEspecialidades(char *especialidad,char *especialidadDoc){
    return strcmp(especialidad,especialidadDoc) == 0;
}

void ResumenEspecilidades(std::ofstream &Reporte,char *especialidad,int cntEspecilidad,int cntPacientes,int cntMedicamentoVencido){
    Reporte << "Especialidad " << std::setw(15) << std::setfill(' ') << std::left << especialidad << ':';
    Reporte << std::setw(2) << std::setfill('0') << std::right << cntEspecilidad << " medicos,";
    Reporte << cntPacientes << " pacientes,";
    Reporte << cntMedicamentoVencido << " medicinas vencidas.\n";
}


