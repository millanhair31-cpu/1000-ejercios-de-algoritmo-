// ===== CÓDIGOS INTERMEDIOS DE C++ (51-150) =====

// 51. Función suma
#include <iostream>
using namespace std;
int suma(int a, int b) {
    return a + b;
}
int main() {
    cout << "Suma: " << suma(5, 3) << endl;
    return 0;
}

// 52. Función factorial recursiva
#include <iostream>
using namespace std;
long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
int main() {
    cout << "Factorial: " << factorial(5) << endl;
    return 0;
}

// 53. Función Fibonacci recursiva
#include <iostream>
using namespace std;
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}
int main() {
    cout << "Fibonacci: " << fibonacci(8) << endl;
    return 0;
}

// 54. Función potencia
#include <iostream>
using namespace std;
double potencia(double base, int exp) {
    if (exp == 0) return 1;
    if (exp < 0) return 1.0 / potencia(base, -exp);
    return base * potencia(base, exp - 1);
}
int main() {
    cout << "Potencia: " << potencia(2, 3) << endl;
    return 0;
}

// 55. Función es primo
#include <iostream>
using namespace std;
bool esPrimo(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
int main() {
    cout << (esPrimo(17) ? "Es primo" : "No es primo") << endl;
    return 0;
}

// 56. Función MCD
#include <iostream>
using namespace std;
int mcd(int a, int b) {
    if (b == 0) return a;
    return mcd(b, a % b);
}
int main() {
    cout << "MCD: " << mcd(48, 18) << endl;
    return 0;
}

// 57. Función MCM
#include <iostream>
using namespace std;
int mcd(int a, int b) {
    if (b == 0) return a;
    return mcd(b, a % b);
}
int mcm(int a, int b) {
    return (a * b) / mcd(a, b);
}
int main() {
    cout << "MCM: " << mcm(12, 8) << endl;
    return 0;
}

// 58. Paso por referencia
#include <iostream>
using namespace std;
void intercambiar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
int main() {
    int x = 5, y = 10;
    cout << "Antes: x=" << x << ", y=" << y << endl;
    intercambiar(x, y);
    cout << "Después: x=" << x << ", y=" << y << endl;
    return 0;
}

// 59. Función con array
#include <iostream>
using namespace std;
int sumaArray(int arr[], int n) {
    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += arr[i];
    }
    return suma;
}
int main() {
    int numeros[] = {1, 2, 3, 4, 5};
    int n = sizeof(numeros) / sizeof(numeros[0]);
    cout << "Suma: " << sumaArray(numeros, n) << endl;
    return 0;
}

// 60. Función sobrecargada
#include <iostream>
using namespace std;
int suma(int a, int b) {
    return a + b;
}
double suma(double a, double b) {
    return a + b;
}
int suma(int a, int b, int c) {
    return a + b + c;
}
int main() {
    cout << "Suma int: " << suma(5, 3) << endl;
    cout << "Suma double: " << suma(5.5, 3.2) << endl;
    cout << "Suma tres: " << suma(1, 2, 3) << endl;
    return 0;
}

// 61. Punteros básicos
#include <iostream>
using namespace std;
int main() {
    int x = 10;
    int *ptr = &x;
    cout << "Valor: " << x << endl;
    cout << "Dirección: " << ptr << endl;
    cout << "Valor via puntero: " << *ptr << endl;
    return 0;
}

// 62. Aritmética de punteros
#include <iostream>
using namespace std;
int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr;
    for (int i = 0; i < 5; i++) {
        cout << "arr[" << i << "] = " << *(ptr + i) << endl;
    }
    return 0;
}

// 63. Puntero a función
#include <iostream>
using namespace std;
int suma(int a, int b) { return a + b; }
int resta(int a, int b) { return a - b; }
int main() {
    int (*operacion)(int, int) = suma;
    cout << "Resultado: " << operacion(5, 3) << endl;
    operacion = resta;
    cout << "Resultado: " << operacion(5, 3) << endl;
    return 0;
}

// 64. Asignación dinámica
#include <iostream>
using namespace std;
int main() {
    int n = 5;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i * 2;
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr;
    return 0;
}

// 65. Estructura básica
#include <iostream>
using namespace std;
struct Persona {
    string nombre;
    int edad;
    float altura;
};
int main() {
    Persona p1 = {"Juan", 25, 1.75};
    cout << "Nombre: " << p1.nombre << endl;
    cout << "Edad: " << p1.edad << endl;
    cout << "Altura: " << p1.altura << endl;
    return 0;
}

