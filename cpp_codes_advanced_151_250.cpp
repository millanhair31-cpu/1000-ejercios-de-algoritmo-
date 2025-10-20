// ===== CÓDIGOS AVANZADOS DE C++ - POO (151-250) =====

// 151. Clase básica
#include <iostream>
using namespace std;
class Rectangulo {
private:
    double ancho, alto;
public:
    Rectangulo(double a, double h) : ancho(a), alto(h) {}
    double area() { return ancho * alto; }
    double perimetro() { return 2 * (ancho + alto); }
};
int main() {
    Rectangulo r(5.0, 3.0);
    cout << "�rea: " << r.area() << endl;
    cout << "Perímetro: " << r.perimetro() << endl;
    return 0;
}

// 152. Constructor por defecto
#include <iostream>
using namespace std;
class Circulo {
private:
    double radio;
public:
    Circulo() : radio(1.0) {}
    Circulo(double r) : radio(r) {}
    double area() { return 3.14159 * radio * radio; }
    void setRadio(double r) { radio = r; }
    double getRadio() { return radio; }
};
int main() {
    Circulo c1;
    Circulo c2(5.0);
    cout << "C1 área: " << c1.area() << endl;
    cout << "C2 área: " << c2.area() << endl;
    return 0;
}

// 153. Destructor
#include <iostream>
using namespace std;
class Recurso {
private:
    int* datos;
public:
    Recurso(int tamano) {
        datos = new int[tamano];
        cout << "Recurso creado" << endl;
    }
    ~Recurso() {
        delete[] datos;
        cout << "Recurso liberado" << endl;
    }
};
int main() {
    Recurso r(100);
    return 0;
}

// 154. Constructor de copia
#include <iostream>
using namespace std;
class MiClase {
private:
    int* valor;
public:
    MiClase(int v) {
        valor = new int(v);
    }
    MiClase(const MiClase& otro) {
        valor = new int(*otro.valor);
    }
    ~MiClase() {
        delete valor;
    }
    int getValor() { return *valor; }
};
int main() {
    MiClase obj1(42);
    MiClase obj2 = obj1;
    cout << "obj1: " << obj1.getValor() << endl;
    cout << "obj2: " << obj2.getValor() << endl;
    return 0;
}

// 155. Operador de asignación
#include <iostream>
using namespace std;
class Vector {
private:
    double x, y;
public:
    Vector(double x = 0, double y = 0) : x(x), y(y) {}
    Vector& operator=(const Vector& otro) {
        if (this != &otro) {
            x = otro.x;
            y = otro.y;
        }
        return *this;
    }
    void mostrar() { cout << "(" << x << ", " << y << ")" << endl; }
};
int main() {
    Vector v1(3, 4);
    Vector v2;
    v2 = v1;
    v2.mostrar();
    return 0;
}

// 156. Sobrecarga de operadores aritméticos
#include <iostream>
using namespace std;
class Complejo {
private:
    double real, imag;
public:
    Complejo(double r = 0, double i = 0) : real(r), imag(i) {}
    Complejo operator+(const Complejo& otro) {
        return Complejo(real + otro.real, imag + otro.imag);
    }
    Complejo operator-(const Complejo& otro) {
        return Complejo(real - otro.real, imag - otro.imag);
    }
    void mostrar() {
        cout << real << " + " << imag << "i" << endl;
    }
};
int main() {
    Complejo c1(3, 4);
    Complejo c2(1, 2);
    Complejo suma = c1 + c2;
    Complejo resta = c1 - c2;
    suma.mostrar();
    resta.mostrar();
    return 0;
}

