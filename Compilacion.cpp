#include<iostream>
using namespace std;
struct NodoDoble{
        int dato;
        NodoDoble* ligaD;
        NodoDoble* ligaI;
};

bool crarListaFinal(NodoDoble* &P, NodoDoble* &Q, bool &verificador);
void imprimirLista(NodoDoble* P);
bool eliminarUltimo(NodoDoble* &P ,NodoDoble* &Q, bool &verificador);

int main(){
    typedef NodoDoble* PNodo;
    PNodo P=nullptr;
    PNodo Q=nullptr;
    bool verificador=false;
    char resp='s';
    crarListaFinal(P,Q,verificador);
    imprimirLista(P);
    eliminarUltimo(P,Q,verificador);
    imprimirLista(P);
}
bool crarListaFinal(NodoDoble* &P, NodoDoble* &Q, bool &verificador){
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