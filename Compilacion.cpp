#include<iostream>
using namespace std;
struct Nodo{
        int dato;
        Nodo* liga;
};

void eliminarCoincidencia(Nodo* &P);
bool crearListaFinal(Nodo* &P, Nodo* &Q,bool &verificador);
void imprimirLista(Nodo* &P);
void insertarDato(Nodo *&P);
void insertarDatoDespuesAOtro(Nodo* &P);
void eliminarAnteriorAOtro(Nodo *&P);

int main(){
    typedef Nodo* PNodo;
    PNodo P=nullptr;
    PNodo Q=nullptr;
    bool verificador=false;
    char resp='s';
    int opc;
    crearListaFinal(P,Q,verificador);
    imprimirLista(P);
    eliminarAnteriorAOtro(P);
    imprimirLista(P);
}

bool crearListaFinal(Nodo* &P, Nodo* &Q,bool &verificador){
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
    return verificador=true;
}

void eliminarCoincidencia(Nodo *&P){
    int eliminado;
    typedef Nodo* PNodo;
    PNodo aux = P;
    PNodo Q = nullptr;
    cout<<"Valor a eliminar?\n";
    cin>>eliminado;
    if (aux->liga != nullptr && aux->dato == eliminado) {
        P=P->liga;
    }
    else{
        while(aux!=nullptr){
            if(aux->dato==eliminado){
                Q->liga=aux->liga;
                delete aux;
                break;
            }
            Q=aux;
            aux=aux->liga;
        }
    }
}

void insertarDato(Nodo *&P)
{
    int Dseleccion;
    typedef Nodo* PNodo;
    PNodo aux = P, T;
    PNodo Q = nullptr;
    T= new Nodo;
    cout<<"Valor a ingresar?\n";
    cin>>T->dato;
    cout<<"Antes de que valor quires insertar el nuevo dato?\n";
    cin>>Dseleccion;

    if (P!= nullptr && P->dato == Dseleccion) {
        T->liga=P;
        P=T;
        return;
    }
    else{
        while(aux->liga != nullptr){
            Q=aux;
            aux=aux->liga;
            if(aux->dato == Dseleccion){
                Q->liga=T;
                T->liga=aux;
            }
        }
    }
}

void insertarDatoDespuesAOtro(Nodo *&P){
    typedef Nodo* PNodo;
    PNodo aux, Q;
    int encontrar=0;
    aux=P;
    Q= new Nodo;
    cout<<"Ingresa el nuevo dato\n";
    cin>>Q->dato;
    cout<<"Despues de que dato lo ingresaras?\n";
    cin>>encontrar;
    while (aux!=nullptr && aux->dato!=encontrar){
        aux=aux->liga;
    }
    if (aux==nullptr){
        cout<<"No existe "<<encontrar<<" en la lista\n";
    }
    else if(aux->liga==nullptr && aux==P){
        P->liga=Q;
        Q->liga=nullptr;
    }
    else{
        Q->liga=aux->liga;
        aux->liga=Q;
    }
}

void imprimirLista(Nodo* &P){
    typedef Nodo* PNodo;
    cout << "Elementos de la lista:" << endl;
    PNodo aux = P;
    while(aux != nullptr){
        cout << aux->dato << " ";
        aux = aux->liga;
    }  
}

void eliminarAnteriorAOtro(Nodo *&P){
    typedef Nodo* PNodo;
    PNodo aux=P, Q=nullptr, T;
    int encontrar = 0;
    cout<<"Ingresa antes de cual dato quires eliminar\n";
    cin>>encontrar;
    while (aux!=nullptr && aux->dato!=encontrar){
        T=Q;
        Q=aux;
        aux=aux->liga;
    }
    if (aux==nullptr){
        cout<<"No existe "<<encontrar<<" en la lista\n"<<endl;
    }
    else if(aux==P){
        cout<<"No existe un dato anterior al primer elemento\n"<<endl;
    }
    else if(aux==P->liga){
        P=aux;
        delete Q;
    }
    else{
        T->liga=aux;
        delete Q;
    }
}