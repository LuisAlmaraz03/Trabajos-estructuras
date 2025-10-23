#include<iostream>
using namespace std;
struct Nodo{
    int dato;
    Nodo* liga;
};
void crearListaporElFinal(Nodo *&P, Nodo* &Q){
    typedef Nodo* PNodo;
    PNodo aux;
    P=new Nodo;
    P->liga=nullptr;
    cout<<"Ingresa un numero para el primer nodo: "<<endl;
    cin>>P->dato;
    Q=P;
    char resp;
    cout<<"Ingresar mas elementos en la lista? (s/n): "<<endl;
    cin>>resp;
    while(resp=='s' || resp== 'S'){
        aux=Q;
        Q=new Nodo;
        Q->liga=nullptr;
        cout<<"Ingresa un numero para el siguiente nodo: "<<endl;
        cin>>Q->dato;
        aux->liga=Q;
        cout<<"Ingresar otro elemento en la lista? (s/n): "<<endl;
        cin>>resp;
    }
    Q->liga=P;
}
void imprimirListaCircular(Nodo* P){
    typedef Nodo* PNodo;
    PNodo aux = P;
    if (P == nullptr) return; // Lista vacia
    do {
        cout << aux->dato << " ";
        aux = aux->liga;
    } while (aux != P);
    cout << endl;
}
void eliminarPrimero(Nodo* &P, Nodo* &Q){
    typedef Nodo* PNodo;
    PNodo aux= P;
    if(P==nullptr) return; // Lista vacia
    if(P==Q){
        delete P;
        P=nullptr;
        Q=nullptr;
    }
    else{
        P=P->liga;
        Q->liga=P;
        delete aux;
    }

}
void BuscarInformacion(Nodo *P){
    typedef Nodo* PNodo;
    int elemento;
    cout<<"Ingresa el elemento a buscar"<<endl;
    cin>>elemento;
    PNodo aux=P;
    PNodo T= aux;
    bool encontrado=false;
    while(aux!=nullptr){
        if(aux->dato==elemento){
            encontrado=true;
            break;
        }
        T=aux;
        aux=aux->liga;
        }
    if(encontrado==true){
        cout<<"La direccion del elemento antecedente es "<<T<<endl;
        cout<<"La informacion del elemento consecuente es "<<aux->liga->dato<<endl;
    }
    else{
        cout<<"El elemento no fue encontrado en la lista"<<endl;
}
}
void insertarDatoAntesAOtro(Nodo *&P){
    if (P == nullptr) {
        cout << "La lista esta vacia. No se puede insertar antes de otro nodo." << endl;
        return;
    }
    int Dseleccion;
    typedef Nodo* PNodo;
    PNodo aux = P,T;
    PNodo Q = nullptr;
    Q= new Nodo;
    cout<<"Valor a ingresar?\n";
    cin>>Q->dato;
    cout<<"Antes de que valor quires insertar el nuevo dato?\n";
    cin>>Dseleccion;

    while(aux->liga!= P){
        T=aux;
        aux=aux->liga;
        if(aux->dato == Dseleccion){
            T->liga=Q;
            Q->liga=aux;
            return;
        }
    }
    if (P->dato == Dseleccion) {
        T=aux;
        aux=P;
        Q->liga=P;
        T->liga=Q;
        P=Q;
    }
    else{
        cout << "El valor especificado no se encontro en la lista." << endl;
    }
}
void insertarAlPrincipio(Nodo *&P){
    typedef Nodo* PNodo;
    PNodo Q= new Nodo;
    PNodo aux= P, T;
    cout<<"Ingresa el nuevo dato para el nodo al principio: "<<endl;
    cin>>Q->dato;
    while(aux->liga!= P){
        T=aux;
        aux=aux->liga;
    }
    T=aux;
    aux=P;
    Q->liga=P;
    T->liga=Q;
    P=Q;
}
void insertarAlFinal(Nodo *&P){
    typedef Nodo* PNodo;
    PNodo Q= new Nodo;
    PNodo aux= P;
    cout<<"Ingresa el nuevo dato para el nodo al final: "<<endl;
    cin>>Q->dato;
    while(aux->liga!= P){
        aux=aux->liga;
    }
    aux->liga=Q;
    Q->liga=P;
}
void eliminarEspecifico(Nodo *&P){
    typedef Nodo* PNodo;
    PNodo aux= P, T;
    int elemento;
    cout<<"Ingresa el elemento a eliminar: "<<endl;
    cin>>elemento;
    if (P==nullptr){
        cout<<"La lista esta vacia"<<endl;
        return;
    }
    while(aux->liga!= P){
        T=aux;
        aux=aux->liga;
        if(aux->dato==elemento){
            T->liga=aux->liga;
            delete aux;
            return;
        }
    }
    if (P->dato==elemento){
        T=aux;
        aux=P;
        P=P->liga;
        T->liga=P;
        aux->liga==aux?P=nullptr:0;
        delete aux;
        return;
    }
    else{
        cout<<"Elemento no encontrado en la lista."<<endl;
    }
}


int main(){
    typedef Nodo* PNodo;
    PNodo P=nullptr;
    PNodo Q=nullptr;
    crearListaporElFinal(P,Q);
    imprimirListaCircular(P);
    eliminarEspecifico(P);
    imprimirListaCircular(P);
}