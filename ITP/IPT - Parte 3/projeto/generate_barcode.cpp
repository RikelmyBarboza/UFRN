#include "barcode_utils.h"

int main() {
    std::string identifier; // Variável para armazenar o identificador EAN-8

    // Solicita ao usuário que insira o identificador EAN-8
    std::cout << "Digite o identificador EAN-8 (8 dígitos): ";
    std::cin >> identifier;

    // Verifica se o identificador tem exatamente 8 dígitos numéricos
    if (identifier.length() != 8 || !std::all_of(identifier.begin(), identifier.end(), ::isdigit)) {
        std::cerr << "O identificador deve conter exatamente 8 dígitos numéricos.\n"; // Mensagem de erro
        return 1; // Finaliza o programa com código de erro
    }

    // Gera o código de barras a partir do identificador
    std::string barcode = BarcodeUtils::generateEAN8Barcode(identifier);

    // Verifica se o código de barras foi gerado com sucesso
    if (!barcode.empty()) {
        // Cria um arquivo PBM com a representação gráfica do código de barras
        BarcodeUtils::createPBMImage("barcode.pbm", barcode);
        std::cout << "Código de barras gerado e salvo como 'barcode.pbm'.\n"; // Mensagem de sucesso
    }

    return 0; 
}
