#include "Rojiblanco.h"

Rojiblanco::Rojiblanco(int vertices, int aristas){
    this->vertices = vertices;
    this->aristas = aristas;
    matriz = new int*[this->vertices];
    for(int i = 0; i<vertices;i++)
        matriz[i] = new int[this->vertices];
}
void Rojiblanco::rellenarAristas(const Rojiblanco &grafo){
    int vertice1, vertice2;
    do{
        cin >> vertice1 >> vertice2;
    }while(vertice1>0 && vertice1<=grafo.vertices && vertice2>0 && vertice2<=grafo.vertices);
}
