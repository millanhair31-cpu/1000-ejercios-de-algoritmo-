#include <iostream>
#include <string>

using namespace std;

int main() {
    string nombre;
    int edad;

    // Pedir el nombre
    cout << "Introduce tu nombre: ";
    getline(cin, nombre);  // Usamos getline para permitir nombres con espacios

    // Pedir la edad
    cout << "Introduce tu edad: ";
    cin >> edad;

    // Mostrar los datos
    cout << "\nHola, " << nombre << ". Tienes " << edad << " años." << endl;

    return 0;
}