// 157. Sobrecarga del operador <<
#include <iostream>
using namespace std;
class Punto {
private:
    int x, y;
public:
    Punto(int x = 0, int y = 0) : x(x), y(y) {}
    friend ostream& operator<<(ostream& os, const Punto& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};
int main() {
    Punto p(5, 7);
    cout << "Punto: " << p << endl;
    return 0;
}

// 158. Herencia básica
#include <iostream>
using namespace std;
class Vehiculo {
protected:
    string marca;
    int año;
public:
    Vehiculo(string m, int a) : marca(m), año(a) {}
    void mostrarInfo() {
        cout << "Marca: " << marca << ", Año: " << año << endl;
    }
};
class Coche : public Vehiculo {
private:
    int puertas;
public:
    Coche(string m, int a, int p) : Vehiculo(m, a), puertas(p) {}
    void mostrarDetalles() {
        mostrarInfo();
        cout << "Puertas: " << puertas << endl;
    }
};
int main() {
    Coche c("Toyota", 2022, 4);
    c.mostrarDetalles();
    return 0;
}

// 159. Herencia múltiple
#include <iostream>
using namespace std;
class Motor {
protected:
    int potencia;
public:
    Motor(int p) : potencia(p) {}
    void encender() { cout << "Motor encendido" << endl; }
};
class Ruedas {
protected:
    int cantidad;
public:
    Ruedas(int c) : cantidad(c) {}
    void rodar() { cout << "Rodando con " << cantidad << " ruedas" << endl; }
};
class Automovil : public Motor, public Ruedas {
public:
    Automovil(int p, int r) : Motor(p), Ruedas(r) {}
    void conducir() {
        encender();
        rodar();
    }
};
int main() {
    Automovil auto(150, 4);
    auto.conducir();
    return 0;
}

// 160. Polimorfismo virtual
#include <iostream>
using namespace std;
class Figura {
public:
    virtual double area() = 0;
    virtual void mostrar() {
        cout << "Figura genérica" << endl;
    }
};
class Cuadrado : public Figura {
private:
    double lado;
public:
    Cuadrado(double l) : lado(l) {}
    double area() override {
        return lado * lado;
    }
    void mostrar() override {
        cout << "Cuadrado de lado " << lado << endl;
    }
};
class Circulo : public Figura {
private:
    double radio;
public:
    Circulo(double r) : radio(r) {}
    double area() override {
        return 3.14159 * radio * radio;
    }
    void mostrar() override {
        cout << "Círculo de radio " << radio << endl;
    }
};
int main() {
    Figura* figuras[] = {new Cuadrado(5), new Circulo(3)};
    for (int i = 0; i < 2; i++) {
        figuras[i]->mostrar();
        cout << "Área: " << figuras[i]->area() << endl;
        delete figuras[i];
    }
    return 0;
}

// 161. Clase abstracta
#include <iostream>
using namespace std;
class Animal {
protected:
    string nombre;
public:
    Animal(string n) : nombre(n) {}
    virtual void hacerSonido() = 0;
    virtual void moverse() = 0;
    void dormir() {
        cout << nombre << " está durmiendo" << endl;
    }
};
class Perro : public Animal {
public:
    Perro(string n) : Animal(n) {}
    void hacerSonido() override {
        cout << nombre << " dice: Guau!" << endl;
    }
    void moverse() override {
        cout << nombre << " está corriendo" << endl;
    }
};
class Gato : public Animal {
public:
    Gato(string n) : Animal(n) {}
    void hacerSonido() override {
        cout << nombre << " dice: Miau!" << endl;
    }
    void moverse() override {
        cout << nombre << " está caminando silenciosamente" << endl;
    }
};
int main() {
    Animal* animales[] = {new Perro("Rex"), new Gato("Miau")};
    for (int i = 0; i < 2; i++) {
        animales[i]->hacerSonido();
        animales[i]->moverse();
        animales[i]->dormir();
        delete animales[i];
    }
    return 0;
}

// 162. Encapsulación
#include <iostream>
using namespace std;
class CuentaBancaria {
private:
    double saldo;
    string numeroCuenta;
public:
    CuentaBancaria(string num, double saldoInicial = 0) 
        : numeroCuenta(num), saldo(saldoInicial) {}
    
    void depositar(double cantidad) {
        if (cantidad > 0) {
            saldo += cantidad;
            cout << "Depositado: $" << cantidad << endl;
        }
    }
    
    bool retirar(double cantidad) {
        if (cantidad > 0 && cantidad <= saldo) {
            saldo -= cantidad;
            cout << "Retirado: $" << cantidad << endl;
            return true;
        }
        cout << "Retiro no válido" << endl;
        return false;
    }
    
    double consultarSaldo() const {
        return saldo;
    }
    
