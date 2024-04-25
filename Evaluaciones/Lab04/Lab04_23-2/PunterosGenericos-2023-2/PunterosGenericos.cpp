/*
 * Consideraciones, la funcion imprimeproductos, proporcionado
 * por los profesores, es incorrecta debido a que imprime de forma erronea el
 * valor de los codigos de los productos.
 */
#include <set>

#include "PunterosGenericos.hpp"
#include "MuestraPunteros.h"
//BIT-434,Campana Extractora modelo Glass,375.09,S
//SSE-115,Refrigeradora  CoolStyle 311N Steel,3243.58,S
//NMV-644,Lavadora Automatica,3272.48,S

void cargaproductos(void *&productos) {
    ifstream file("Productos2.csv", ios::in);
    if (not file.is_open()) {
        cerr << "No se pudo abrir el archivo de Productos2.csv";
        exit(1);
    }
    void *registro[200]{}, **buffer;
    int cnt = 0;
    while (true) {
        registro[cnt] = leerProducto(file);
        if (registro[cnt] == nullptr) break;
        cnt++;
    }
    buffer = new void*[cnt + 1];
    for (int i = 0; i <= cnt; i++) {
        buffer[i] = registro[i];
    }
    productos = buffer;
    imprimeproductos(productos);
    file.close();
}

void *leerProducto(ifstream &file) {
    char *codigo, *nombre, *tlinea, c;
    double *precio;
    codigo = leerString(file);
    if (file.eof()) return nullptr;
    nombre = leerString(file);
    precio = new double;
    tlinea = new char;
    file >> *precio >> c >> *tlinea;
    file.get();
    void **producto = new void *[4];
    producto[CODIGO] = codigo;
    producto[DESCRIP] = nombre;
    producto[PRECIO] = precio;
    producto[TLINEA] = tlinea;
    return producto;
}

char *leerString(ifstream &file) {
    char buffer[100];
    file.getline(buffer, 100, ',');
    if (file.eof())return nullptr;
    char *str = new char[strlen(buffer) + 1] {
    };
    strcpy(str, buffer);
    return str;
}

void cargaclientes(void *&clientes) {
    ifstream file("Clientes2.csv", ios::in);
    if (not file.is_open()) {
        cerr << "No se pudo abrir el archivo de Clientes2.csv";
        exit(1);
    }
    void *registro[200]{}, **buffer;
    int cnt = 0;
    while (true) {
        registro[cnt] = leerCliente(file);
        if (registro[cnt] == nullptr) break;
        cnt++;
    }
    buffer = new void*[cnt + 1] {
    };
    for (int i = 0; i <= cnt; i++) {
        buffer[i] = registro[i];
    }
    clientes = buffer;
    imprimeclientes(clientes);
    file.close();
}

// Consideraciones con esta lectura, el numero de telefono no se va a utilizar
// para este laboratorio
//79464412,PORTUGAL RAFFO ALEXANDER,3902394,10000
//16552775,YALLICO PAREDES LOURDES CARMELA,960176666,20000
//20864087,ZEGARRA CASANOVA ESTEFANIA,2639311,10000

void * leerCliente(ifstream &file) {
    char *nombre, c;
    int *dni, telefono;
    double *credito; //esta es la linea de credito del cliente
    dni = new int;
    file >> *dni;
    if (file.eof())return nullptr;
    // Recien le asignamos memoria a los punteros, por que si en caso falla
    // no deberian de tener 
    file.get();
    credito = new double;
    nombre = leerString(file);
    file >> telefono >> c >> *credito;
    file.get();
    void **cliente = new void*[4];
    cliente[DNI] = dni;
    cliente[NOMBRE] = nombre;
    cliente[PEDIDOS] = nullptr;
    cliente[CREDITO] = credito;
    return cliente;
}


//JXD-139,50375303,6
//CRU-009,50375303,5

void cargapedidos(void *productos, void *&clientes) {
    ifstream file("Pedidos2.csv", ios::in);
    if (not file.is_open()) {
        cerr << "NO se pudo abrir el archivo Pedidos2.csv" << endl;
        exit(1);
    }
    char *codigo, c;
    int dni, cntPedido;
    while (true) {
        codigo = leerString(file);
        if (file.eof())break;
        file >> dni >> c >> cntPedido;
        file.get();
        agregarPedidoCliente(productos, clientes, codigo, dni, cntPedido);
    }
    recortarMemoriaCliente(clientes);
    imprimerepfinal(clientes);
    file.close();
}

void agregarPedidoCliente(void *productos, void *clientes, char *codigo, int dni,
        int cntPedido) {
    double precio;
    bool tieneLineaCredito = verificarLineaCredito(productos, codigo, precio);
    if (tieneLineaCredito) {
        if (verificarLineaDeCreditoCliente(clientes, precio, cntPedido, dni)) {
            agregarPedidoCliente(clientes, precio, cntPedido, codigo, dni);
        }
    } else {
        agregarPedidoCliente(clientes, precio, cntPedido, codigo, dni);
    }
}

bool verificarLineaCredito(void *p, char *codigo, double &precio) {
    void **lpedidos = (void **) p;
    for (int i = 0; lpedidos[i] != nullptr; i++) {
        void **producto = (void **) lpedidos[i];
        char *codigoProducto = (char *) producto[CODIGO];
        if (strcmp(codigoProducto, codigo) == 0) {//encontramos el producto
            char *tipo = (char *) producto[TLINEA];
            double *price = (double *) producto[PRECIO];
            precio = *price;
            return *tipo == 'S';
        }
    }
}

