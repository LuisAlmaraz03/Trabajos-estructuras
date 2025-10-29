#include <iostream>
using namespace std;
struct NodoCola {
    int dato;
    NodoCola* liga;
};
void PushPorElFinal(NodoCola*& ini, NodoCola*& fin, int valor) {
    NodoCola* nuevo = new NodoCola();
    nuevo->dato = valor;
    nuevo->liga = nullptr;
    if (fin != nullptr) {
        fin->liga = nuevo;
    }
    fin = nuevo;
    if (ini == nullptr) {
        ini = nuevo;
    }
}
void PushPorElInicio(NodoCola*& ini, NodoCola*&fin, int valor){
    NodoCola* nuevo = new NodoCola;
    nuevo->dato = valor;
    nuevo->liga = ini;
    ini = nuevo;
    if(fin == nullptr){
        fin = nuevo;
    }
}
void imprimirCola(NodoCola* ini) {
    NodoCola* aux = ini;
    cout << "Elementos de la cola: ";
    while (aux != nullptr) {
        cout << aux->dato << " ";
        aux = aux->liga;
    }
    cout << endl;
}
void PopPorElInicio(NodoCola*& ini, NodoCola*& fin) {
    if (ini != nullptr) {
        NodoCola* aux = ini;
        ini = ini->liga;
        if (ini == nullptr) {
            fin = nullptr;
        }
        delete aux;
    } else {
        cout << "La cola esta vacia no se puede hacer pop." << endl;
    }
}
void PopPorElFinal(NodoCola*& ini, NodoCola*& fin) {
    if(ini==nullptr){
        cout<<"La cola esta vacia"<<endl;
        return;
    }
    else if(ini==fin){
        delete ini;
        ini= nullptr;
        fin= nullptr;
    }
    else{
        NodoCola* aux;
        aux= ini;
        while(aux->liga!=fin){
            aux=aux->liga;
        }
        delete fin;
        fin=aux;
        fin->liga= nullptr;
    }
}
void ColaConEntradaRestringida(){
    typedef NodoCola* cola;
    int opc;
    cola ini=nullptr;
    cola fin=nullptr;
    char resp='s';
    int dato;
    while(resp=='s'||resp=='S'){
        cout<<"Que elemento deseas agregar?"<<endl;
        cin>>dato;
        PushPorElFinal(ini,fin,dato);
        cout<<"Deseas agregar otro elemento? (s/n): "<<endl;
        cin>>resp;
    }
    imprimirCola(ini);
    cout<<"Por que extremo deseas eliminar un elemento? \n1. Inicio\n2. Final\n";
    cin>>opc;
    if(opc==1){
        PopPorElInicio(ini,fin);
    }
    else if(opc==2){
       PopPorElFinal(ini,fin);
}
    imprimirCola(ini);
}
void ColaConSalidaRestringida()
{
   typedef NodoCola* cola;
   cola ini = nullptr;
   cola fin= nullptr;
   char resp;
   int dato;
   cout<<"Agregar elementos a la cola (s/n): "<<endl;
    resp='s';
   while(resp=='s'||resp=='S'){
        cout<<"Que elemento deseas agregar?"<<endl;
        cin>>dato;
        PushPorElFinal(ini,fin,dato);
        cout<<"Deseas agregar otro elemento? (s/n): "<<endl;
        cin>>resp;
    }
    imprimirCola(ini);
    cout<<"Por donde deseas agregar un elemento? \n1. Inicio\n2. Final\n";
    int opc;
    cin>>opc;
    if(opc==1){
        cout<<"Que elemento deseas agregar?"<<endl;
        cin>>dato;
        PushPorElInicio(ini,fin,dato);
    }
    else if(opc==2){
       cout<<"Que elemento deseas agregar?"<<endl;
       cin>>dato;
       PushPorElFinal(ini,fin,dato);
    }
    imprimirCola(ini);
    PopPorElInicio(ini,fin);
    imprimirCola(ini);
}
int main(){
int dato;
typedef NodoCola* cola;
cola ini = nullptr;
cola fin = nullptr;
/*cout<<"Que elemento deseas agregar?"<<endl;
cin>>dato;*/
/*PushPorElFinal(ini,fin,dato);
PushPorElFinal(ini,fin,20);
PushPorElFinal(ini,fin,30);
PopPorElInicio(ini,fin);
imprimirCola(ini);
ColaConEntradaRestringida();
*/
ColaConSalidaRestringida();
}