#include <iostream>
#include <cmath>
using namespace std;

double calcularDeterminante(double **matriz, int orden);
double adjunto(double **matriz, int orden, int fila, int columna);

double calcularDeterminante(double **matriz, int tam){  // metedo de resolucion de matrices por adjuntos
          double deter = 0;

          if (tam == 1) {                              // caso de matriz de orden 1
             deter = matriz[0][0];
          } else {
             for (int j = 0; j < tam; j++) {
                deter = deter + matriz[0][j] * adjunto(matriz, tam, 0, j);
             }
          }

          return deter;
}

double adjunto(double **matriz, int tam, int fila, int columna){    // realiza los detemianntes de los adjuntos
   int tam_max = 5;
   double **submatriz;
   submatriz = new double*[tam_max];
   for(int i = 0; i<tam;i++){
       submatriz[i] = new double[tam_max];
   }
   int n = tam - 1;
   int x = 0;
   int y = 0;
   for (int i = 0; i < tam; i++) {
      for (int j = 0; j < tam; j++) {
         if (i != fila && j != columna) {
            submatriz[x][y] = matriz[i][j];
            y++;
            if (y >= n) {
               x++;
               y = 0;
            }
         }
      }
   }
   return pow(-1.0, fila + columna) * calcularDeterminante(submatriz, n);   // la funcion pow sirve para hacer la potencia de un numero, en este caso -1
}

void imprimir_matriz(double **matriz, int tam)
{
   for (int i = 0; i < tam; i++) {
      for (int j = 0; j < tam; j++) {
         cout << matriz[i][j]<< " ";
      }
      cout << "\n";
   }
}

int main(){
    int tam, i;
    double **matriz;
    cout << "Introduce el orden o tamanio de la matriz \n";
    cin >> tam;
    matriz = new double*[tam];
    for(int i = 0; i<tam;i++){
        matriz[i] = new double[tam];
    }
    for(int i=0;i<tam;i++){
        for(int j=0; j<tam; j++){
            cout << "Introduce el numero en la posicion fila: " << i+1 << " columna: " << j+1 << "\n";
            cin >> matriz[i][j];
        }
    }
    cout << "Matriz: \n";
    imprimir_matriz(matriz, tam);
    cout << "Determiante: " << calcularDeterminante(matriz,tam) << endl;

}
