#include <iostream>
using namespace std;

int main() {
    int opcao;
    double temperatura, resultado;

    cout << "Digite 1 para converter Celsius->Fahrenheit" << endl;
    cout << "Digite 2 para converter Fahrenheit->Celsius" << endl;
    cin >> opcao;

    cout << "Digite a temperatura: ";
    cin >> temperatura;

    if (opcao == 1) {
        resultado = temperatura * 9.0 / 5.0 + 32;
        cout << temperatura << " C equivale a " << resultado << " F" << endl;
    } else if (opcao == 2) {
        resultado = (temperatura - 32) * 5.0 / 9.0;
        cout << temperatura << " F equivale a " << resultado << " C" << endl;
    } else {
        cout << "Opcao invalida!" << endl;
    }

    return 0;
}