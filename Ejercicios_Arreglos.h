#include <iostream>
using namespace std;

void Arreglos_1() {
    int arr[8];
    cout << "Ingrese 8 números enteros:" << endl;
    for (int i = 0; i < 8; ++i) {
        cin >> arr[i];
    }

    for (int i = 1; i < 8; ++i) {
        if(arr[i]<arr[i-1]){
            int temp = arr[i];
            arr[i] = arr[i-1];
            arr[i-1] = temp;
            i=0;
        }
    }

    cout << "Arreglo ordenado: ";
    for (int i = 0; i < 8; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Arreglos_2() {
    const int TAM = 14;
    cout << "Ingrese una palabra de 14 caracteres: ";
    string pal;
    cin>> pal;
    char buscar;
    cout << "Ingrese el caracter a buscar: ";
    cin >> buscar;

    bool encontrado = false;
    for (int i = 0; i < TAM; ++i) {
        if (pal[i] == buscar) {
            cout << "El caracter '" << buscar << "' se encuentra en la posicion " << ++i << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "DATO NO LOCALIZADO" << endl;
    }
}