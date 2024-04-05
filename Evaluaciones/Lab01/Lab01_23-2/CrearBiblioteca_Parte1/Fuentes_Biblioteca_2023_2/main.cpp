/* 
 * File:   main.cpp
 * Author: JesusHuayhua
 * Codigo: 20196201
 *
 * Created on 3 de abril de 2024, 09:33 AM
 */

#include "Utils.hpp"
#include "operadores_sobrecargados.hpp"
using namespace std;

int main(int argc, char** argv) {
    ifstream archCliente;
    ifstream archPedido;
    ifstream archProducto;
    ofstream archReporte;
    AperturaDeUnArchivoDeTextosParaLeer(archCliente,"Clientes.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archProducto,"Productos.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archPedido,"Pedidos.csv");
    AperturaDeUnArchivoDeTextosParaEscribir(archReporte,"Reporte.txt");
    
    Cliente clientes[100],cliente1;
    Producto productos[100];
    Pedido ped1,ped2;
    
    archCliente>>clientes[0];
    archProducto>>productos[0];
    archProducto>>productos[1];
    archPedido>>ped1;
    archPedido>>ped2;
    
    clientes[1].dni = 0;
    strcpy(productos[2].codigo,"XXXXXXX");
    
    ped1.dniCliente = 79464412;
    ped2.dniCliente = 79464412;
    
    strcpy(ped1.CodigoProducto,"BIT-434");
    strcpy(ped2.CodigoProducto,"BIT-434");
    
    productos += ped1;
    productos += ped2;
    
    clientes += ped1;
    clientes += ped2;
    
    
    archReporte<<clientes[0];
    archReporte<<"=============================================="<<endl;
    archReporte<<productos[0];



    // cerramos los archivos
    archCliente.close();
    archPedido.close();
    archProducto.close();
    archReporte.close();
    return 0;
}