    string getNumeroCuenta() const {
        return numeroCuenta;
    }
};
int main() {
    CuentaBancaria cuenta("123456789", 1000);
    cuenta.depositar(500);
    cuenta.retirar(200);
    cout << "Saldo actual: $" << cuenta.consultarSaldo() << endl;
    return 0;
}

// 163. Métodos estáticos
#include <iostream>
using namespace std;
class Matematicas {
public:
    static double PI;
    static int sumar(int a, int b) {
        return a + b;
    }
    static double areaCirculo(double radio) {
        return PI * radio * radio;
    }
    static int factorial(int n) {
        if (n <= 1) return 1;
        return n * factorial(n - 1);
    }
};
double Matematicas::PI = 3.14159265359;
int main() {
    cout << "Suma: " << Matematicas::sumar(5, 3) << endl;
    cout << "Área: " << Matematicas::areaCirculo(5) << endl;
    cout << "Factorial: " << Matematicas::factorial(5) << endl;
    return 0;
}

// 164. Variables estáticas
#include <iostream>
using namespace std;
class Contador {
private:
    static int cuenta;
    int id;
public:
    Contador() {
        id = ++cuenta;
    }
    static int getCuenta() {
        return cuenta;
    }
    int getId() {
        return id;
    }
};
int Contador::cuenta = 0;
int main() {
    Contador c1, c2, c3;
    cout << "Total objetos: " << Contador::getCuenta() << endl;
    cout << "ID c1: " << c1.getId() << endl;
    cout << "ID c2: " << c2.getId() << endl;
    cout << "ID c3: " << c3.getId() << endl;
    return 0;
}

// 165. Clases amigas
#include <iostream>
using namespace std;
class ClaseB;
class ClaseA {
private:
    int valorPrivado;
public:
    ClaseA(int v) : valorPrivado(v) {}
    friend class ClaseB;
    friend void funcionAmiga(ClaseA& a);
};
class ClaseB {
public:
    void accederA(ClaseA& a) {
        cout << "Accediendo a valor privado de A: " << a.valorPrivado << endl;
        a.valorPrivado *= 2;
    }
};
void funcionAmiga(ClaseA& a) {
    cout << "Función amiga accede: " << a.valorPrivado << endl;
}
int main() {
    ClaseA a(10);
    ClaseB b;
    b.accederA(a);
    funcionAmiga(a);
    return 0;
}

// 166. Plantillas de clase
#include <iostream>
using namespace std;
template<typename T>
class Pila {
private:
    T* datos;
    int capacidad;
    int tope;
public:
    Pila(int cap = 10) : capacidad(cap), tope(-1) {
        datos = new T[capacidad];
    }
    ~Pila() {
        delete[] datos;
    }
    void push(T elemento) {
        if (tope < capacidad - 1) {
            datos[++tope] = elemento;
        }
    }
    T pop() {
        if (tope >= 0) {
            return datos[tope--];
        }
        return T();
    }
    bool estaVacia() {
        return tope == -1;
    }
};
int main() {
    Pila<int> pilaInt;
    Pila<string> pilaString;
    
    pilaInt.push(10);
    pilaInt.push(20);
    
    pilaString.push("Hola");
    pilaString.push("Mundo");
    
    cout << "Pila int: " << pilaInt.pop() << ", " << pilaInt.pop() << endl;
    cout << "Pila string: " << pilaString.pop() << ", " << pilaString.pop() << endl;
    
    return 0;
}

// 167. Especialización de plantillas
#include <iostream>
using namespace std;
template<typename T>
class Contenedor {
private:
    T valor;
public:
    Contenedor(T v) : valor(v) {}
    void mostrar() {
        cout << "Valor: " << valor << endl;
    }
};
// Especialización para bool
template<>
class Contenedor<bool> {
private:
    bool valor;
public:
    Contenedor(bool v) : valor(v) {}
    void mostrar() {
        cout << "Valor booleano: " << (valor ? "true" : "false") << endl;
    }
};
int main() {
    Contenedor<int> cInt(42);
    Contenedor<bool> cBool(true);
    
    cInt.mostrar();
    cBool.mostrar();
    
    return 0;
}

// 168. Iteradores básicos
#include <iostream>
using namespace std;
class Lista {
private:
    int* datos;
    int tamano;
public:
    Lista(int tam) : tamano(tam) {
        datos = new int[tamano];
        for (int i = 0; i < tamano; i++) {
            datos[i] = i + 1;
        }
    }
    ~Lista() { delete[] datos; }
    
    class Iterador {
    private:
        int* ptr;
    public:
        Iterador(int* p) : ptr(p) {}
        int& operator*() { return *ptr; }
        Iterador& operator++() { ++ptr; return *this; }
        bool operator!=(const Iterador& otro) { return ptr != otro.ptr; }
    };
    
