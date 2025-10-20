// ===== CÓDIGOS ESPECIALIZADOS (451-500) =====

// 451. Manejo de archivos - lectura/escritura
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    // Escribir archivo
    ofstream archivo_salida("datos.txt");
    if (archivo_salida.is_open()) {
        archivo_salida << "Primera línea\n";
        archivo_salida << "Segunda línea\n";
        archivo_salida << "Número: " << 42 << endl;
        archivo_salida.close();
    }
    
    // Leer archivo
    ifstream archivo_entrada("datos.txt");
    string linea;
    if (archivo_entrada.is_open()) {
        cout << "Contenido del archivo:" << endl;
        while (getline(archivo_entrada, linea)) {
            cout << linea << endl;
        }
        archivo_entrada.close();
    }
    
    return 0;
}

// 452. Manejo de archivos CSV
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;
struct Empleado {
    string nombre;
    int edad;
    double salario;
};
vector<string> dividirCSV(const string& linea, char delimitador = ',') {
    vector<string> tokens;
    stringstream ss(linea);
    string token;
    
    while (getline(ss, token, delimitador)) {
        tokens.push_back(token);
    }
    return tokens;
}
int main() {
    // Escribir CSV
    ofstream csv_salida("empleados.csv");
    csv_salida << "Nombre,Edad,Salario\n";
    csv_salida << "Juan Perez,30,50000\n";
    csv_salida << "Ana Garcia,25,45000\n";
    csv_salida << "Luis Rodriguez,35,60000\n";
    csv_salida.close();
    
    // Leer CSV
    vector<Empleado> empleados;
    ifstream csv_entrada("empleados.csv");
    string linea;
    
    getline(csv_entrada, linea); // Saltar encabezado
    
    while (getline(csv_entrada, linea)) {
        vector<string> campos = dividirCSV(linea);
        if (campos.size() == 3) {
            Empleado emp;
            emp.nombre = campos[0];
            emp.edad = stoi(campos[1]);
            emp.salario = stod(campos[2]);
            empleados.push_back(emp);
        }
    }
    csv_entrada.close();
    
    cout << "Empleados leídos:" << endl;
    for (const auto& emp : empleados) {
        cout << "Nombre: " << emp.nombre << ", Edad: " << emp.edad 
             << ", Salario: $" << emp.salario << endl;
    }
    
    return 0;
}

// 453. Archivo binario
#include <iostream>
#include <fstream>
using namespace std;
struct Persona {
    char nombre[50];
    int edad;
    double salario;
};
int main() {
    // Escribir archivo binario
    Persona personas[] = {
        {"Juan", 30, 50000.0},
        {"Ana", 25, 45000.0},
        {"Luis", 35, 60000.0}
    };
    
    ofstream archivo_bin("personas.dat", ios::binary);
    archivo_bin.write(reinterpret_cast<char*>(personas), sizeof(personas));
    archivo_bin.close();
    
    // Leer archivo binario
    ifstream archivo_entrada("personas.dat", ios::binary);
    Persona persona_leida;
    
    cout << "Datos leídos del archivo binario:" << endl;
    while (archivo_entrada.read(reinterpret_cast<char*>(&persona_leida), sizeof(Persona))) {
        cout << "Nombre: " << persona_leida.nombre 
             << ", Edad: " << persona_leida.edad 
             << ", Salario: $" << persona_leida.salario << endl;
    }
    archivo_entrada.close();
    
    return 0;
}

