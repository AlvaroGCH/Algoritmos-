#include <iostream>

using namespace std;

void ordenar_burbuja(){
    int tam=0, tmp = 0, i, j, *array;
    cin >> tam;
    array = new int[tam];
    for(int i=0;i<tam;i++)
        cin >> array[i];
    for(i=1;i<tam;i++){
        for(j=0; j<tam-i;j++){
            if(array[j] > array[j+1]){
                tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
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
    ordenar_burbuja();
}
