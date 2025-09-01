#include <iostream>
using namespace std;

int main() {
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
    return 0;
}