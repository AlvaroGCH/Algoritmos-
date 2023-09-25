#include "ListaCircular.h"

Nodo* ListaCircular::getNodo(int posicion)
{
    assertdomjudge(posicion >= 0)
    Nodo* resultado = nullptr;
    resultado = lista;
    for (int i = 0; i < posicion; i++) {
        resultado = resultado->siguienteNodo;
    }
    return resultado;
}

ListaCircular::ListaCircular()
{
    lista = nullptr;
    n = 0;
}

string ListaCircular::getValor(int posicion)
{
    assertdomjudge(posicion < getN() && posicion >= 0)
    Nodo* resultado = getNodo(posicion);
    return resultado->elemento;
}

void ListaCircular::setValor(int posicion, string nuevoValor)
{
    assertdomjudge(posicion < getN() && posicion >= 0)

    getNodo(posicion)->elemento = nuevoValor;
}

int ListaCircular::getN()
{
    return this->n;
}

void ListaCircular::insertar(int posicion, string nuevoValor)
{
    assertdomjudge(posicion <= n && posicion >= 0)

    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->elemento = nuevoValor;


    if (posicion == 0) {
        lista = nuevoNodo;
        lista->siguienteNodo = nuevoNodo;
        lista->anteriorNodo = nuevoNodo;
    }
    else {
        lista->anteriorNodo->siguienteNodo = nuevoNodo;
        nuevoNodo->anteriorNodo = lista->anteriorNodo;
        nuevoNodo->siguienteNodo = lista;
        lista->anteriorNodo = nuevoNodo;
    }

    n++;
}

void ListaCircular::eliminar(int posicion)
{
    assertdomjudge(posicion < n && posicion >= 0)

    Nodo* nodoAEliminar = nullptr;

    if (posicion == 0) {
        nodoAEliminar = lista;
        Nodo* nodoSiguiente = nodoAEliminar->siguienteNodo;
        nodoSiguiente->anteriorNodo = nodoAEliminar->anteriorNodo;
        nodoAEliminar->anteriorNodo->siguienteNodo = nodoSiguiente;
        lista = nodoSiguiente;
    }
    else {
        Nodo* anterior = getNodo(posicion - 1);
        nodoAEliminar = anterior->siguienteNodo;
        anterior->siguienteNodo = nodoAEliminar->siguienteNodo;
        nodoAEliminar->siguienteNodo->anteriorNodo = anterior;
    }
    delete(nodoAEliminar);

    n--;
}

void ListaCircular::girar(int p)
{
    int temp = p;
    if (p < 0) {
        p *= -1;
        temp += n;
    }
    for (int i = 0; i < temp; i++) {
        lista = lista->siguienteNodo;
    }
}

ListaCircular::~ListaCircular()
{
    while (n > 0)
        eliminar(0);
}
