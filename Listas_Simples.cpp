#include<iostream>
using namespace std;
struct Nodo{
        int dato;
        Nodo* liga;
    };

void crearListaInicio(Nodo* &P, Nodo* &Q);
void imprimirLista(Nodo* P);
void eliminarUltimo(Nodo* &P, Nodo* &Q);
void crearListaFinal(Nodo* &P, Nodo* &Q);

int main(){
    typedef Nodo* PNodo;
    PNodo P=nullptr;
    PNodo Q=nullptr;
    crearListaFinal(P,Q);
    imprimirLista(P);

}

void crearListaInicio(Nodo* &P, Nodo* &Q){
    typedef Nodo* PNodo;
    char resp;
    P=new Nodo;
    cout<<"Ingresa un numero para el primer nodo: "<<endl;
    cin>>P->dato;
    P->liga=nullptr;
    cout<<"Existen mas elementos en la lista? (s/n): "<<endl;
    cin>>resp;
    while(resp=='s'||resp=='S'){
        Q=new Nodo;
        cout<<"Ingresa un numero para el siguiente nodo: "<<endl;
        cin>>Q->dato;
        Q->liga=P;
        P=Q;
        cout<<"Existen mas elementos en la lista? (s/n): "<<endl;
        cin>>resp;
    }
}

void imprimirLista(Nodo* P){
    typedef Nodo* PNodo;
    cout << "Elementos de la lista:" << endl;
    PNodo aux = P;
    while(aux != nullptr){
        cout << aux->dato << " ";
        aux = aux->liga;
    }  
}

void eliminarUltimo(Nodo* &P, Nodo* &Q){
    typedef Nodo* PNodo;
    PNodo aux;
    aux= P;
    while (aux->liga->liga!=NULL) {
        aux=aux->liga;
    }
    delete aux->liga;
    aux->liga=NULL;
}

void crearListaFinal(Nodo* &P, Nodo* &Q){
    typedef Nodo* PNodo;
    char resp;
    P=new Nodo;
    PNodo aux;
    P->liga=nullptr;
    cout<<"Ingresa un numero para el primer nodo: "<<endl;
    cin>>P->dato;
    Q=P;
    cout<<"Ingresar mas elementos en la lista? (s/n): "<<endl;
    cin>>resp;
    while (resp == 's' || resp == 'S'){
        aux=Q;
        Q=new Nodo;
        Q->liga=nullptr;
        cout<<"Ingresa un numero para el siguiente nodo: "<<endl;
        cin>>Q->dato;
        Q->liga=nullptr;
        aux->liga=Q;
        cout<<"Ingresar otro elemento en la lista? (s/n): "<<endl;
        cin>>resp;
    }
}