bool verificarLineaDeCreditoCliente(void *c, double precio,
        int cntPedido, int dni) {
    void **lclientes = (void **) c; //lista de clientes
    for (int i = 0; lclientes[i] != nullptr; i++) {
        void **cliente = (void **) lclientes[i];
        int *dniCliente = (int *) cliente[DNI];
        if (dni == *dniCliente) {
            double *credito = (double *) (cliente[CREDITO]);
            if (*credito >= precio * cntPedido) {
                *credito -= precio * cntPedido;
                return true;
            } else
                return false;
        }
    }
}

void agregarPedidoCliente(void *c, double precio, int cnt,
        char* codigo, int dni) {
    void **lclientes = (void **) c; //lista de clientes
    for (int i = 0; lclientes[i] != nullptr; i++) {
        void **cliente = (void **) lclientes[i];
        int *dniCliente = (int *) cliente[DNI];
        if (dni == *dniCliente) {
            if (cliente[PEDIDOS] == nullptr) {
                void **aux = new void *[200] {
                }; //creamos memoria para almacenar los pedidos;
                cliente[PEDIDOS] = aux;
            }
            insertarPedidoCliente(cliente[PEDIDOS], codigo, precio * cnt, cnt);
        }
    }
}

void insertarPedidoCliente(void *&p, char *codigo, double monto, int cnt) {
    void **pedido = (void **) p;
    void **registro;
    //cantidad de pedidos;
    int cntPedidos = 0;
    for (cntPedidos = 0; pedido[cntPedidos] != nullptr; cntPedidos++);
    double *ptr_monto = new double;
    int *ptr_cnt = new int;
    *ptr_cnt = cnt;
    *ptr_monto = monto;
    registro = new void *[3];
    registro[CODIGOPEDIDO] = codigo;
    registro[CNTPEDIDO] = ptr_cnt;
    registro[MONTOPEDIDO] = ptr_monto;
    pedido[cntPedidos] = registro;
}

void recortarMemoriaCliente(void *&c) {
    void **lclientes = (void **) c;
    for (int i = 0; lclientes[i] != nullptr; i++) {
        void **cliente = (void **) lclientes[i];
        void **pedidos = (void **) cliente[PEDIDOS];
        if (pedidos != nullptr) {
            int cnt = 0;
            for (int i = 0; pedidos[i] != nullptr; i++) cnt++;
            void **pedidoExacto = new void *[cnt + 1] {
            };
            for (int i = 0; i <= cnt; i++) {
                pedidoExacto[i] = pedidos[i];
            }
            delete pedidos;
            cliente[PEDIDOS] = pedidoExacto;
        }
    }
}

void imprimereporte(void *c) {
    ofstream file("ReporteDePedidos.txt", ios::out);
    if (not file.is_open()) {
        cerr << "NO se pudo abrir el reporte de pedidos" << endl;
        exit(1);
    }
    void **lclientes = (void **) c;
    file << left << setprecision(2) << fixed;
    for (int i = 0; lclientes[i] != nullptr; i++) {
        imprimiCabecera(file, lclientes[i]);
        imprimirCodigo(file, lclientes[i]);
    }

}

void imprimirLinea(ofstream &file, char c) {
    file << setfill(c);
    file << setw(100) << c << endl;
    file << setfill(' ');
}

void imprimiCabecera(ofstream &file, void * lclientes) {
    //    void **lclientes = (void **) c;
    imprimirLinea(file, '=');
    file << setw(20) << "DNI" << setw(50) << "Nombre" << "Credito" << endl;
    void **cliente = (void **) lclientes;
    int *dni = (int *) cliente[DNI];
    char *nombre = (char *)(cliente[NOMBRE]);
    double *credito = (double *) cliente[CREDITO];
    file << setw(20) << *dni << setw(50) << nombre << *credito << endl;
    imprimirLinea(file, '-');
    file << "Pedidos atentidos:" << endl;
    imprimirLinea(file, '-');
}

void imprimirCodigo(ofstream &file, void *lclientes) {
    void **lpedidos = (void **) lclientes;
    void **p = (void **)lpedidos[PEDIDOS];
    if (p == nullptr) return;
    file << setw(10) << "Codigo" << setw(10) << "Cantidad" << "Total" << endl;

    for (int i = 0; p[i] != nullptr; i++) {
        void **pedido = (void **) p[i];
        char *codigo = (char *) pedido[CODIGOPEDIDO];
        int *cnt = (int *) pedido[CNTPEDIDO];
        double *monto = (double *) pedido[MONTOPEDIDO];
        file << setw(10) << codigo << setw(10) << *cnt << *monto << endl;
    }
}

//====================================================================================================
//DNI                 Nombre                                            Credito   
//79464412            PORTUGAL RAFFO ALEXANDER                          5782.30   
//----------------------------------------------------------------------------------------------------
//Pedidos atendidos:
//----------------------------------------------------------------------------------------------------
//Codigo    Cantidad  Total     
//----------------------------------------------------------------------------------------------------
//NSM-283   2         1873.62   
//JXD-139   4         2344.08   