// 66. Array de estructuras
#include <iostream>
using namespace std;
struct Estudiante {
    string nombre;
    float nota;
};
int main() {
    Estudiante estudiantes[3] = {
        {"Ana", 8.5},
        {"Luis", 7.2},
        {"María", 9.1}
    };
    for (int i = 0; i < 3; i++) {
        cout << estudiantes[i].nombre << ": " << estudiantes[i].nota << endl;
    }
    return 0;
}

// 67. Puntero a estructura
#include <iostream>
using namespace std;
struct Punto {
    int x, y;
};
int main() {
    Punto p = {10, 20};
    Punto *ptr = &p;
    cout << "x: " << ptr->x << ", y: " << ptr->y << endl;
    return 0;
}

// 68. Unión básica
#include <iostream>
using namespace std;
union Dato {
    int entero;
    float decimal;
    char caracter;
};
int main() {
    Dato d;
    d.entero = 65;
    cout << "Entero: " << d.entero << endl;
    cout << "Caracter: " << d.caracter << endl;
    return 0;
}

// 69. Enumeración
#include <iostream>
using namespace std;
enum DiaSemana {
    LUNES, MARTES, MIERCOLES, JUEVES, VIERNES, SABADO, DOMINGO
};
int main() {
    DiaSemana hoy = MIERCOLES;
    cout << "Hoy es el día: " << hoy << endl;
    return 0;
}

// 70. Typedef
#include <iostream>
using namespace std;
typedef unsigned long long ull;
typedef struct {
    string nombre;
    int edad;
} Persona;
int main() {
    ull numero = 1234567890ULL;
    Persona p = {"Carlos", 30};
    cout << "Número: " << numero << endl;
    cout << "Persona: " << p.nombre << ", " << p.edad << endl;
    return 0;
}

// 71. Recursividad: Torre de Hanoi
#include <iostream>
using namespace std;
void hanoi(int n, char origen, char destino, char auxiliar) {
    if (n == 1) {
        cout << "Mover disco 1 de " << origen << " a " << destino << endl;
        return;
    }
    hanoi(n-1, origen, auxiliar, destino);
    cout << "Mover disco " << n << " de " << origen << " a " << destino << endl;
    hanoi(n-1, auxiliar, destino, origen);
}
int main() {
    hanoi(3, 'A', 'C', 'B');
    return 0;
}

// 72. Función con valores por defecto
#include <iostream>
using namespace std;
int potencia(int base, int exp = 2) {
    int resultado = 1;
    for (int i = 0; i < exp; i++) {
        resultado *= base;
    }
    return resultado;
}
int main() {
    cout << "3^2 = " << potencia(3) << endl;
    cout << "3^4 = " << potencia(3, 4) << endl;
    return 0;
}

// 73. Plantilla de función
#include <iostream>
using namespace std;
template<typename T>
T maximo(T a, T b) {
    return (a > b) ? a : b;
}
int main() {
    cout << "Máximo int: " << maximo(5, 3) << endl;
    cout << "Máximo double: " << maximo(5.7, 3.2) << endl;
    cout << "Máximo char: " << maximo('a', 'z') << endl;
    return 0;
}

// 74. Espacio de nombres
#include <iostream>
using namespace std;
namespace Matematicas {
    int suma(int a, int b) { return a + b; }
    int resta(int a, int b) { return a - b; }
}
int main() {
    cout << "Suma: " << Matematicas::suma(10, 5) << endl;
    cout << "Resta: " << Matematicas::resta(10, 5) << endl;
    return 0;
}

// 75. Manejo de excepciones básico
#include <iostream>
using namespace std;
int main() {
    try {
        int a = 10, b = 0;
        if (b == 0) throw "División por cero";
        cout << "Resultado: " << a / b << endl;
    }
    catch (const char* error) {
        cout << "Error: " << error << endl;
    }
    return 0;
}

// 76. Cadenas de caracteres
#include <iostream>
#include <cstring>
using namespace std;
int main() {
    char str1[50] = "Hola";
    char str2[] = " Mundo";
    strcat(str1, str2);
    cout << "Concatenación: " << str1 << endl;
    cout << "Longitud: " << strlen(str1) << endl;
    return 0;
}

