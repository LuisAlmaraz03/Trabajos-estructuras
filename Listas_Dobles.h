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
bool eliminarCoincidencia(NodoDoble* &P,NodoDoble* &Q,bool &veficador);

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
        cout<<"1. Crear lista que agregue los elementos al final\n";
        cout<<"2. Imprimir lista\n";
        cout<<"3. Eliminar ultimo elemento de la lista\n";
        cout<<"4. Eliminar un elemento especifico en la lista\n";
        cin>>opc;
        if(opc == 1)
            {
                verificador=true;
            }
        while(verificador!=true){
            cout<<"No hay lista creado, crea una lista para poder relizar la accion seleccionada (1)\n";
            cin>>opc;
            if(opc == 1)
            {
                verificador=true;
            }
        }
        switch(opc){
            case 1:
                crearListaFinal(P,Q,verificador);
                break;
    
            case 2:
                imprimirLista(P);
                break;
    
            case 3:
                eliminarUltimo(P,Q,verificador);
                break;
    
            case 4:
                eliminarCoincidencia(P,Q,verificador);
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
bool eliminarCoincidencia(NodoDoble* &P,NodoDoble* &Q,bool &veficador){
    typedef NodoDoble* PNodo;
    int eliminado;
    PNodo aux;
    aux=P;
    cout<<"Ingresa el elemento que quieres eliminar\n";
    cin>>eliminado;
    while (aux!=nullptr && aux->dato!=eliminado){
        aux=aux->ligaD;
    }
    if(aux==nullptr){
        cout<<eliminado<<" No existe en la lista"<<endl;
    }
    else if (aux==P && P==Q){
        delete aux;
        P=nullptr;
        Q=nullptr;
        return veficador=false;
    }
    else if(aux==P){
        P=P->ligaD;
        P->ligaI=nullptr;
        delete aux;
    }
    else if(aux==Q){
        Q=Q->ligaI;
        Q->ligaD=nullptr;
        delete aux;
    }
    else{
        aux->ligaI->ligaD=aux->ligaD;
        aux->ligaD->ligaI=aux->ligaI;
        delete aux;
    }
    return veficador=true;
}