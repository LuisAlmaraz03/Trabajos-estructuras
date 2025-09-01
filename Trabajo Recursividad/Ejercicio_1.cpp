#include <iostream>
using namespace std;    
int Recursividad(int n, int resp) {
    if (n ==0) {
        return resp;
    } else {
        resp += n % 10;       // tomar el último dígito
        n /= 10;              // eliminar el último dígito
        return Recursividad(n, resp);
    }
}

int main() {
    int n = 0, resp = 0;
    cout<<"Ingrese un numero: ";
    cin >> n;
    int ans = Recursividad(n, resp);
    cout << "\nEl resultado de la suma es "<<ans;
    return 0;
}