#include "operadores_sobrecargados.hpp"

using namespace std;

//FUNCIONES DE LECTURA

bool operator>>(ifstream &arch, struct Cliente &cliente) {
    arch >> cliente.dni;
    if (arch.eof()) return false;
    arch.get();
    arch.getline(cliente.nombre, 60, ',');
    arch >> cliente.telefono;
    cliente.montoTotal = 0.0;
    cliente.cantidadProductosEntrgados = 0;
    // Productos entregados
    cliente.productosEntregados[0].precio = 0.0;
    strcpy(cliente.productosEntregados[0].codigo, "XXXXXXX");
    return true;
}

bool operator>>(istream &arch, struct Producto &producto) {
    arch.getline(producto.codigo, 8, ',');
    if (arch.eof()) return false;
    char c;
    arch.getline(producto.descripcion, 60, ',');
    arch >> producto.precio >> c >> producto.stock;
    producto.cantidadClientesNoServidos = 0;
    producto.cantidadClientesServidos = 0;
    return true;
}

bool operator>>(ifstream &arch, struct Pedido &pedido) {
    arch.get(pedido.CodigoProducto, 8, ',');
    if (arch.eof()) return false;
    arch >> pedido.dniCliente;
    arch.get();
    return true;
}


//FUNCIONES DE AGREGACION

void operator+=(struct Cliente *arregloCliente, const struct Pedido pedido) {
    for (int i = 0; arregloCliente[i].dni != 0; i++) {
        if (arregloCliente[i].dni == pedido.dniCliente) {
            int cnt = arregloCliente[i].cantidadProductosEntrgados;
            strcpy(arregloCliente[i].productosEntregados[cnt].codigo, pedido.CodigoProducto);
            arregloCliente[i].cantidadProductosEntrgados++;
            arregloCliente[i].montoTotal += pedido.precioProducto;
            arregloCliente[i + 1].dni = 0;
            break;
        }
    }
}

bool operator+=(struct Producto *arregloProducto, struct Pedido &pedido) {
    for (int i = 0; strcmp(arregloProducto[i].codigo, "XXXXXXX"); i++) {
        if (strcmp(arregloProducto[i].codigo, pedido.CodigoProducto) == 0) {
            pedido.precioProducto = arregloProducto[i].precio;
            if (arregloProducto[i].stock > 0) {
                int cnt = arregloProducto[i].cantidadClientesServidos;
                arregloProducto[i].clientesServidos[cnt] = pedido.dniCliente;
                arregloProducto[i].cantidadClientesServidos++;
                arregloProducto[i].stock--;
                strcpy(arregloProducto[i + 1].codigo, "XXXXXXX");
                return true;
            } else {
                int cnt = arregloProducto[i].cantidadClientesNoServidos;
                arregloProducto[i].clientesNoServidos[cnt] = pedido.dniCliente;
                arregloProducto[i].cantidadClientesNoServidos++;
                return false;
            }
        }
    }
}

// IMPRESION

ofstream & operator<<(ofstream &arch, const struct Cliente cliente) {
    arch << fixed << setprecision(2) << left; // condiciones generales para este apartado
    arch << setw(10) << cliente.dni
            << setw(60) << cliente.nombre
            << setw(10) << cliente.telefono << cliente.montoTotal
            << "  Productos entregados: ";
    if (cliente.cantidadProductosEntrgados == 0)
        arch << " NO SE LE ENTREGARON PRODUCTOS" << endl;
    else
        for (int i = 0; i < cliente.cantidadProductosEntrgados; i++) {
            arch << cliente.productosEntregados[i].codigo << "  ";
        }
    arch << endl;
    return arch;
}

ofstream& operator<<(ofstream &arch, const struct Producto producto) {
    arch << fixed << setprecision(2) << left; // condiciones generales para este apartado
    arch << setw(10) << producto.codigo
            << setw(60) << producto.descripcion
            << setw(5) << producto.precio
            << setw(5) << producto.stock;
    arch << "\nClientes atendidos: ";
    if (producto.cantidadClientesServidos == 0) {
        arch << "NO SE ATENDIERON PEDIDOS" << endl;
    } else
        for (int i = 0; i < producto.cantidadClientesServidos; i++) {
            arch << producto.clientesServidos[i] << "   ";
        }
    arch << "\nClientes no atendidos: ";
    if (producto.cantidadClientesNoServidos == 0) {
        arch << "NO HAY CLIENTES SIN ATENDER" << endl;
    } else
        for (int i = 0; i < producto.cantidadClientesNoServidos; i++) {
            arch << producto.clientesNoServidos[i] << "   ";
        }
    return arch;
}






























