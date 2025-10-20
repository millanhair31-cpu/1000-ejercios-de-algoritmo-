// ===== CÓDIGOS BÁSICOS DE C++ (1-50) =====

// 1. Hola Mundo
#include <iostream>
using namespace std;
int main() {
    cout << "Hola Mundo!" << endl;
    return 0;
}

// 2. Suma de dos números
#include <iostream>
using namespace std;
int main() {
    int a = 5, b = 3;
    int suma = a + b;
    cout << "La suma es: " << suma << endl;
    return 0;
}

// 3. Área de un círculo
#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double radio = 5.0;
    double area = M_PI * radio * radio;
    cout << "El área del círculo es: " << area << endl;
    return 0;
}

// 4. Número par o impar
#include <iostream>
using namespace std;
int main() {
    int num = 15;
    if (num % 2 == 0)
        cout << num << " es par" << endl;
    else
        cout << num << " es impar" << endl;
    return 0;
}

// 5. Mayor de tres números
#include <iostream>
using namespace std;
int main() {
    int a = 10, b = 25, c = 15;
    int mayor = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
    cout << "El mayor es: " << mayor << endl;
    return 0;
}

// 6. Factorial de un número
#include <iostream>
using namespace std;
int main() {
    int n = 5;
    long long factorial = 1;
    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }
    cout << "Factorial de " << n << " es: " << factorial << endl;
    return 0;
}

// 7. Serie de Fibonacci
#include <iostream>
using namespace std;
int main() {
    int n = 10;
    int a = 0, b = 1;
    cout << "Serie Fibonacci: " << a << " " << b << " ";
    for (int i = 2; i < n; i++) {
        int c = a + b;
        cout << c << " ";
        a = b;
        b = c;
    }
    cout << endl;
    return 0;
}

// 8. Número primo
#include <iostream>
using namespace std;
int main() {
    int n = 17;
    bool esPrimo = true;
    if (n <= 1) esPrimo = false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            esPrimo = false;
            break;
        }
    }
    cout << n << (esPrimo ? " es primo" : " no es primo") << endl;
    return 0;
}

// 9. Tabla de multiplicar
#include <iostream>
using namespace std;
int main() {
    int num = 7;
    cout << "Tabla del " << num << ":" << endl;
    for (int i = 1; i <= 10; i++) {
        cout << num << " x " << i << " = " << num * i << endl;
    }
    return 0;
}

// 10. Suma de dígitos
#include <iostream>
using namespace std;
int main() {
    int num = 12345;
    int suma = 0;
    while (num > 0) {
        suma += num % 10;
        num /= 10;
    }
    cout << "Suma de dígitos: " << suma << endl;
    return 0;
}

// 11. Número invertido
#include <iostream>
using namespace std;
int main() {
    int num = 12345;
    int invertido = 0;
    while (num > 0) {
        invertido = invertido * 10 + num % 10;
        num /= 10;
    }
    cout << "Número invertido: " << invertido << endl;
    return 0;
}

// 12. Palíndromo
#include <iostream>
using namespace std;
int main() {
    int num = 121;
    int original = num;
    int invertido = 0;
    while (num > 0) {
        invertido = invertido * 10 + num % 10;
        num /= 10;
    }
    cout << original << (original == invertido ? " es palíndromo" : " no es palíndromo") << endl;
    return 0;
}

// 13. Números perfectos
#include <iostream>
using namespace std;
int main() {
    int n = 28;
    int suma = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) suma += i;
    }
    cout << n << (suma == n ? " es perfecto" : " no es perfecto") << endl;
    return 0;
}

// 14. Conversión de temperatura
#include <iostream>
using namespace std;
int main() {
    double celsius = 25.0;
    double fahrenheit = (celsius * 9.0/5.0) + 32;
    cout << celsius << "°C = " << fahrenheit << "°F" << endl;
    return 0;
}

// 15. Calculadora simple
#include <iostream>
using namespace std;
int main() {
    double a = 10, b = 5;
    char op = '+';
    switch(op) {
        case '+': cout << a + b << endl; break;
        case '-': cout << a - b << endl; break;
        case '*': cout << a * b << endl; break;
        case '/': cout << a / b << endl; break;
        default: cout << "Operador inválido" << endl;
    }
    return 0;
}

// 16. Números Armstrong
#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int num = 153;
    int original = num;
    int suma = 0, digitos = 0;
    int temp = num;
    while (temp != 0) {
        digitos++;
        temp /= 10;
    }
    temp = num;
    while (temp != 0) {
        suma += pow(temp % 10, digitos);
        temp /= 10;
    }
    cout << original << (suma == original ? " es Armstrong" : " no es Armstrong") << endl;
    return 0;
}

