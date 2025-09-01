#include <iostream>
using namespace std;


void sucesion(int n) {
    if (n == 0) return;        
    sucesion(n - 1);           
    cout << n << " \n";          
}

int main() {
    int N;
    cout << "Ingresa un número: ";
    cin >> N;


    sucesion(N);
    cout << endl;

    return 0;
}
