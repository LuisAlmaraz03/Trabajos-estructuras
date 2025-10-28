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
        if (posfija[i] <= 'z' && posfija[i] >= 'a'){
            if(var.find(posfija[i]) == var.end()){
                cout<<"Ingresa el valor de "<<posfija[i]<<": ";
                double val; cin>>val; cout<<'\n';
                var.insert({posfija[i],val});
            }
            pila.push(var[posfija[i]]);
        }
        else if(posfija[i] == ','){
            int j=i+1;
            string cam;
            while(posfija[j] != ','){
                cam+=posfija[j];
                j++;
            }
            if(!cam.empty()){
                pila.push(stod(cam));
            }
        }
        else{
            double a,b;
            b=pila.top();
            pila.pop();
            a=pila.top();
            pila.pop();
            double resul;
            switch(posfija[i]){
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