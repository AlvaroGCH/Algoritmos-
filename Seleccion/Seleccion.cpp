#include <iostream>

using namespace std;

void ordenar_seleccion(){
    int tam=0, minimo = 9999999, i, j, *array;
    cin >> tam;
    array = new int[tam];
    for(int i=0;i<tam;i++)
        cin >> array[i];
    for(i=0;i<tam;i++){
        for(j=i+1; j<tam;j++){
            if(array[i] > array[j]){
                minimo = array[j];
                array[j] = array[i];
                array[i] = minimo;
            }
        }
        for(int t=0;t<tam;t++){
            cout << array[t] << " ";
        }
        cout << endl;
    }
    delete [] array;
}

int main(){
    ordenar_seleccion();
}
