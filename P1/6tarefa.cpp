#include <iostream>
using namespace std;

int main() {
    int n;
    bool ehPrimo = true;

    cout << "Digite um numero: ";
    cin >> n;

    if (n <= 1) {
        ehPrimo = false;
    } else {
        for (int i = 2; i < n; i++) {
            if (n % i == 0) {
                ehPrimo = false;
                break;
            }
        }
    }

    if (ehPrimo) {
        cout << n << " e primo." << endl;
    } else {
        cout << n << " nao e primo." << endl;
    }

    return 0;
}