#include <iostream>
using namespace std;

int contarDigitos(int n) {
    if (n < 10 && n > -10) {
        return 1;
    }
    return 1 + contarDigitos(n / 10);
}

int potencia10(int exp) {
    if (exp == 0) {
        return 1;
    }
    return 10 * potencia10(exp - 1);
}

int invertirRecursivo(int n, int potencia) {
    if (n < 10 && n > -10) {
        return n;
    }
    
    int ultimoDigito = n % 10;
    int numeroSinUltimo = n / 10;
    
    return ultimoDigito * potencia + invertirRecursivo(numeroSinUltimo, potencia / 10);
}

int invertirNumero(int n) {
    if (n == 0) return 0;
    
    int digitos = contarDigitos(n);
    int potencia = potencia10(digitos - 1);
    
    return invertirRecursivo(n, potencia);
}

int main() {
    int n;
    cin >> n;
    
    if (n < 0) {
        cout << "-";
        n = -n;
    }
    
    cout << invertirNumero(n);
    return 0;
}