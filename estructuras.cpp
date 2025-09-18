#include<iostream>
using namespace std;
#define cantidad 2

int main(){
    struct datos
    {
        string cuenta;
        int edad;
        char sexo;
        float calificacion1;
        float calificacion2;
        float promedio;
    };
    datos alumnos[cantidad];
    float prom_gen;
    int buscador;
    int count= 1;

    for(int i=0; i<cantidad; i++){
    cout<<"Cuenta\n";
    cin>>alumnos[i].cuenta;
    cout<<"Edad\n";
    cin>>alumnos[i].edad;
    cout<<"Sexo\n";
    cin>>alumnos[i].sexo;
    cout<<"Calificacion 1\n";
    cin>>alumnos[i].calificacion1;
    cout<<"Calificacion 2\n";
    cin>>alumnos[i].calificacion2;
    alumnos[i].promedio=alumnos[i].calificacion1 + alumnos[i].calificacion2; 
   }

    cout<<"Edad a buscar\n";
    cin>>buscador;
   for (int i = 0; i < cantidad; i++)
   {
    if (alumnos[i].sexo == 'F'){
        cout<<"\nAlumna "<<count<<alumnos[i].cuenta;
        count++;
    }
    else if ()
    {
        /* code */
    }

    cout<<"\nJugador "<<i+1<<"\nNombre:"<<jugadores[i].nombre<<"\nEdad: "<<jugadores[i].edad<<"\nAltura: "<<
    jugadores[i].altura<<"\nSexo: "<<jugadores[i].sexo<<endl;
   }

}