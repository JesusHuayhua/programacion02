/**
 * Consideraciones del codigo:
 * Al momentod de realizar el codigo, se va a percatar
 * de que se realiza lo siguiente:
 * int *arr = new char[ size ]{
 * };
 * Esto de debe a que se utiliza el comando de NetBeans, para 
 * formatear el código, y que este se vea de formás visible
 * lamentablemente para dicho no lo realiza de forma correcta
 */
#include "AsignacionDinamicaMemoriaExacta.hpp"

void abrirArchivoLectura(ifstream &file, const char *name) {
    file.open(name, ios::in);
    if (not file.is_open()) {
        cerr << "ERROR: No se abriro el archivo " << name << endl;
        exit(1);
    }
}

void abrirArchivoEscritura(ofstream &file, const char* name) {
    file.open(name, ios::out);
    if (not file.is_open()) {
        cerr << "ERROR: No se abriro el archivo " << name << endl;
        exit(1);
    }
}

//BIT-434,Campana Extractora modelo Glass,375.09,10
//SSE-115,Refrigeradora  CoolStyle 311N Steel,3243.58,23

void lecturaDeProductos(const char *name, char ***&productos, int *& stock, double *& precios) {
    ifstream file;
    abrirArchivoLectura(file, name);
    char **bufferProductos, c;
    int auxStock, size = 0, capacity = 0;
    double auxPrecio;
    while (true) {
        bufferProductos = leerProductos(file);
        if (file.eof()) break;
        file >> auxPrecio >> c >> auxStock >> c; //leemos la coma y el salto de linea
        if (size == capacity) {
            incrementarMemoriaProductos(productos, stock, precios, size, capacity);
        }
        productos[size - 1] = bufferProductos;
        stock[size - 1] = auxStock;
        precios[size - 1] = auxPrecio;
        size++;
    }
    file.close();
}

char **leerProductos(ifstream &file) {
    char *codigo, *nombre;
    codigo = leerString(file);
    if (file.eof()) return nullptr;
    nombre = leerString(file);
    char ** buffer;
    buffer = new char *[2];
    buffer[0] = codigo;
    buffer[1] = nombre;
    return buffer;
}

char *leerString(ifstream &file) {
    char buffer[100];
    file.getline(buffer, 100, ',');
    if (file.eof()) return nullptr;
    char *str;
    str = new char [strlen(buffer) + 1];
    strcpy(str, buffer);
    return str;
}

void incrementarMemoriaProductos(char ***&productos, int *& stock, double *& precios,
        int &size, int &capacity) {
    capacity += INCREMENTO;
    if (size == 0) {
        productos = new char **[capacity] {
        };
        stock = new int [capacity] {
        };
        precios = new double [capacity] {
        };
        size = 1;
    } else {
        char ***auxProductos;
        auxProductos = new char **[capacity] {
        };
        int *auxStock;
        auxStock = new int [capacity] {
        };
        double *auxPrecios;
        auxPrecios = new double [capacity] {
        };
        for (int i = 0; i < size; i++) {
            auxProductos[i] = productos[i];
            auxStock[i] = stock[i];
            auxPrecios[i] = precios[i];
        }
        delete[] productos;
        delete[] stock;
        delete[] precios;
        productos = auxProductos;
        stock = auxStock;
        precios = auxPrecios;
    }
}

void pruebaDeLecturaDeProductos(const char *name, char ***productos, int *stock, double * precios) {
    ofstream file;
    abrirArchivoEscritura(file, name);
    file << fixed << setprecision(2) << left;
    file << setw(10) << "CODIGO" << setw(60) << "NOMBRE" << setw(10) << "PRECIO" << setw(10) << "STOCK" << endl;
    for (int i = 0; productos[i] != nullptr; i++) {
        char **auxProducto = productos[i];
        file << setw(10) << auxProducto[0] << setw(60) << auxProducto[1]
                << setw(11) << precios[i] << setw(10) << stock[i] << endl;
    }
    file.close();
}

//JXD-139,50375303,6,24/08/2023

