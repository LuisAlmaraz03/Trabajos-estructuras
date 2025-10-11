#include<iostream>
using namespace std;
struct Nodo{
        int dato;
        Nodo* ligaD;
        Nodo* ligaI;
};

bool crarListaFinal(Nodo* &P, Nodo* &Q, bool &verificador);
void imprimirLista(Nodo* P);

int main(){
    typedef Nodo* PNodo;
    PNodo P=nullptr;
    PNodo Q=nullptr;
    bool verificador=false;
    char resp='s';
    crarListaFinal(P,Q,verificador);
    imprimirLista(P);
}
bool crarListaFinal(Nodo* &P, Nodo* &Q, bool &verificador){
    typedef Nodo* PNodo;
    PNodo aux;
    char resp;
    P= new Nodo;
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
        Q=new Nodo;
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
void imprimirLista(Nodo* P){
    typedef Nodo* PNodo;
    cout << "Elementos de la lista:" << endl;
    PNodo aux = P;
    while(aux != nullptr){
        cout << aux->dato << " ";
        aux = aux->ligaD;
    }  
}