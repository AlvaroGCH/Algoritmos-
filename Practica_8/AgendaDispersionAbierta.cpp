#include "Agenda.h"
#include "ListaEnlazada.h"
#include "assertdomjudge.h"
#include <iostream>
#include "impresionListasEnlazadas.h" // Para el método imprimir de la tabla hash

using namespace std;

Agenda::Agenda(int capacidad)
{
    Contacto rellenar;
    rellenar.nombre = "";
    rellenar.telefono = 0;
    this->capacidad = capacidad;
    n = 0;
    tabla = new ListaEnlazada[capacidad];
}

int Agenda::obtenerPosicion(long telefono)
{
    int resto = telefono % capacidad;
    return resto;
}

bool Agenda::existeContacto(long telefono)
{
    Contacto resultado;
    resultado.nombre = "";
    resultado.telefono = telefono;
    int num = obtenerPosicion(telefono);
    int buscar = tabla[num].buscar(resultado);

    if (buscar > -1) {
        return true;
    }
    return false;
}

string Agenda::getContacto(long telefono)
{
    assertdomjudge(existeContacto(telefono))
    int posicion = obtenerPosicion(telefono);
    Contacto resultado;
    resultado.nombre = "";
    resultado.telefono = telefono;
    int buscar = tabla[posicion].buscar(resultado);

    return tabla[posicion].getValor(buscar).nombre;
}

void Agenda::introducirContacto(long telefono, string contacto)
{
    Contacto nuevoContacto;
    nuevoContacto.nombre = contacto;
    nuevoContacto.telefono = telefono;
    for (int i = obtenerPosicion(telefono); i <= n; i++) {
        tabla[i].insertar(nuevoContacto);
        n++;
        return;
    }
}

void Agenda::eliminarContacto(long telefono)
{
    assertdomjudge(existeContacto(telefono))

    Contacto contacto;
    contacto.nombre = "";
    contacto.telefono = telefono;
    int posicion = obtenerPosicion(telefono);
    int buscar = tabla[posicion].buscar(contacto);
    tabla[posicion].eliminar(buscar);
    n--;
}

void Agenda::imprimir() {
    for (int i = 0; i < capacidad; i++) {
        cout << "Posicion " << i << ": ";
        imprimirListaEnlazada(&tabla[i]);
    }
}
