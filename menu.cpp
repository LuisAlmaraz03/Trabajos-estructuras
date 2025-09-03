#include<iostream>
#include "Ejercicios_Recursividad.h"
using namespace std;

int main() {
    int opc;
    cout<<"Menu de compilados\n";
    cout<<"1. Algortimos de Recursividad\n";
    cout<<"2. Algoritmos de Arreglos Unidimensionales"<<endl;
    cin>>opc;
    switch(opc) {
        int opc2;
    case 1:
        cout<<"Has seleccionado Algoritmos de Recursividad\nQue ejercicio quieres ejercutar?\n";
        cout<<"1. Suma de digitos de un numero entero\n";
        cout<<"2. Ipresion del 1 a N\n";
        cout<<"3. Conteo de numeros pares del 1 al N\n";
        cout<<"4. Impresion de numero de derecha a izquierda\n"<<endl;
        cin>>opc2;
        switch (opc2){
        case 1:
            Recusividad_1();
            break;
        case 2:
            Recursividad_2();
            break;
        case 3:
            Recursividad_3();
            break;
        case 4:
            Recursividad_4();
            break;
        default:
            cout<<"Opcion no valida"<<endl;
            break;
        }
        break;
    case 2:
        cout<<"Has seleccionado Algoritmos de Arreglos Unidimensionales"<<endl;
        break;
    default:
        cout<<"Opcion no valida"<<endl;
        break;
    }
}