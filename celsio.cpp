#include <iostream>
using namespace std;

int main() {
    double celsius, fahrenheit;
    cout << "Ingresa la temperatura en grados Celsius: ";
    cin >> celsius;
    fahrenheit = (celsius * 9.0 / 5.0) + 32;
    cout << celsius << "°C equivalen a " << fahrenheit << "°F" << endl;
    return 0;
}

