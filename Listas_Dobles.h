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
void eliminarAntesDeOtro(NodoDoble* &P, NodoDoble* &Q);
void insertarAlInicio(NodoDoble* &P);
void insertarDespuesDeOtro(NodoDoble* &P, NodoDoble* &Q);
void palindromo();

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
        cout<<"5. Eliminar un elemento anterior a otro\n";
        cout<<"6. Insertar un elemento en el inicio de la lista\n";
        cout<<"7. Insertar un elemento despues de otro\n";
        cout<<"8. Verificar si la palabra es un palindromo\n";
        cin>>opc;
        if(opc == 1){
                verificador=true;
            }
        else if(opc == 8){
                palindromo();
                opc=0;
                verificador=true;
            }
        while(verificador!=true){
            cout<<"No hay lista creado, crea una lista para poder relizar la accion seleccionada (1)\n";
            cout<<"O si deseas verificar un palindromo selecciona la opcion 8\n";
            cin>>opc;
            if(opc == 1)
            {
                verificador=true;
            }else if(opc == 8){
                palindromo();
                opc=0;
                verificador=true;
            }
        }
        switch(opc){
            case 0:
                if(P==nullptr){
                    verificador=false;
                }else{
                    verificador=true;
                }
                break;
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
            case 5:
                eliminarAntesDeOtro(P,Q);
                break;
            case 6:
                insertarAlInicio(P);
                break;
            case 7:
                insertarDespuesDeOtro(P,Q);
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
void eliminarAntesDeOtro(NodoDoble* &P, NodoDoble* &Q){
    typedef NodoDoble* PNodo;
    int eliminado;
    PNodo aux;
    aux=P;
    int Buscar;
    cout<<"Antes de que dato eliminaras?\n";
    cin>>Buscar;
    while (aux!=nullptr && aux->dato!=Buscar){
        aux=aux->ligaD;
    }
    if (aux==nullptr){
        cout<<Buscar<<"No existe en la lista"<<endl;
    }
    else if(aux==P){
        cout<<"No existe un dato anterior a "<<Buscar<<endl;
    }
    else if(aux->ligaI==P){
        delete P;
        P=aux;
        aux->ligaI = nullptr;
    }
    else{
        aux=aux->ligaI;
        aux->ligaI->ligaD=aux->ligaD;
        aux->ligaD->ligaI=aux->ligaI;
        delete aux;
    }
}
void insertarAlInicio(NodoDoble* &P){
    typedef NodoDoble* PNodo;
    PNodo aux;
    aux=P;
    P= new NodoDoble;
    cout<<"Ingresa el nuevo dato\n";
    cin>>P->dato;
    P->ligaI=nullptr;
    P->ligaD=aux;
    aux->ligaI=P;
}
void insertarDespuesDeOtro(NodoDoble* &P, NodoDoble* &Q){
    typedef NodoDoble* PNodo;
    int Buscar;
    PNodo aux,T;
    cout<<"Despues de que dato ingresaras el nuevo?\n";
    cin>>Buscar;
    aux=P;
    while (aux!=nullptr && aux->dato!=Buscar){
        aux=aux->ligaD;
    }
    if(aux==nullptr){
        cout<<Buscar<<" No existe en la lista"<<endl;
    }
    else if(aux==Q){
        aux=new NodoDoble;
        cout<<"Ingresa el nuevo dato\n";
        cin>>aux->dato;
        aux->ligaD=nullptr;
        aux->ligaI=Q;
        Q->ligaD=aux;
        Q=aux;
    }
    else{
        T=new NodoDoble;
        cout<<"Ingresa el nuevo dato\n";
        cin>>T->dato;
        T->ligaD=aux->ligaD;
        aux->ligaD->ligaI=T;
        aux->ligaD=T;
        T->ligaI=aux;
    }
}
void palindromo(){
    struct NodoLetra
    {
        char letra;
        NodoLetra* ligaD;
        NodoLetra* ligaI;
    };
    
    typedef NodoLetra* PNodo;
    PNodo P,Q,aux,auxF;
    char continuar='s';
    P=new NodoLetra;
    cout<<"Ingresa la primer letra\n";
    cin>>P->letra;
    P->ligaI=nullptr;
    Q=P;
    while(continuar=='s' || continuar=='S'){ //Creando la palabra
        aux=Q;
        Q=new NodoLetra;
        cout<<"Ingresa la siguiente letra sin espacios\n";
        cin>>Q->letra;
        aux->ligaD=Q;
        Q->ligaI=aux;
        Q->ligaD=nullptr;
        cout<<"Agregar otra letra?[S/N]\n";
        cin>>continuar;
    }

    aux=P; //aux toma el la primer letra de la palabra
    auxF=Q; //auxF toma el valor de la ultima letra de la palabra
    while (aux!=nullptr && aux->letra==auxF->letra){//Comienza a compara las letras de inicio a fin
        aux=aux->ligaD;
        auxF=auxF->ligaI;
    }
    if(aux==nullptr){
        cout<<"La palabra es un palindromo\n";
    }else{
        cout<<"La palabra no es un palindromo\n";
    }
}