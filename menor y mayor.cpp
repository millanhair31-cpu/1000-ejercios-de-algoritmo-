#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cout << "Ingresa tres números: ";
    cin >> a >> b >> c;
    int menor = a, mayor = a;
    if (b < menor) menor = b;
    if (c < menor) menor = c;
    if (b > mayor) mayor = b;
    if (c > mayor) mayor = c;
    cout << "Menor: " << menor << endl;
    cout << "Mayor: " << mayor << endl;
    return 0;
}