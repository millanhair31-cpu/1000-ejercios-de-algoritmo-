#include <iostream>
using namespace std;

int main() {
    int num, original, invertido = 0;
    cout << "Ingresa un número entero: ";
    cin >> num;
    original = num;
    while (num > 0) {
        invertido = invertido * 10 + num % 10;
        num /= 10;
    }
    if (original == invertido)
        cout << original << " es un palíndromo." << endl;
    else
        cout << original << " no es un palíndromo." << endl;
    return 0;
}