#include "funciones.h"

using namespace std;

void imprimir(int *vector, int tam) {
   if(vector != NULL){
       if (tam<10)
           for (int i = 0; i<tam; i++)
               cout << vector[i] << " ";
       else
           cout << "<demasiados componentes para mostrar>";
   }
   else
        cout << "No existe ese vector";
}

void ordenar(int *array, int tam){
    int maximo=-999;
    for(int i=0;i<tam;i++){
        for(int j=i; j<tam;j++){
            if(array[j]>maximo){
                maximo = array[j];
                array[j] = array[i];
                array[i] = maximo;
            }
        }
    }
}


int compareInt(const void *p1, const void *p2){
    int *puntero1 = (int*)p1;
    int *puntero2 = (int*)p2;
    int operando1 = *puntero1;
    int operando2 = *puntero2;
    return (operando1 - operando2);
}
