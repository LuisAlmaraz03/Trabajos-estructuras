#include <iostream>
using namespace std;

int main() {
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

    return 0;
}