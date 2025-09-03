#include <iostream>
using namespace std;   

int Recursividad(int n, int resp) {
    if (n ==0) {
        return resp;
    } else {
        resp += n % 10;
        n /= 10;
        return Recursividad(n, resp);
    }
}

void sucesion(int n) {
    if (n == 0) return;        
    sucesion(n - 1);           
    cout << n << " \n";          
}

int contar(int n){
    if(n==0){
        return 0;
    }
    else if (n%2==0){
    return 1+contar(n-1);
    }
    else if(n%2!=0){
        return contar(n-1);
    }
}

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

void Recusividad_1() {
    int n = 0, resp = 0;
    cout<<"Ingrese un numero: ";
    cin >> n;
    int ans = Recursividad(n, resp);
    cout << "\nEl resultado de la suma es "<<ans;
}


void Recursividad_2() {
    int N;
    cout << "Ingresa un número: ";
    cin >> N;


    sucesion(N);
    cout << endl;
}


void Recursividad_3 (){
    int n;
    cout<<"Ingrese un numero: ";
    cin>>n;
    cout<<"el numero de pares es: "<<contar(n); 
}


void Recursividad_4() {
    int n;
    cin >> n;
    
    if (n < 0) {
        cout << "-";
        n = -n;
    }
    
    cout << invertirNumero(n);
}