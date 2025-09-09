#include<iostream>
#include "Ejercicios_Recursividad.h"
#include "Ejercicios_Arreglos.h"
#include "ArreglosBi.h"
using namespace std;

int main() {
    int opc;
    cout<<"Menu de compilados\n";
    cout<<"1. Algortimos de Recursividad\n";
    cout<<"2. Algoritmos de Arreglos Unidimensionales"<<endl;
    cout<<"3. Algoritmos de Arreglos Bidimensionales"<<endl;
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
        cout<<"Has seleccionado Algoritmos de Arreglos Unidimensionales\n";
        cout<<"1. Ordenand un arreglo de enteros MAX 8\n";
        cout<<"2. Localizador de carracter\n";
        cout<<"3. Suma de arreglos unidimensionales\n";
        cout<<"4. Promedio y desviacion estandar de calificacion\n";
        cout<<"5. Añadir y recorrer elementos en un vector\n";
        cout<<"6. Almacenamiento de pares e impares en arreglos\n";
        cout<<"7. Producto escalar de dos vectores\n"<<endl;
        cin>>opc2;
        switch (opc2)
        {
        case 1:
            Arreglo_1();
            break;
        case 2:
            Arreglo_2();
            break;
        case 3:
            Arreglo_3();
            break;
        case 4:
            Arreglo_4();
            break;
        case 5:
            Arreglo_5();
            break;
        case 6:
            Arreglo_6();
            break;
        case 7:
            Arreglo_7();
            break;
        default:
            cout<<"Opcion no valida"<<endl;
            break;
        }
        break;
       case 3:
       cout<<"Has seleccionado Algoritmos de Arreglos Bidimensionales\n";
       cout<<"1. Palindromo de una matriz\n";
       cout<<"2. Suma de matrices\n";
       cout<<"3. Columnas a una potencia\n";
       cout<<"4. Suma de Renglones\n";
       cout<<"5.Multiplicacion de matrices\n";
       cout<<"6.Determinante de una matriz 3x3\n";
       cout<<"7. Conteo de ceros, positivos y negativos en una matriz 5x4\n";
       cout<<"8.Mayor y menor en una matriz 4x4\n";
       cin>>opc2;
         switch (opc2){
        case 1:
            ArreglosBi_1();
            break;
        case 2:
            ArreglosBi_2();
            break;
        case 3:
            ArreglosBi_3();
            break;
        case 4:
            ArreglosBi_4();
            break;
        case 5:
            ArreglosBi_5(); 
            break;
        case 6:
            ArreglosBi_6();
            break;
        case 7:
            ArreglosBi_7();
            break;
        case 8:
            ArreglosBi_8(); 
            break;
        default:
            cout<<"Opcion no valida"<<endl;
            break;
         }
    

        default:
        cout<<"Opcion no valida"<<endl;
        break;
    }
}