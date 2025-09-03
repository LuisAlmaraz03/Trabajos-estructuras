#include<iostream>
using namespace std;
int main() {
    int opc;
    cout<<"Menu de compilados"<<endl;
    cout<<"1. Algortimos de Recursividad"<<endl;
    cout<<"2. Algoritmos de Arreglos Unidimensionales"<<endl;
    cin>>opc;
    switch(opc) {
    case 1:
        cout<<"Has seleccionado Algoritmos de Recursividad"<<endl;
        break;
    case 2:
        cout<<"Has seleccionado Algoritmos de Arreglos Unidimensionales"<<endl;
        break;
    default:
        cout<<"Opcion no valida"<<endl;
        break;
    }
}