// 77. Comparación de cadenas
#include <iostream>
#include <cstring>
using namespace std;
int main() {
    char str1[] = "hello";
    char str2[] = "world";
    char str3[] = "hello";
    cout << "str1 vs str2: " << strcmp(str1, str2) << endl;
    cout << "str1 vs str3: " << strcmp(str1, str3) << endl;
    return 0;
}

// 78. Copia de cadenas
#include <iostream>
#include <cstring>
using namespace std;
int main() {
    char origen[] = "Texto original";
    char destino[50];
    strcpy(destino, origen);
    cout << "Origen: " << origen << endl;
    cout << "Destino: " << destino << endl;
    return 0;
}

// 79. Búsqueda en cadena
#include <iostream>
#include <cstring>
using namespace std;
int main() {
    char texto[] = "Hola mundo";
    char *resultado = strstr(texto, "mundo");
    if (resultado) {
        cout << "Encontrado: " << resultado << endl;
    } else {
        cout << "No encontrado" << endl;
    }
    return 0;
}

// 80. Conversión string a número
#include <iostream>
#include <cstdlib>
using namespace std;
int main() {
    char str1[] = "123";
    char str2[] = "45.67";
    int entero = atoi(str1);
    double decimal = atof(str2);
    cout << "Entero: " << entero << endl;
    cout << "Decimal: " << decimal << endl;
    return 0;
}

// 81. Ordenamiento por selección
#include <iostream>
using namespace std;
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIdx]) minIdx = j;
        }
        int temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}
int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    cout << "Array ordenado: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}

// 82. Ordenamiento por inserción
#include <iostream>
using namespace std;
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr, n);
    cout << "Array ordenado: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}

// 83. Búsqueda binaria
#include <iostream>
using namespace std;
int busquedaBinaria(int arr[], int n, int x) {
    int izq = 0, der = n - 1;
    while (izq <= der) {
        int medio = izq + (der - izq) / 2;
        if (arr[medio] == x) return medio;
        if (arr[medio] < x) izq = medio + 1;
        else der = medio - 1;
    }
    return -1;
}
int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 10;
    int resultado = busquedaBinaria(arr, n, x);
    cout << (resultado == -1 ? "No encontrado" : "Encontrado en posición " + to_string(resultado)) << endl;
    return 0;
}

