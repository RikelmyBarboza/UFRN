#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "recursao.cpp" // crie este arquivo com suas soluções

/**
 * Escreva funções RECURSIVAS (no arquivo recursao.cpp) que passe nos testes a seguir.
 * As funções que você irá criar devem seguir as assinaturas definidas nos testes.
 * Atente, portanto, para o nome das funções, os tipos e ordem de seus parâmetros e
 * o tipo de retorno.
 */

TEST_CASE("Dado um inteiro N, retorna o somatório dos números positivos de 1 a N") {
  CHECK(soma_positivos(3) == 6);   // 1 + 2 + 3 = 6
  CHECK(soma_positivos(7) == 28);  // 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28
  CHECK(soma_positivos(1) == 1);   // 1 = 1
  CHECK(soma_positivos(0) == 0);   // não há número a somar
  CHECK(soma_positivos(-4) == 0);  // não há número a somar
}

TEST_CASE("Dado um inteiro N, retorna o somatório dos números de 0 a N") {
  CHECK(soma_inteiros(3) == 6);   // 0 + 1 + 2 + 3 = 6
  CHECK(soma_inteiros(7) == 28);  // 0 + 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28
  CHECK(soma_inteiros(-1) == -1); // 0 + (-1) = -1
  CHECK(soma_inteiros(0) == 0);   // 0 = 0
  CHECK(soma_inteiros(-4) == -10);  // 0 + (-1) + (-2) + (-3) + (-4) = -10
}

// Um palíndromo é uma palavra cuja grafia é a mesma se escrita no sentido inverso (de trás pra frente).
TEST_CASE("Dada uma sting S, retorna verdadeiro se S for um palíndromo ou falso caso contrário") {
  CHECK(palindromo("arara") == true);
  CHECK(palindromo("esse") == true);
  CHECK(palindromo("mirim") == true);
  CHECK(palindromo("radar") == true);
  CHECK(palindromo("abacate") == false);
  CHECK(palindromo("ida") == false);
  CHECK(palindromo("palindromo") == false);
}

// Fatorial duplo de um número N é o produto de todos os inteiros de 1 até N que possuam
// a mesma paridade com N (se N é par, serão todos os pares. Se N for ímpar, serão os ímpares).
TEST_CASE("Dado um inteiro positivo N, retorna o fatorial duplo de N") {
  CHECK(fatorial_duplo(3) == 3);   // 3!! = 1 x 3 = 3
  CHECK(fatorial_duplo(7) == 105); // 7!! = 1 x 3 x 5 x 7 = 105
  CHECK(fatorial_duplo(0) == 1);   // 0!! = 1
  CHECK(fatorial_duplo(6) == 48);  // 6!! = 2 x 4 x 6 = 48
  CHECK(fatorial_duplo(10) == 3840);  // 10!! = 2 x 4 x 6 x 8 x 10 = 3840
}

// A sequência de Padovan P é uma sequência de naturais definida pelos valores iniciais
// P(0) = P(1) = P(2) = 1 e P(n) = P(n-2) + P(n-3) se n > 2.
TEST_CASE("Dado um inteiro positivo N, retorna o n-ésimo termo da sequência de Padovan") {
  CHECK(padovan(0) == 1);   // 3!! = 1 x 3 = 3
  CHECK(padovan(2) == 1); // 7!! = 1 x 3 x 5 x 7 = 105
  CHECK(padovan(6) == 4);   // 0!! = 1
  CHECK(padovan(9) == 9);  // 6!! = 2 x 4 x 6 = 48
  CHECK(padovan(10) == 12);  // 10!! = 2 x 4 x 6 x 8 x 10 = 3840
}

// Questão dada em aula 25/11
TEST_CASE("Dado um número inteiro positivo N, retorne quantas vezes um digito se repetiu") {
  CHECK(conta_digitos(12345, 1) == 1);   // 1 aparece 1 vez
  CHECK(conta_digitos(22223, 2) == 4);   // 2 aparece 4 vezes
  CHECK(conta_digitos(12345, 0) == 0);   // 0 não aparece
  CHECK(conta_digitos(912345, 9) == 1);  // 9 aparece 1 vez
  CHECK(conta_digitos(55555, 5) == 5);   // 5 aparece 1 vez
}
