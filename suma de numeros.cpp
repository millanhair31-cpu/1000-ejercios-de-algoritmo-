#include <iostream>
using namespace std;

int main() {
    int num, suma = 0;
    cout << "Ingresa un número entero positivo: ";
    cin >> num;
    while (num > 0) {
        suma += num % 10;
        num /= 10;
    }
    cout << "La suma de los dígitos es: " << suma << endl;
    return 0;
}