// 84. Multiplicación de matrices
#include <iostream>
using namespace std;
void multiplicarMatrices(int a[][2], int b[][2], int resultado[][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                resultado[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}
int main() {
    int a[2][2] = {{1, 2}, {3, 4}};
    int b[2][2] = {{5, 6}, {7, 8}};
    int resultado[2][2];
    multiplicarMatrices(a, b, resultado);
    cout << "Resultado:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << resultado[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

// 85. Lista enlazada simple
#include <iostream>
using namespace std;
struct Nodo {
    int dato;
    Nodo* siguiente;
};
void insertarInicio(Nodo** cabeza, int dato) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = dato;
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
}
void mostrarLista(Nodo* cabeza) {
    while (cabeza != nullptr) {
        cout << cabeza->dato << " ";
        cabeza = cabeza->siguiente;
    }
    cout << endl;
}
int main() {
    Nodo* cabeza = nullptr;
    insertarInicio(&cabeza, 3);
    insertarInicio(&cabeza, 2);
    insertarInicio(&cabeza, 1);
    mostrarLista(cabeza);
    return 0;
}

// 86. Pila con array
#include <iostream>
using namespace std;
class Pila {
private:
    int arr[100];
    int tope;
public:
    Pila() { tope = -1; }
    void push(int x) {
        if (tope < 99) arr[++tope] = x;
    }
    int pop() {
        if (tope >= 0) return arr[tope--];
        return -1;
    }
    bool estaVacia() {
        return tope == -1;
    }
};
int main() {
    Pila p;
    p.push(10);
    p.push(20);
    p.push(30);
    while (!p.estaVacia()) {
        cout << p.pop() << " ";
    }
    cout << endl;
    return 0;
}

// 87. Cola con array
#include <iostream>
using namespace std;
class Cola {
private:
    int arr[100];
    int frente, final;
public:
    Cola() { frente = final = -1; }
    void enqueue(int x) {
        if (final < 99) {
            if (frente == -1) frente = 0;
            arr[++final] = x;
        }
    }
    int dequeue() {
        if (frente != -1 && frente <= final) {
            return arr[frente++];
        }
        return -1;
    }
    bool estaVacia() {
        return frente == -1 || frente > final;
    }
};
int main() {
    Cola c;
    c.enqueue(10);
    c.enqueue(20);
    c.enqueue(30);
    while (!c.estaVacia()) {
        cout << c.dequeue() << " ";
    }
    cout << endl;
    return 0;
}

// 88. �rbol binario básico
#include <iostream>
using namespace std;
struct NodoArbol {
    int dato;
    NodoArbol* izquierdo;
    NodoArbol* derecho;
};
NodoArbol* crearNodo(int dato) {
    NodoArbol* nuevo = new NodoArbol();
    nuevo->dato = dato;
    nuevo->izquierdo = nuevo->derecho = nullptr;
    return nuevo;
}
void preorden(NodoArbol* raiz) {
    if (raiz != nullptr) {
        cout << raiz->dato << " ";
        preorden(raiz->izquierdo);
        preorden(raiz->derecho);
    }
}
int main() {
    NodoArbol* raiz = crearNodo(1);
    raiz->izquierdo = crearNodo(2);
    raiz->derecho = crearNodo(3);
    cout << "Preorden: ";
    preorden(raiz);
    cout << endl;
    return 0;
}

// 89. Recorrido inorden
#include <iostream>
using namespace std;
struct NodoArbol {
    int dato;
    NodoArbol* izquierdo;
    NodoArbol* derecho;
};
void inorden(NodoArbol* raiz) {
    if (raiz != nullptr) {
        inorden(raiz->izquierdo);
        cout << raiz->dato << " ";
        inorden(raiz->derecho);
    }
}
NodoArbol* crearNodo(int dato) {
    NodoArbol* nuevo = new NodoArbol();
    nuevo->dato = dato;
    nuevo->izquierdo = nuevo->derecho = nullptr;
    return nuevo;
}
int main() {
    NodoArbol* raiz = crearNodo(2);
    raiz->izquierdo = crearNodo(1);
    raiz->derecho = crearNodo(3);
    cout << "Inorden: ";
    inorden(raiz);
    cout << endl;
    return 0;
}

// 90. Recorrido postorden
#include <iostream>
using namespace std;
struct NodoArbol {
    int dato;
    NodoArbol* izquierdo;
    NodoArbol* derecho;
};
void postorden(NodoArbol* raiz) {
    if (raiz != nullptr) {
        postorden(raiz->izquierdo);
        postorden(raiz->derecho);
        cout << raiz->dato << " ";
    }
}
NodoArbol* crearNodo(int dato) {
    NodoArbol* nuevo = new NodoArbol();
    nuevo->dato = dato;
    nuevo->izquierdo = nuevo->derecho = nullptr;
    return nuevo;
}
int main() {
    NodoArbol* raiz = crearNodo(1);
    raiz->izquierdo = crearNodo(2);
    raiz->derecho = crearNodo(3);
    cout << "Postorden: ";
    postorden(raiz);
    cout << endl;
    return 0;
}

// 91. Hash table simple
#include <iostream>
using namespace std;
class HashTable {
private:
    int tabla[10];
    bool ocupado[10];
public:
    HashTable() {
        for (int i = 0; i < 10; i++) {
            ocupado[i] = false;
        }
    }
    int hash(int clave) {
        return clave % 10;
    }
    void insertar(int clave) {
        int indice = hash(clave);
        while (ocupado[indice]) {
            indice = (indice + 1) % 10;
        }
        tabla[indice] = clave;
        ocupado[indice] = true;
    }
    bool buscar(int clave) {
        int indice = hash(clave);
        int inicio = indice;
        while (ocupado[indice]) {
            if (tabla[indice] == clave) return true;
            indice = (indice + 1) % 10;
            if (indice == inicio) break;
        }
        return false;
    }
};
int main() {
    HashTable ht;
    ht.insertar(15);
    ht.insertar(25);
    ht.insertar(35);
    cout << (ht.buscar(25) ? "Encontrado" : "No encontrado") << endl;
    return 0;
}

// 92. Generador de números aleatorios
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    srand(time(0));
    cout << "Números aleatorios: ";
    for (int i = 0; i < 10; i++) {
        cout << rand() % 100 << " ";
    }
    cout << endl;
    return 0;
}

// 93. Matriz dinámica
#include <iostream>
using namespace std;
int main() {
    int filas = 3, columnas = 4;
    int** matriz = new int*[filas];
    for (int i = 0; i < filas; i++) {
        matriz[i] = new int[columnas];
    }
    
    // Llenar matriz
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = i * columnas + j;
        }
    }
    
    // Mostrar matriz
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
    
    // Liberar memoria
    for (int i = 0; i < filas; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
    
    return 0;
}

