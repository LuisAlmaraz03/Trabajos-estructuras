#include<iostream>
using namespace std;
struct Nodo{
        int dato;
        Nodo* liga;
    };
void menu();
bool crearListaInicio(Nodo* &P, Nodo* &Q,bool &verificador);
void imprimirLista(Nodo* P);
bool eliminarUltimo(Nodo* &P, bool &verificador);
bool crearListaFinal(Nodo* &P, Nodo* &Q,bool &verificador);
void BuscarElemento(Nodo *P);
void agregarUnSoloElementoaListaExistente(Nodo* &P);
void AgregarUnSoloElementoAlFinalDeLaListaExistente(Nodo* &P);
bool eliminarPrimero(Nodo* &P, bool &verificador);
void menu(){
    typedef Nodo* PNodo;
    PNodo P=nullptr;
    PNodo Q=nullptr;
    bool verificador=false;
    char resp='s';
    int opc;
    while (resp=='s'||resp=='S'){
        system("cls");
        cout<<"Listas Simples"<<endl;
        cout<<"Que deseas hacer?"<<endl;
        cout<<"1. Crear lista que agregue los elementos al inicio"<<endl;
        cout<<"2. Crear lista que agregue los elementos al final"<<endl;
        cout<<"3. Imprimir lista"<<endl;
        cout<<"4. Eliminar ultimo elemento de la lista"<<endl;
        cout<<"5. Buscar un elemento en la lista"<<endl;
        cout<<"6. Agregar un solo elemento al inicio de la lista existente"<<endl;
        cout<<"7. Agregar un solo elemento al final de la lista existente"<<endl;
        cout<<"8. Eliminar el primer elemento de la lista"<<endl;
        cin>>opc;
        switch(opc){
            case 1:
                crearListaInicio(P,Q,verificador);
                break;
    
            case 2:
                crearListaFinal(P,Q,verificador);
                break;
    
            case 3:
                if(verificador==true){
                    imprimirLista(P);
                }
                else{
                    cout<<"No hay lista creada"<<endl;
                }
                break;
    
            case 4:
                if(verificador==true){
                    eliminarUltimo(P,verificador);
                }
                else{
                    cout<<"No hay lista creada"<<endl;
                }  
                break;
            case 5:
                if(verificador==true){
                    BuscarElemento(P);
                }
                else{
                    cout<<"No hay lista creada"<<endl;
                }
                break;
            case 6:
                if(verificador==true){
                    agregarUnSoloElementoaListaExistente(P);
                }
                else{
                    cout<<"No hay lista creada"<<endl;
                }
                break;
            case 7:
                if(verificador==true){
                    AgregarUnSoloElementoAlFinalDeLaListaExistente(P);
                }
                else{
                    cout<<"No hay lista creada"<<endl;
                }
                break;
            case 8:
                if(verificador==true){
                    eliminarPrimero(P,verificador);
                }
                else{
                    cout<<"No hay lista creada"<<endl;
                }
                break;
            default:
                cout<<"Opcion no valida"<<endl;
        }
        cout<<"\nDeseas continuar? (s/n)"<<endl;
        cin>>resp;
    }
}

bool crearListaInicio(Nodo* &P, Nodo* &Q,bool &verificador){
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
    return verificador=true;
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

bool eliminarUltimo(Nodo* &P, bool &verificador){
    typedef Nodo* PNodo;
    PNodo aux;
    aux= P;
    if(aux->liga==NULL){
        delete P;
        P=NULL;
        return verificador=false;
    }
    while (aux->liga->liga!=NULL) {
        aux=aux->liga;
    }
    delete aux->liga;
    aux->liga=NULL;    
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
void BuscarElemento(Nodo *P){
    typedef Nodo* PNodo;
    int elemento;
    cout<<"Lista Actual"<<endl;
    imprimirLista(P);
    cout<<"Que elemento deseas buscar?"<<endl;
    cin>>elemento;
    PNodo aux=P;
    bool encontrado=false;
    while(aux!=nullptr){
        if(aux->dato==elemento){
            encontrado=true;
            break;
        }
        aux=aux->liga;
    }
    if(encontrado==true){
        cout<<"El elemento "<<elemento<<" fue encontrado en la lista."<<endl;
    }else{
        cout<<"El elemento "<<elemento<<" no fue encontrado en la lista."<<endl;
    }
}
void agregarUnSoloElementoaListaExistente(Nodo* &P){
    typedef Nodo* PNodo;
    PNodo aux;
    PNodo Q;
    aux=P;
    Q=new Nodo;
    Q->liga=aux;
    cout<<"Ingresa un numero para el siguiente nodo: "<<endl;
    cin>>Q->dato;
    P=Q;
}

void AgregarUnSoloElementoAlFinalDeLaListaExistente(Nodo* &P){
    typedef Nodo* PNodo;
    PNodo aux;
    PNodo Q;
    aux=P;
    while(aux->liga!=nullptr){
        aux=aux->liga;
    }
    Q=new Nodo;
    Q->liga=nullptr;
    cout<<"Ingresa un numero para el siguiente nodo: "<<endl;
    cin>>Q->dato;
    aux->liga=Q;
}

bool eliminarPrimero(Nodo* &P, bool &verificador){
    typedef Nodo* PNodo;
    PNodo aux;
    aux=P;
    if(aux->liga==NULL){
        delete P;
        P=NULL;
        return verificador=false;
    }
    P=aux->liga;
    delete aux;
    return verificador=true;
}