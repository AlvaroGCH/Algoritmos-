#include"Pila.h"


Pila::Pila(string name)
{
    this->name = name;
}

std::string Pila::nombrePila()
{
    return this->name;
}

void Pila::apilar(int num)
{
    Nodo* nuevoNodo = new Nodo(num, cima);
    this->cima = nuevoNodo;
    cout<<"Apilando disco "<<num<<" en poste "<<name<<endl;
}

int Pila::desapilar()
{

    Nodo* aux = this->cima;
    int num = aux->valor;
    cima = aux->siguiente;
    cout << "Desapilando disco " << num << " del poste " << name << endl;
    return num;

}

/*bool Pila::estaVacia()
{

}
*/
