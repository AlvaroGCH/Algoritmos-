#include <iostream>

using namespace std;

int busqueda_binaria(int array[],int inicio, int final, int buscar){
    int medio = (inicio+final)/2;
    if(inicio > final)
        return -1;
    else if(array[medio]==buscar)
        return medio;
    else if(array[medio]<buscar)
        busqueda_binaria(array,inicio,medio,buscar);
    else if(array[medio]>buscar)
        busqueda_binaria(array,medio,final,buscar);
    else
        return -1;
}

int main()
{
    int tam=0, buscar=0, *array;
    cin >> tam;
    array = new int[tam];
    for(int i=0;i<tam;i++)
        cin >> array[i];
    do{
        cin >> buscar;
        cout << busqueda_binaria(array,0,tam-1,buscar);
    }while(buscar>=0);
    delete [] array;
}