// 454. Sistema de logging
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;
enum LogLevel {
    INFO, WARNING, ERROR
};
class Logger {
private:
    ofstream archivo;
    string nivelAString(LogLevel nivel) {
        switch (nivel) {
            case INFO: return "INFO";
            case WARNING: return "WARNING";
            case ERROR: return "ERROR";
            default: return "UNKNOWN";
        }
    }
    string obtenerTimestamp() {
        time_t rawtime;
        struct tm* timeinfo;
        char buffer[80];
        
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
        
        return string(buffer);
    }
public:
    Logger(const string& nombreArchivo) {
        archivo.open(nombreArchivo, ios::app);
    }
    ~Logger() {
        if (archivo.is_open()) archivo.close();
    }
    void log(LogLevel nivel, const string& mensaje) {
        if (archivo.is_open()) {
            archivo << "[" << obtenerTimestamp() << "] " 
                   << "[" << nivelAString(nivel) << "] " 
                   << mensaje << endl;
            archivo.flush();
        }
    }
};
int main() {
    Logger logger("aplicacion.log");
    
    logger.log(INFO, "Aplicación iniciada");
    logger.log(WARNING, "Advertencia: memoria baja");
    logger.log(ERROR, "Error: fallo en la conexión");
    logger.log(INFO, "Aplicación terminada");
    
    cout << "Logs escritos en aplicacion.log" << endl;
    return 0;
}

// 455. Parser JSON simple
#include <iostream>
#include <string>
#include <map>
using namespace std;
class JSONParser {
private:
    size_t pos;
    string json;
    
    void saltarEspacios() {
        while (pos < json.length() && isspace(json[pos])) pos++;
    }
    
    string parseString() {
        if (json[pos] != '"') return "";
        pos++; // Saltar comilla inicial
        
        string resultado;
        while (pos < json.length() && json[pos] != '"') {
            resultado += json[pos++];
        }
        pos++; // Saltar comilla final
        return resultado;
    }
    
public:
    map<string, string> parse(const string& jsonStr) {
        json = jsonStr;
        pos = 0;
        map<string, string> resultado;
        
        saltarEspacios();
        if (json[pos] != '{') return resultado;
        pos++;
        
        while (pos < json.length()) {
            saltarEspacios();
            if (json[pos] == '}') break;
            
            string clave = parseString();
            saltarEspacios();
            
            if (json[pos] == ':') {
                pos++;
                saltarEspacios();
                string valor = parseString();
                resultado[clave] = valor;
            }
            
            saltarEspacios();
            if (json[pos] == ',') pos++;
        }
        
        return resultado;
    }
};
int main() {
    string jsonString = R"({"nombre": "Juan", "edad": "30", "ciudad": "Madrid"})";
    
    JSONParser parser;
    auto datos = parser.parse(jsonString);
    
    cout << "Datos parseados:" << endl;
    for (const auto& par : datos) {
        cout << par.first << ": " << par.second << endl;
    }
    
    return 0;
}

// 456. Calculadora de expresiones
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;
class CalculadoraExpresiones {
private:
    int precedencia(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }
    
    double aplicarOperacion(double a, double b, char op) {
        switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
            default: return 0;
        }
    }
    
public:
    double evaluar(string expresion) {
        stack<double> valores;
        stack<char> operadores;
        
        for (int i = 0; i < expresion.length(); i++) {
            if (isspace(expresion[i])) continue;
            
            if (isdigit(expresion[i])) {
                double valor = 0;
                while (i < expresion.length() && (isdigit(expresion[i]) || expresion[i] == '.')) {
                    if (expresion[i] == '.') {
                        i++;
                        double decimal = 0.1;
                        while (i < expresion.length() && isdigit(expresion[i])) {
                            valor += (expresion[i] - '0') * decimal;
                            decimal *= 0.1;
                            i++;
                        }
                        break;
                    } else {
                        valor = valor * 10 + (expresion[i] - '0');
                        i++;
                    }
                }
                i--;
                valores.push(valor);
            } else if (expresion[i] == '(') {
                operadores.push(expresion[i]);
            } else if (expresion[i] == ')') {
                while (!operadores.empty() && operadores.top() != '(') {
                    double b = valores.top(); valores.pop();
                    double a = valores.top(); valores.pop();
                    char op = operadores.top(); operadores.pop();
                    valores.push(aplicarOperacion(a, b, op));
                }
                operadores.pop(); // Remover '('
            } else {
                while (!operadores.empty() && precedencia(operadores.top()) >= precedencia(expresion[i])) {
                    double b = valores.top(); valores.pop();
                    double a = valores.top(); valores.pop();
                    char op = operadores.top(); operadores.pop();
                    valores.push(aplicarOperacion(a, b, op));
                }
                operadores.push(expresion[i]);
            }
        }
        
        while (!operadores.empty()) {
            double b = valores.top(); valores.pop();
            double a = valores.top(); valores.pop();
            char op = operadores.top(); operadores.pop();
            valores.push(aplicarOperacion(a, b, op));
        }
        
        return valores.top();
    }
};
int main() {
    CalculadoraExpresiones calc;
    
    string expresiones[] = {
        "3 + 5 * 2",
        "(3 + 5) * 2",
        "10 / 2 + 3",
        "2.5 * 4 + 1.5"
    };
    
    for (const string& expr : expresiones) {
        double resultado = calc.evaluar(expr);
        cout << expr << " = " << resultado << endl;
    }
    
    return 0;
}