    Iterador begin() { return Iterador(datos); }
    Iterador end() { return Iterador(datos + tamano); }
};
int main() {
    Lista lista(5);
    for (auto it = lista.begin(); it != lista.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}

// 169. RAII (Resource Acquisition Is Initialization)
#include <iostream>
using namespace std;
class GestorArchivo {
private:
    string nombreArchivo;
    bool abierto;
public:
    GestorArchivo(const string& nombre) : nombreArchivo(nombre), abierto(false) {
        // Simular apertura de archivo
        abierto = true;
        cout << "Archivo " << nombreArchivo << " abierto" << endl;
    }
    
    ~GestorArchivo() {
        if (abierto) {
            cout << "Archivo " << nombreArchivo << " cerrado" << endl;
        }
    }
    
    void escribir(const string& contenido) {
        if (abierto) {
            cout << "Escribiendo: " << contenido << endl;
        }
    }
};
void funcionQueUsaArchivo() {
    GestorArchivo archivo("datos.txt");
    archivo.escribir("Contenido importante");
    // El archivo se cierra automáticamente al salir del ámbito
}
int main() {
    funcionQueUsaArchivo();
    cout << "Función principal terminada" << endl;
    return 0;
}

// 170. Singleton pattern
#include <iostream>
using namespace std;
class Singleton {
private:
    static Singleton* instancia;
    string dato;
    Singleton(string d = "Dato por defecto") : dato(d) {}
public:
    static Singleton* getInstance() {
        if (instancia == nullptr) {
            instancia = new Singleton();
        }
        return instancia;
    }
    void setDato(string d) { dato = d; }
    string getDato() { return dato; }
    static void destruir() {
        if (instancia) {
            delete instancia;
            instancia = nullptr;
        }
    }
};
Singleton* Singleton::instancia = nullptr;
int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();
    
    s1->setDato("Nuevo dato");
    cout << "s1: " << s1->getDato() << endl;
    cout << "s2: " << s2->getDato() << endl;
    cout << "Son la misma instancia: " << (s1 == s2) << endl;
    
    Singleton::destruir();
    return 0;
}

// 171. Factory pattern
#include <iostream>
using namespace std;
class Producto {
public:
    virtual void usar() = 0;
    virtual ~Producto() {}
};
class ProductoA : public Producto {
public:
    void usar() override {
        cout << "Usando Producto A" << endl;
    }
};
class ProductoB : public Producto {
public:
    void usar() override {
        cout << "Usando Producto B" << endl;
    }
};
class Fabrica {
public:
    static Producto* crearProducto(char tipo) {
        switch (tipo) {
            case 'A': return new ProductoA();
            case 'B': return new ProductoB();
            default: return nullptr;
        }
    }
};
int main() {
    Producto* p1 = Fabrica::crearProducto('A');
    Producto* p2 = Fabrica::crearProducto('B');
    
    if (p1) p1->usar();
    if (p2) p2->usar();
    
    delete p1;
    delete p2;
    return 0;
}

// 172. Observer pattern
#include <iostream>
#include <vector>
using namespace std;
class Observador {
public:
    virtual void actualizar(int valor) = 0;
};
class Sujeto {
private:
    vector<Observador*> observadores;
    int estado;
public:
    void agregarObservador(Observador* obs) {
        observadores.push_back(obs);
    }
    void setEstado(int nuevoEstado) {
        estado = nuevoEstado;
        notificar();
    }
    void notificar() {
        for (auto obs : observadores) {
            obs->actualizar(estado);
        }
    }
};
class ObservadorConcreto : public Observador {
private:
    string nombre;
public:
    ObservadorConcreto(string n) : nombre(n) {}
    void actualizar(int valor) override {
        cout << nombre << " notificado. Nuevo valor: " << valor << endl;
    }
};
int main() {
    Sujeto sujeto;
    ObservadorConcreto obs1("Observador1");
    ObservadorConcreto obs2("Observador2");
    
    sujeto.agregarObservador(&obs1);
    sujeto.agregarObservador(&obs2);
    
    sujeto.setEstado(42);
    sujeto.setEstado(100);
    
    return 0;
}

// 173. Smart pointers - unique_ptr simulado
#include <iostream>
using namespace std;
template<typename T>
class unique_ptr_custom {
private:
    T* ptr;
public:
    explicit unique_ptr_custom(T* p = nullptr) : ptr(p) {}
    
    ~unique_ptr_custom() {
        delete ptr;
    }
    
