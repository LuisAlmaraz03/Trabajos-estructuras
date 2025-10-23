#include<iostream>
using namespace std;
struct NodoCircular{
    int dato;
    NodoCircular* liga;
};
void crearListaporElFinal(NodoCircular *&P, NodoCircular* &Q){
    typedef NodoCircular* PNodo;
    PNodo aux;
    P=new NodoCircular;
    P->liga=nullptr;
    cout<<"Ingresa un numero para el primer nodo: "<<endl;
    cin>>P->dato;
    Q=P;
    char resp;
    cout<<"Ingresar mas elementos en la lista? (s/n): "<<endl;
    cin>>resp;
    while(resp=='s' || resp== 'S'){
        aux=Q;
        Q=new NodoCircular;
        Q->liga=nullptr;
        cout<<"Ingresa un numero para el siguiente nodo: "<<endl;
        cin>>Q->dato;
        aux->liga=Q;
        cout<<"Ingresar otro elemento en la lista? (s/n): "<<endl;
        cin>>resp;
    }
    Q->liga=P;
}
void imprimirListaCircular(NodoCircular* P){
    if (P==nullptr)
    {
        cout << "La lista esta vacia. No se puede imprimir." << endl;
        return; 
    }
    typedef NodoCircular* PNodo;
    PNodo aux = P;
    if (P == nullptr) return; // Lista vacia
    do {
        cout << aux->dato << " ";
        aux = aux->liga;
    } while (aux != P);
    cout << endl;
}
void eliminarPrimero(NodoCircular* &P, NodoCircular* &Q){
    typedef NodoCircular* PNodo;
    PNodo aux= P;
    if(P==nullptr){
        cout<<"La lista esta vacia"<<endl;
        return;
    }
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
void BuscarInformacion(NodoCircular *P){
    typedef NodoCircular* PNodo;
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
void insertarDatoAntesAOtro(NodoCircular *&P){
    if (P == nullptr) {
        cout << "La lista esta vacia. No se puede insertar antes de otro nodo." << endl;
        return;
    }
    int Dseleccion;
    typedef NodoCircular* PNodo;
    PNodo aux = P,T;
    PNodo Q = nullptr;
    Q= new NodoCircular;
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
void insertarAlPrincipio(NodoCircular *&P){
    if (P==nullptr)
    {
        cout << "La lista esta vacia. No se puede insertar al principio." << endl;
        return;
    }
    typedef NodoCircular* PNodo;
    PNodo Q= new NodoCircular;
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
void insertarAlFinal(NodoCircular *&P){
    if (P==nullptr)
    {
        cout << "La lista esta vacia. No se puede insertar al final." << endl;
        return;
    }
    typedef NodoCircular* PNodo;
    PNodo Q= new NodoCircular;
    PNodo aux= P;
    cout<<"Ingresa el nuevo dato para el nodo al final: "<<endl;
    cin>>Q->dato;
    while(aux->liga!= P){
        aux=aux->liga;
    }
    aux->liga=Q;
    Q->liga=P;
}
void eliminarEspecifico(NodoCircular *&P){
    if (P==nullptr){
        cout<<"La lista esta vacia"<<endl;
        return;
    }
    typedef NodoCircular* PNodo;
    PNodo aux= P, T;
    int elemento;
    cout<<"Ingresa el elemento a eliminar: "<<endl;
    cin>>elemento;
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


void menuCirculares(){
    typedef NodoCircular* PNodo;
    PNodo P = nullptr;
    PNodo Q = nullptr;
    int opcion;

    do {
        cout << "\n--- Menu Listas Circulares ---\n";
        cout << "1. Crear lista por el final\n";
        cout << "2. Imprimir lista\n";
        cout << "3. Insertar al principio\n";
        cout << "4. Insertar antes de otro\n";
        cout << "5. Insertar al final\n";
        cout << "6. Eliminar primero\n";
        cout << "7. Eliminar especifico\n";
        cout << "8. Buscar informacion\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                crearListaporElFinal(P, Q);
                break;
            case 2:
                imprimirListaCircular(P);
                break;
            case 3:
                insertarAlPrincipio(P);
                break;
            case 4:
                insertarDatoAntesAOtro(P);
                break;
            case 5:
                insertarAlFinal(P);
                break;
            case 6:
                eliminarPrimero(P, Q);
                break;
            case 7:
                eliminarEspecifico(P);
                break;
            case 8:
                BuscarInformacion(P);
                break;
            case 0:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion no valida\n";
                break;
        }
        system("pause");
    } while (opcion != 0);
}