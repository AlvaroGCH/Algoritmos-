#include "ListaEnlazada.h"

Nodo* ListaEnlazada::getNodo(int pos)
{

    Nodo* resultado = new Nodo;

    resultado = lista;

    for (int i = 0; i < pos; i++) {
        resultado = resultado->siguienteNodo;
    }

    posicionUltimoNodoAccedido = pos;
    punteroUltimoNodoAccedido = resultado;
    return resultado;
}

ListaEnlazada::ListaEnlazada()
{
    lista = nullptr;
    n = 0;
    posicionUltimoNodoAccedido = -1;
    punteroUltimoNodoAccedido = nullptr;
}

Contacto ListaEnlazada::getValor(int pos)
{
    Nodo* resultado = getNodo(pos);
    return resultado->elemento;
}

void ListaEnlazada::setValor(int pos, Contacto val)
{
    Nodo* nodoQueContieneElResultado = new Nodo;
    nodoQueContieneElResultado = getNodo(pos);
    nodoQueContieneElResultado->elemento = val;
}

int ListaEnlazada::getN()
{
    return n;
}

void ListaEnlazada::insertar(Contacto val)
{
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->elemento = val;

    if (estaVacia()) {
        lista = nuevoNodo;
        lista->siguienteNodo = nuevoNodo;
        lista->anteriorNodo = nuevoNodo;
    }
    else {
        lista->anteriorNodo->siguienteNodo = nuevoNodo;
        nuevoNodo->anteriorNodo = lista->anteriorNodo;
        nuevoNodo->siguienteNodo = lista;
        lista->anteriorNodo = nuevoNodo;
        lista = nuevoNodo;
    }

    n++;

    posicionUltimoNodoAccedido = -1;
    punteroUltimoNodoAccedido = nullptr;
}

void ListaEnlazada::eliminar(int pos)
{

    Nodo* nodoAEliminar = nullptr;

    if (pos == 0) {
        nodoAEliminar = lista;
        Nodo* nodoSiguiente = nodoAEliminar->siguienteNodo;
        nodoSiguiente->anteriorNodo = nodoAEliminar->anteriorNodo;
        nodoAEliminar->anteriorNodo->siguienteNodo = nodoSiguiente;
    }
    else {
        Nodo* anterior = getNodo(pos - 1);
        nodoAEliminar = anterior->siguienteNodo;
        anterior->siguienteNodo = nodoAEliminar->siguienteNodo;
        nodoAEliminar->siguienteNodo->anteriorNodo = anterior;
    }
    delete(nodoAEliminar);

    n--;

    posicionUltimoNodoAccedido = -1;
    punteroUltimoNodoAccedido = nullptr;
}

void ListaEnlazada::concatenar(ListaEnlazada* listaAConcatenar)
{
    int m = listaAConcatenar->getN();

    for (int i = 0; i < m; i++) {
        Contacto elementoACopiar = listaAConcatenar->getValor(i);
        insertar(elementoACopiar);
    }
}

int ListaEnlazada::buscar(Contacto elementoABuscar)
{
    int pos = 0;
    bool encontrado = false;

    while (!encontrado && pos < n) {
        if (getValor(pos).telefono == elementoABuscar.telefono)
            encontrado = true;
        pos++;
    }

    if (encontrado) {
        return pos - 1;
    }
    else
        return -1;
}

bool ListaEnlazada::estaVacia()
{
    if (lista == nullptr) {
        return true;
    }
    return false;
}

ListaEnlazada::~ListaEnlazada()
{
    while (n > 0)
        eliminar(0);
}
