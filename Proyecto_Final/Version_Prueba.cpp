#include <bits/stdc++.h>
using namespace std;

// Función auxiliar para verificar si es una función
bool esFuncion(const string& str) {
    return str == "sin" || str == "cos" || str == "tan" || 
           str == "log" || str == "ln" || str == "sqrt";
}

// Función auxiliar para obtener precedencia
int precedencia(const string& op) {
    if (op == "^") return 4;
    if (op == "*" || op == "/") return 3;
    if (op == "+" || op == "-") return 2;
    if (esFuncion(op)) return 5; // Funciones tienen alta precedencia
    return 0;
}

string trad_pos(string infija) {
    stack<string> pila;
    pila.push("(");
    string posfija;
    bool num = false;
    
    for(int i = 0; i < infija.size(); i++) {
        char c = infija[i];
        
        // Si es el inicio de una posible función
        if (isalpha(c)) {
            string posible_func;
            int j = i;
            // Leer la palabra completa
            while (j < infija.size() && isalpha(infija[j])) {
                posible_func += infija[j];
                j++;
            }
            
            // Verificar si es una función (termina con paréntesis)
            if (j < infija.size() && infija[j] == '(' && esFuncion(posible_func)) {
                pila.push(posible_func);
                i = j; // Saltar al paréntesis
                continue;
            } else {
                // Es una variable simple
                if(num) {
                    posfija += ',';
                    num = false;
                }
                posfija += posible_func;
                i = j - 1; // Ajustar índice
            }
        }
        // Números de múltiples dígitos
        else if (c >= '0' && c <= '9') {
            if(num) {
                posfija += c; // Continuar número existente
            } else {
                // Nuevo número
                if(!posfija.empty() && posfija.back() != ',') {
                    posfija += ',';
                }
                posfija += c;
                num = true;
            }
            
            // Verificar si el siguiente carácter no es dígito
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
            
            // Si después de cerrar paréntesis hay una función en la pila
            if (!pila.empty() && esFuncion(pila.top())) {
                if(posfija.back() != ',') posfija += ',';
                posfija += pila.top();
                pila.pop();
            }
        }
        else if (c == ' ') {
            // Ignorar espacios
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
    
    // Vaciar pila
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
        // Variables (letras minúsculas individuales)
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
        // Funciones (palabras completas)
        else if (isalpha(posfija[i])) {
            string funcion;
            while(i < posfija.size() && isalpha(posfija[i])) {
                funcion += posfija[i];
                i++;
            }
            i--; // Ajustar índice
            
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
                    cerr << "Error: Raíz cuadrada de número negativo" << endl;
                    return 0;
                }
                resultado = sqrt(arg);
            }
            else {
                // Si no es función reconocida, asumir variable
                if (funcion.size() == 1) {
                    if(var.find(funcion[0]) == var.end()) {
                        cout << "\nIngresa el valor de " << funcion[0] << ": ";
                        double val; 
                        cin >> val;
                        var.insert({funcion[0], val});
                    }
                    resultado = var[funcion[0]];
                } else {
                    cerr << "Error: Función desconocida " << funcion << endl;
                    return 0;
                }
            }
            
            pila.push(resultado);
        }
        // Números
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
        // Operadores
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
                        cerr << "Error: División por cero" << endl;
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
        cerr << "Error: Expresión mal formada" << endl;
        return 0;
    }
    
    cout << "\nLa expresión evaluada es: \n";
    return pila.top();
}

int main() {
    string infija;
    cout << "Ingresa la expresión infija: \n";
    getline(cin, infija);
    
    string posfija = trad_pos(infija);
    cout << "\nLa expresión traducida a posfija es: \n" << posfija << '\n';
    
    double resultado = eva_func(posfija);
    cout << resultado << '\n';
    
    return 0;
}