#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Ingresa un número: ";
    cin >> num;
    if (num > 0)
        cout << "El número es positivo." << endl;
    else if (num < 0)
        cout << "El número es negativo." << endl;
    else
        cout << "El número es cero." << endl;
    return 0;
}