void lecturaDePedidos(const char *name, int *&fechaPedidos, char ***& codigoPedidos,
        int ***&dniCantPedidos) {
    ifstream file;
    abrirArchivoLectura(file, name);
    char *codigo, c;
    /**
     * numSizePedidos=> es cuantos pedidos se van llenando en esa fecha, para ver si es necesario incrementarlo
     * numCapacityPedidos=> es la capacidad de pedidos maximos para esa fecha
     */
    int fecha, posicion, dni, cntPedido, dia, mes, anho, numSizePedidos[200]{}, numCapacityPedidos[200]{}, size = 0, capacity = 0;
    while (true) {
        codigo = leerString(file);
        if (file.eof()) break;
        file >> dni >> c >> cntPedido >> c >> dia >> c >> mes >> c >> anho;
        file.get();
        fecha = dia + (mes * 100) + (anho * 10000);
        posicion = buscarFecha(fechaPedidos, fecha, size);
        if (size == capacity) {
            incrementarMemoriaFechas(fechaPedidos, codigoPedidos, dniCantPedidos, size, capacity);
        }
        if (posicion == -1) {
            insertarFechaOrdenada(fechaPedidos, codigoPedidos, dniCantPedidos,
                    numSizePedidos, numCapacityPedidos, fecha, size, posicion);
            //            fechaPedidos[size] = 0;
            size++;
        }
        if (numSizePedidos[posicion] == numCapacityPedidos[posicion]) {
            incrementarMemoriaPedidosFecha(codigoPedidos[posicion], dniCantPedidos[posicion],
                    numSizePedidos[posicion], numCapacityPedidos[posicion]);
        }
        agregarPedidosFecha(codigoPedidos[posicion], dniCantPedidos[posicion], numSizePedidos[posicion],
                codigo, dni, cntPedido);
        numSizePedidos[posicion]++;
    }
    file.close();
}

int buscarFecha(int *fechaPedidos, int fecha, int size) {
    for (int i = 0; i < size - 1; i++) {
        if (fecha == fechaPedidos[i]) return i;
    }
    return -1;
}

void incrementarMemoriaFechas(int *&fechaPedidos, char ***& codigoPedidos,
        int ***&dniCantPedidos, int &size, int & capacity) {
    capacity += INCREMENTO;
    if (size == 0) {
        fechaPedidos = new int [capacity] {
        };
        codigoPedidos = new char **[capacity] {
        };
        dniCantPedidos = new int **[capacity] {
        };
        size = 1;
    } else {
        int *auxFechaPedidos = new int [capacity] {
        };
        char ***auxCodigoPedidos = new char **[capacity] {
        };
        int ***auxDniCantPedidos = new int**[capacity] {
        };
        for (int i = 0; i < size; i++) {
            auxFechaPedidos[i] = fechaPedidos[i];
            auxCodigoPedidos[i] = codigoPedidos[i];
            auxDniCantPedidos[i] = dniCantPedidos[i];
        }
        delete [] fechaPedidos;
        delete [] codigoPedidos;
        delete [] dniCantPedidos;
        fechaPedidos = auxFechaPedidos;
        codigoPedidos = auxCodigoPedidos;
        dniCantPedidos = auxDniCantPedidos;
    }
}

void insertarFechaOrdenada(int *&fechaPedidos, char ***&codigoPedidos, int ***&dniCantPedidos,
        int *numSizePedidos, int *numCapacityPedidos, int fecha, int size, int & posicion) {
    int i = 0;
    //    for (int i = 0; i <= size - 1; i++) {
    //        if (fechaPedidos[i] < fecha and fechaPedidos[i] != 0) break;
    //    }
    while (fecha > fechaPedidos[i] and fechaPedidos[i] != 0)i++;

    for (int j = size - 1; j >= i; j--) {
        fechaPedidos[j + 1] = fechaPedidos[j];
        codigoPedidos[j + 1] = codigoPedidos[j];
        dniCantPedidos[j + 1] = dniCantPedidos[j];
        numSizePedidos[j + 1] = numSizePedidos[j];
        numCapacityPedidos[j + 1] = numCapacityPedidos[j];
    }
    fechaPedidos[i] = fecha;
    codigoPedidos[i] = nullptr;
    dniCantPedidos[i] = nullptr;
    numSizePedidos[i] = 0;
    numCapacityPedidos[i] = 0;
    posicion = i;
}

void incrementarMemoriaPedidosFecha(char **&codigoPedidos, int **&dniCantPedidos,
        int &size, int & capacity) {
    capacity += INCREMENTO;
    if (size == 0) {
        codigoPedidos = new char*[capacity] {
        };
        dniCantPedidos = new int*[capacity] {
        };
        size = 1;
    } else {
        char **auxCodigo = new char *[capacity] {
        };
        int **auxDniCant = new int *[capacity] {
        };
        for (int i = 0; i < size; i++) {
            auxCodigo[i] = codigoPedidos[i];
            auxDniCant[i] = dniCantPedidos[i];
        }
        delete[] codigoPedidos;
        delete[] dniCantPedidos;
        codigoPedidos = auxCodigo;
        dniCantPedidos = auxDniCant;
    }
}

void agregarPedidosFecha(char **&codigoPedidos, int **& dniCantPedidos, int posicion, char*& codigo,
        int dni, int cntPedido) {
    codigoPedidos[posicion - 1] = codigo;
    dniCantPedidos[posicion - 1] = new int [2];
    int *aux = dniCantPedidos[posicion - 1];
    aux[0] = dni;
    aux[1] = cntPedido;
}

