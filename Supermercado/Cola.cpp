#include "Cola.h"


Cola::Cola()
{
    principio = nullptr;
    final = nullptr;
}

void Cola::encolar(int num)
{
    Nodo* nuevoNodo = new Nodo(num);

    if (estaVacia()) {
        principio = nuevoNodo;
    }
    else {
        final->siguiente = nuevoNodo;
    }
    final = nuevoNodo;
}

int Cola::desencolar()
{
    int n;
    Nodo* aux = principio;
    n = aux->valor;
    if (principio == final) {
        principio = nullptr;
        final = nullptr;
    }
    else
    {
        principio = principio->siguiente;
    }
    delete aux;
    return n;
}

bool Cola::estaVacia()
{
    if (principio == nullptr) {
        return true;
    }
    else {
        return false;
    }
}