// 17. Intercambio de variables
#include <iostream>
using namespace std;
int main() {
    int a = 10, b = 20;
    cout << "Antes: a = " << a << ", b = " << b << endl;
    int temp = a;
    a = b;
    b = temp;
    cout << "Después: a = " << a << ", b = " << b << endl;
    return 0;
}

// 18. Suma de números pares
#include <iostream>
using namespace std;
int main() {
    int n = 10;
    int suma = 0;
    for (int i = 2; i <= n; i += 2) {
        suma += i;
    }
    cout << "Suma de pares hasta " << n << ": " << suma << endl;
    return 0;
}

// 19. Contar vocales
#include <iostream>
#include <string>
using namespace std;
int main() {
    string texto = "Hola Mundo";
    int vocales = 0;
    for (char c : texto) {
        c = tolower(c);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            vocales++;
    }
    cout << "Número de vocales: " << vocales << endl;
    return 0;
}

// 20. Potencia de un número
#include <iostream>
using namespace std;
int main() {
    int base = 2, exponente = 5;
    long long resultado = 1;
    for (int i = 0; i < exponente; i++) {
        resultado *= base;
    }
    cout << base << "^" << exponente << " = " << resultado << endl;
    return 0;
}

// 21. Máximo común divisor
#include <iostream>
using namespace std;
int main() {
    int a = 48, b = 18;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    cout << "MCD: " << a << endl;
    return 0;
}

// 22. Mínimo común múltiplo
#include <iostream>
using namespace std;
int mcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main() {
    int a = 12, b = 8;
    int mcm = (a * b) / mcd(a, b);
    cout << "MCM: " << mcm << endl;
    return 0;
}

// 23. Suma de serie aritmética
#include <iostream>
using namespace std;
int main() {
    int a1 = 2, d = 3, n = 10;
    int suma = n * (2 * a1 + (n - 1) * d) / 2;
    cout << "Suma de la serie: " << suma << endl;
    return 0;
}

// 24. Conversión decimal a binario
#include <iostream>
#include <string>
using namespace std;
int main() {
    int decimal = 25;
    string binario = "";
    while (decimal > 0) {
        binario = (decimal % 2 == 0 ? "0" : "1") + binario;
        decimal /= 2;
    }
    cout << "Binario: " << binario << endl;
    return 0;
}

// 25. Suma de cuadrados
#include <iostream>
using namespace std;
int main() {
    int n = 5;
    int suma = 0;
    for (int i = 1; i <= n; i++) {
        suma += i * i;
    }
    cout << "Suma de cuadrados: " << suma << endl;
    return 0;
}

// 26. Año bisiesto
#include <iostream>
using namespace std;
int main() {
    int año = 2024;
    bool bisiesto = (año % 4 == 0 && año % 100 != 0) || (año % 400 == 0);
    cout << año << (bisiesto ? " es bisiesto" : " no es bisiesto") << endl;
    return 0;
}

// 27. Número de días en un mes
#include <iostream>
using namespace std;
int main() {
    int mes = 2, año = 2024;
    int dias;
    if (mes == 2) {
        bool bisiesto = (año % 4 == 0 && año % 100 != 0) || (año % 400 == 0);
        dias = bisiesto ? 29 : 28;
    } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        dias = 30;
    } else {
        dias = 31;
    }
    cout << "Días en el mes: " << dias << endl;
    return 0;
}

// 28. Suma de números impares
#include <iostream>
using namespace std;
int main() {
    int n = 10;
    int suma = 0;
    for (int i = 1; i <= n; i += 2) {
        suma += i;
    }
    cout << "Suma de impares: " << suma << endl;
    return 0;
}

// 29. Promedio de números
#include <iostream>
using namespace std;
int main() {
    int numeros[] = {10, 20, 30, 40, 50};
    int n = sizeof(numeros) / sizeof(numeros[0]);
    double suma = 0;
    for (int i = 0; i < n; i++) {
        suma += numeros[i];
    }
    cout << "Promedio: " << suma / n << endl;
    return 0;
}

// 30. Número mayor en array
#include <iostream>
using namespace std;
int main() {
    int arr[] = {3, 7, 2, 9, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int mayor = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > mayor) mayor = arr[i];
    }
    cout << "Mayor: " << mayor << endl;
    return 0;
}

// 31. Número menor en array
#include <iostream>
using namespace std;
int main() {
    int arr[] = {3, 7, 2, 9, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int menor = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < menor) menor = arr[i];
    }
    cout << "Menor: " << menor << endl;
    return 0;
}

// 32. Búsqueda lineal
#include <iostream>
using namespace std;
int main() {
    int arr[] = {3, 7, 2, 9, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int buscar = 7;
    int posicion = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == buscar) {
            posicion = i;
            break;
        }
    }
    cout << (posicion != -1 ? "Encontrado en posición " + to_string(posicion) : "No encontrado") << endl;
    return 0;
}

