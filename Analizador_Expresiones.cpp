#include <bits/stdc++.h>
using namespace std;

string trad_pos(string infija){
    stack<char> pila;
    pila.push('(');
    string posfija;
    for(auto c: infija){
        if ((c <= 'z' && c >= 'a') || (c <= '9' && c >= '0'))posfija += c;
        else if(c == '(')pila.push(c);
        else if (c == ')'){
            while(pila.top() != '('){
                posfija += pila.top();
                pila.pop();
            }
            pila.pop();
        }
        else{
            switch(c){
                case '+':
                case '-':
                    while(pila.top() != '('){
                        posfija += pila.top();
                        pila.pop();
                    }
                    pila.push(c);
                    break;
                case '*':
                case '/':
                    while(pila.top() != '(' && pila.top() != '+' && pila.top() != '-'){
                        posfija += pila.top();
                        pila.pop();          
                    }
                    pila.push(c);
                    break;
                case '^':
                    while(pila.top() == '^'){
                        posfija += pila.top();
                        pila.pop();          
                    }
                    pila.push(c);
                    break;
            }
        }
    }
    return posfija;
}

double eva_func(string posfija){
    stack<double> pila;
    unordered_map<char,double> var;
    for(auto c: posfija){
        if (c <= 'z' && c >= 'a'){
            if(var.find(c) == var.end()){
                cout<<"Ingresa el valor de "<<c<<": ";
                double val; cin>>val; cout<<'\n';
                var.insert({c,val});
            }
            pila.push(var[c]);
        }
        else if(c <= '9' && c >= '0'){
            pila.push(c-'0');
        }
        else{
            double a,b;
            b=pila.top();
            pila.pop();
            a=pila.top();
            pila.pop();
            double resul;
            switch(c){
                case '+':
                    resul=b+a;
                    break;
                case '-':
                    resul=b-a;
                    break;
                case '*':
                    resul=b*a;
                    break;
                case '/':
                    resul=a/b;
                    break;
                case '^':
                    resul=pow(a,b);
                    break;
            }
            pila.push(resul);
            
        }
    }
    return pila.top();
}

int main() {
    string infija;
    cin>>infija;
    string posfija;
    posfija = trad_pos(infija);
    cout<<posfija<<'\n';
    cout<<eva_func(posfija)<<'\n';
    return 0;
}