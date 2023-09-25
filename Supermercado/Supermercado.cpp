#include "Supermercado.h"

Supermercado::Supermercado(int n)
{
    assertdomjudge(n > 0)
    cajas = new Cola[n];
    this->n_cajas = n;
}

void Supermercado::nuevoUsuario(int n, int id)
{
    assertdomjudge(n >= 0 && n < n_cajas)
    cajas[n].encolar(id);
}

void Supermercado::cerrarCaja(int n)
{
    assertdomjudge(n >= 0 && n < n_cajas)
    int i = 0;
    while (!cajaVacia(n)) {
        int usuario = cajas[n].desencolar();
        if (!cajas[i].estaVacia() && i != n) {
            cajas[i].encolar(usuario);
        }
        i++;
        if (i == n_cajas - 1)
            i = 0;
    }
}

int Supermercado::atenderUsuario(int n)
{
    assertdomjudge(n >= 0 && n < n_cajas)
    int id;
    id = cajas[n].desencolar();
    return id;
}

bool Supermercado::cajaVacia(int n)
{
    assertdomjudge(n >= 0 && n < n_cajas)
    if (cajas[n].estaVacia()) {
        return true;
    }
    else {
        return false;
    }
}
