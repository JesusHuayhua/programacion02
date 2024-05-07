#include "Pregunta01Examen01PunterosMultiples.hpp"


//JXD-139,50375303,6,24/08/2023
//CRU-009,50375303,5,3/09/2023

void cargarPedidos(int **&fechaClienteCantidad, char **& codigoDelProducto, const char *name) {
    ifstream file(name, ios::in);
    if (not file.is_open()) {
        cout << "ERORR: No se pudo abrir el archivo " << name << endl;
        exit(1);
    }
    int size = 0, capacity = 0;
    char *codigo, c;
    int dni, fecha, cntSolicitada, dia, mes, anho;
    while (true) {
        codigo = leerString(file);
        if (file.eof()) break;
        file >> dni >> c >> cntSolicitada >> c >> dia >> c >> mes >> c >> anho;
        file.get(); // salto de linea
        fecha = anho * 10000 + mes * 100 + dia;
        if (size == capacity) incrementarMemoria(size, capacity, fechaClienteCantidad, codigoDelProducto);
        codigoDelProducto[size - 1] = codigo;
        insertarFechaClienteCantidad(fechaClienteCantidad[size - 1], fecha, dni, cntSolicitada);
        size++;
    }
    qsort(fechaClienteCantidad, codigoDelProducto, 0, size - 2); // funcion de ordenamiento que flojera
    file.close();
}

char *leerString(ifstream &file) {
    char buffer[100];
    file.getline(buffer, 100, ',');
    if (file.eof()) return nullptr;
    char *str = new char[strlen(buffer) + 1];
    strcpy(str, buffer);
    return str;
}

void incrementarMemoria(int &size, int &capacity, int **&fechaClienteCantidad,
        char **&codigoDelProducto) {
    capacity += 5;
    if (size == 0) {
        fechaClienteCantidad = new int * [capacity] {
        };
        codigoDelProducto = new char *[capacity] {
        };
        size = 1;
    } else {
        int ** newFecha = new int *[capacity] {
        };
        char **newCodigo = new char *[capacity] {
        };
        for (int i = 0; i < size; i++) {
            newFecha[i] = fechaClienteCantidad[i];
            newCodigo[i] = codigoDelProducto[i];
        }
        delete []fechaClienteCantidad;
        delete []codigoDelProducto;
        fechaClienteCantidad = newFecha;
        codigoDelProducto = newCodigo;
    }
}

void insertarFechaClienteCantidad(int *&fechaClienteCantidad, int fecha, int dni, int cntSolicitada) {
    fechaClienteCantidad = new int[3];
    fechaClienteCantidad[0] = fecha;
    fechaClienteCantidad[1] = dni;
    fechaClienteCantidad[2] = cntSolicitada;
}

void qsort(int **&fechaClienteCantidad, char **&codigoDelProducto, int izq, int der) {
    int limite, pos;
    if (izq >= der) return;
    pos = (izq + der) / 2;
    cambiar(fechaClienteCantidad[izq], fechaClienteCantidad[pos],
            codigoDelProducto[izq], codigoDelProducto[der]);
    limite = izq;
    for (int i = izq + 1; i <= der; i++) {
        if (comparar(fechaClienteCantidad[i], fechaClienteCantidad[izq])) {
            limite++;
            cambiar(fechaClienteCantidad[limite], fechaClienteCantidad[i],
                    codigoDelProducto[limite], codigoDelProducto[i]);
        }
    }
    cambiar(fechaClienteCantidad[limite], fechaClienteCantidad[izq],
            codigoDelProducto[limite], codigoDelProducto[izq]);
    qsort(fechaClienteCantidad, codigoDelProducto, izq, limite - 1);
    qsort(fechaClienteCantidad, codigoDelProducto, limite + 1, der);
}

void cambiar(int *&fechaIzq, int *&fechaDer, char *&codigoIzq, char *&codigoDer) {
    int *fechaAux;
    char *codigoAux;
    fechaAux = fechaIzq;
    fechaIzq = fechaDer;
    fechaDer = fechaAux;
    codigoAux = codigoIzq;
    codigoIzq = codigoDer;
    codigoDer = codigoAux;
}

bool comparar(int *&fechaI, int *&fechaIzq) {
    return fechaI[0] < fechaIzq[0];
}

void pruebaDeCargaDePedidos(int **fechaClienteCantidad, char **codigoDelProducto,
        const char *name) {
    ofstream file(name, ios::out);
    if (not file.is_open()) {
        cout << "ERROR: No se puede abrir el archivo " << name << endl;
        exit(1);
    }
    int i = 0;
    file << left;
    file << setw(20) << "CODIGO" << setw(15) << "FECHA" << setw(10) << "DNI"
            << "CANTIDAD SOLICITADA" << endl;
    while (fechaClienteCantidad[i] != nullptr) {
        int *auxFecha = fechaClienteCantidad[i];
        file << setw(18) << codigoDelProducto[i]
                << setw(15) << auxFecha[0] << setw(10) << auxFecha[1]
                << right << setw(7) << auxFecha[2] << endl;
        file << left;
        i++;
    }


    file.close();
}
