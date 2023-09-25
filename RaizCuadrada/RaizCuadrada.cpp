#include <iostream>

using namespace std;

float RaizCuadrada(float calcular, float error, float valor){
    if(valor*valor > calcular - error && valor*valor < calcular + error){
        return valor;
    }
    else if(valor*valor > calcular + error){
        return RaizCuadrada(calcular,error, valor/2);
    }
    else if(valor*valor < calcular - error)
        return RaizCuadrada(calcular,error, valor+valor/2);
}

int main()
{
    float calcular, error;
    cin >> calcular;
    cin >> error;
    if(calcular>0 && error>0)
        cout << RaizCuadrada(calcular,error, calcular/2);
    else
        cout << "ERROR";
    return 0;
}

