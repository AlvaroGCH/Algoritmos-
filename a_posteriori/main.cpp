#include <funciones.h>
#include "ctime"
#include "cstdlib"
using namespace std;

int main()
{
    int tam;
    srand(time(NULL));
    cout << "Introduce el tamano del vector(numero mayor o igual que 1): ";
    cin >> tam;
    int *vector_inicial = (int*)malloc(tam*sizeof(int));
    for (int i = 0; i<tam; i++)
        vector_inicial[i] = rand();
    cout << "\nEl vector original es el siguiente:\n";
    imprimir(vector_inicial, tam);
    cout << endl << endl;
    unsigned long int inicio = clock();
    cout << "Clocks de inicio con ordenacion: " << inicio << endl;
    ordenar(vector_inicial, tam);
    unsigned long int fin = clock();
    cout << "Clocks de fin con ordenacion:    " << fin << endl;
    cout << "CLOCK_PER_SEC:                                 " << CLOCKS_PER_SEC << endl;
    float segundos = (fin - inicio) / (float)CLOCKS_PER_SEC;
    cout << "Con ordenacion por seleccion he tardado" << segundos << "segundos en ordenarlo.\nEl vector resultado es:\n";
    imprimir(vector_inicial, tam);
    cout << endl << endl;
    int *vector_qshort;
    inicio = clock();
    for (int i = 0; i<tam; i++)
        vector_qshort[i] = rand();
    cout << "Clocks de inicio con ordenacion por QuickSort: " << inicio << endl;
    qsort(vector_qshort, tam, sizeof(int), compareInt);
    fin = clock();
    cout << "Clocks de fin con ordenacion por QuickSort:    " << fin << endl;
    cout << "CLOCK_PER_SEC:                                 " << CLOCKS_PER_SEC << endl;
    segundos = (fin - inicio) / (float)CLOCKS_PER_SEC;
    cout << "Con ordenacion por QuickShort he tardado" << segundos << "segundos en ordenarlo.\nEl vector resultado es:\n";
    imprimir(vector_qshort, tam);
    cout << endl << endl;
    return 0;
}
