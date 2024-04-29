#include "funcionesLista.hpp"

void construir_lista(Lista &lista) {
    lista.cabeza = nullptr;
    lista.longitud = 0;
}

int es_lista_vacia(Lista lista) {
    return lista.cabeza == nullptr;
}

int longitud(Lista lista) {
    return lista.longitud;
}

Nodo *crear_nuevo_nodo(ElementoLista elemento, Nodo *siguiente) {
    Nodo *nuevo_nodo = new Nodo;
    nuevo_nodo->elemento = elemento;
    nuevo_nodo->siguiente = siguiente;
    return nuevo_nodo;
}

Nodo *obtener_ultimo_nodo(Lista lista) {
    Nodo *recorrido = lista.cabeza;
    Nodo *ultimo = nullptr;
    while (recorrido != nullptr) {
        ultimo = recorrido;
        recorrido = recorrido->siguiente;
    }
    return ultimo;
}

Nodo *obtener_nodo_anterior(Lista lista, ElementoLista elemento) {
    Nodo *anterior = nullptr;
    Nodo *recorrido = lista.cabeza;
    while (recorrido != nullptr and comparar_elemento(recorrido->elemento, elemento)) {
        anterior = recorrido;
        recorrido = recorrido->siguiente;
    }
    return anterior;
}

/**
 * Funciones de comparación, para este ejemplo vamos a realizar de forma
 * sencilla, y que sea por medio del id.
 */
bool comparar_elemento(ElementoLista e, ElementoLista d) {
    void **elemento = (void **) e;
    void **dato = (void **) d;
    int *elemento_id = (int *) elemento[ID];
    int *dato_id = (int *) dato[ID];
    return *elemento_id < *dato_id;
}

/**
 * Funcion de impresion, que va a depender del valor
 * @param lista
 */
void imprime(Lista lista) {
    cout << fixed << setprecision(2);
    if (es_lista_vacia(lista)) {
        cerr << "ERROR: No se puede imprimir una lista vacia" << endl;
        exit(1);
    }
    Nodo *recorrido = lista.cabeza;
    while (recorrido != nullptr) {
        imprimir_elemento(recorrido->elemento);
        recorrido = recorrido->siguiente;
    }
}

void eliminar_lista(Lista &lista) {
    Nodo *recorrido = lista.cabeza;
    while (recorrido != nullptr) {
        Nodo*nodo_a_eliminar = recorrido;
        recorrido = recorrido->siguiente;
        eliminar_elemento_lista(nodo_a_eliminar->elemento);
        delete nodo_a_eliminar;
    }
    lista.cabeza = nullptr;
    lista.longitud = 0;
}

void eliminar_elemento_lista(ElementoLista &e) {
    void **producto = (void **) e;
    int *id = (int *) producto[ID];
    char *nombre = (char *) (producto[NOMBRE]);
    double *precio = (double *) producto[PRECIO];
    int *stock = (int *) producto[STOCK];
    delete id;
    delete nombre;
    delete precio;
    delete stock;
}

/**
 * Funciones que va a depender del valor que tengamos; puesto que, estamos
 * trabajando con un puntero void*.
 * 
 * Para este ejemplo el elemento va a consistir de los siguiente:
 *
 * id: int
 * 
 * nombre: char *
 * 
 * precio: double
 * 
 * stock: int
 */
void imprimir_elemento(void *elemento) {
    void **producto = (void **) (elemento);
    int *id = (int *) producto[ID];
    char *nombre = (char *) (producto[NOMBRE]);
    double *precio = (double *) producto[PRECIO];
    int *stock = (int *) producto[STOCK];
    cout << left;
    cout << setw(5) << *id << setw(60) << nombre
            << setw(10) << *precio << *stock << endl;
}

void insertar_al_inicio(Lista &lista, ElementoLista elemento) {
    Nodo *nuevo_nodo = crear_nuevo_nodo(elemento, lista.cabeza);
    lista.cabeza = nuevo_nodo;
    lista.longitud++;
}

