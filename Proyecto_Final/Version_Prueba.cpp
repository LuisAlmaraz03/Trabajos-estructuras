#include <bits/stdc++.h>
using namespace std;

bool esFuncion(const string& str) {
    return str == "sin" || str == "cos" || str == "tan" || 
           str == "log" || str == "ln" || str == "sqrt";
}

int precedencia(const string& op) {
    if (op == "^") return 4;
    if (op == "*" || op == "/") return 3;
    if (op == "+" || op == "-") return 2;
    if (esFuncion(op)) return 5; 
    return 0;
}
string trad_pre(string infija) {
    stack<string> pila;
    pila.push("(");
    string prefija;
    bool num = false;
    
    for(int i = 0; i < infija.size(); i++) {
        char c = infija[i];
        
        if (isalpha(c)) {
            string posible_func;
            int j = i;
            while (j < infija.size() && isalpha(infija[j])) {
                posible_func += infija[j];
                j++;
            }
            
            if (j < infija.size() && infija[j] == '(' && esFuncion(posible_func)) {
                pila.push(posible_func);
                i = j; 
                continue;
            } else {
                if(num) {
                    prefija += ',';
                    num = false;
                }
                prefija += posible_func;
                i = j - 1; 
            }
        }
        else if (c >= '0' && c <= '9') {
            if(num) {
                prefija += c;
            } else {
                if(!prefija.empty() && prefija.back() != ',') {
                    prefija += ',';
                }
                prefija += c;
                num = true;
            }
            
            if (i + 1 >= infija.size() || !(infija[i + 1] >= '0' && infija[i + 1] <= '9')) {
                num = false;
                if (i + 1 < infija.size() && infija[i + 1] != ',') {
                    prefija += ',';
                }
            }
        }
        else if (!(c >= '0' && c <= '9') && num) {
            prefija += ',';
            num = false;
        }
        else if(c == '(') {
            pila.push("(");
            if(num) {
                prefija += ',';
                num = false;
            }
        }
        else if (c == ')') {
            while(!pila.empty() && pila.top() != "(") {
                if(prefija.back() != ',') prefija += ',';
                prefija += pila.top();
                pila.pop();
            }
            if (!pila.empty()) pila.pop();
            num = false;
            
            if (!pila.empty() && esFuncion(pila.top())) {
                if(prefija.back() != ',') prefija += ',';
                prefija += pila.top();
                pila.pop();
            }
        }
        else if (c == ' ') {
            continue;
        }
        else {
            string operador(1, c);
            int prec_actual = precedencia(operador);
            
            if(num) {
                prefija += ',';
                num = false;
            }
            
            while(!pila.empty() && pila.top() != "(" && 
                   precedencia(pila.top()) >= prec_actual) {
                if(prefija.back() != ',') prefija += ',';
                prefija += pila.top();
                pila.pop();
            }
            
            if(prefija.empty() || prefija.back() != ',') prefija += ',';
            pila.push(operador);
        }
    }
    
    if(num) prefija += ',';
    
    while(!pila.empty() && pila.top() != "(") {
        if(prefija.back() != ',') prefija += ',';
        prefija += pila.top();
        pila.pop();
    }
    
    return prefija;
}
string trad_pos(string infija) {
    stack<string> pila;
    pila.push("(");
    string posfija;
    bool num = false;
    
    for(int i = 0; i < infija.size(); i++) {
        char c = infija[i];
        
        if (isalpha(c)) {
            string posible_func;
            int j = i;
            while (j < infija.size() && isalpha(infija[j])) {
                posible_func += infija[j];
                j++;
            }
            
            if (j < infija.size() && infija[j] == '(' && esFuncion(posible_func)) {
                pila.push(posible_func);
                i = j; 
                continue;
            } else {
                if(num) {
                    posfija += ',';
                    num = false;
                }
                posfija += posible_func;
                i = j - 1; 
            }
        }
        else if (c >= '0' && c <= '9') {
            if(num) {
                posfija += c;
            } else {
                if(!posfija.empty() && posfija.back() != ',') {
                    posfija += ',';
                }
                posfija += c;
                num = true;
            }
            
            if (i + 1 >= infija.size() || !(infija[i + 1] >= '0' && infija[i + 1] <= '9')) {
                num = false;
                if (i + 1 < infija.size() && infija[i + 1] != ',') {
                    posfija += ',';
                }
            }
        }
        else if (!(c >= '0' && c <= '9') && num) {
            posfija += ',';
            num = false;
        }
        else if(c == '(') {
            pila.push("(");
            if(num) {
                posfija += ',';
                num = false;
            }
        }
        else if (c == ')') {
            while(!pila.empty() && pila.top() != "(") {
                if(posfija.back() != ',') posfija += ',';
                posfija += pila.top();
                pila.pop();
            }
            if (!pila.empty()) pila.pop();
            num = false;
            
            if (!pila.empty() && esFuncion(pila.top())) {
                if(posfija.back() != ',') posfija += ',';
                posfija += pila.top();
                pila.pop();
            }
        }
        else if (c == ' ') {
            continue;
        }
        else {
            string operador(1, c);
            int prec_actual = precedencia(operador);
            
            if(num) {
                posfija += ',';
                num = false;
            }
            
            while(!pila.empty() && pila.top() != "(" && 
                   precedencia(pila.top()) >= prec_actual) {
                if(posfija.back() != ',') posfija += ',';
                posfija += pila.top();
                pila.pop();
            }
            
            if(posfija.empty() || posfija.back() != ',') posfija += ',';
            pila.push(operador);
        }
    }
    
    if(num) posfija += ',';
    
    while(!pila.empty() && pila.top() != "(") {
        if(posfija.back() != ',') posfija += ',';
        posfija += pila.top();
        pila.pop();
    }
    
    return posfija;
}
double eva_func(string posfija) {
    stack<double> pila;
    unordered_map<char, double> var;
    
    for(int i = 0; i < posfija.size(); i++) {
        if (posfija[i] == ',') {
            continue;
        }
        else if (posfija[i] >= 'a' && posfija[i] <= 'z' && 
                 (i + 1 >= posfija.size() || posfija[i + 1] == ',')) {
            if(var.find(posfija[i]) == var.end()) {
                cout << "\nIngresa el valor de " << posfija[i] << ": ";
                double val; 
                cin >> val;
                var.insert({posfija[i], val});
            }
            pila.push(var[posfija[i]]);
        }
        else if (isalpha(posfija[i])) {
            string funcion;
            while(i < posfija.size() && isalpha(posfija[i])) {
                funcion += posfija[i];
                i++;
            }
            i--; 
            
            if (pila.empty()) {
                cerr << "Error: Falta argumento para " << funcion << endl;
                return 0;
            }
            
            double arg = pila.top(); 
            pila.pop();
            double resultado;
            
            if (funcion == "sin") resultado = sin(arg);
            else if (funcion == "cos") resultado = cos(arg);
            else if (funcion == "tan") resultado = tan(arg);
            else if (funcion == "log") resultado = log10(arg);
            else if (funcion == "ln") resultado = log(arg);
            else if (funcion == "sqrt") {
                if (arg < 0) {
                    cerr << "Error: Raiz cuadrada de numero negativo" << endl;
                    return 0;
                }
                resultado = sqrt(arg);
            }
            else {
                if (funcion.size() == 1) {
                    if(var.find(funcion[0]) == var.end()) {
                        cout << "\nIngresa el valor de " << funcion[0] << ": ";
                        double val; 
                        cin >> val;
                        var.insert({funcion[0], val});
                    }
                    resultado = var[funcion[0]];
                } else {
                    cerr << "Error: Funcion desconocida " << funcion << endl;
                    return 0;
                }
            }
            
            pila.push(resultado);
        }
        else if (posfija[i] >= '0' && posfija[i] <= '9') {
            int j = i;
            string num_str;
            while(j < posfija.size() && posfija[j] >= '0' && posfija[j] <= '9') {
                num_str += posfija[j];
                j++;
            }
            pila.push(stod(num_str));
            i = j - 1;
        }
        else {
            if (pila.size() < 2) {
                cerr << "Error: Faltan operandos para el operador " << posfija[i] << endl;
                return 0;
            }
            
            double b = pila.top(); 
            pila.pop();
            double a = pila.top(); 
            pila.pop();
            double resultado;
            
            switch(posfija[i]) {
                case '+': resultado = a + b; break;
                case '-': resultado = a - b; break;
                case '*': resultado = a * b; break;
                case '/': 
                    if(b == 0) {
                        cerr << "Error: Division por cero" << endl;
                        return 0;
                    }
                    resultado = a / b; 
                    break;
                case '^': resultado = pow(a, b); break;
                default:
                    cerr << "Error: Operador desconocido" << endl;
                    return 0;
            }
            pila.push(resultado);
        }
    }
    
    if(pila.size() != 1) {
        cerr << "Error: Expresion mal formada" << endl;
        return 0;
    }
    
    cout << "\nLa expresion evaluada es: \n";
    return pila.top();
}

int main() {
    string infija;
    cout << "Ingresa la expresion infija: \n";
    getline(cin, infija);
    
    string posfija = trad_pos(infija);
    cout << "\nLa expresion traducida a posfija es: \n" << posfija << '\n';
    
    double resultado = eva_func(posfija);
    cout << resultado << '\n';
    
    return 0;
}