// 457. Sistema de eventos simple
#include <iostream>
#include <vector>
#include <functional>
#include <map>
using namespace std;
template<typename... Args>
class Event {
private:
    vector<function<void(Args...)>> callbacks;
    
public:
    void subscribe(function<void(Args...)> callback) {
        callbacks.push_back(callback);
    }
    
    void trigger(Args... args) {
        for (auto& callback : callbacks) {
            callback(args...);
        }
    }
};
class EventManager {
private:
    map<string, Event<string, int>> eventos;
    
public:
    void subscribe(const string& nombreEvento, function<void(string, int)> callback) {
        eventos[nombreEvento].subscribe(callback);
    }
    
    void trigger(const string& nombreEvento, const string& mensaje, int valor) {
        if (eventos.find(nombreEvento) != eventos.end()) {
            eventos[nombreEvento].trigger(mensaje, valor);
        }
    }
};
void manejadorUsuario(string mensaje, int valor) {
    cout << "Manejador Usuario: " << mensaje << " (" << valor << ")" << endl;
}
void manejadorSistema(string mensaje, int valor) {
    cout << "Manejador Sistema: " << mensaje << " [" << valor << "]" << endl;
}
int main() {
    EventManager manager;
    
    manager.subscribe("usuario_login", manejadorUsuario);
    manager.subscribe("usuario_login", manejadorSistema);
    manager.subscribe("error", [](string msg, int codigo) {
        cout << "Error Lambda: " << msg << " - Código: " << codigo << endl;
    });
    
    manager.trigger("usuario_login", "Usuario Juan conectado", 123);
    manager.trigger("error", "Fallo en la base de datos", 500);
    
    return 0;
}

// 458. Cache LRU (Least Recently Used)
#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;
template<typename K, typename V>
class LRUCache {
private:
    int capacidad;
    list<pair<K, V>> cache;
    unordered_map<K, typename list<pair<K, V>>::iterator> mapa;
    
public:
    LRUCache(int cap) : capacidad(cap) {}
    
    V get(const K& clave) {
        auto it = mapa.find(clave);
        if (it == mapa.end()) {
            throw runtime_error("Clave no encontrada");
        }
        
        // Mover al frente
        cache.splice(cache.begin(), cache, it->second);
        return it->second->second;
    }
    
    void put(const K& clave, const V& valor) {
        auto it = mapa.find(clave);
        
        if (it != mapa.end()) {
            // Actualizar valor existente
            it->second->second = valor;
            cache.splice(cache.begin(), cache, it->second);
            return;
        }
        
        if (cache.size() >= capacidad) {
            // Eliminar el menos usado
            auto ultimo = cache.back();
            mapa.erase(ultimo.first);
            cache.pop_back();
        }
        
        // Añadir nuevo elemento
        cache.emplace_front(clave, valor);
        mapa[clave] = cache.begin();
    }
    
