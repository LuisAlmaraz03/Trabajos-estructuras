// ...existing code...
#include <iostream>
using namespace std;
struct NodoCola {
    int dato;
    NodoCola* liga;
    int prioridad;
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

void PushPorElInicio(NodoCola*& ini, NodoCola*& fin, int valor){
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
    if (ini == nullptr) {
        cout << "La cola esta vacia" << endl;
        return;
    } else if (ini == fin) {
        delete ini;
        ini = nullptr;
        fin = nullptr;
    } else {
        NodoCola* aux = ini;
        while (aux->liga != fin) {
            aux = aux->liga;
        }
        delete fin;
        fin = aux;
        fin->liga = nullptr;
    }
}
void ColaConEntradaRestringida(NodoCola*& ini, NodoCola*& fin) {
    char resp = 's';
    int dato;
    int opc;

    if (ini == nullptr) {
        cout << "La cola esta vacia, se debe construir primero.\n";
        cout << "Construya la cola (solo entrada por el final)\n";
        while (resp == 's' || resp == 'S') {
            cout << "Que elemento deseas agregar? ";
            cin >> dato;
            PushPorElFinal(ini, fin, dato);
            cout << "Deseas agregar otro elemento? (s/n): ";
            cin >> resp;
        }

        imprimirCola(ini);
        cout << "Deseas eliminar un elemento? (s/n): ";
        cin >> resp;
        if (resp == 's' || resp == 'S') {
            cout << "Por que extremo deseas eliminar un elemento? \n1. Inicio\n2. Final\n";
            cin >> opc;
            if (opc == 1) {
                PopPorElInicio(ini, fin);
            } else if (opc == 2) {
                PopPorElFinal(ini, fin);
            } else {
                cout << "Opcion no valida\n";
            }
            imprimirCola(ini);
        }
    } else {
        cout << "La cola ya existe.\n";
        cout << "Deseas agregar un elemento? (s/n): ";
        cin >> resp;
        if (resp == 's' || resp == 'S') {
            cout << "Que elemento deseas agregar? ";
            cin >> dato;
            PushPorElFinal(ini, fin, dato);
            imprimirCola(ini);
        }

        cout << "Deseas eliminar un elemento? (s/n): ";
        cin >> resp;
        if (resp == 's' || resp == 'S') {
            cout << "Por que extremo deseas eliminar un elemento? \n1. Inicio\n2. Final\n";
            cin >> opc;
            if (opc == 1) {
                PopPorElInicio(ini, fin);
            } else if (opc == 2) {
                PopPorElFinal(ini, fin);
            } else {
                cout << "Opcion no valida\n";
            }
            imprimirCola(ini);
        }
    }
}
void ColaConSalidaRestringida(NodoCola*& ini, NodoCola*& fin) {
    char resp = 's';
    int dato;
    int opc;
    if(ini == nullptr && fin == nullptr){
        cout<<"La cola esta vacia, se debe construir primero.\n";
        cout << "Construya la cola (inserciones iniciales por el final)\n";
    while (resp == 's' || resp == 'S') {
        cout << "Que elemento deseas agregar? ";
        cin >> dato;
        PushPorElFinal(ini, fin, dato);
        cout << "Deseas agregar otro elemento? (s/n): ";
        cin >> resp;
    }
    }
    else{
    imprimirCola(ini);
    cout << "Deseas insertar un elemento adicional? (s/n): ";
    cin >> resp;
    if (resp == 's' || resp == 'S') {
        cout << "Por donde deseas agregar el elemento? \n1. Inicio\n2. Final\n";
        cin >> opc;
        cout << "Que elemento deseas agregar? ";
        cin >> dato;
        if (opc == 1) {
            PushPorElInicio(ini, fin, dato);
        } else if (opc == 2) {
            PushPorElFinal(ini, fin, dato);
        } else {
            cout << "Opcion no valida\n";
        }
        imprimirCola(ini);
    }
    char resp2;
    cout<<"Quieres eliminar un elemento? (s/n): ";
    cin>>resp2;
    if(resp2=='s' || resp2=='S'){
    cout << "Ahora se realizara una eliminacion por el inicio (salida restringida).\n";
    PopPorElInicio(ini, fin);
    imprimirCola(ini);
}
}
}
void insert(NodoCola*& ini, NodoCola*& fin, int valor, int pr) {
    NodoCola* nuevo = new NodoCola();
    nuevo->dato = valor;
    nuevo->prioridad = pr;
    nuevo->liga = nullptr;

    if (ini == nullptr) {
        ini = fin = nuevo;
        return;
    }
    if (nuevo->prioridad < ini->prioridad) {
        nuevo->liga = ini;
        ini = nuevo;
        return;
    }
    NodoCola* prev = ini;
    NodoCola* cur = ini->liga;
    while (cur != nullptr && cur->prioridad <= nuevo->prioridad) {
        prev = cur;
        cur = cur->liga;
    }
    prev->liga = nuevo;
    nuevo->liga = cur;
    if (cur == nullptr) fin = nuevo;
}
void imprimirColaPorPrioridad(NodoCola* ini) {
    NodoCola* aux = ini;
    cout << "Elementos (dato:prioridad) en orden de prioridad: ";
    while (aux != nullptr) {
        cout << aux->dato << ":" << aux->prioridad << " ";
        aux = aux->liga;
    }
    cout << endl;
}

void ColaPorPrioridad(NodoCola*& ini, NodoCola*& fin) {
    char resp = 's';
    while (resp == 's' || resp == 'S') {
        int opc;
        cout << "\n--- Cola por Prioridad (0 = mayor) ---\n";
        cout << "1. Insertar (con prioridad)\n";
        cout << "2. Imprimir (dato:prioridad)\n";
        cout << "5. Salir\n";
        cout << "Elige: ";
        cin >> opc;
        if (opc == 1) {
            int v, p;
            cout << "Valor: "; cin >> v;
            cout << "Prioridad (0..4): "; cin >> p;
            if (p < 0) p = 0; if (p > 4) p = 4;
            insert(ini, fin, v, p);
        }  else if (opc == 2) {
            imprimirColaPorPrioridad(ini);
        } else {
            cout << "Opcion no valida\n";
        }
        cout << "Continuar en bicola por prioridad? (s/n): ";
        cin >> resp;
    }
}
void MenuColas(){
    int dato;
    typedef NodoCola* cola;
    cola ini = nullptr;
    cola fin = nullptr;
    int opc;
    char resp;
    char respt = 's';

    do {
        cout<<"Menu de Colas\n";
        cout<<"1. Colas simples"<<endl;
        cout<<"2. Bicolas"<<endl;
        cout<<"3. Bicola por prioridad"<<endl;
        cout<<"Seleccione una opcion (1-3): ";
        cin>>opc;

        switch(opc){
            case 1: {
                resp = 's';
                do{
                    int opc2;
                    cout<<"1.Push por el final"<<endl;
                    cout<<"2.Pop por el inicio"<<endl;
                    cout<<"3. Imprimir cola"<<endl;
                    cout<<"Seleccione una opcion (1-3): ";
                    cin>>opc2;
                    switch(opc2){
                        case 1:
                            cout<<"Que elemento deseas agregar?"<<endl;
                            cin>>dato;
                            PushPorElFinal(ini,fin,dato);
                            break;
                        case 2:
                            PopPorElInicio(ini,fin);
                            break;
                        case 3:
                            imprimirCola(ini);
                            break;
                        default:
                            cout<<"Opcion no valida"<<endl;
                    }
                    cout<<"Deseas realizar otra operacion en la cola? (s/n): ";
                    cin>>resp;
                } while(resp=='s' || resp=='S');
                break;
            }

            case 2: {
                resp = 's';
                do{
                    int opc3;
                    cout<<"1. Cola con entrada restringida"<<endl;
                    cout<<"2. Cola con salida restringida"<<endl;
                    cout<<"Seleccione una opcion (1-2): ";
                    cin>>opc3;
                    switch(opc3){
                        case 1:
                            ColaConEntradaRestringida(ini, fin);
                            break;
                        case 2:
                            ColaConSalidaRestringida(ini, fin);
                            break;
                        default:
                            cout<<"Opcion no valida"<<endl;
                    }
                    cout<<"Deseas realizar otra operacion en la cola? (s/n): ";
                    cin>>resp;
                } while(resp=='s' || resp=='S');
                break;
            }
            case 3:
                ColaPorPrioridad(ini, fin);
                break;
            default:
                cout<<"Opcion no valida"<<endl;
                break;
        }

        cout<<"Deseas regresar al menu de colas? (s/n): ";
        cin>>respt;
    } while(respt=='s' || respt=='S');

    return;
}