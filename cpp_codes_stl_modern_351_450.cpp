// ===== STL Y C++ MODERNO (351-450) =====

// 351. Vector STL básico
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6};
    
    cout << "Vector original: ";
    for (int x : v) cout << x << " ";
    cout << endl;
    
    sort(v.begin(), v.end());
    cout << "Vector ordenado: ";
    for (int x : v) cout << x << " ";
    cout << endl;
    
    v.push_back(8);
    v.insert(v.begin() + 2, 7);
    
    cout << "Después de modificaciones: ";
    for (int x : v) cout << x << " ";
    cout << endl;
    
    return 0;
}

// 352. Map STL
#include <iostream>
#include <map>
using namespace std;
int main() {
    map<string, int> edades;
    
    edades["Ana"] = 25;
    edades["Luis"] = 30;
    edades["María"] = 22;
    edades.insert({"Carlos", 28});
    
    cout << "Edades:" << endl;
    for (auto& par : edades) {
        cout << par.first << ": " << par.second << " años" << endl;
    }
    
    auto it = edades.find("Luis");
    if (it != edades.end()) {
        cout << "Luis encontrado con edad: " << it->second << endl;
    }
    
    return 0;
}

// 353. Set STL
#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;
int main() {
    set<int> conjunto = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    
    cout << "Set ordenado (sin duplicados): ";
    for (int x : conjunto) cout << x << " ";
    cout << endl;
    
    unordered_set<string> palabras = {"hola", "mundo", "hola", "C++"};
    
    cout << "Unordered set: ";
    for (const string& palabra : palabras) cout << palabra << " ";
    cout << endl;
    
    if (conjunto.count(5)) {
        cout << "5 está en el conjunto" << endl;
    }
    
    return 0;
}

// 354. Queue y Stack STL
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main() {
    queue<int> cola;
    stack<int> pila;
    
    // Operaciones con cola
    for (int i = 1; i <= 5; i++) {
        cola.push(i);
        pila.push(i);
    }
    
    cout << "Cola (FIFO): ";
    while (!cola.empty()) {
        cout << cola.front() << " ";
        cola.pop();
    }
    cout << endl;
    
    cout << "Pila (LIFO): ";
    while (!pila.empty()) {
        cout << pila.top() << " ";
        pila.pop();
    }
    cout << endl;
    
    return 0;
}

// 355. Priority Queue STL
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    vector<int> datos = {3, 1, 4, 1, 5, 9, 2, 6};
    
    for (int x : datos) {
        maxHeap.push(x);
        minHeap.push(x);
    }
    
    cout << "Max Heap: ";
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    cout << endl;
    
    cout << "Min Heap: ";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;
    
    return 0;
}

// 356. Deque STL
#include <iostream>
#include <deque>
using namespace std;
int main() {
    deque<int> dq;
    
    dq.push_back(2);
    dq.push_back(3);
    dq.push_front(1);
    dq.push_front(0);
    
    cout << "Deque: ";
    for (int x : dq) cout << x << " ";
    cout << endl;
    
    cout << "Frente: " << dq.front() << ", Atrás: " << dq.back() << endl;
    
    dq.pop_front();
    dq.pop_back();
    
    cout << "Después de pop: ";
    for (int x : dq) cout << x << " ";
    cout << endl;
    
    return 0;
}

// 357. List STL
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
int main() {
    list<int> lista = {3, 1, 4, 1, 5, 9, 2, 6};
    
    cout << "Lista original: ";
    for (int x : lista) cout << x << " ";
    cout << endl;
    
    lista.sort();
    cout << "Lista ordenada: ";
    for (int x : lista) cout << x << " ";
    cout << endl;
    
    lista.unique(); // Eliminar duplicados consecutivos
    cout << "Sin duplicados: ";
    for (int x : lista) cout << x << " ";
    cout << endl;
    
    lista.reverse();
    cout << "Invertida: ";
    for (int x : lista) cout << x << " ";
    cout << endl;
    
    return 0;
}

// 358. Pair y Tuple
#include <iostream>
#include <utility>
#include <tuple>
#include <vector>
using namespace std;
int main() {
    // Pair
    pair<string, int> persona = make_pair("Juan", 25);
    cout << "Persona: " << persona.first << ", " << persona.second << " años" << endl;
    
    // Tuple
    tuple<string, int, double> estudiante = make_tuple("Ana", 20, 8.5);
    cout << "Estudiante: " << get<0>(estudiante) << ", "
         << get<1>(estudiante) << " años, nota: " << get<2>(estudiante) << endl;
    
    // Vector de pairs
    vector<pair<int, string>> puntuaciones = {{95, "Excelente"}, {80, "Bueno"}, {65, "Regular"}};
    
    for (auto& p : puntuaciones) {
        cout << "Puntuación: " << p.first << " - " << p.second << endl;
    }
    
    return 0;
}