    void mostrar() {
        cout << "Cache (más reciente primero): ";
        for (const auto& par : cache) {
            cout << "[" << par.first << ":" << par.second << "] ";
        }
        cout << endl;
    }
};
int main() {
    LRUCache<int, string> cache(3);
    
    cache.put(1, "uno");
    cache.put(2, "dos");
    cache.put(3, "tres");
    cache.mostrar();
    
    cout << "Get(1): " << cache.get(1) << endl;
    cache.mostrar();
    
    cache.put(4, "cuatro"); // Esto debería eliminar el 2
    cache.mostrar();
    
    return 0;
}

// 459. Máquina de estados finitos
#include <iostream>
#include <map>
#include <functional>
using namespace std;
enum Estado {
    APAGADO, ENCENDIDO, PAUSADO
};
enum Evento {
    ENCENDER, APAGAR, PAUSAR, REANUDAR
};
class MaquinaEstados {
private:
    Estado estadoActual;
    map<pair<Estado, Evento>, Estado> transiciones;
    map<Estado, function<void()>> accionesEntrada;
    map<Estado, function<void()>> accionesSalida;
    
public:
    MaquinaEstados(Estado inicial) : estadoActual(inicial) {
        // Definir transiciones
        transiciones[{APAGADO, ENCENDER}] = ENCENDIDO;
        transiciones[{ENCENDIDO, APAGAR}] = APAGADO;
        transiciones[{ENCENDIDO, PAUSAR}] = PAUSADO;
        transiciones[{PAUSADO, REANUDAR}] = ENCENDIDO;
        transiciones[{PAUSADO, APAGAR}] = APAGADO;
        
        // Definir acciones
        accionesEntrada[APAGADO] = []() { cout << "Entrando en estado APAGADO" << endl; };
        accionesEntrada[ENCENDIDO] = []() { cout << "Entrando en estado ENCENDIDO" << endl; };
        accionesEntrada[PAUSADO] = []() { cout << "Entrando en estado PAUSADO" << endl; };
        
        accionesSalida[APAGADO] = []() { cout << "Saliendo del estado APAGADO" << endl; };
        accionesSalida[ENCENDIDO] = []() { cout << "Saliendo del estado ENCENDIDO" << endl; };
        accionesSalida[PAUSADO] = []() { cout << "Saliendo del estado PAUSADO" << endl; };
    }
    
    bool procesarEvento(Evento evento) {
        auto transicion = transiciones.find({estadoActual, evento});
        if (transicion != transiciones.end()) {
            // Ejecutar acción de salida
            if (accionesSalida[estadoActual]) {
                accionesSalida[estadoActual]();
            }
            
            // Cambiar estado
            estadoActual = transicion->second;
            
            // Ejecutar acción de entrada
            if (accionesEntrada[estadoActual]) {
                accionesEntrada[estadoActual]();
            }
            
            return true;
        }
        return false;
    }
    
    Estado getEstadoActual() const {
        return estadoActual;
    }
};
string estadoAString(Estado estado) {
    switch (estado) {
        case APAGADO: return "APAGADO";
        case ENCENDIDO: return "ENCENDIDO";
        case PAUSADO: return "PAUSADO";
        default: return "DESCONOCIDO";
    }
}
int main() {
    MaquinaEstados maquina(APAGADO);
    
    cout << "Estado inicial: " << estadoAString(maquina.getEstadoActual()) << endl;
    
    maquina.procesarEvento(ENCENDER);
    cout << "Después de ENCENDER: " << estadoAString(maquina.getEstadoActual()) << endl;
    
    maquina.procesarEvento(PAUSAR);
    cout << "Después de PAUSAR: " << estadoAString(maquina.getEstadoActual()) << endl;
    
    maquina.procesarEvento(REANUDAR);
    cout << "Después de REANUDAR: " << estadoAString(maquina.getEstadoActual()) << endl;
    
    maquina.procesarEvento(APAGAR);
    cout << "Después de APAGAR: " << estadoAString(maquina.getEstadoActual()) << endl;
    
    return 0;
}

