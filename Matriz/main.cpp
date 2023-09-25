#include "matriz.h"
using namespace std;

int main()
{
    Matriz matriz1(3,3);
    Matriz matriz2(3,3);
    matriz1.rellenarManual();
    matriz2.rellenarManual();
    matriz1.mostrarMatriz();
    cout << "\n";
    matriz2.mostrarMatriz();
    cout << "\n";
    /*
    Matriz suma = matriz1+matriz2;
    suma.mostrarMatriz();
    cout << "\n";
    Matriz resta = matriz1-matriz2;
    resta.mostrarMatriz();
    cout << "\n";
    */
    Matriz producto = matriz1 * matriz2;
    producto.mostrarMatriz();
    cout << "\n";
    /*
    Matriz productoEscalar = matriz1*2;
    productoEscalar.mostrarMatriz();
    cout << "\n";
    Matriz traspuesta = matriz2.calcularTraspuesta();
    traspuesta.mostrarMatriz();
    cout << "\n";
    cout <<  matriz1.esSimetrica() << matriz1.obtenerMaximo() << matriz2.obtenerMinimo() << "\n";*/
    return 0;
}
