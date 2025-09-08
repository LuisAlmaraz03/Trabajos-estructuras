#include <bits/stdc++.h>
using namespace std;

void ArreglosBi_1(){
    int n;
    cout<<"Ingresa la longitud de la frase"<<"\n";
    cin>> n;
    int m=n-1;
    char A[2][n];
    cout<<"ingresa la frase (con espacios entre letras)"<<endl;
    int i=0;
    while(i==0){
        for(int j=0; j<n; ++j){
            cin>>A[0][j];
            A[1][m--]=A[0][j];
        }
        i++;
    }
    
    int cont=0;
    for(int i=0; i<n; i++){
        if(A[0][i]==A[1][i])cont++;
    }
    if(cont==n)cout<<"Es palindromo";
    else "No es palindromo";
    
    
}

void ArreglosBi_2(){
    int n,m;
    cout<<"ingresa el numero de filas"<<endl;
    cin>>n;
    cout<<"ingresa el numero de columnas"<<endl;
    cin>>m;
    int A[n][m], B[n][m],C[n][m];
    cout<<"ingresa los valores de la primera matriz"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>A[i][j];
        }
    }
    cout<<"ingresa los valores de la segunda matriz"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>B[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            C[i][j]=A[i][j]+B[i][j];
        }
    }
    cout<<"La matriz suma es"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }

}

void ArreglosBi_3(){
    int m; 
    cout<<"Ingresa el numero de elementos que deseas en el arreglo: ";
    cin>>m;
    int a[m][3];
    cout<<"Ingresa los elementos del arreglo: "<<endl;
    for(int i=0; i<m; i++){
        cin>>a[i][0];
        a[i][1]=pow(a[i][0],2);
        a[i][2]=pow(a[i][0],3);
    }
    cout<<"Numero"<<" "<<"Cuadrado"<<" "<<"Cubo"<<endl;
    for(int i=0; i<m; i++){
        cout<<a[i][0]<<"      "<<a[i][1]<<"       "<<a[i][2]<<endl;
    }
}

void ArreglosBi_4(){
    int matriz[4][3];

    cout << "Ingrese los valores de la matriz 4x3:" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> matriz[i][j];
        }
    }

    for (int i = 0; i < 4; i++) {
        int suma = 0;
        for (int j = 0; j < 3; j++) {
            suma += matriz[i][j];
        }
        cout << "La suma del renglon " << i+1 << " es: " << suma << endl;
    }

}


void ArreglosBi_5(){
    int r1, c1, r2, c2;

    cout << "Filas de la primera matriz: ";
    cin >> r1;
    cout << "Columnas de la primera matriz: ";
    cin >> c1;

    cout << "Filas de la segunda matriz: ";
    cin >> r2;
    cout << "Columnas de la segunda matriz: ";
    cin >> c2;

    if (c1 != r2) {
        cout << "No se pueden multiplicar las matrices." << endl;
    }
    else{
    int A[r1][c1], B[r2][c2], C[r1][c2];

    cout << "Ingrese los elementos de la primera matriz:" << endl;
    for (int i = 0; i < r1; ++i)
        for (int j = 0; j < c1; ++j)
            cin >> A[i][j];
            
    cout << "Ingrese los elementos de la segunda matriz:" << endl;
    for (int i = 0; i < r2; ++i)
        for (int j = 0; j < c2; ++j)
            cin >> B[i][j];
    
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < c1; ++k)
                C[i][j] += A[i][k] * B[k][j];
        }
    }

    cout << "Resultado de la multiplicacion:" << endl;
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j)
            cout << C[i][j] << " ";
        cout << endl;
    }
}
}

void ArreglosBi_6(){
    int matriz[3][3];
    cout << "Ingrese los elementos de la matriz 3x3:\n";
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) {
            cin >> matriz[i][j];
        }

    int determinante = 
        matriz[0][0]*(matriz[1][1]*matriz[2][2] - matriz[1][2]*matriz[2][1]) -
        matriz[0][1]*(matriz[1][0]*matriz[2][2] - matriz[1][2]*matriz[2][0]) +
        matriz[0][2]*(matriz[1][0]*matriz[2][1] - matriz[1][1]*matriz[2][0]);

    cout << "El determinante de la matriz es: " << determinante << endl;
}

void ArreglosBi_7(){
    int cero=0, neg=0, pos=0, sumN=0, sumP=0, a;
    cout<<"Ingrese los valores de la matriz 5x4: "<<endl;
    for(int i=0; i<5; i++){
        for(int j=0; j<4; j++){
            cin>>a;
            if(a==0){
                cero++;
            }else if(a<0){
                neg++;
                sumN+=a;
            }else{
                pos++;
                sumP+=a;
            }
        }
    }
    cout<<"Cantidad de ceros: "<<cero<<endl;
    cout<<"Cantidad de negativos: "<<neg<<endl; 
    cout<<"Suma de negativos: "<<sumN<<endl;
    cout<<"Cantidad de positivos: "<<pos<<endl; 
    cout<<"Suma de positivos: "<<sumP<<endl;   
}

void ArreglosBi_8(){
    int menor, mayor,posM, posm, a;
    cout<<"Ingrese los valores de la matriz 4x4: "<<endl;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cin>>a;
            if(i==0 && j==0){
                mayor=a;
                posM=j+1;
                menor=a;
                posm=i+1;
            }
            if(a>mayor){ mayor=a; posM=j+1;}
            if(a<menor){ menor=a; posm=i+1;}
        }
    }
    cout<<"La fila donde se encuentra el menor numero es: "<<posm<<endl;
    cout<<"La columna donde se encuentra el mayor numero es: "<<posM<<endl;
       
}