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
<<<<<<< HEAD
void insertarDatoDespuesAOtro(Nodo* &P);
void eliminarAnteriorAOtro(Nodo *&P);
=======
void insertarDatoDespuesdeOtro(Nodo *&P);
void eliminarNodoAntesdeOtro(Nodo *&P);
void eliminarNodoDespuesDeOtro(Nodo *&P);
>>>>>>> dabe2f75fde5c7f0c30207f5dc3f756324766ba0

int main(){
    typedef Nodo* PNodo;
    PNodo P=nullptr;
    PNodo Q=nullptr;
    bool verificador=false;
    char resp='s';
    int opc;
    crearListaFinal(P,Q,verificador);
    imprimirLista(P);
<<<<<<< HEAD
    eliminarAnteriorAOtro(P);
=======
    eliminarNodoDespuesDeOtro(P);
    //eliminarNodoAntesdeOtro(P);
>>>>>>> dabe2f75fde5c7f0c30207f5dc3f756324766ba0
    imprimirLista(P);
    //eliminarCoincidencia(P);
    //imprimirLista(P);
    //insertarDatoDespuesdeOtro(P);
    //insertarDato(P);
    //imprimirLista(P);
    //insertarDato(P);
    //imprimirLista(P);
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
<<<<<<< HEAD

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
=======
void insertarDatoDespuesdeOtro(Nodo *&P)
{
    int Dseleccion;
    typedef Nodo* PNodo;
    PNodo aux = P, T;
    T= new Nodo;
    cout<<"Valor a ingresar?\n";
    cin>>T->dato;
    cout<<"Despues de que valor quires insertar el nuevo dato?\n";
    cin>>Dseleccion;

    while(aux != nullptr){
        if(aux->dato == Dseleccion){
            T->liga=aux->liga;
            aux->liga=T;
            break;
        }
        aux=aux->liga;
    }
}
void eliminarNodoAntesdeOtro(Nodo *&P)
{
    int Dseleccion;
    typedef Nodo* PNodo;
    PNodo aux = P, Q = nullptr, R = nullptr;
    cout<<"Valor antes del cual se eliminara el nodo?\n";
    cin>>Dseleccion;

    if (P != nullptr && P->dato == Dseleccion) {
        cout << "No hay nodo antes del primer nodo." << endl;
        return;
    }
    while(aux != nullptr && aux->dato != Dseleccion){
        R = Q;
        Q = aux;
        aux = aux->liga;
    }
    if (aux != nullptr && Q != nullptr) {
        if (R == nullptr) {
            P = aux; 
        } else {
            R->liga = aux; 
        }
        delete Q; 
    } else {
        cout << "No se encontro el valor especificado en la lista." << endl;
    }
}
void eliminarNodoDespuesDeOtro(Nodo *&P){
    int Dseleccion;
    typedef Nodo* PNodo;
    PNodo aux = P, Q=nullptr, R=nullptr;
    cout<<"Ingresa el valor a eliminar"<<endl;
    cin>>Dseleccion;
    if(P != nullptr && P->dato == Dseleccion){
        Q= P->liga;
        if(Q != nullptr){
            P->liga = Q->liga;
            delete Q;
        }
        else{
            cout<<"No hay nodo despues del primer nodo"<<endl;
        }
}
    while(aux != nullptr && aux->dato != Dseleccion){
            R=aux;
            aux=aux->liga;
        }
        if(R != nullptr){
            R=aux->liga;
            if(R != nullptr){
                aux->liga=R->liga;
                delete R;
            }
            else{
                cout<<"No hay nodo despues de este nodo"<<endl;
            }
    }
}
>>>>>>> dabe2f75fde5c7f0c30207f5dc3f756324766ba0