// 359. Iteradores STL
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    
    // Iterador normal
    cout << "Forward: ";
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    // Iterador reverso
    cout << "Reverse: ";
    for (auto it = v.rbegin(); it != v.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    // Advance e distance
    auto it = v.begin();
    advance(it, 2);
    cout << "Elemento en posición 2: " << *it << endl;
    
    cout << "Distancia desde begin hasta it: " << distance(v.begin(), it) << endl;
    
    return 0;
}

// 360. Algoritmos STL - find, count, etc.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<int> v = {1, 2, 3, 2, 4, 2, 5};
    
    // find
    auto it = find(v.begin(), v.end(), 3);
    if (it != v.end()) {
        cout << "Encontrado 3 en posición: " << distance(v.begin(), it) << endl;
    }
    
    // count
    int cuenta = count(v.begin(), v.end(), 2);
    cout << "Número de 2s: " << cuenta << endl;
    
    // find_if
    auto it2 = find_if(v.begin(), v.end(), [](int x) { return x > 4; });
    if (it2 != v.end()) {
        cout << "Primer elemento > 4: " << *it2 << endl;
    }
    
    // all_of, any_of, none_of
    bool todosPares = all_of(v.begin(), v.end(), [](int x) { return x % 2 == 0; });
    bool algunPar = any_of(v.begin(), v.end(), [](int x) { return x % 2 == 0; });
    bool ningunNegativo = none_of(v.begin(), v.end(), [](int x) { return x < 0; });
    
    cout << "Todos pares: " << todosPares << endl;
    cout << "Algún par: " << algunPar << endl;
    cout << "Ningún negativo: " << ningunNegativo << endl;
    
    return 0;
}

// 361. Algoritmos STL - transform, for_each
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    vector<int> cuadrados(v.size());
    
    // transform
    transform(v.begin(), v.end(), cuadrados.begin(), [](int x) { return x * x; });
    
    cout << "Originales: ";
    for (int x : v) cout << x << " ";
    cout << endl;
    
    cout << "Cuadrados: ";
    for (int x : cuadrados) cout << x << " ";
    cout << endl;
    
    // for_each
    cout << "Duplicados: ";
    for_each(v.begin(), v.end(), [](int& x) { x *= 2; });
    for (int x : v) cout << x << " ";
    cout << endl;
    
    return 0;
}

// 362. Algoritmos STL - sort con predicados
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct Persona {
    string nombre;
    int edad;
    double salario;
};
int main() {
    vector<Persona> personas = {
        {"Ana", 25, 50000},
        {"Luis", 30, 60000},
        {"María", 22, 45000},
        {"Carlos", 28, 55000}
    };
    
    // Ordenar por edad
    sort(personas.begin(), personas.end(), [](const Persona& a, const Persona& b) {
        return a.edad < b.edad;
    });
    
    cout << "Ordenado por edad:" << endl;
    for (const auto& p : personas) {
        cout << p.nombre << " (" << p.edad << " años)" << endl;
    }
    
    // Ordenar por salario descendente
    sort(personas.begin(), personas.end(), [](const Persona& a, const Persona& b) {
        return a.salario > b.salario;
    });
    
    cout << "\nOrdenado por salario (desc):" << endl;
    for (const auto& p : personas) {
        cout << p.nombre << " ($" << p.salario << ")" << endl;
    }
    
    return 0;
}

// 363. Lambdas en C++11
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // Lambda simple
    auto esPar = [](int x) { return x % 2 == 0; };
    
    // Lambda con captura
    int factor = 3;
    auto multiplicar = [factor](int x) { return x * factor; };
    
    // Lambda con captura por referencia
    int contador = 0;
    auto contar = [&contador]() { return ++contador; };
    
    cout << "Pares: ";
    for (int x : v) {
        if (esPar(x)) cout << x << " ";
    }
    cout << endl;
    
    cout << "Multiplicados por " << factor << ": ";
    for (int x : v) {
        cout << multiplicar(x) << " ";
    }
    cout << endl;
    
    cout << "Contador: " << contar() << " " << contar() << " " << contar() << endl;
    
    return 0;
}