void pruebaDeLecturaDePedidos(const char *name,int *fechaPedidos,
        char ***codigoPedidos,int ***dniCantPedidos){
    
    ofstream file(name,ios::out);
    if(!file){
        cout<<"No se pudo abrir el archivo de prueba de pedidos";
        exit(1);
    }
    
    char **auxCodPed;
    int **auxDniCant,*buffDniCant;
    
    for(int i=0;fechaPedidos[i] != 0;i++){
        file<<"FECHA:   "<<fechaPedidos[i]<<endl;
        file<<"PEDIDOS REALIZADOS:  "<<endl;
        file<<"Codigo"<<"       DNI"<<"        Cantidad"<<endl;
        auxCodPed = codigoPedidos[i];
        auxDniCant = dniCantPedidos[i];
        for(int j=0;auxCodPed[j];j++){
            buffDniCant = auxDniCant[j];
            file<<auxCodPed[j]<<setw(12)<<buffDniCant[0]<<setw(10)<<buffDniCant[1]
                    <<endl;
        }
        file<<endl;
    }
}

void reporteDeEnvioDePedidos(const char *name,char ***productos,int *stock,
        double *precios,int *fechaPedidos,char ***codigoPedidos,int ***dniCantPedidos){
    
    ofstream file(name,ios::out);
    if(!file){
        cout<<"No se pudo abrir el archivo de prueba de pedidos";
        exit(1);
    }
    int dd,mm,aa;
    double ingresosPeriodo=0,ingresosPerdidos=0;
    file<<setw(73)<<"REPORTE DE ENTREGA DE PEDIDOS"<<endl;
    
    for(int i=0;fechaPedidos[i] != -1;i++){
        imprimeLinea(file,125,'=');
        convertirFecha(fechaPedidos[i],dd,mm,aa);
        file<<"FECHA:  "<<setfill('0')<<setw(2)<<dd<<"/"<<setw(2)<<mm<<"/"<<aa<<setfill(' ')<<endl;
        imprimeLinea(file,125,'=');
        file<<"No.   "<<"DNI"<<setw(28)<<"Producto"<<setw(59)<<"Cantidad"<<
                "   Precio"<<"    Total de ingresos"<<endl;
        imprimeLinea(file,125,'-');
        imprimirProductos(productos,stock,precios,codigoPedidos[i],dniCantPedidos[i],
                file,ingresosPeriodo,ingresosPerdidos);
    }
    imprimeLinea(file,125,'=');
    file<<"Resumen de ingresos:"<<endl;
    file<<"Total de ingresos en el periodo:  "<<ingresosPeriodo<<endl;
    file<<"Total perdido por falta de stock: "<<ingresosPerdidos<<endl;
}


void imprimirProductos(char ***productos,int *stock,double *precios,
        char **codigoPedidos,int **dniCantPedidos,ofstream &file,double &ingresosPeriodo,
        double &ingresosPerdidos){
    int *buffdni;
    double totalGanado=0,totalPerdido=0;
    for(int i=0;codigoPedidos[i];i++){
        buffdni = dniCantPedidos[i];
        file<<setw(2)<<i+1<<")   "<<buffdni[0]<<setw(15)<<codigoPedidos[i]
                <<"     ";
        imprimirVerificarProducto(productos,stock,precios,totalGanado,
                totalPerdido,codigoPedidos[i],buffdni[1],file);
    }
    imprimeLinea(file,125,'-');
    file<<"Total ingresado:    "<<totalGanado<<endl;
    file<<"Total perdido por falta de stock:  "<<totalPerdido<<endl;
    ingresosPeriodo += totalGanado;
    ingresosPerdidos += totalPerdido;
}


void imprimirVerificarProducto(char ***productos,int *stock,double *precios,
        double &totalGanado,double &totalPerdido,char *cod,int cant,ofstream &file){
    char **auxProd;
    for(int i=0;productos[i];i++){
        auxProd = productos[i];
        if(!strcmp(auxProd[0],cod)){
            file<<left<<setw(55)<<auxProd[1]<<right<<setw(5)<<cant<<setw(10)
                    <<precios[i];
            if(stock[i] >= cant){ //verifico que el stock con la cantidad pedida
                stock[i] -= cant;
                file<<fixed<<setprecision(2)<<setw(14)<<precios[i]*cant<<endl;
                totalGanado += precios[i]*cant;
            }else{
                file<<"     SIN STOCK"<<endl;
                totalPerdido += precios[i]*cant;
            } 
        }
    }
}

void convertirFecha(int fecha,int &dd,int &mm,int &aa){
    dd = fecha%100;
    fecha /= 100;
    mm = fecha%100;
    fecha /= 100;
    aa = fecha;
}


void imprimeLinea(ofstream &file,int numcar,char c){
    for(int i=0;i<numcar;i++) file<<c;
    file<<endl;
}
