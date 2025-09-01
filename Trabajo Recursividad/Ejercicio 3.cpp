#include<iostream> 
using namespace std;
int contar(int n){
    if(n==0){
        return 0;
    }
    else if (n%2==0){
       return 1+contar(n-1);
    }
    else if(n%2!=0){
        return contar(n-1);
    }

    
    
}

int main(){
    int n;
    cout<<"Ingrese un numero: ";
    cin>>n;
    cout<<"el numero de pares es: "<<contar(n); 
}