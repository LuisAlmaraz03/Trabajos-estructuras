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
void insertarEnABB(NodoRaiz* &nodo, const int elemento){
    if(nodo == nullptr){
       nodo = new NodoRaiz;
       nodo->dato = elemento;
       nodo->izquierda = nodo->derecha = nullptr;
    }
    else if (elemento < nodo->dato){
        insertarEnABB(nodo->izquierda,elemento);
    }
    else{
        insertarEnABB(nodo->derecha,elemento);
}
}
void buscarEnABB(NodoRaiz* nodo , const int elemento){
    if(nodo == nullptr){
        cout<<"El elemento"<<elemento<<" no se encuentra en el arbol."<<endl;
        return;
    }
    else if(nodo->dato == elemento){
       cout<<"El elemento"<<elemento<<" SE ENCUENTRA EN EL ARBOL"<<endl;
       return;

    }
    else if(elemento < nodo->dato){
        buscarEnABB(nodo->izquierda,elemento);
    }
    else{
        buscarEnABB(nodo->derecha,elemento);
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

NodoRaiz* encontrarMin(NodoRaiz* nodo){
    if (nodo == nullptr) return nullptr;
    while (nodo->izquierda != nullptr) nodo = nodo->izquierda;
    return nodo;
}

void eliminarEnABB(NodoRaiz* &nodo, const int elemento){
    if (nodo == nullptr) return;
    if (elemento < nodo->dato){
        eliminarEnABB(nodo->izquierda, elemento);
    } else if (elemento > nodo->dato){
        eliminarEnABB(nodo->derecha, elemento);
    } else {
        // Nodo encontrado
        if (nodo->izquierda == nullptr && nodo->derecha == nullptr){
            delete nodo;
            nodo = nullptr;
        } else if (nodo->izquierda == nullptr){
            NodoRaiz* aux = nodo;
            nodo = nodo->derecha;
            delete aux;
        } else if (nodo->derecha == nullptr){
            NodoRaiz* aux = nodo;
            nodo = nodo->izquierda;
            delete aux;
        } else {
            NodoRaiz* sucesor = encontrarMin(nodo->derecha);
            nodo->dato = sucesor->dato;
            eliminarEnABB(nodo->derecha, sucesor->dato);
        }
    }
}

int main(){
    NodoRaiz* raiz = nullptr;
    char continuar='s';
    int opc1=0;
    do
    {
        cout<<"Que quires realizar?\n";
        cout<<"1. Cargar dato\n";
        cout<<"2. Imprimir datos en preorden\n";
        cout<<"3. Imprimir datos en inorden\n";
        cout<<"4. Imprimir datos en posorden"<<endl;
        cout<<"5. Cargar elementos en ABB"<<endl;
        cout<<"6. Buscar elemento en ABB"<<endl;
        cout<<"7. Eliminar elemento en ABB"<<endl;
        cin>>opc1;
        switch (opc1)
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
        case 5:
        int dato2;
          cout<<"Ingresa el nuevo dato para ABB"<<endl;
          cin>>dato2;
          insertarEnABB(raiz,dato2);
          break;
          case 6:
          int dato3;
          cout<<"Ingresa el dato a buscar en ABB"<<endl;
          cin>>dato3;
          buscarEnABB(raiz,dato3);
          break;      
          case 7:
          int dato4;
          cout<<"Ingresa el dato a eliminar en ABB"<<endl;
          cin>>dato4;
          eliminarEnABB(raiz,dato4);
          cout<<"Si el elemento existia, fue eliminado."<<endl;
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