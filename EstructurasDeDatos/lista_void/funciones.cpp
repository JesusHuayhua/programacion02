#include "funciones.hpp"
#include "funcionesLista.hpp"

void apertura_de_archivo_para_leer(ifstream &archivo, const char *name) {
    archivo.open(name, ios::in);
    if (not archivo.is_open()) {
        cerr << "ERROR: No se puedo abrir el archivo " << name << endl;
        exit(1);
    }
}

void apertura_de_archivo_para_escribir(ofstream &archivo, const char *name) {
    archivo.open(name, ios::out);
    if (not archivo.is_open()) {
        cerr << "ERROR: No se puedo abrir el archivo " << name << endl;
        exit(1);
    }
}

/**
 * El ejemplo de la lectura de los archivos, va a ser por metodo
 * exacto.
 */
void leer_archivo_productos(Lista &lista, ifstream &archivo) {
    ElementoLista elemento;
    while (true) {
        elemento = leer_producto(archivo);
        if (archivo.eof() or elemento == nullptr)break;
        //        insertar_al_inicio(lista, elemento);
        //        insertar_al_final(lista,elemento
        insertar_en_orden(lista, elemento);
    }
}

//77,Soup - Campbells Beef Strogonoff,21.21,67
//19,Cod - Black Whole Fillet,22.8,75
//34,Coffee - Decafenated,9.58,84
//190,Cookie Choc,8.49,60

ElementoLista leer_producto(ifstream &archivo) {
    int *id, *stock;
    char *nombre, c;
    double *precio;
    id = new int;
    archivo >> *id;
    if (archivo.eof()) return nullptr;
    archivo.get(); // leemos la coma
    nombre = leerString(archivo);
    precio = new double;
    stock = new int;
    archivo >> *precio >> c >> *stock;
    archivo.get(); //leemos el salto de linea
    void **buffer = new void*[4];
    buffer[ID] = id;
    buffer[NOMBRE] = nombre;
    buffer[PRECIO] = precio;
    buffer[STOCK] = stock;
    return buffer;
}

char *leerString(ifstream &file) {
    char buffer[100];
    file.getline(buffer, 100, ',');
    if (file.eof())return nullptr;
    char *str = new char[strlen(buffer) + 1];
    strcpy(str, buffer);
    return str;
}