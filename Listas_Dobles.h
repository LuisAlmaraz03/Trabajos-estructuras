#include<iostream>
using namespace std;
struct NodoDoble{
        int dato;
        NodoDoble* ligaD;
        NodoDoble* ligaI;
    };
void menuListDoble();
void imprimirLista(NodoDoble* P);
bool crearListaFinal(NodoDoble* &P, NodoDoble* &Q, bool &verificador);
bool eliminarUltimo(NodoDoble* &P ,NodoDoble* &Q, bool &verificador);

void menuListDoble(){
    typedef NodoDoble* PNodo;
    PNodo P=nullptr;
    PNodo Q=nullptr;
    bool verificador=false;
    char resp='s';
    int opc;
    while (resp=='s'||resp=='S'){
        system("cls");
        cout<<"Listas Simples\n";
        cout<<"Que deseas hacer?\n";
        cout<<"1. Crear lista que agregue los elementos al inicio\n";
        cout<<"2. Crear lista que agregue los elementos al final\n";
        cout<<"3. Imprimir lista\n";
        cout<<"4. Eliminar ultimo elemento de la lista\n";
        cout<<"5. Buscar un elemento en la lista\n";
        cout<<"6. Agregar un solo elemento al inicio de la lista existente\n";
        cout<<"7. Agregar un solo elemento al final de la lista existente\n";
        cout<<"8. Eliminar el primer elemento de la lista\n";
        cout<<"9. Eliminar un dato especifico de la lista\n";
        cout<<"10 Agegar un dato antes de otro\n";
        cout<<"11 Agregar un dato despues de otro\n";
        cout<<"12 Eliminar un dato antes de otro\n";
        cout<<"13 Eliminar un dato despues de otro"<<endl;
        cin>>opc;
        if(opc == 1 || opc == 2)
            {
                verificador=true;
            }
        while(verificador!=true){
            cout<<"No hay lista creado, crea una lista para poder relizar la accion seleccionada (1 o 2)\n";
            cin>>opc;
            if(opc == 1 || opc == 2)
            {
                verificador=true;
            }
        }
        switch(opc){
            case 1:
                //crearListaInicio(P,Q,verificador);
                break;
    
            case 2:
                crearListaFinal(P,Q,verificador);
                break;
    
            case 3:
                imprimirLista(P);
                break;
    
            case 4:
                eliminarUltimo(P,Q,verificador);
                break;

            default:
                cout<<"Opcion no valida"<<endl;
                break;
        }
        cout<<"\nDeseas continuar? (s/n)"<<endl;
        cin>>resp;
    }
}

bool crearListaFinal(NodoDoble* &P, NodoDoble* &Q, bool &verificador){
    typedef NodoDoble* PNodo;
    PNodo aux;
    char resp;
    P= new NodoDoble;
    P->ligaD=nullptr;
    P->ligaI=nullptr;
    cout<<"Ingresa un dato para el primer nodo\n";
    cin>>P->dato;
    cout<<"Quires ingresar otro dato?[S/N]\n";
    cin>>resp;
    Q=P;
    while (resp=='S' || resp=='s')
    {
        aux=Q;
        Q=new NodoDoble;
        Q->ligaI=aux;
        Q->ligaD=nullptr;
        cout<<"Ingresa el nuevo dato\n";
        cin>>Q->dato;
        aux->ligaD=Q;
        cout<<"Quires ingresar otro dato?[S/N]\n";
        cin>>resp;
    }
    return verificador=true;   
}
void imprimirLista(NodoDoble* P){
    typedef NodoDoble* PNodo;
    cout << "Elementos de la lista:" << endl;
    PNodo aux = P;
    while(aux != nullptr){
        cout << aux->dato << " ";
        aux = aux->ligaD;
    }  
}
bool eliminarUltimo(NodoDoble* &P ,NodoDoble* &Q, bool &verificador){
    typedef NodoDoble* PNodo;
    PNodo aux;
    if (Q==P){
        delete P;
        P=nullptr;
        Q=nullptr;
        return verificador=false;
    }
    else{
        aux=Q->ligaI;
        aux->ligaD= nullptr;
        delete Q;
        Q=aux;
        return verificador=true;
    }
}