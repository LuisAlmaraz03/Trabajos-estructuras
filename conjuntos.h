#include<iostream>
using namespace std;
void conjuntos_1(){
    char alfabeto[6]={'A','B','C','D','E','F'};
    char vocales[2]={'A','E'};
    char consonantes[4]={'B','C','D','F'};
    char A[2];
     cout << "Alfabeto interseccion Vocales: ";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 6; j++) {
            if (vocales[i] == alfabeto[j]) {
                cout << vocales[i] << " ";
                break;
            }
        }
    }
    cout << endl;
    cout<<"Consonantes - Alfabeto: "<<endl;
    for (int i = 0; i < 4; i++)
    {
        bool found = false;
        for(int j=0;j<6;j++){
            if(consonantes[i]==alfabeto[j]){
                found = true;
                break;
            }
        }
        if(!found){
            cout<<consonantes[i]<<" ";
        }
        else{
            cout<<"No hay elementos en la diferencia"<<endl;
            break;
        }
    }
    cout<<endl;
    cout<<"Consonantes + Vocales"<<endl;
for (int i = 0; i < 2; i++)
    cout<<vocales[i]<<" ";
for (int i = 0; i < 4; i++)
    cout<<consonantes[i]<<" ";
cout<<endl;
}
void conjuntos_2(){
string claseA[4]={"Juan","Maria","Pedro","Sofia"};
string claseB[4]={"Pedro","Sofia","Luis","Ana"};
cout<<"Clase A interseccion Clase B: "<<endl;
for (int i = 0; i < 4; i++)
{
    for(int j=0;j<4;j++){
        if(claseA[i]==claseB[j]){
            cout<<claseA[i]<<",";
        }
    }
}
cout<<endl;
cout<<"Diferencia de Clase A - Clase B: "<<endl;
for (int i = 0; i < 4; i++)
{
    bool found = false;
    for(int j=0;j<4;j++){
        if(claseA[i]==claseB[j]){
            found = true;
            break;
        }
    }
    if(!found){
        cout<<claseA[i]<<",";
    }
}
cout<<endl;
cout<<"Diferencia de Clase B - Clase A: "<<endl;
for (int i = 0; i < 4; i++)
{
    bool found = false;
    for(int j=0;j<4;j++){
        if(claseB[i]==claseA[j]){
            found = true;
            break;
        }
    }
    if(!found){
        cout<<claseB[i]<<",";
    }
}
cout<<endl;
}
