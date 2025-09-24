#include <iostream> 
using namespace std;
#define dia 5
void ArreglosMulti_1 (){
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

void Arreglosmulti_2(){
    int examenes, estudiantes, cursos, count=0;
    char genero;
    cout<<"Ingrese la cantidad de estudiantes: ";
    cin>>estudiantes;
    cout<<"Ingrese la cantidad de cursos: ";
    cin>>cursos;
    cout<<"Ingrese la cantidad de examenes: ";
    cin>>examenes;
    
    float calificaciones[estudiantes][cursos][examenes+1]; // Promedio final por curso
    for(int i=0;i<estudiantes;i++){
        cout<<"Estudiante "<<i+1<<". ";
        for(int j=0;j<cursos;j++){
            cout<<"Curso "<<j+1<<".\n";
            calificaciones[i][j][examenes]=0; 
            for(int k=0;k<examenes;k++){
                cout<<"Examen "<<k+1<<": ";
                cin>>calificaciones[i][j][k];
                calificaciones[i][j][examenes]+=calificaciones[i][j][k];
            }
            if (j==cursos-1){
                cout<<"Cual es el genero del estudiante (M/F): ";
                cin>>genero;
                if(genero=='F' || genero=='f'){
                    count++;
                }
            }
        }
        cout<<endl;
    }
    cout<<"Cantidad de estudiantes mujeres en el grupo: "<<count<<endl;
    cout<<"Promedios Final: "<<endl;
    for(int i=0;i<estudiantes;i++){
        float suma=0;
        cout<< "Estudiante "<<i+1<<". ";
        for(int j=0;j<cursos;j++){
            suma+=calificaciones[i][j][examenes];
        }
        cout<<"Promedio Final: "<<suma/(cursos*examenes)<<endl;
        suma=0;
    }
}