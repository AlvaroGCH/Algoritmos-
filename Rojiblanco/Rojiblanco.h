#include <iostream>
using namespace std;

class Rojiblanco{
private:
        int vertices;
        int aristas;
        int **matriz;        // orden de la matriz representa el número de vértices, donde haya un 0 significa que no hay union entre vertices(se representan mediante las filas y columnas de la matriz)
public:
    Rojiblanco(int vertices, int aristas);
    void rellenarAristas(const Rojiblanco &grafo); // rellena con 1 la matriz para unir vertices con aristas
};

