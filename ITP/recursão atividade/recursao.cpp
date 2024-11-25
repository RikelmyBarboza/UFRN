#include <iostream>
using namespace std;

// atividade 1
int soma_positivos(int n) {
    if (n <= 0) {
        return 0;
    }
    return n + soma_positivos(n - 1);
}

// atividade 2
int soma_inteiros(int n) {
    if (n == 0) {
        return 0;
    } else if (n > 0) {
        return n + soma_inteiros(n - 1);
    } else {
        return n + soma_inteiros(n + 1);
    }
}

// atividade 3
bool palindromo(string s, int start, int end) {
    if (start >= end) {
        return true;
    }
    if (s[start] != s[end]) {
        return false;
    }
    return palindromo(s, start + 1, end - 1);
}
bool palindromo(string s) {
    return palindromo(s, 0, s.length() - 1);
}

//atividade 4
int fatorial_duplo(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * fatorial_duplo(n - 2);
}

//atividade 5
int padovan(int n) {
    if (n == 0 || n == 1 || n == 2) {
        return 1;
    }
    return padovan(n - 2) + padovan(n - 3);
}

//atividade extra - escreva uma função para contar quantas vezes um digito aparece em um número inteiro.
int conta_digitos(int n, int d) {
    if (n == 0) {
        return 0;
    }
    if (n % 10 == d) {
        return 1 + conta_digitos(n / 10, d);
    }
    return conta_digitos(n / 10, d);
}

