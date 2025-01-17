#include <iostream>
#include <cstdlib>
#include <ctime> // Biblioteca para manipulação de tempo
using namespace std;

int main() {
    int soma = 0; // Armazena a soma dos 7 primeiros digitos
    int sete_digitos[7]; // Armazena os 7 primeiros digitos
    int oitavo_digito; // Armazena o oitavo digito

    do {
        srand(time(0)); //Gera um número aleatório a partir do tempo atual (biblioteca cstdlib)

        for (int i = 0; i < 7; i++) {
            sete_digitos[i] = rand() % 10; //Gera um número aleatório entre 0 e 9
        }

        // Calcula a soma com os multiplicadores alternados entre 3 e 1
        soma = 0; // Reset soma
        for (int i = 0; i < 7; i++) {
            if (i % 2 == 0) { // Índices pares usam multiplicador 3
                soma += 3 * sete_digitos[i];
            } else { // Índices ímpares usam multiplicador 1
                soma += sete_digitos[i];
            }
        }

    } while (soma % 10 == 0);

cout << endl; // remover dps

// Subtrai o oitavo digito e soma com os sete_digitos

    oitavo_digito = 10 - (soma % 10); // Calcula o oitavo digito

    // Imprime o código gerado
    cout << "Código gerado: ";
    for (int i = 0; i < 7; i++) {
        cout << sete_digitos[i]; // Imprime os 7 primeiros digitos
    }
    cout << oitavo_digito << endl; // Imprime o oitavo digito formatado

    return 0;
}
