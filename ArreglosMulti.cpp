#include <iostream> 
using namespace std;
#define dia 5
int main (){
int mes, anio, mesEsp;
float suma=0,suma2=0;
cout<<"Ingresa la cantidad de meses:\n";
cin>>mes;
cout<<"Ingresa la cantidad de anios:\n";
cin>>anio;
cout<<"Ingresa el mes que deseas promediar (1-12):\n";
cin>>mesEsp;
float temp [anio][mes][dia];
for(int k=0; k<anio; k++){
    for(int j=0; j<mes; j++){
        for(int i=0; i<dia; i++){
            cout<<"Ingresa la temperatura del dia "<<i+1<<" del mes "<<j+1<<" del anio "<<k+1<<":\n";
            cin>>temp[k][j][i];
            suma+=temp[k][j][i];
            if(j==mesEsp-1){
                suma2+=temp[k][j][i];
            }

            
        }
      }
      cout<<"El promedio anual es: "<<suma/(anio*mes*dia)<<endl;
                suma=0;
    }
    cout<<"El promedio del mes "<<mesEsp<<" es: "<<suma2/(anio*dia)<<endl;
    
}