#include <iostream>
#include <string.h>
using namespace std;

bool palindromo(char array[], int inicio, int final){
    if(inicio <= final)
        return true;
    else if(array[inicio]==array[final])
        return palindromo(array, inicio+1,final-1);
    else
        return false;
}

int main()
{
    char array[] = "anilina";
    if(palindromo(array, 0, strlen(array)) == true)
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return palindromo(array, 0, strlen(array));
}
