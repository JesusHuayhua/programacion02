/* 
 * File:   archivos.cpp
 * Author: Jesus Huayhua Flores
 * Codigo: 20296202
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "funcionesAuxiliares.hpp"

int main(int argc, char** argv) {
    // Especialidades
    char especialidad1[50], especialidad2[50], c;
    int ddV, mmV, aaaaV, fechaVencimiento;
    int cntEspecilidad1 = 0, cntEspecilidad2 = 0;
    int cntEsp1Pacientes = 0, cntEsp2Pacientes = 0;
    int cntMedVecEspecilidad1 = 0, cntMedVecEspecilidad2 = 0;
    // doctor
    char codigoDoctor[10], nombreDoctor[100], especialidadDoctor[50], especialidadMayusculaDoc[50];
    // paciente y medicamentos
    char nombrePaciente[100], nombreMedicamento[50];
    int dniPaciente, cntMedicamentos, codMedicamento, ddM, mmM, aaaaM, fechaMedicamento, cntPacientes = 0;
    int cntMedicamentosVencidos = 0;
    // Apertura de archivos
    std::ifstream Datos("Medico-Paciente-Medicinas.txt", std::ios::in);
    std::ofstream Reporte("Reporte.txt", std::ios::out);
    
    Datos >> especialidad1 >> especialidad2 >> ddV >> c >> mmV >> c >> aaaaV;
    fechaVencimiento = fecha(ddV, mmV, aaaaV);
    imprirCabeceraReporte(Reporte,especialidad1, especialidad2, ddV, mmV, aaaaV);

    while (true) {
        Datos >> dniPaciente;
        if (Datos.eof()) break;
        if (Datos.fail()) {
            imprimeLinea(Reporte,'=');
            Datos.clear();
            Datos >> codigoDoctor >> nombreDoctor;
            especialidadDelDoctor(nombreDoctor, especialidadDoctor, especialidadMayusculaDoc);
            imprimeDoctor(Reporte,codigoDoctor, nombreDoctor, especialidadDoctor);
            if (compararEspecialidades(especialidad1, especialidadMayusculaDoc)) {
                cntEspecilidad1++;
                cntEsp1Pacientes += cntPacientes;
            } else if (compararEspecialidades(especialidad2, especialidadMayusculaDoc)) {
                cntEspecilidad2++;
                cntEsp2Pacientes += cntPacientes;
            }
            cntPacientes = 1;
        } else {
            imprimeLinea(Reporte,'-');
            Datos >> nombrePaciente >> cntMedicamentos;
            imprimirPaciente(Reporte,cntPacientes, dniPaciente, nombrePaciente);
            cntMedicamentosVencidos = 0;
            for (int i = 0; i < cntMedicamentos; i++) {
                Datos >> codMedicamento >> nombreMedicamento >> ddM >> c >> mmM >> c >> aaaaM;
                fechaMedicamento = fecha(ddM, mmM, aaaaM);
                imprimeMedicamento(Reporte,i, cntMedicamentos, codMedicamento, nombreMedicamento, ddM, mmM, aaaaM);
                if (fechaMedicamento >= fechaVencimiento) {
                    Reporte << std::setw(11) << std::right << "VENCIDA\n";
                    cntMedicamentosVencidos++;
                } else {
                    Reporte << "\n";
                }
            }
            if (compararEspecialidades(especialidad1, especialidadMayusculaDoc)) {
                cntMedVecEspecilidad1+= cntMedicamentosVencidos;
            } else if (compararEspecialidades(especialidad2, especialidadMayusculaDoc)) {
                cntMedVecEspecilidad2+= cntMedicamentosVencidos;
            }
            Reporte << std::setw(100) << std::right << "Cantidad de medicamentos vencidos: " << cntMedicamentosVencidos << '\n';
            cntPacientes++;
        }
    }
    
    imprimeLinea(Reporte,'=');
    Reporte << "RESUMEN\n";
    ResumenEspecilidades(Reporte,especialidad1,cntEspecilidad1,cntEsp1Pacientes,cntMedVecEspecilidad1);
    ResumenEspecilidades(Reporte,especialidad2,cntEspecilidad2,cntEsp2Pacientes,cntMedVecEspecilidad2);
    imprimeLinea(Reporte,'=');
    return 0;
}