// 460. Pool de objetos
#include <iostream>
#include <queue>
#include <memory>
#include <mutex>
using namespace std;
template<typename T>
class ObjectPool {
private:
    queue<unique_ptr<T>> pool;
    mutex mtx;
    
public:
    unique_ptr<T> acquire() {
        lock_guard<mutex> lock(mtx);
        if (pool.empty()) {
            return make_unique<T>();
        } else {
            auto obj = move(pool.front());
            pool.pop();
            return obj;
        }
    }
    
    void release(unique_ptr<T> obj) {
        lock_guard<mutex> lock(mtx);
        pool.push(move(obj));
    }
    
    size_t size() const {
        lock_guard<mutex> lock(mtx);
        return pool.size();
    }
};
class ExpensiveObject {
public:
    int id;
    static int contador;
    
    ExpensiveObject() {
        id = ++contador;
        cout << "Objeto caro " << id << " creado" << endl;
    }
    
    ~ExpensiveObject() {
        cout << "Objeto caro " << id << " destruido" << endl;
    }
    
    void reset() {
        cout << "Objeto " << id << " reseteado" << endl;
    }
    
    void usar() {
        cout << "Usando objeto " << id << endl;
    }
};
int ExpensiveObject::contador = 0;
int main() {
    ObjectPool<ExpensiveObject> pool;
    
    cout << "=== Adquiriendo objetos ===" << endl;
    auto obj1 = pool.acquire();
    auto obj2 = pool.acquire();
    
    obj1->usar();
    obj2->usar();
    
    cout << "\n=== Liberando objetos ===" << endl;
    pool.release(move(obj1));
    pool.release(move(obj2));
    
    cout << "Objetos en pool: " << pool.size() << endl;
    
    cout << "\n=== Reutilizando objetos ===" << endl;
    auto obj3 = pool.acquire();
    obj3->reset();
    obj3->usar();
    
    return 0;
}

// 461. Serialización de objetos
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
class Serializable {
public:
    virtual string serialize() const = 0;
    virtual void deserialize(const string& data) = 0;
    virtual ~Serializable() = default;
};
class Persona : public Serializable {
public:
    string nombre;
    int edad;
    double salario;
    
    Persona() = default;
    Persona(const string& n, int e, double s) : nombre(n), edad(e), salario(s) {}
    
    string serialize() const override {
        ostringstream oss;
        oss << nombre << "|" << edad << "|" << salario;
        return oss.str();
    }
    
    void deserialize(const string& data) override {
        istringstream iss(data);
        string token;
        
        getline(iss, nombre, '|');
        getline(iss, token, '|');
        edad = stoi(token);
        getline(iss, token, '|');
        salario = stod(token);
    }
    
    void mostrar() const {
        cout << "Persona: " << nombre << ", " << edad << " años, $" << salario << endl;
    }
};
class Serializador {
public:
    static string serializarLista(const vector<Persona>& personas) {
        ostringstream oss;
        oss << personas.size() << "\n";
        for (const auto& p : personas) {
            oss << p.serialize() << "\n";
        }
        return oss.str();
    }
    
    static vector<Persona> deserializarLista(const string& data) {
        vector<Persona> personas;
        istringstream iss(data);
        string linea;
        
        getline(iss, linea);
        int count = stoi(linea);
        
        for (int i = 0; i < count; i++) {
            getline(iss, linea);
            Persona p;
            p.deserialize(linea);
            personas.push_back(p);
        }
        
        return personas;
    }
};
int main() {
    vector<Persona> personas = {
        {"Juan", 30, 50000},
        {"Ana", 25, 45000},
        {"Luis", 35, 60000}
    };
    
    cout << "Personas originales:" << endl;
    for (const auto& p : personas) {
        p.mostrar();
    }
    
    string datos = Serializador::serializarLista(personas);
    cout << "\nDatos serializados:\n" << datos << endl;
    
    vector<Persona> personasDeserializadas = Serializador::deserializarLista(datos);
    
    cout << "Personas deserializadas:" << endl;
    for (const auto& p : personasDeserializadas) {
        p.mostrar();
    }
    
    return 0;
}