// 364. Auto keyword y range-based for
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main() {
    // auto con tipos simples
    auto entero = 42;
    auto decimal = 3.14;
    auto texto = "Hola mundo";
    
    cout << "Tipos inferidos: " << entero << ", " << decimal << ", " << texto << endl;
    
    // auto con containers
    vector<int> numeros = {1, 2, 3, 4, 5};
    map<string, int> edades = {{"Ana", 25}, {"Luis", 30}};
    
    // Range-based for
    cout << "Números: ";
    for (auto num : numeros) {
        cout << num << " ";
    }
    cout << endl;
    
    cout << "Edades:" << endl;
    for (const auto& par : edades) {
        cout << par.first << ": " << par.second << " años" << endl;
    }
    
    // auto con iteradores
    for (auto it = numeros.begin(); it != numeros.end(); ++it) {
        *it *= 2;
    }
    
    cout << "Duplicados: ";
    for (auto num : numeros) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}

// 365. Smart Pointers - unique_ptr
#include <iostream>
#include <memory>
using namespace std;
class Recurso {
public:
    Recurso(int id) : id_(id) {
        cout << "Recurso " << id_ << " creado" << endl;
    }
    ~Recurso() {
        cout << "Recurso " << id_ << " destruido" << endl;
    }
    void usar() {
        cout << "Usando recurso " << id_ << endl;
    }
private:
    int id_;
};
int main() {
    {
        unique_ptr<Recurso> ptr1 = make_unique<Recurso>(1);
        ptr1->usar();
        
        unique_ptr<Recurso> ptr2 = move(ptr1); // Transferir propiedad
        if (ptr1 == nullptr) {
            cout << "ptr1 es nullptr después del move" << endl;
        }
        ptr2->usar();
        
        // ptr2 se destruye automáticamente al salir del ámbito
    }
    
    cout << "Fin del programa" << endl;
    return 0;
}

// 366. Smart Pointers - shared_ptr
#include <iostream>
#include <memory>
using namespace std;
class Nodo {
public:
    int valor;
    shared_ptr<Nodo> siguiente;
    
    Nodo(int v) : valor(v) {
        cout << "Nodo " << valor << " creado" << endl;
    }
    ~Nodo() {
        cout << "Nodo " << valor << " destruido" << endl;
    }
};
int main() {
    {
        shared_ptr<Nodo> nodo1 = make_shared<Nodo>(1);
        shared_ptr<Nodo> nodo2 = make_shared<Nodo>(2);
        
        nodo1->siguiente = nodo2;
        
        cout << "Uso de nodo1: " << nodo1.use_count() << endl;
        cout << "Uso de nodo2: " << nodo2.use_count() << endl;
        
        shared_ptr<Nodo> ptr3 = nodo2;
        cout << "Uso de nodo2 después de asignar ptr3: " << nodo2.use_count() << endl;
    }
    
    cout << "Fin del programa" << endl;
    return 0;
}

// 367. Smart Pointers - weak_ptr
#include <iostream>
#include <memory>
using namespace std;
class Padre;
class Hijo {
public:
    weak_ptr<Padre> padre; // weak_ptr para evitar referencia circular
    int id;
    
    Hijo(int i) : id(i) {
        cout << "Hijo " << id << " creado" << endl;
    }
    ~Hijo() {
        cout << "Hijo " << id << " destruido" << endl;
    }
};
class Padre {
public:
    shared_ptr<Hijo> hijo;
    int id;
    
    Padre(int i) : id(i) {
        cout << "Padre " << id << " creado" << endl;
    }
    ~Padre() {
        cout << "Padre " << id << " destruido" << endl;
    }
};
int main() {
    {
        shared_ptr<Padre> padre = make_shared<Padre>(1);
        shared_ptr<Hijo> hijo = make_shared<Hijo>(1);
        
        padre->hijo = hijo;
        hijo->padre = padre; // weak_ptr no incrementa el contador
        
        cout << "Uso del padre: " << padre.use_count() << endl;
        cout << "Uso del hijo: " << hijo.use_count() << endl;
        
        if (auto p = hijo->padre.lock()) {
            cout << "Acceso al padre desde el hijo: ID " << p->id << endl;
        }
    }
    
    cout << "Fin del programa" << endl;
    return 0;
}

// 368. Move semantics y rvalue references
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
class MiClase {
public:
    vector<int> datos;
    
    // Constructor
    MiClase(int tamano) : datos(tamano) {
        cout << "Constructor: creando vector de tamaño " << tamano << endl;
    }
    
    // Constructor de copia
    MiClase(const MiClase& otro) : datos(otro.datos) {
        cout << "Constructor de copia" << endl;
    }
    
