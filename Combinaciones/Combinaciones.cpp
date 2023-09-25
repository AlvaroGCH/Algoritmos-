#include <iostream>

using namespace std;

int combinaciones(int n,int r){
    if(r==0 || r==n){
     return 1;
    }else{
     return combinaciones(n-1,r-1)+ combinaciones(n-1,r);
    }
}

int main()
{
    int n, r,salida=0;
   do{
        cin >> n;
        cin >> r;
        if(n > 0 && r > 0)
           cout << combinaciones(n,r) << endl;
        else if(n <0 || r <0)
            salida=1;
        else
            cout << "ERROR" << endl;
    }while(salida == 0);

}
