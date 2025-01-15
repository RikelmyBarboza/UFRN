#include <iostream>
#include <cstdlib>
#include <ctime> // Biblioteca para manipulação de tempo
using namespace std;

int main() {
    srand(time(0)); //Gera um número aleatório a partir do tempo atual (biblioteca cstdlib)

    int sete_digitos[7]; // Armazena os 7 primeiros digitos
    int soma = 0; // Armazena a soma dos 7 primeiros digitos

    for (int i = 0; i < 7; i++) {
        sete_digitos[i] = rand() % 10; //Gera um número aleatório entre 0 e 9
        cout << sete_digitos[i] << endl; //Imprime o número gerado
    }

    cout << endl; 
}