// 462. Sistema de plugins
#include <iostream>
#include <map>
#include <memory>
#include <functional>
using namespace std;
class Plugin {
public:
    virtual ~Plugin() = default;
    virtual string getName() const = 0;
    virtual void execute() = 0;
};
class PluginMath : public Plugin {
public:
    string getName() const override {
        return "MathPlugin";
    }
    
    void execute() override {
        cout << "Ejecutando plugin de matemáticas: 2 + 2 = " << (2 + 2) << endl;
    }
};
class PluginString : public Plugin {
public:
    string getName() const override {
        return "StringPlugin";
    }
    
    void execute() override {
        cout << "Ejecutando plugin de strings: Hola Mundo en mayúsculas: HOLA MUNDO" << endl;
    }
};
class PluginManager {
private:
    map<string, unique_ptr<Plugin>> plugins;
    map<string, function<unique_ptr<Plugin>()>> factories;
    
public:
    template<typename T>
    void registerPlugin(const string& name) {
        factories[name] = []() { return make_unique<T>(); };
    }
    
    bool loadPlugin(const string& name) {
        auto it = factories.find(name);
        if (it != factories.end()) {
            plugins[name] = it->second();
            cout << "Plugin '" << name << "' cargado" << endl;
            return true;
        }
        cout << "Plugin '" << name << "' no encontrado" << endl;
        return false;
    }
    
    void unloadPlugin(const string& name) {
        plugins.erase(name);
        cout << "Plugin '" << name << "' descargado" << endl;
    }
    
    void executePlugin(const string& name) {
        auto it = plugins.find(name);
        if (it != plugins.end()) {
            it->second->execute();
        } else {
            cout << "Plugin '" << name << "' no está cargado" << endl;
        }
    }
    
    void listPlugins() {
        cout << "Plugins disponibles: ";
        for (const auto& factory : factories) {
            cout << factory.first << " ";
        }
        cout << endl;
        
        cout << "Plugins cargados: ";
        for (const auto& plugin : plugins) {
            cout << plugin.first << " ";
        }
        cout << endl;
    }
};
int main() {
    PluginManager manager;
    
    // Registrar plugins
    manager.registerPlugin<PluginMath>("math");
    manager.registerPlugin<PluginString>("string");
    
    manager.listPlugins();
    
    // Cargar y ejecutar plugins
    manager.loadPlugin("math");
    manager.loadPlugin("string");
    
    manager.listPlugins();
    
    manager.executePlugin("math");
    manager.executePlugin("string");
    
    // Descargar plugin
    manager.unloadPlugin("math");
    manager.executePlugin("math"); // Debería fallar
    
    return 0;
}

// 463. Expresiones regulares simples
#include <iostream>
#include <string>
#include <regex>
using namespace std;
class RegexValidator {
public:
    static bool validarEmail(const string& email) {
        regex pattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
        return regex_match(email, pattern);
    }
    
    static bool validarTelefono(const string& telefono) {
        regex pattern(R"(^\+?[1-9]\d{1,14}$)"); // Formato internacional simple
        return regex_match(telefono, pattern);
    }
    
    static bool validarIP(const string& ip) {
        regex pattern(R"(^((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$)");
        return regex_match(ip, pattern);
    }
    
    static vector<string> extraerNumeros(const string& texto) {
        vector<string> numeros;
        regex pattern(R"(\d+)");
        sregex_iterator iter(texto.begin(), texto.end(), pattern);
        sregex_iterator end;
        
        while (iter != end) {
            numeros.push_back(iter->str());
            ++iter;
        }
        
        return numeros;
    }
    
