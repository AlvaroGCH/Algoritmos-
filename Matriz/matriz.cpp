#include "matriz.h"

Matriz::Matriz(){
    n_filas = 0;
    n_columnas = 0;
    matriz = nullptr;
}

Matriz::Matriz(int n_filas, int n_columnas){
    this->n_filas = n_filas;
    this->n_columnas = n_columnas;
    matriz = new double*[this->n_filas];
    for(int i = 0; i<n_filas;i++){
        matriz[i] = new double[this->n_columnas];
    }
}

Matriz::Matriz(const Matriz &matriz_copia):Matriz(matriz_copia.n_filas, matriz_copia.n_columnas){
    int i,j;
    if(this->n_filas == matriz_copia.n_filas && this->n_columnas == matriz_copia.n_columnas){
        for(i=0;i<this->n_filas;i++){
            for(j=0; j<this->n_columnas; j++)
                this->matriz[i][j]= matriz_copia.matriz[i][j];
        }
    }
}

Matriz Matriz::operator =(const Matriz &a_copiar){

    this->n_filas = a_copiar.n_filas;
    this->n_columnas = a_copiar.n_columnas;
    this->matriz = new double*[this->n_filas];
    for(int i = 0; i<this->n_filas;i++){
         *(this->matriz) = new double[this->n_columnas];
    }
    for(int i=0;i<this->n_filas;i++){
        for(int j=0; j<this->n_columnas; j++)
            this->matriz[i][j]= a_copiar.matriz[i][j];
    }
    return(*this);
}

Matriz Matriz::operator +(const Matriz &a_sumar){
    if(n_filas == a_sumar.n_filas && n_columnas == a_sumar.n_columnas){
        Matriz suma(a_sumar.n_filas,a_sumar.n_columnas);
        for(int i=0;i<suma.n_filas;i++){
            for(int j=0; j<suma.n_columnas; j++)
                suma.matriz[i][j] = matriz[i][j]+a_sumar.matriz[i][j];
        }
        return suma;
    }
    else{
        cout << "Operacion errónea" << endl;
    }
}

Matriz Matriz::operator -(const Matriz &a_restar){
    if(n_filas == a_restar.n_filas && n_columnas == a_restar.n_columnas){
        Matriz resta(a_restar.n_filas,a_restar.n_columnas);
        for(int i=0;i<resta.n_filas;i++){
            for(int j=0; j<resta.n_columnas; j++)
                resta.matriz[i][j] = matriz[i][j]-a_restar.matriz[i][j];
        }
        return resta;
    }
    else{
        cout << "Operacion errónea" << endl;
    }
}

Matriz Matriz::operator *(int multiplicar){
    Matriz producto(this->n_filas,this->n_columnas);
    for(int i=0;i<producto.n_filas;i++){
        for(int j=0; j<producto.n_columnas; j++)
            producto.matriz[i][j] = multiplicar * this->matriz[i][j];
    }
    return producto;
}

Matriz Matriz::operator *(const Matriz &a_producto_matriz){


    Matriz producto(a_producto_matriz.n_filas,a_producto_matriz.n_columnas);
    if(a_producto_matriz.n_columnas != a_producto_matriz.n_filas){
        for(int i=0;i<a_producto_matriz.n_filas;i++)
          for(int j=0;j<a_producto_matriz.n_columnas;j++)
              producto.matriz[i][j]=matriz[i][j];
        return producto;
    }
    else{
        for(int i=0;i<a_producto_matriz.n_filas;i++)
            for(int j=0;j<a_producto_matriz.n_columnas;j++)
              for(int k =0;k<a_producto_matriz.n_columnas;k++)
                  producto.matriz[i][j]+=matriz[i][k]*a_producto_matriz.matriz[i][j];
        return producto;
    }
}


Matriz Matriz::calcularTraspuesta(){
    for(int i=0;i<n_filas;i++){
        for(int j=0; j<n_columnas; j++)
            matriz[i][j] = matriz[j][i];
    }
    return (*this);
}

bool Matriz::esSimetrica(){
    for(int i=0;i<n_filas;i++){
        for(int j=0; j<n_columnas; j++)
            if(matriz[i][j] != matriz[j][i])
                return false;
    }
    return true;
}

double Matriz::obtenerMaximo(){
    double maximo = matriz[0][0];
    for(int i=0;i<n_filas;i++){
        for(int j=0; j<n_columnas; j++)
            if(maximo < matriz[i][j])
                maximo = matriz[i][j];
    }
    return maximo;
}

double Matriz::obtenerMinimo(){
    double minimo = matriz[0][0];
    for(int i=0;i<n_filas;i++){
        for(int j=0; j<n_columnas; j++)
            if(minimo > matriz[i][j])
                minimo = matriz[i][j];
    }
    return minimo;
}

void Matriz::rellenarManual(){
    for(int i=0;i<n_filas;i++){
        for(int j=0; j<n_columnas; j++){
            cout << "Introduce el numero en la posicion fila: " << i+1 << " columna: " << j+1 << "\n";
            cin >> matriz[i][j];
        }
    }
}

void Matriz::rellenarAleatorio(long seed){
    srand(seed);
    for(int i=0;i<n_filas;i++){
        for(int j=0; j<n_columnas; j++)
            matriz[i][j] = rand();
    }
}

void Matriz::mostrarMatriz(){
    for(int i=0;i<n_filas;i++){
        for(int j=0; j<n_columnas; j++){
            cout << matriz[i][j] << " ";
        }
        cout << "\n";
    }
}

Matriz::~Matriz(){
    for(int i = 0; i<n_filas;i++)
        delete[] this->matriz[i];
    delete[] matriz;
}
