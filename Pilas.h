#include <iostream>
using namespace std;

struct NodoPila
{
    int dato;
    NodoPila* liga;
};

void push(NodoPila*& tope, int valor)
{
    NodoPila* nuevo = new NodoPila();
    nuevo->dato = valor;
    nuevo->liga = tope;
    tope = nuevo;
}

void pop(NodoPila*& tope)
{
    if (tope != nullptr)
    {
        NodoPila* aux = tope;
        tope = tope->liga;
        delete aux;
    }
    else
    {
        cout << "La pila esta vacia, no se puede hacer pop." << endl;
    }
}

void mostrarPila(NodoPila* tope)
{
    NodoPila* aux = tope;
    while (aux != nullptr)
    {
        cout << aux->dato << " ";
        aux = aux->liga;
    }
    cout << endl;
}

void menuPilas(){
    NodoPila* pila = nullptr;
    int opcion, valor;

    do {
        cout << "Menu de la Pila:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Mostrar Pila\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
            case 1:
                cout << "Ingrese un valor para push: ";
                cin >> valor;
                push(pila, valor);
                break;
            case 2:
                pop(pila);
                break;
            case 3:
                cout << "Contenido de la pila: ";
                mostrarPila(pila);
                break;
            case 4:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
        }
        system("pause");
    } while (opcion != 4);

    while (pila != nullptr)
    {
        pop(pila);
    }
}