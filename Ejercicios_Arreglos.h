#include <iostream>
#include <cmath>
using namespace std;

void Arreglo_1() {
    int arr[8];
    cout << "Ingrese 8 numeros enteros:" << endl;
    for (int i = 0; i < 8; ++i) {
        cin >> arr[i];
    }

    for (int i = 1; i < 8; ++i) {
        if(arr[i]<arr[i-1]){
            int temp = arr[i];
            arr[i] = arr[i-1];
            arr[i-1] = temp;
            i=0;
        }
    }

    cout << "Arreglo ordenado: ";
    for (int i = 0; i < 8; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Arreglo_2() {
    const int TAM = 14;
    cout << "Ingrese una palabra de 14 caracteres: ";
    string pal;
    cin>> pal;
    char buscar;
    cout << "Ingrese el caracter a buscar: ";
    cin >> buscar;

    bool encontrado = false;
    for (int i = 0; i < TAM; ++i) {
        if (pal[i] == buscar) {
            cout << "El caracter '" << buscar << "' se encuentra en la posicion " << ++i << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "DATO NO LOCALIZADO" << endl;
    }
}

void Arreglo_3(){
    const int SIZE = 20;
    float arr1[SIZE], arr2[SIZE], arrSum[SIZE], n;

    cout << "Ingrese la cantidad de numeros flotantes para los arreglos:\n";
    cin >> n;
    cout << "Ingrese los elementos del primer arreglo:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
    }
    cout << "Ingrese los elementos del segundo arreglo:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr2[i];
    }

    for (int i = 0; i < n; ++i) {
        arrSum[i] = arr1[i] + arr2[i];
    }

    cout << "El arreglo suma es:\n";
    for (int i = 0; i < n; ++i) {
        cout << arrSum[i] << " ";
    }
    cout << endl;
}

void Arreglo_4(){
    int n;
    cout << "Ingrese la cantidad de datos: ";
    cin >> n;
    double Datos[n]; 
    cout << "Ingrese los datos:\n";
    for(int i=0; i<n; i++){
        cin >> Datos[i];
    }

    double suma = 0;
    for (int i = 0; i < n; ++i) {
        suma += Datos[i];
    }
    double promedio = suma / n;


    double sumaDesv = 0;
    for (int i = 0; i < n; ++i) {
        sumaDesv += pow(Datos[i] - promedio, 2);
    }
    double desviacionEstandar = sqrt(sumaDesv / n);

    cout << "Promedio: " << promedio << endl;
    cout << "Desviacion estandar: " << desviacionEstandar << endl;
}

void Arreglo_5(){
    int n, pos, elem;
    cout << "Ingrese el tamaño del vector: ";
    cin >> n;
    int vec[n+1]; 
    cout << "Ingrese los elementos del vector:\n";
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }

    cout << "Ingrese la posicion donde insertar (0 a " << n << "): ";
    cin >> pos;
    if (pos < 0 || pos > n) {
        cout << "Posicion invalida.\n";
    }
    pos-=1;
    cout << "Ingrese el elemento a insertar: ";
    cin >> elem;
    for (int i = n; i >= pos; --i) {
        vec[i] = vec[i - 1];
    }
    vec[pos] = elem;

    cout << "Vector resultante:\n";
    for (int v : vec) {
        cout << v << " ";
    }
    cout << endl;
}

void Arreglo_6(){
    int n;
    cout << "Ingrese la cantidad de elementos: ";
    cin >> n;

    int a[n], b[n];
    int count_par = 0, count_impar = 0;
    cout << "Ingrese los elementos:\n";
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        if (num % 2 == 0) {
            a[count_par++] = num;
        } else {
            b[count_impar++] = num;
        }
    }

    cout << "Cantidad de elementos pares: " << count_par << endl;
    cout << "Elementos pares: ";
    for (int i = 0; i < count_par; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "Cantidad de elementos impares: " << count_impar << endl;
    cout << "Elementos impares: ";
    for (int i = 0; i < count_impar; ++i) {
        cout << b[i] << " ";
    }
    cout << endl;
}

void Arreglo_7(){
    int n;
    cout << "Ingrese el tamaño de los vectores: ";
    cin >> n;

    int a[n], b[n];

    cout << "Ingrese los elementos del primer vector:\n";
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << "Ingrese los elementos del segundo vector:\n";
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    int productoEscalar = 0;
    for (int i = 0; i < n; ++i) {
        productoEscalar += a[i] * b[i];
    }

    cout << "El producto escalar es: " << productoEscalar << endl;
}