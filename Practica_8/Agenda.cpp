#include "Agenda.h"
#include "ListaEnlazada.h"
#include "assertdomjudge.h"
#include <iostream>
#include "impresionListasEnlazadas.h"
#include "Agenda.h"
using namespace std;

Agenda::Agenda(int capacidad){
    this->capacidad = capacidad;
    n = 0;
    tabla = new ListaEnlazada[capacidad];
}

int Agenda::obtenerPosicion(long telefono){
    return telefono%capacidad;
}

bool Agenda::existeContacto(long telefono){
    int pos = obtenerPosicion(telefono);

    Contacto comprobar;
    comprobar.telefono = telefono;

    if(tabla[pos].buscar(comprobar) != -1){
        return true;
    }

    return false;
}

string Agenda::getContacto(long telefono){

    if(existeContacto(telefono)){
        int pos = obtenerPosicion(telefono);

        Contacto comprobar;
        comprobar.telefono = telefono;

        int posContacto = tabla[pos].buscar(comprobar);

        return tabla[pos].getValor(posContacto).nombre;

    }

    return "No existe contacto asignado a este telefono";
}

void Agenda::introducirContacto(long telefono, string nombre){

    if(existeContacto(telefono))
        return;

    int pos = obtenerPosicion(telefono);

    Contacto nuevoContacto;

    nuevoContacto.telefono = telefono;
    nuevoContacto.nombre = nombre;

    tabla[pos].insertar(tabla[pos].getN(), nuevoContacto);

    n++;

    return;
}

void Agenda::eliminarContacto(long telefono){

    if(existeContacto(telefono)){
        int pos = obtenerPosicion(telefono);

        Contacto contactoEliminar;
        contactoEliminar.telefono = telefono;

        int posContacto = tabla[pos].buscar(contactoEliminar);

        tabla[pos].eliminar(posContacto);

        n--;
    }

    return;
}

void Agenda::imprimir() {
    for (int i=0; i<capacidad; i++) {
        cout << "Posicion " << i << ": ";
        imprimirListaEnlazada(&tabla[i]);
    }
}

Agenda::~Agenda(){
    for(int i = 0; i < capacidad; i++){
        tabla[i].~ListaEnlazada();
    }

    delete[] tabla;
}
