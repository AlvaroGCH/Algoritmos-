#include "ListaContigua.h"
#include <iostream>
#include <cstdlib>
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}
using namespace std;

ListaContigua :: ListaContigua(int incremento) // Constructor
{
    this->n = 0;
    this->capacidad = incremento;
    this->vector = new int[capacidad];
}

int ListaContigua::getValor(int pos)
{
    return this->vector[pos];
}

void ListaContigua::setValor(int pos, int val)
{
    assertdomjudge(pos >= 0 && pos < n);
    this->vector[pos] = val;
}

int ListaContigua::getN()
{
    return this->n;
}

int ListaContigua::getCapacidad()
{
    return this->capacidad;
}

void ListaContigua::insertar(int pos, int val)// Inserta un nuevo elemento en la posición "pos" de la lista con valor "val", dejando primero un hueco para introducirlo
{
    if (capacidad == n) {
        capacidad += 2;
        this->vector = (int*)realloc(vector, capacidad * sizeof(int));
    }
    n++;
    setValor(pos, val);
}

void ListaContigua::eliminar(int pos)  // Elimina el elemento que se encuentra en la posición "pos" y por tanto deberá desplazar a la izquierda todos los elementos que se encuentren a su derecha
{
    for (int i = pos; i < this->n; i++)
        vector[i] = vector[i + 1];
    n--;

    if ((capacidad - n) == 4) {
        capacidad -= 2;
        this->vector = (int*)realloc(vector, capacidad * sizeof(int));
    }
}

void ListaContigua::concatenar(ListaContigua* listaAConcatenar){    //Concatena la lista indicada como parámetro al final de nuestra lista
    int n = listaAConcatenar->getN();

    for (int i = 0; i < n; i++) {
        int elementoACopiar = listaAConcatenar->getValor(i);
        insertar(n, elementoACopiar);
    }
}

int ListaContigua::buscar(int elementoABuscar){ // Busca un elemento en la lista contigua con valor igual a num y retorna su posición o -1 si no se ha podido encontrar.

    int pos = 0;
    bool encontrado = false;

    while (!encontrado && pos < n)
    {
        if (getValor(pos) == elementoABuscar)
            encontrado = true;
        pos++;
    }

    if (encontrado)
        return pos - 1;
    else
        return -1;
}

ListaContigua::~ListaContigua(){    // Destructor
    delete[] vector;
    vector = nullptr;
}
