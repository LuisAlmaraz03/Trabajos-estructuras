#include <iostream>
using namespace std;
struct NodoRaiz{
    int dato;
    NodoRaiz* izquierda;
    NodoRaiz* derecha;
};

void cargar(NodoRaiz* &nodo, const int elemento){
    system("cls");
    if (nodo != nullptr){
        int opc;
        cout<<"Este nodo ya contiene un elemento.\n";
        cout<<"En que lado quieres ingresar el nuevo dato?\n1. Izquierda\n2. Derecha"<<endl;
        cin>>opc;
        switch (opc)
        {
        case 1:
            cargar(nodo->izquierda, elemento);
            break;
        case 2:
            cargar(nodo->derecha, elemento);
            break;
        default:
            cout<<"Esta opcion no es valida. Selecciona una opcion valida";
            system("pause");
            cargar(nodo,elemento);
            break;
        }
    }else{
        nodo = new NodoRaiz;
        nodo->dato = elemento;
        nodo->izquierda = nodo->derecha = nullptr;
        return;
    }
}

void imprimirPreorden(NodoRaiz* nodo){
    if (nodo != nullptr){
        cout << nodo->dato << " ";
        imprimirPreorden(nodo->izquierda);
        imprimirPreorden(nodo->derecha);
    }
}
void imprimirInorden(NodoRaiz* nodo){
    if (nodo != nullptr){
        imprimirInorden(nodo->izquierda);
        cout << nodo->dato << " ";
        imprimirInorden(nodo->derecha);
    }
}
void imprimirPosorden(NodoRaiz* nodo){
    if (nodo != nullptr){
        imprimirPosorden(nodo->izquierda);
        imprimirPosorden(nodo->derecha);
        cout << nodo->dato << " ";
    }
}

int main(){
    NodoRaiz* raiz = nullptr;
    char continuar='s';
    int opc=0;
    do
    {
        cout<<"Que quires realizar?\n";
        cout<<"1. Cargar dato\n";
        cout<<"2. Imprimir datos en preorden\n";
        cout<<"3. Imprimir datos en inorden\n";
        cout<<"4. Imprimir datos en posorden"<<endl;
        cin>>opc;
        switch (opc)
        {
        case 1:
            int dato;
            cout<<"Ingresa el nuevo dato"<<endl;
            cin>>dato;
            cargar(raiz,dato);
            break;
        case 2:
            cout<<"Los datos en preorden son: "<<endl;
            imprimirPreorden(raiz);
            system("pause");
            break;
        case 3:
            cout<<"Los datos en inorden son: "<<endl;
            imprimirInorden(raiz);
            system("pause");
            break;
        case 4:
            cout<<"Los datos en posorden son: "<<endl;
            imprimirPosorden(raiz);
            system("pause");
            break;        
        default:
            break;
        }

        cout<<"Hacer otra accion?[S/N]"<<endl;
        cin>>continuar;
    } while (continuar== 's' || continuar=='S');
    return 0;
}