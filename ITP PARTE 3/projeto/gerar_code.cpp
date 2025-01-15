#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    srand(time(0)); //Gera um número aleatório a partir do tempo atual (biblioteca cstdlib)

    for (int i = 0; i < 7; i++) {
        int sete_digitos = rand() % 10; //Gera um número aleatório entre 0 e 9
        cout << sete_digitos << endl; //Imprime o número gerado
    }

    return 0;
}
