#include "AsignacionDinamicaMemoriaExacta.h"
/*
 * Consideraciones del codigo:
 * Se vera que al momento de hacer 'new', ocurre una separacion entre las '{}', de la siguietne manera:
 * int arr = new int[cnt]{
 * };
 * Esto ocurre porque se realiza el comando: ALT + SHIFT + F, el cual formatea nuestro código, para que sea más ligeble
 * en ciertos aspectos, aunque aquí falla.
 *
 * Otra forma cosa a tener en considración, es que no es necesario inicializar todas las variables con new,
 * se puede hacer de forma estática, ya que se esta guardando de forma temporal. Esto principalmente para cuando se trabaja
 * con punteros simples (type *).
 * */
using namespace std;

void abrirArchivoLectura(ifstream &file, const char *name) {
    file.open(name, ios::in);
    if (!file) {
        cerr << "No se puedo abrir el archivo para su lectura: " << name;
        exit(1);
    }
}

void abrirArchivoEscritura(ofstream &file, const char *name) {
    file.open(name, ios::out);
    if (!file) {
        cerr << "No se puedo abrir el archivo para su escritura: " << name;
        exit(1);
    }
}

//BIT-434,Campana Extractora modelo Glass,375.09,10
//SSE-115,Refrigeradora  CoolStyle 311N Steel,3243.58,23

void lecturaDeProductos(const char *name, char ***&productos, int *& stock, double *&precios) {
    ifstream file;
    abrirArchivoLectura(file, name);
    //codigo
    inicializarProductos(MAX_PRODUCTOS, productos, stock, precios);
    int i = 0;
    while (true) {
        char **tupla = productos[i];
        leerString(file, tupla[0]);
        if (file.eof()) break;
        leerString(file, tupla[1]);
        file >> precios[i];
        file.get();
        file >> stock[i];
        file.get();
        i++;
    }
    recortarValoresProductos(i, productos, stock, precios);
    file.close(); //cerramos el archivo
}

// funcion para inicializar los valores, esto de aquí tbm nos va a servir para cuando se realice
// el recorte y sea exacto

void inicializarProductos(int cnt, char ***&productos, int *& stock, double *&precios) {
    stock = new int [cnt] {
    };
    precios = new double [cnt] {
    };
    // Productos al ser un puntero triple, tbm vamos a inicializar sus valores dobles, con 2, porque estos van a manejar tuplas
    productos = new char **[cnt] {
    };
    for (int i = 0; i < cnt; i++) {
        productos[i] = new char *[2] {
        };
    }
}

// funcion para leer un string de un file

void leerString(ifstream &file, char *&str) {
    char aux_str[100];
    file.getline(aux_str, 100, ',');
    str = new char[strlen(aux_str) + 1] {
    };
    strcpy(str, aux_str); // copiamos el nuevo valor a str
}

/**
 * funcion que sirve para recortar los valores, y solo asignar de forma exacta
 * @param cnt
 * @param productos
 * @param stock
 * @param precios
 */
void recortarValoresProductos(int cnt, char ***&productos, int *& stock, double *&precios) {
    char ***nuevoProducto;
    int *nuevoStock;
    double *nuevoPrecio;
    inicializarProductos(cnt, nuevoProducto, nuevoStock, nuevoPrecio); //inicializamos ahora si con el nuevo valor por defecto
    for (int i = 0; i < cnt; i++) {
        nuevoProducto[i] = productos[i]; //ya se realizo el recorte de cada string interno
        nuevoStock[i] = stock[i];
        nuevoPrecio[i] = precios[i];
    }
    borrarValoresProductos(productos, stock, precios);
    productos = nuevoProducto;
    stock = nuevoStock;
    precios = nuevoPrecio;
}

/**
 * funcion para borrar los archivos que ya se dejaron de utilizar porque no son exactos
 * @param productos
 * @param stock
 * @param precios
 */
void borrarValoresProductos(char ***&productos, int *& stock, double *&precios) {
    delete []productos;
    delete []stock;
    delete []precios;
}

void pruebaDeLecturaDeProductos(const char *name, char ***productos, int *stock, double *precios) {
    ofstream file;
    abrirArchivoEscritura(file, name);
    file << left;
    file << setw(20) << "Codigo"
            << setw(40) << "Nombre"
            << setw(10) << "Precio"
            << setw(10) << "Stock" << endl;
    for (int i = 0; stock[i] != 0; i++) {
        char **producto_interno = productos[i]; //puntero auxiliar para que no se tenga que trabajar con matriz
        file << setw(20) << producto_interno[0]
                << setw(40) << producto_interno[1]
                << setw(10) << precios[i]
                << setw(10) << stock[i] << endl;
    }
    file.close();
}


//codigo, dni,cantidadSolicitada, fecha
//JXD-139,50375303,6,24/08/2023
//CRU-009,50375303,5,3/09/2023
void lecturaDePedidos(const char *name, int*& fechaPedidos, char ***&codigoPedidos, int ***& dniCantPedidos) {
    ifstream file;
    abrirArchivoLectura(file, name);
    inicializarPedidos(MAX_FECHA, MAX_PEDIDOS,fechaPedidos, codigoPedidos, dniCantPedidos);
    char codigo[8],c;
    int dni, fechacntPedido = 0,dd,mm,aaaa;
    while (true) {
        file.getline(codigo,8,',');
        if(file.eof()) break;
        file >> dni >> c >> cntPedido >> c >> dd >> c >> mm >> c >> aaaa  >> c;
        fecha = aaaa * 1000 + mm * 100 + dd;//obtenemos la fecha
        if (existeFecha(fechaPedidos,fecha)){ // si la fecha existe, agregamos solo el nuevo pedido
            int indice = indiceFecha(fechaPedidos,fecha); // obtenemos el indice de la fecha
            agregarPedido(codigoPedidos[indice],codigo);//agregamos el pedido;
            agregarDniCantPedido(dniCantPedidos[indice],dni,cntPedido); // agregamos el dni y la cantidad
        } else{ // si la fecha no existe, agregamos la fecha y el pedido
            int indice = 0;
            while(fechaPedidos[indice] != 0) indice++;
            fechaPedidos[indice] = fecha; // agregamos la fecha
            agregarPedido(codigoPedidos[indice],codigo);//agregamos el pedido;
            agregarDniCantPedido(dniCantPedidos[indice],dni,cntPedido); // agregamos el dni y la cantidad
        }
    }
}

void inicializarPedidos(int cnt, int cnt2, int*& fechaPedidos, char ***&codigoPedidos, int ***& dniCantPedidos) {
    fechaPedidos = new int [cnt] {
    };
    codigoPedidos = new char **[cnt] {
    };
    dniCantPedidos = new int **[cnt] {
    };
    // inicializamos tbm los valores internos de codigo y dni
    for (int i = 0; i < cnt; i++) {
        codigoPedidos[i] = new char *[cnt2] {
        };
        dniCantPedidos[i] = new int *[cnt2] {
        };
    }
}

bool existeFecha(int *&fechaPedidos,const int fecha){
    for (int i = 0; fechaPedidos[i] != 0; ++i) {
        if(fechaPedidos[i] == fecha) return true;
    }
    return false; // no se encontro la fecha
}

int indiceFecha(int *&fechaPedidos,const int fecha){
    int i = 0;
    while(fechaPedidos[i] != fecha) i++;
    return i;
}

void agregarPedido(char **&codigoPedidos,const char *codigo){

}
void agregarDniCantPedido(int **&dniCantPedidos,const int dni,const int cntPedido){

}




