    // No permitir copia
    unique_ptr_custom(const unique_ptr_custom&) = delete;
    unique_ptr_custom& operator=(const unique_ptr_custom&) = delete;
    
    // Permitir movimiento
    unique_ptr_custom(unique_ptr_custom&& otro) : ptr(otro.ptr) {
        otro.ptr = nullptr;
    }
    
    unique_ptr_custom& operator=(unique_ptr_custom&& otro) {
        if (this != &otro) {
            delete ptr;
            ptr = otro.ptr;
            otro.ptr = nullptr;
        }
        return *this;
    }
    
    T& operator*() { return *ptr; }
    T* operator->() { return ptr; }
    T* get() { return ptr; }
    
    T* release() {
        T* temp = ptr;
        ptr = nullptr;
        return temp;
    }
};
int main() {
    unique_ptr_custom<int> ptr(new int(42));
    cout << "Valor: " << *ptr << endl;
    
    unique_ptr_custom<int> ptr2 = move(ptr);
    cout << "Valor en ptr2: " << *ptr2 << endl;
    
    return 0;
}

// 174. Operador de conversión
#include <iostream>
using namespace std;
class Temperatura {
private:
    double celsius;
public:
    Temperatura(double c = 0) : celsius(c) {}
    
    // Operador de conversión a double (Fahrenheit)
    operator double() const {
        return celsius * 9.0 / 5.0 + 32;
    }
    
    // Operador de conversión a int (Celsius redondeado)
    operator int() const {
        return static_cast<int>(celsius + 0.5);
    }
    
    double getCelsius() const { return celsius; }
};
int main() {
    Temperatura t(25.7);
    
    cout << "Celsius: " << t.getCelsius() << endl;
    cout << "Fahrenheit: " << static_cast<double>(t) << endl;
    cout << "Celsius (int): " << static_cast<int>(t) << endl;
    
    return 0;
}

// 175. Clases anidadas
#include <iostream>
using namespace std;
class ClaseExterna {
private:
    int valorExterno;
    
public:
    ClaseExterna(int v) : valorExterno(v) {}
    
    class ClaseInterna {
    private:
        int valorInterno;
    public:
        ClaseInterna(int v) : valorInterno(v) {}
        
        void mostrar(ClaseExterna& externa) {
            cout << "Valor externo: " << externa.valorExterno << endl;
            cout << "Valor interno: " << valorInterno << endl;
        }
    };
    
    ClaseInterna crearInterna(int v) {
        return ClaseInterna(v);
    }
};
int main() {
    ClaseExterna externa(10);
    ClaseExterna::ClaseInterna interna = externa.crearInterna(20);
    
    interna.mostrar(externa);
    
    return 0;
}

// 176. Métodos const
#include <iostream>
using namespace std;
class Punto3D {
private:
    double x, y, z;
public:
    Punto3D(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
    
    // Métodos const
    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }
    
    double distanciaOrigen() const {
        return sqrt(x*x + y*y + z*z);
    }
    
    void mostrar() const {
        cout << "(" << x << ", " << y << ", " << z << ")" << endl;
    }
    
    // Métodos no const
    void setX(double newX) { x = newX; }
    void setY(double newY) { y = newY; }
    void setZ(double newZ) { z = newZ; }
};
void procesarPunto(const Punto3D& p) {
    p.mostrar();
    cout << "Distancia al origen: " << p.distanciaOrigen() << endl;
}
int main() {
    Punto3D p(3, 4, 5);
    procesarPunto(p);
    
    p.setX(1);
    procesarPunto(p);
    
    return 0;
}

// 177. Mutable keyword
#include <iostream>
using namespace std;
class Cache {
private:
    int valor;
    mutable int contadorAccesos;
    mutable bool cacheValido;
    mutable int valorCache;
    
public:
    Cache(int v) : valor(v), contadorAccesos(0), cacheValido(false) {}
    
    int getValorCostoso() const {
        contadorAccesos++;
        
        if (!cacheValido) {
            cout << "Calculando valor costoso..." << endl;
            valorCache = valor * valor; // Operación "costosa"
            cacheValido = true;
        }
        
        return valorCache;
    }
    
    int getContadorAccesos() const {
        return contadorAccesos;
    }
    
