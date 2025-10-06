#include <iostream>
using namespace std;

int main() {
    int n, factorial = 1;
    cout << "Ingresa un número entero no negativo: ";
    cin >> n;
    if (n < 0) {
        cout << "El factorial no está definido para números negativos." << endl;
        return 1;
    }
    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }
    cout << "El factorial de " << n << " es " << factorial << endl;
    return 0;
}