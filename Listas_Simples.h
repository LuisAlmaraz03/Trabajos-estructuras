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
bool eliminarCoincidencia(Nodo *&P, bool &verificador);
void insertarDatoAntesAOtro(Nodo *&P);
void insertarDatoDespuesAOtro(Nodo *&P);
void eliminarAnteriorAOtro(Nodo *&P);
void insertarDatoDespuesdeOtro(Nodo *&P);
void eliminarNodoAntesdeOtro(Nodo *&P);
void eliminarNodoDespuesDeOtro(Nodo *&P);

void menu(){
    typedef Nodo* PNodo;
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
                crearListaInicio(P,Q,verificador);
                break;
    
            case 2:
                crearListaFinal(P,Q,verificador);
                break;
    
            case 3:
                imprimirLista(P);
                break;
    
            case 4:
                eliminarUltimo(P,verificador);
                break;
            case 5:
                BuscarElemento(P);
                break;
            case 6:
                agregarUnSoloElementoaListaExistente(P);
                break;
            case 7:
                AgregarUnSoloElementoAlFinalDeLaListaExistente(P);
                break;
            case 8:
                eliminarPrimero(P,verificador);
                break;
            case 9:
                eliminarCoincidencia(P,verificador);
                break;
            case 10:
                insertarDatoAntesAOtro(P);
                break;
            case 11:
                insertarDatoDespuesdeOtro(P);
                break;
            case 12:
                eliminarNodoAntesdeOtro(P);
                break;
            case 13:
                eliminarNodoDespuesDeOtro(P);
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
    return verificador=true; 
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
    if(P->liga==NULL){
        delete P;
        P=NULL;
        return verificador=false;
    }
    P=P->liga;
    return verificador=true;
}
bool eliminarCoincidencia(Nodo *&P, bool &verificador){
    int eliminado;
    typedef Nodo* PNodo;
    PNodo aux = P;
    PNodo Q = nullptr;
    cout<<"Valor a eliminar?\n";
    cin>>eliminado;
    if(P->dato == eliminado){
        if(P->liga==nullptr){
            P=nullptr;
            return verificador= false;
        }
        else{
            cout<<"Entro en el segundo caso\n";
            P=P->liga;
            return verificador = true;
        }
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
        return verificador = true;
    }
}
void insertarDatoAntesAOtro(Nodo *&P)
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

    if (P->dato == Dseleccion) {
        T->liga=P;
        P=T;
        return;
    }
    else{
        while(aux->dato!=Dseleccion && aux->liga != nullptr){
            Q=aux;
            aux=aux->liga;
            if(aux->dato == Dseleccion){
                Q->liga=T;
                T->liga=aux;
                break;
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
    cout<<"Despues de que dato se eliminara?"<<endl;
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