    static string reemplazarPalabras(const string& texto, const string& buscar, const string& reemplazar) {
        regex pattern(buscar);
        return regex_replace(texto, pattern, reemplazar);
    }
};
int main() {
    // Validaciones
    vector<string> emails = {"test@example.com", "invalid.email", "user@domain.org"};
    cout << "Validación de emails:" << endl;
    for (const auto& email : emails) {
        cout << email << ": " << (RegexValidator::validarEmail(email) ? "Válido" : "Inválido") << endl;
    }
    
    vector<string> telefonos = {"+34123456789", "123456789", "invalid"};
    cout << "\nValidación de teléfonos:" << endl;
    for (const auto& tel : telefonos) {
        cout << tel << ": " << (RegexValidator::validarTelefono(tel) ? "Válido" : "Inválido") << endl;
    }
    
    vector<string> ips = {"192.168.1.1", "256.1.1.1", "127.0.0.1"};
    cout << "\nValidación de IPs:" << endl;
    for (const auto& ip : ips) {
        cout << ip << ": " << (RegexValidator::validarIP(ip) ? "Válido" : "Inválido") << endl;
    }
    
    // Extracción
    string texto = "Tengo 25 años y he leído 150 libros en 2023";
    auto numeros = RegexValidator::extraerNumeros(texto);
    cout << "\nNúmeros encontrados en '" << texto << "': ";
    for (const auto& num : numeros) {
        cout << num << " ";
    }
    cout << endl;
    
    // Reemplazo
    string textoOriginal = "Me gusta programar en C++";
    string textoModificado = RegexValidator::reemplazarPalabras(textoOriginal, "C\\+\\+", "Python");
    cout << "\nOriginal: " << textoOriginal << endl;
    cout << "Modificado: " << textoModificado << endl;
    
    return 0;
}

// 464. Sistema de configuración
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
using namespace std;
class ConfigManager {
private:
    map<string, string> configuracion;
    string archivoConfig;
    
    void cargarDesdeArchivo() {
        ifstream archivo(archivoConfig);
        string linea;
        
        while (getline(archivo, linea)) {
            // Ignorar comentarios y líneas vacías
            if (linea.empty() || linea[0] == '#') continue;
            
            size_t pos = linea.find('=');
            if (pos != string::npos) {
                string clave = linea.substr(0, pos);
                string valor = linea.substr(pos + 1);
                
                // Limpiar espacios
                clave.erase(0, clave.find_first_not_of(" \t"));
                clave.erase(clave.find_last_not_of(" \t") + 1);
                valor.erase(0, valor.find_first_not_of(" \t"));
                valor.erase(valor.find_last_not_of(" \t") + 1);
                
                configuracion[clave] = valor;
            }
        }
    }
    
public:
    ConfigManager(const string& archivo) : archivoConfig(archivo) {
        cargarDesdeArchivo();
    }
    
    string getString(const string& clave, const string& porDefecto = "") {
        auto it = configuracion.find(clave);
        return (it != configuracion.end()) ? it->second : porDefecto;
    }
    
    int getInt(const string& clave, int porDefecto = 0) {
        string valor = getString(clave);
        if (!valor.empty()) {
            try {
                return stoi(valor);
            } catch (...) {
                return porDefecto;
            }
        }
        return porDefecto;
    }
    
    double getDouble(const string& clave, double porDefecto = 0.0) {
        string valor = getString(clave);
        if (!valor.empty()) {
            try {
                return stod(valor);
            } catch (...) {
                return porDefecto;
            }
        }
        return porDefecto;
    }
    
    bool getBool(const string& clave, bool porDefecto = false) {
        string valor = getString(clave);
        if (!valor.empty()) {
            return (valor == "true" || valor == "1" || valor == "yes");
        }
        return porDefecto;
    }
    
    void set(const string& clave, const string& valor) {
        configuracion[clave] = valor;
    }
    