// 94. Contador de palabras
#include <iostream>
#include <string>
using namespace std;
int contarPalabras(string texto) {
    int contador = 0;
    bool enPalabra = false;
    for (char c : texto) {
        if (c != ' ' && c != '\t' && c != '\n') {
            if (!enPalabra) {
                contador++;
                enPalabra = true;
            }
        } else {
            enPalabra = false;
        }
    }
    return contador;
}
int main() {
    string texto = "Hola mundo desde C++";
    cout << "Número de palabras: " << contarPalabras(texto) << endl;
    return 0;
}

// 95. Validador de paréntesis
#include <iostream>
#include <string>
using namespace std;
bool validarParentesis(string expresion) {
    int contador = 0;
    for (char c : expresion) {
        if (c == '(') contador++;
        else if (c == ')') {
            contador--;
            if (contador < 0) return false;
        }
    }
    return contador == 0;
}
int main() {
    string expr = "((())())";
    cout << (validarParentesis(expr) ? "Válido" : "Inválido") << endl;
    return 0;
}

// 96. Calculadora de expresiones
#include <iostream>
#include <string>
using namespace std;
int evaluarExpresion(string expr) {
    int resultado = 0;
    int numero = 0;
    char operador = '+';
    
    for (char c : expr + "+") {
        if (isdigit(c)) {
            numero = numero * 10 + (c - '0');
        } else {
            if (operador == '+') resultado += numero;
            else if (operador == '-') resultado -= numero;
            numero = 0;
            operador = c;
        }
    }
    return resultado;
}
int main() {
    string expr = "10+5-3+7";
    cout << "Resultado: " << evaluarExpresion(expr) << endl;
    return 0;
}

// 97. Conversor de base numérica
#include <iostream>
#include <string>
using namespace std;
string convertirBase(int numero, int base) {
    if (numero == 0) return "0";
    string resultado = "";
    string digitos = "0123456789ABCDEF";
    while (numero > 0) {
        resultado = digitos[numero % base] + resultado;
        numero /= base;
    }
    return resultado;
}
int main() {
    int num = 255;
    cout << "Decimal: " << num << endl;
    cout << "Binario: " << convertirBase(num, 2) << endl;
    cout << "Octal: " << convertirBase(num, 8) << endl;
    cout << "Hexadecimal: " << convertirBase(num, 16) << endl;
    return 0;
}

// 98. Cifrado César
#include <iostream>
#include <string>
using namespace std;
string cifrarCesar(string texto, int desplazamiento) {
    string resultado = "";
    for (char c : texto) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            resultado += char((c - base + desplazamiento) % 26 + base);
        } else {
            resultado += c;
        }
    }
    return resultado;
}
int main() {
    string texto = "Hola Mundo";
    int desplazamiento = 3;
    string cifrado = cifrarCesar(texto, desplazamiento);
    cout << "Original: " << texto << endl;
    cout << "Cifrado: " << cifrado << endl;
    return 0;
}

// 99. Generador de permutaciones
#include <iostream>
#include <string>
using namespace std;
void permutar(string str, int inicio, int final) {
    if (inicio == final) {
        cout << str << endl;
    } else {
        for (int i = inicio; i <= final; i++) {
            swap(str[inicio], str[i]);
            permutar(str, inicio + 1, final);
            swap(str[inicio], str[i]);
        }
    }
}
int main() {
    string str = "ABC";
    cout << "Permutaciones de " << str << ":" << endl;
    permutar(str, 0, str.length() - 1);
    return 0;
}

// 100. Sistema de coordenadas
#include <iostream>
#include <cmath>
using namespace std;
struct Punto {
    double x, y;
};
double distancia(Punto p1, Punto p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}
Punto puntoMedio(Punto p1, Punto p2) {
    return {(p1.x + p2.x) / 2, (p1.y + p2.y) / 2};
}
int main() {
    Punto p1 = {0, 0};
    Punto p2 = {3, 4};
    cout << "Distancia: " << distancia(p1, p2) << endl;
    Punto medio = puntoMedio(p1, p2);
    cout << "Punto medio: (" << medio.x << ", " << medio.y << ")" << endl;
    return 0;
}