    // Constructor de movimiento
    MiClase(MiClase&& otro) noexcept : datos(move(otro.datos)) {
        cout << "Constructor de movimiento" << endl;
    }
    
    // Operador de asignación de copia
    MiClase& operator=(const MiClase& otro) {
        cout << "Operador de asignación de copia" << endl;
        if (this != &otro) {
            datos = otro.datos;
        }
        return *this;
    }
    
    // Operador de asignación de movimiento
    MiClase& operator=(MiClase&& otro) noexcept {
        cout << "Operador de asignación de movimiento" << endl;
        if (this != &otro) {
            datos = move(otro.datos);
        }
        return *this;
    }
};
MiClase crearObjeto() {
    return MiClase(1000);
}
int main() {
    cout << "=== Creación directa ===" << endl;
    MiClase obj1(100);
    
    cout << "\n=== Copia ===" << endl;
    MiClase obj2 = obj1;
    
    cout << "\n=== Movimiento desde función ===" << endl;
    MiClase obj3 = crearObjeto();
    
    cout << "\n=== Movimiento explícito ===" << endl;
    MiClase obj4 = move(obj1);
    
    return 0;
}

// 369. Variadic templates
#include <iostream>
using namespace std;
// Template recursivo para imprimir argumentos
template<typename T>
void imprimir(T&& t) {
    cout << t << endl;
}
template<typename T, typename... Args>
void imprimir(T&& t, Args&&... args) {
    cout << t << " ";
    imprimir(args...);
}
// Template para sumar argumentos
template<typename T>
T sumar(T t) {
    return t;
}
template<typename T, typename... Args>
T sumar(T t, Args... args) {
    return t + sumar(args...);
}
// Template con fold expression (C++17)
template<typename... Args>
auto sumarFold(Args... args) {
    return (args + ...);
}
int main() {
    cout << "Imprimiendo argumentos:" << endl;
    imprimir(1, 2.5, "hola", 'c', true);
    
    cout << "\nSuma tradicional: " << sumar(1, 2, 3, 4, 5) << endl;
    cout << "Suma con fold: " << sumarFold(1, 2, 3, 4, 5) << endl;
    
    return 0;
}

// 370. Perfect forwarding
#include <iostream>
#include <utility>
using namespace std;
class Objeto {
public:
    Objeto() { cout << "Constructor por defecto" << endl; }
    Objeto(const Objeto&) { cout << "Constructor de copia" << endl; }
    Objeto(Objeto&&) { cout << "Constructor de movimiento" << endl; }
};
template<typename T>
void procesar(T&& obj) {
    cout << "Procesando objeto..." << endl;
}
template<typename T>
void forwardear(T&& obj) {
    cout << "Forwardeando: ";
    procesar(forward<T>(obj));
}
int main() {
    cout << "=== Objeto lvalue ===" << endl;
    Objeto obj;
    forwardear(obj);
    
    cout << "\n=== Objeto rvalue ===" << endl;
    forwardear(Objeto());
    
    return 0;
}

// 371. SFINAE y enable_if
#include <iostream>
#include <type_traits>
using namespace std;
// Template habilitado solo para tipos enteros
template<typename T>
typename enable_if<is_integral<T>::value, void>::type
procesarEntero(T valor) {
    cout << "Procesando entero: " << valor << endl;
}
// Template habilitado solo para tipos de punto flotante
template<typename T>
typename enable_if<is_floating_point<T>::value, void>::type
procesarDecimal(T valor) {
    cout << "Procesando decimal: " << valor << endl;
}
// Versión moderna con if constexpr (C++17)
template<typename T>
void procesarModerno(T valor) {
    if constexpr (is_integral_v<T>) {
        cout << "Es entero: " << valor << endl;
    } else if constexpr (is_floating_point_v<T>) {
        cout << "Es decimal: " << valor << endl;
    } else {
        cout << "Otro tipo: " << valor << endl;
    }
}
int main() {
    procesarEntero(42);
    procesarDecimal(3.14);
    
    cout << "\nVersión moderna:" << endl;
    procesarModerno(42);
    procesarModerno(3.14);
    procesarModerno("texto");
    
    return 0;
}