// 33. Contador de elementos
#include <iostream>
using namespace std;
int main() {
    int arr[] = {1, 2, 3, 2, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int elemento = 2;
    int contador = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == elemento) contador++;
    }
    cout << "El elemento " << elemento << " aparece " << contador << " veces" << endl;
    return 0;
}

// 34. Suma de array
#include <iostream>
using namespace std;
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += arr[i];
    }
    cout << "Suma del array: " << suma << endl;
    return 0;
}

// 35. Producto de array
#include <iostream>
using namespace std;
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long producto = 1;
    for (int i = 0; i < n; i++) {
        producto *= arr[i];
    }
    cout << "Producto del array: " << producto << endl;
    return 0;
}

// 36. Invertir array
#include <iostream>
using namespace std;
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n/2; i++) {
        int temp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = temp;
    }
    cout << "Array invertido: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

// 37. Números duplicados
#include <iostream>
using namespace std;
int main() {
    int arr[] = {1, 2, 3, 2, 4, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Elementos duplicados: ";
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                cout << arr[i] << " ";
                break;
            }
        }
    }
    cout << endl;
    return 0;
}

// 38. Segundo mayor
#include <iostream>
using namespace std;
int main() {
    int arr[] = {3, 7, 2, 9, 1, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int mayor = arr[0], segundo = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > mayor) {
            segundo = mayor;
            mayor = arr[i];
        } else if (arr[i] > segundo && arr[i] != mayor) {
            segundo = arr[i];
        }
    }
    cout << "Segundo mayor: " << segundo << endl;
    return 0;
}

// 39. Frecuencia de elementos
#include <iostream>
using namespace std;
int main() {
    int arr[] = {1, 2, 3, 2, 1, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++) {
        int contador = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                contador++;
                arr[j] = -1; // Marcar como visitado
            }
        }
        if (arr[i] != -1) {
            cout << arr[i] << " aparece " << contador << " veces" << endl;
        }
    }
    return 0;
}

// 40. Ordenamiento burbuja
#include <iostream>
using namespace std;
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    cout << "Array ordenado: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

// 41. Matriz identidad
#include <iostream>
using namespace std;
int main() {
    int n = 3;
    int matriz[3][3];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = (i == j) ? 1 : 0;
        }
    }
    cout << "Matriz identidad:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

// 42. Suma de matrices
#include <iostream>
using namespace std;
int main() {
    int a[2][2] = {{1, 2}, {3, 4}};
    int b[2][2] = {{5, 6}, {7, 8}};
    int suma[2][2];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            suma[i][j] = a[i][j] + b[i][j];
        }
    }
    cout << "Suma de matrices:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << suma[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

// 43. Transpuesta de matriz
#include <iostream>
using namespace std;
int main() {
    int matriz[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int transpuesta[3][2];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            transpuesta[j][i] = matriz[i][j];
        }
    }
    cout << "Matriz transpuesta:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            cout << transpuesta[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

// 44. Diagonal de matriz
#include <iostream>
using namespace std;
int main() {
    int matriz[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "Diagonal principal: ";
    for (int i = 0; i < 3; i++) {
        cout << matriz[i][i] << " ";
    }
    cout << endl;
    return 0;
}

// 45. Suma diagonal
#include <iostream>
using namespace std;
int main() {
    int matriz[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int suma = 0;
    for (int i = 0; i < 3; i++) {
        suma += matriz[i][i];
    }
    cout << "Suma de diagonal: " << suma << endl;
    return 0;
}

// 46. Determinante 2x2
#include <iostream>
using namespace std;
int main() {
    int matriz[2][2] = {{3, 2}, {1, 4}};
    int det = matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];
    cout << "Determinante: " << det << endl;
    return 0;
}

// 47. Imprimir patrón
#include <iostream>
using namespace std;
int main() {
    int n = 5;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}

// 48. Patrón numérico
#include <iostream>
using namespace std;
int main() {
    int n = 5;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}

// 49. Pirámide de números
#include <iostream>
using namespace std;
int main() {
    int n = 5;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n-i; j++) cout << " ";
        for (int j = 1; j <= i; j++) cout << j << " ";
        cout << endl;
    }
    return 0;
}

// 50. Números romanos básicos
#include <iostream>
using namespace std;
int main() {
    int num = 27;
    string romano = "";
    int valores[] = {10, 9, 5, 4, 1};
    string simbolos[] = {"X", "IX", "V", "IV", "I"};
    for (int i = 0; i < 5; i++) {
        while (num >= valores[i]) {
            romano += simbolos[i];
            num -= valores[i];
        }
    }
    cout << "Romano: " << romano << endl;
    return 0;
}
