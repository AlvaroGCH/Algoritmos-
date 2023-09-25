#include "listaenlazada.h"


using namespace std;
Nodo* ListaEnlazada::getNodo(int pos){
    assertdomjudge(pos >= 0)

    Nodo* resultado = nullptr;

    resultado = lista;

    for (int i = 0; i < pos; i++) {
        resultado = resultado->siguienteNodo;
    }
    return resultado;
}

ListaEnlazada::ListaEnlazada(){
    lista = nullptr;
    n = 0;
}

int ListaEnlazada::getValor(int pos){
    assertdomjudge(pos < getN() && pos >= 0)

    Nodo* nodoResultado = getNodo(pos);

    return nodoResultado->elemento;
}

void ListaEnlazada::setValor(int pos, int val){
    assertdomjudge(pos < getN() && pos >= 0)

    getNodo(pos)->elemento = val;
}

int ListaEnlazada::getN(){
    return this->n;
}

void ListaEnlazada::insertar(int pos, int val){ // Inserta un nuevo elemento en la posición pos de la lista con valor val, cambiando los punteros correspondientes
    assertdomjudge(pos <= n && pos >= 0)

    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->elemento = val;


    if (pos == 0) {
        nuevoNodo->siguienteNodo = lista;
        lista = nuevoNodo;
    }

    else {
        Nodo* anterior = getNodo(pos - 1);
        nuevoNodo->siguienteNodo = anterior->siguienteNodo;
        anterior->siguienteNodo = nuevoNodo;
    }


    n++;
}

void ListaEnlazada::eliminar(int pos){ // Elimina el elemento que se encuentra en la posición pos cambiando los punteros correspondientes
    assertdomjudge(pos < n && pos >= 0)

    Nodo* nodoAEliminar = nullptr;


    if (pos == 0) {
        nodoAEliminar = lista;
        Nodo* nodoSiguiente = nodoAEliminar->siguienteNodo;
        lista = nodoSiguiente;
    }

    else {
        Nodo* nodoAnterior = getNodo(pos - 1);
        nodoAEliminar = nodoAnterior->siguienteNodo;
        Nodo* nodoSiguiente = nodoAEliminar->siguienteNodo;
        nodoAnterior->siguienteNodo = nodoSiguiente;
    }

    delete(nodoAEliminar);

    n--;
}

void ListaEnlazada::concatenar(ListaEnlazada* lista){ // Concatena la lista indicada como parámetro al final de nuestra lista
    int m = lista->getN();
    for (int i = 0; i < m; i++) {
        insertar(this->n, lista->getValor(i));
    }
}

int ListaEnlazada::buscar(int num){ // Busca un elemento en la lista contigua con valor igual a num y retorna su posición o - 1 si no se ha podido encontrar
    int pos = 0;
    bool encontrado = false;

    while (encontrado == false && pos < n) {
        Nodo* busqueda = getNodo(pos);

        if (busqueda->elemento == num) {
            encontrado = true;
        }

        pos++;
    }

    if (encontrado) {
        return (pos - 1);
    }
    else {
        return -1;
    }

}

ListaEnlazada::~ListaEnlazada(){
    while (n > 0)
        eliminar(0);
}