void insertar_al_final(Lista &lista, ElementoLista elemento) {
    Nodo *nuevo_nodo = crear_nuevo_nodo(elemento, nullptr);
    Nodo *ultimo_nodo = obtener_ultimo_nodo(lista);
    if (ultimo_nodo == nullptr) {
        lista.cabeza = nuevo_nodo;
    } else {
        ultimo_nodo->siguiente = nuevo_nodo;
    }
    lista.longitud++;
}

void insertar_en_orden(Lista &lista, ElementoLista elemento) {
    Nodo *nodo_anterior = obtener_nodo_anterior(lista, elemento);
    Nodo *nuevo_nodo = crear_nuevo_nodo(elemento, nullptr);
    if (nodo_anterior == nullptr) {
        nuevo_nodo->siguiente = lista.cabeza;
        lista.cabeza = nuevo_nodo;
    } else {
        nuevo_nodo->siguiente = nodo_anterior->siguiente;
        nodo_anterior->siguiente = nuevo_nodo;
    }
    lista.longitud++;
}

/**
 * De igual forma que la funcion comparar_elemento, para que este sea de forma
 * sencilla, vamos a buscar por medio del id.
 */
Nodo *se_encuentra(Lista lista, ElementoLista d) {
    Nodo *recorrido = lista.cabeza;
    void **dato = (void **) d;
    int *id_dato = (int *) dato[ID];
    while (recorrido != nullptr) {
        void **elemento = (void **) recorrido->elemento;
        int *id_elemento = (int *) elemento[ID];
        if (*id_elemento == *id_dato) break;
        recorrido = recorrido->siguiente;
    }
    return recorrido;
}

void elimina_cabeza(Lista &lista) {
    Nodo *nodo_a_eliminar = lista.cabeza;
    if (nodo_a_eliminar == nullptr) return; // el nodo no se puede eliminar
    lista.cabeza = lista.cabeza->siguiente;
    eliminar_elemento_lista(nodo_a_eliminar->elemento);
    delete nodo_a_eliminar;
    nodo_a_eliminar = nullptr;
    lista.longitud--;
}

void elimina_cola(Lista &lista) {
    Nodo *ultimo = nullptr;
    Nodo *penultimo = nullptr;
    Nodo * recorrido = lista.cabeza;
    // buscamos el ultimo nodo de la lista
    while (recorrido != nullptr) {
        if (ultimo != nullptr)
            penultimo = ultimo;
        ultimo = recorrido;
        recorrido = recorrido->siguiente;
    }

    if (ultimo == nullptr) return;
    //Si no hay penultimo, se está¡ eliminando el Único nodo de la lista
    if (penultimo == nullptr)
        lista.cabeza = nullptr;
    else
        penultimo->siguiente = nullptr;
    delete ultimo;
    ultimo = nullptr;
    lista.longitud--;
}

void elimina_nodo(Lista &lista, ElementoLista e) {
    Nodo * ultimo = nullptr;
    Nodo * recorrido = lista.cabeza;
    /*Avanzo hasta encontrar el elemento*/
    /*Si no lo encuentra no elimina nada*/
    void **elemento = (void **) e;
    int *id_elemento = (int *) elemento[ID];
    while (recorrido != nullptr) {
        void **producto = (void **) recorrido->elemento;
        int *id_producto = (int *) producto[ID];
        if (*id_elemento == *id_producto) break;
        ultimo = recorrido;
        recorrido = recorrido->siguiente;
    }

    if (recorrido != nullptr) {
        if (ultimo == nullptr) /*Estoy al inicio de la lista*/
            lista.cabeza = recorrido->siguiente;
        else
            ultimo->siguiente = recorrido->siguiente;
        delete recorrido; /*libera la memoria*/
        recorrido = nullptr;
        lista.longitud--;
    }
}