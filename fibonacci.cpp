#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "¿Cuántos términos de Fibonacci quieres? ";
    cin >> n;
    if (n <= 0) return 0;
    long long a = 0, b = 1;
    cout << "Serie: ";
    for (int i = 0; i < n; i++) {
        if (i == 0)
            cout << a;
        else if (i == 1)
            cout << ", " << b;
        else {
            long long c = a + b;
            cout << ", " << c;
            a = b;
            b = c;
        }
    }
    cout << endl;
    return 0;
}