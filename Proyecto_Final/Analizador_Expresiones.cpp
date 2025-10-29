#include <bits/stdc++.h>
using namespace std;

string trad_pos(string infija){
    stack<char> pila;
    pila.push('(');
    string posfija;
    bool num = false;
    for(auto c: infija){
        if(!(c >= '0' && c <= '9') && num){
            posfija += ',';
            num = false;
        }
        if ((c <= 'z' && c >= 'a')){
            if(num){
                posfija += ',';
            }
            num = false;
            posfija += c;
        }
        else if (c <= '9' && c >= '0'){
            if(!num){
                posfija += ',';
                posfija += c;
                num = true;
            }    
            else{
                posfija += c;
            }
        }
        else if(c == '(')pila.push(c);
        else if (c == ')'){
            while(pila.top() != '('){
                posfija += pila.top();
                pila.pop();
            }
            pila.pop();
            num = false;
        }
        else{
            switch(c){
                case '+':
                case '-':
                    while(pila.top() != '('){    
                        posfija += pila.top();
                        pila.pop();
                    }
                    if(posfija.empty() || posfija.back() != ',') posfija += ',';
                    pila.push(c);
                    break;
                case '*':
                case '/':
                    while(pila.top() != '(' && pila.top() != '+' && pila.top() != '-'){
                        posfija += pila.top();
                        pila.pop();          
                    }
                    if(posfija.empty() || posfija.back() != ',') posfija += ',';
                    pila.push(c);
                    break;
                case '^':
                    while(pila.top() == '^'){
                        posfija += pila.top();
                        pila.pop();          
                    }
                    if(posfija.empty() || posfija.back() != ',') posfija += ',';
                    pila.push(c);
                    break;
            }
            num = false;
        }
    }
    if(num) posfija += ',';
    return posfija;
}

double eva_func(string posfija){
    stack<double> pila;
    unordered_map<char,double> var;
    
    for(int i=0; i<posfija.size(); i++){
        if (posfija[i] >= 'a' && posfija[i] <= 'z'){
            if(var.find(posfija[i]) == var.end()){
                cout<<"\nIngresa el valor de "<<posfija[i]<<": ";
                double val; cin>>val;
                var.insert({posfija[i],val});
            }
            pila.push(var[posfija[i]]);
        }
        else if(posfija[i] == ','){
            continue;
        }
        else if(posfija[i] >= '0' && posfija[i] <= '9'){
            int j = i;
            string num_str;
            while(j < posfija.size() && posfija[j] >= '0' && posfija[j] <= '9'){
                num_str += posfija[j];
                j++;
            }
            pila.push(stod(num_str));
            i = j - 1;
        }
        else{
            if(pila.size() < 2){
                cerr << "Error: Faltan operandos para el operador " << posfija[i] << endl;
                return 0;
            }
            double b = pila.top(); pila.pop();
            double a = pila.top(); pila.pop();
            double resul;
            
            switch(posfija[i]){
                case '+': resul = a + b; break;
                case '-': resul = a - b; break;
                case '*': resul = a * b; break;
                case '/': 
                    if(b == 0){
                        cerr << "Error: Division por cero" << endl;
                        return 0;
                    }
                    resul = a / b; 
                    break;
                case '^': resul = pow(a, b); break;
                default:
                    cerr << "Error: Operador desconocido" << endl;
                    return 0;
            }
            pila.push(resul);
        }
    }
    
    if(pila.size() != 1){
        cerr << "Error: Expresion mal formada" << endl;
        return 0;
    }
    cout<<"\nLa expresion evaluada es: \n";
    return pila.top();
}

int main() {
    string infija;
    cout<<"Ingresa la expresion infija: \n";
    cin>>infija;
    string posfija;
    posfija = trad_pos(infija);
    cout<<"\nLa expresion traducida a posfija es: \n"<<posfija<<'\n';
    double resultado = eva_func(posfija);
    cout<<resultado<<'\n';
    return 0;
}