    void setValor(int v) {
        valor = v;
        cacheValido = false; // Invalidar cache
    }
};
int main() {
    const Cache cache(10);
    
    cout << "Primer acceso: " << cache.getValorCostoso() << endl;
    cout << "Segundo acceso: " << cache.getValorCostoso() << endl;
    cout << "Accesos totales: " << cache.getContadorAccesos() << endl;
    
    return 0;
}

// 178. Agregación vs Composición
#include <iostream>
#include <vector>
using namespace std;
// Composición - El motor es parte del coche
class Motor {
public:
    void encender() { cout << "Motor encendido" << endl; }
};
class Coche {
private:
    Motor motor; // Composición
public:
    void arrancar() {
        motor.encender();
        cout << "Coche arrancado" << endl;
    }
};
// Agregación - Los estudiantes existen independientemente
class Estudiante {
public:
    string nombre;
    Estudiante(string n) : nombre(n) {}
};
class Clase {
private:
    vector<Estudiante*> estudiantes; // Agregación
public:
    void agregarEstudiante(Estudiante* e) {
        estudiantes.push_back(e);
    }
    void mostrarEstudiantes() {
        for (auto e : estudiantes) {
            cout << e->nombre << " ";
        }
        cout << endl;
    }
};
int main() {
    Coche coche;
    coche.arrancar();
    
    Estudiante e1("Ana");
    Estudiante e2("Luis");
    
    Clase clase;
    clase.agregarEstudiante(&e1);
    clase.agregarEstudiante(&e2);
    clase.mostrarEstudiantes();
    
    return 0;
}

// 179. Patrón Strategy
#include <iostream>
using namespace std;
class EstrategiaOrdenamiento {
public:
    virtual void ordenar(int arr[], int n) = 0;
    virtual ~EstrategiaOrdenamiento() {}
};
class BubbleSort : public EstrategiaOrdenamiento {
public:
    void ordenar(int arr[], int n) override {
        cout << "Ordenando con Bubble Sort" << endl;
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < n-i-1; j++) {
                if (arr[j] > arr[j+1]) {
                    swap(arr[j], arr[j+1]);
                }
            }
        }
    }
};
class SelectionSort : public EstrategiaOrdenamiento {
public:
    void ordenar(int arr[], int n) override {
        cout << "Ordenando con Selection Sort" << endl;
        for (int i = 0; i < n-1; i++) {
            int minIdx = i;
            for (int j = i+1; j < n; j++) {
                if (arr[j] < arr[minIdx]) minIdx = j;
            }
            swap(arr[minIdx], arr[i]);
        }
    }
};
class Contexto {
private:
    EstrategiaOrdenamiento* estrategia;
public:
    Contexto(EstrategiaOrdenamiento* e) : estrategia(e) {}
    void setEstrategia(EstrategiaOrdenamiento* e) { estrategia = e; }
    void ejecutarOrdenamiento(int arr[], int n) {
        estrategia->ordenar(arr, n);
    }
};
int main() {
    int arr1[] = {64, 34, 25, 12, 22};
    int arr2[] = {64, 34, 25, 12, 22};
    int n = 5;
    
    BubbleSort bubble;
    SelectionSort selection;
    
    Contexto contexto(&bubble);
    contexto.ejecutarOrdenamiento(arr1, n);
    
    contexto.setEstrategia(&selection);
    contexto.ejecutarOrdenamiento(arr2, n);
    
    return 0;
}

// 180. Exception handling avanzado
#include <iostream>
#include <stdexcept>
using namespace std;
class MiExcepcion : public exception {
private:
    string mensaje;
public:
    MiExcepcion(const string& msg) : mensaje(msg) {}
    const char* what() const noexcept override {
        return mensaje.c_str();
    }
};
void funcionPeligrosa(int valor) {
    if (valor < 0) {
        throw invalid_argument("Valor no puede ser negativo");
    }
    if (valor == 0) {
        throw MiExcepcion("Valor personalizado de error");
    }
    if (valor > 100) {
        throw out_of_range("Valor fuera de rango");
    }
    cout << "Valor válido: " << valor << endl;
}
int main() {
    int valores[] = {-5, 0, 50, 150};
    
    for (int valor : valores) {
        try {
            funcionPeligrosa(valor);
        }
        catch (const invalid_argument& e) {
            cout << "Error de argumento: " << e.what() << endl;
        }
        catch (const MiExcepcion& e) {
            cout << "Mi excepción: " << e.what() << endl;
        }
        catch (const exception& e) {
            cout << "Excepción general: " << e.what() << endl;
        }
    }
    
    return 0;
}
