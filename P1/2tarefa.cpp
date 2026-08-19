#include <iostream>
using namespace std;

int main() {
    int n;
    int fatorial = 1; 
    
    cout << "bota um numero: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        fatorial = fatorial * i;
    }

    cout << fatorial << endl;

    return 0;
}