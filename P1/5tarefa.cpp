#include <iostream>
#include <string>
using namespace std;

int main() {
    string texto;

    cout << "Digite um texto: ";
    getline(cin, texto);

    int quantidade = texto.length();

    cout << "A string possui " << quantidade << " caracteres." << endl;

    return 0;
}