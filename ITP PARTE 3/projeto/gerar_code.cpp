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

    cout << endl; // remover dps


// Calcula a soma com os multiplicadores alternados entre 3 e 1
    for (int i = 0; i < 7; i++) {
        if (i % 2 == 0) { // Índices pares usam multiplicador 3
            soma += 3 * sete_digitos[i];
        } else { // Índices ímpares usam multiplicador 1
            soma += sete_digitos[i];
        }
    }

    // só pra saber se ta certinho (temporario)
    cout << "Soma calculada: " << soma << endl;

    return 0;
}