// 372. Constexpr
#include <iostream>
using namespace std;
// Función constexpr para factorial
constexpr long long factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}
// Clase con constructor constexpr
class Punto {
public:
    constexpr Punto(double x, double y) : x_(x), y_(y) {}
    constexpr double getX() const { return x_; }
    constexpr double getY() const { return y_; }
    constexpr double distanciaOrigen() const {
        return x_ * x_ + y_ * y_;
    }
private:
    double x_, y_;
};
int main() {
    // Evaluación en tiempo de compilación
    constexpr long long fact5 = factorial(5);
    cout << "Factorial de 5: " << fact5 << endl;
    
    constexpr Punto p(3, 4);
    constexpr double dist = p.distanciaOrigen();
    cout << "Distancia al origen: " << dist << endl;
    
    // Array con tamaño constexpr
    constexpr int tam = factorial(4);
    int array[tam]; // Tamaño conocido en tiempo de compilación
    cout << "Tamaño del array: " << sizeof(array) / sizeof(int) << endl;
    
    return 0;
}

// 373. Thread y async
#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std;
void tarea(int id, int duracion) {
    cout << "Tarea " << id << " iniciada" << endl;
    this_thread::sleep_for(chrono::milliseconds(duracion));
    cout << "Tarea " << id << " completada" << endl;
}
int calcularCuadrado(int x) {
    this_thread::sleep_for(chrono::milliseconds(100));
    return x * x;
}
int main() {
    cout << "=== Threads ===" << endl;
    thread t1(tarea, 1, 200);
    thread t2(tarea, 2, 300);
    
    t1.join();
    t2.join();
    
    cout << "\n=== Async ===" << endl;
    auto futuro1 = async(launch::async, calcularCuadrado, 5);
    auto futuro2 = async(launch::async, calcularCuadrado, 7);
    
    cout << "Calculando..." << endl;
    cout << "5^2 = " << futuro1.get() << endl;
    cout << "7^2 = " << futuro2.get() << endl;
    
    return 0;
}

// 374. Mutex y atomic
#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <vector>
using namespace std;
mutex mtx;
atomic<int> contadorAtomic(0);
int contadorNormal = 0;
void incrementarConMutex(int iteraciones) {
    for (int i = 0; i < iteraciones; i++) {
        lock_guard<mutex> lock(mtx);
        contadorNormal++;
    }
}
void incrementarAtomic(int iteraciones) {
    for (int i = 0; i < iteraciones; i++) {
        contadorAtomic++;
    }
}
int main() {
    const int iteraciones = 10000;
    const int numThreads = 4;
    
    // Test con mutex
    vector<thread> threads;
    auto inicio = chrono::high_resolution_clock::now();
    
    for (int i = 0; i < numThreads; i++) {
        threads.emplace_back(incrementarConMutex, iteraciones);
    }
    
    for (auto& t : threads) {
        t.join();
    }
    
    auto fin = chrono::high_resolution_clock::now();
    auto duracionMutex = chrono::duration_cast<chrono::microseconds>(fin - inicio);
    
    // Test con atomic
    threads.clear();
    inicio = chrono::high_resolution_clock::now();
    
    for (int i = 0; i < numThreads; i++) {
        threads.emplace_back(incrementarAtomic, iteraciones);
    }
    
    for (auto& t : threads) {
        t.join();
    }
    
    fin = chrono::high_resolution_clock::now();
    auto duracionAtomic = chrono::duration_cast<chrono::microseconds>(fin - inicio);
    
    cout << "Contador con mutex: " << contadorNormal << " (" << duracionMutex.count() << " μs)" << endl;
    cout << "Contador atómico: " << contadorAtomic << " (" << duracionAtomic.count() << " μs)" << endl;
    
    return 0;
}

// 375. Condition Variable
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
using namespace std;
class Buffer {
private:
    queue<int> cola;
    mutex mtx;
    condition_variable cv;
    bool terminado = false;
    
public:
    void producir(int item) {
        unique_lock<mutex> lock(mtx);
        cola.push(item);
        cout << "Producido: " << item << endl;
        cv.notify_one();
    }
    
    int consumir() {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this] { return !cola.empty() || terminado; });
        
        if (cola.empty()) return -1; // Terminado
        
        int item = cola.front();
        cola.pop();
        cout << "Consumido: " << item << endl;
        return item;
    }
    
    void terminar() {
        unique_lock<mutex> lock(mtx);
        terminado = true;
        cv.notify_all();
    }
};
void productor(Buffer& buffer) {
    for (int i = 1; i <= 5; i++) {
        buffer.producir(i);
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    buffer.terminar();
}
void consumidor(Buffer& buffer) {
    while (true) {
        int item = buffer.consumir();
        if (item == -1) break;
        this_thread::sleep_for(chrono::milliseconds(150));
    }
}
int main() {
    Buffer buffer;
    
    thread prodThread(productor, ref(buffer));
    thread consThread(consumidor, ref(buffer));
    
    prodThread.join();
    consThread.join();
    
    cout << "Programa terminado" << endl;
    return 0;
}
