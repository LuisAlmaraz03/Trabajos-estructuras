#include<iostream>
using namespace std;
#define max 10
int main(){
    struct datos{
        string nombre;
        int edad;
        char sexo;
        struct domicilio{
            string calle;
            int numero;
            string ciudad;
        } direccion;
        int telefono;
        bool asegurado;

    };
    datos persona[max];
    int n;
    string nombrebuscado;
    cout<<"Cuantas personas desea registrar? (max 10)"<<endl;
    cin>>n;
    cin.ignore();
    int counta=0,countb=0,sumamenores=0,sumamujeres=0,countm=0;
    for(int i=0;i<n;i++){
        cout<<"Nombre:  "<<endl;
       getline(cin, persona[i].nombre);
        cout<<"Edad:  "<<endl;
        cin>>persona[i].edad;
        cin.ignore();
        if(persona[i].edad<13){
            countb++;
        }
        cout<<"Sexo:  "<<endl;
        cin>>persona[i].sexo;
        cin.ignore();
         if(persona[i].sexo=='F'||persona[i].sexo=='f'){
            countm++;
        }
        cout<<"Calle:  "<<endl;
        getline(cin, persona[i].direccion.calle);

        cout<<"Numero:  "<<endl;
        cin>>persona[i].direccion.numero;
        cin.ignore();
        cout<<"Ciudad:  "<<endl;
        getline(cin, persona[i].direccion.ciudad);
        cout<<"Telefono:  "<<endl;
        cin>>persona[i].telefono;
        cin.ignore();
        cout<<"Asegurado (1=si/0=no):  "<<endl;
        cin>>persona[i].asegurado;
        cin.ignore();
        if(persona[i].asegurado==1){
            counta++;
        }
    }
    cout<<"Lista de los nombres de los pacientes hospitalizados: "<<endl;
    for(int i=0;i<n;i++){
        cout<<persona[i].nombre<<endl;
    }
    cout<<"Porcentaje de edad de los menores de 13 años: "<<(countb/n)*100<<"%"<<endl;
    cout<<"Numero de personas aseguradas: "<<counta<<endl;
    cout<<"Porcentaje de mujeres hospitalizadas: "<<(countm/n)*100<<"%"<<endl;
    cout<<"Ingresa un nombre de un paciente para darte los datos de su domicilio: "<<endl;
    getline(cin,nombrebuscado);
    for(int i=0;i<n;i++){
        if(persona[i].nombre==nombrebuscado){
            cout<<"Calle: "<<persona[i].direccion.calle<<endl;
            cout<<"Numero: "<<persona[i].direccion.numero<<endl;
            cout<<"Ciudad: "<<persona[i].direccion.ciudad<<endl;
        }
    }



}