    void guardar() {
        ofstream archivo(archivoConfig);
        archivo << "# Archivo de configuración generado automáticamente\n\n";
        
        for (const auto& par : configuracion) {
            archivo << par.first << " = " << par.second << endl;
        }
    }
    
    void mostrar() {
        cout << "Configuración actual:" << endl;
        for (const auto& par : configuracion) {
            cout << par.first << " = " << par.second << endl;
        }
    }
};
int main() {
    // Crear archivo de configuración de ejemplo
    ofstream configFile("app.config");
    configFile << "# Configuración de la aplicación\n";
    configFile << "servidor = localhost\n";
    configFile << "puerto = 8080\n";
    configFile << "timeout = 30.5\n";
    configFile << "debug = true\n";
    configFile << "max_conexiones = 100\n";
    configFile.close();
    
    // Usar el gestor de configuración
    ConfigManager config("app.config");
    
    config.mostrar();
    
    cout << "\nValores leídos:" << endl;
    cout << "Servidor: " << config.getString("servidor") << endl;
    cout << "Puerto: " << config.getInt("puerto") << endl;
    cout << "Timeout: " << config.getDouble("timeout") << endl;
    cout << "Debug: " << (config.getBool("debug") ? "Activado" : "Desactivado") << endl;
    cout << "Max conexiones: " << config.getInt("max_conexiones") << endl;
    
    // Modificar y guardar
    config.set("nuevo_parametro", "valor_nuevo");
    config.guardar();
    
    return 0;
}

// 465. Cronometría y benchmark
#include <iostream>
#include <chrono>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;
using namespace chrono;
class Benchmark {
public:
    template<typename Func>
    static double medirTiempo(Func funcion) {
        auto inicio = high_resolution_clock::now();
        funcion();
        auto fin = high_resolution_clock::now();
        
        auto duracion = duration_cast<microseconds>(fin - inicio);
        return duracion.count() / 1000.0; // Retornar en milisegundos
    }
    
    template<typename Func>
    static double medirTiempoPromedio(Func funcion, int iteraciones = 10) {
        double total = 0.0;
        for (int i = 0; i < iteraciones; i++) {
            total += medirTiempo(funcion);
        }
        return total / iteraciones;
    }
    
    template<typename Func>
    static void compararAlgoritmos(const vector<pair<string, Func>>& algoritmos, int iteraciones = 5) {
        cout << "Comparación de algoritmos (" << iteraciones << " iteraciones):" << endl;
        cout << "===========================================" << endl;
        
        for (const auto& par : algoritmos) {
            double tiempo = medirTiempoPromedio(par.second, iteraciones);
            cout << par.first << ": " << tiempo << " ms" << endl;
        }
    }
};
// Algoritmos de ejemplo para comparar
void bubbleSort(vector<int> arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
void quickSortSTL(vector<int> arr) {
    sort(arr.begin(), arr.end());
}
vector<int> generarDatos(int tamano) {
    vector<int> datos(tamano);
    for (int i = 0; i < tamano; i++) {
        datos[i] = rand() % 1000;
    }
    return datos;
}
int main() {
    auto datos = generarDatos(1000);
    
    // Benchmark individual
    cout << "Benchmark individual:" << endl;
    double tiempo1 = Benchmark::medirTiempo([&]() {
        bubbleSort(datos);
    });
    cout << "Bubble sort: " << tiempo1 << " ms" << endl;
    
    double tiempo2 = Benchmark::medirTiempo([&]() {
        quickSortSTL(datos);
    });
    cout << "STL sort: " << tiempo2 << " ms" << endl;
    
    // Comparación de algoritmos
    cout << "\nComparación:" << endl;
    vector<pair<string, function<void()>>> algoritmos = {
        {"Bubble Sort", [&]() { bubbleSort(datos); }},
        {"STL Sort", [&]() { quickSortSTL(datos); }}
    };
    
    Benchmark::compararAlgoritmos(algoritmos, 3);
    
    return 0;
}
