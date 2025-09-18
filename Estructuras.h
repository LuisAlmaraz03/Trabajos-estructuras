#include<iostream>
using namespace std;
#define cantidad 2 
int main(){
   struct Basquetbolista{
    float altura;
    int edad;
    string nombre;
    char sexo;
   };
   Basquetbolista jugadores[cantidad];
   float suma=0;

   for (int i=0; i<cantidad; i++){
    cout<<"Nombre\n";
    cin>>jugadores[i].nombre;
    cout<<"Edad\n";
    cin>>jugadores[i].edad;
    cout<<"Sexo\n";
    cin>>jugadores[i].sexo;
    cout<<"Altura\n";
    cin>>jugadores[i].altura;
    suma+=jugadores[i].altura;
   }

   for (int i = 0; i < cantidad; i++)
   {
    cout<<"\nJugador "<<i+1<<"\nNombre:"<<jugadores[i].nombre<<"\nEdad: "<<jugadores[i].edad<<"\nAltura: "<<
    jugadores[i].altura<<"\nSexo: "<<jugadores[i].sexo<<endl;
   }
   
   suma=suma/cantidad;
   cout<<"El promedio de altura es: "<<suma<<endl;
}