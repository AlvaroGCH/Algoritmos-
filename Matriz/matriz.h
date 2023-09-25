#ifndef MATRIZ_H
#define MATRIZ_H
#include <iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

class Matriz
{
private:
    int n_filas;
    int n_columnas;
    double **matriz;
public:
    Matriz();
    Matriz(int n_filas, int n_columnas);
    Matriz(const Matriz &matriz_copia);
    Matriz operator + (const Matriz &a_sumar);
    Matriz operator -(const Matriz &a_restar);
    Matriz operator *(int multiplicar);
    Matriz operator *(const Matriz &producto);
    Matriz operator =(const Matriz &copia);
    Matriz calcularTraspuesta();
    bool esSimetrica();
    double obtenerMaximo();
    double obtenerMinimo();
    void rellenarManual();
    void rellenarAleatorio(long seed);
    void mostrarMatriz();
    //Operador de asignación.
    ~Matriz();
};

#endif // MATRIZ_H
