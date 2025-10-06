#include <iostream>
#include <string>
using namespace std;

int main() {
    string frase;
    cout << "Ingresa una frase: ";
    getline(cin, frase);
    int palabras = 0;
    bool enPalabra = false;
    for (char c : frase) {
        if (c != ' ' && !enPalabra) {
            palabras++;
            enPalabra = true;
        } else if (c == ' ') {
            enPalabra = false;
        }
    }
    cout << "La frase tiene " << palabras << " palabra(s)." << endl;
    return 0;
}