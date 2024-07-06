/**
 * Alumno: Jesus Huayhua
 * Codigo: 20196201
 */
#include "Pregunta02Examen01PunterosGenericos.hpp"
void cargarProductos (void *&p,const char *name){
    ifstream file(name,ios::in);
    if (not file.is_open()){
        cout << "ERORR: No se puede abrir el archivo " << name <<endl;
        exit(1);
    }
    void *registro, **productos,**aux;
    int size = 0, capacity = 0;
    while(true){
        registro = leerRegistro(file);
        if(file.eof()) break;
        if(size == capacity) incrementarMemoriaProductos(productos,size, capacity);
        aux = new void *[2]{};
        aux[0] = registro;
        productos[size - 1] = aux;
        size++;
    }
    p = productos;
    file.close();
}


void *leerRegistro(ifstream &file){
    char *codigo, *descripcion,c;
    double *precio;
    int *stock;
    codigo = leerString(file);
    if(file.eof()) return nullptr;
    descripcion = leerString(file);
    precio = new double;
    stock = new int;
    file >> *precio >> c >> *stock;
    file.get();
    void **buffer = new void *[4];
    buffer[CODIGO] = codigo;
    buffer[DESCRIPCION] = descripcion;
    buffer[PRECIO] = precio;
    buffer[STOCK] = stock;
    return buffer;
}

char *leerString(ifstream &file){
    char buffer[100];
    file.getline(buffer,100,',');
    if(file.eof()) return nullptr;
    char *str = new char[strlen(buffer) + 1];
    strcpy(str,buffer);
    return str;
}


void incrementarMemoriaProductos(void **&productos,int &size,int & capacity){
    capacity += INCREMENTO;
    if (size == 0){
        productos = new void *[capacity]{};
        size = 1;
    }else{
        void **aux = new void *[capacity]{};
        for (int i = 0; i < size; ++i) {
            aux[i] = productos[i];
        }
        delete productos;
        productos = aux;
    }
}


void pruebaDeCargaDeProductos (void *p) {
    void **productos = (void **) p;
    int i = 0;
    cout << left << fixed << setprecision(2);
    while (productos[i] != nullptr) {
        void **registro = (void **) productos[0];
        void **datos = (void **) registro[0];
        char *codigo = (char *) datos[CODIGO];
        char *descripcion = (char *) datos[DESCRIPCION];
        double *precio = (double *) datos[PRECIO];
        int *stock = (int *) datos[STOCK];
        cout << setw(50) << descripcion << setw(20) << codigo << setw(10) << *precio << *stock << endl;
        i++;
    }
}
