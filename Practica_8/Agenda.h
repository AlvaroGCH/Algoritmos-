#include "ListaEnlazada.h"
#include <string>

using namespace std;

class Agenda {
    int capacidad;
    int n;
    ListaEnlazada* tabla;
public:
    Agenda(int capacidad);
    int obtenerPosicion(long telefono);
    bool existeContacto(long telefono);
    string getContacto(long telefono);
    void introducirContacto(long telefono, string contacto);
    void eliminarContacto(long telefono);
    void imprimir();
};
