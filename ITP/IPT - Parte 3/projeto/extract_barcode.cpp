#include "barcode_utils.h" 

int main() {
    const std::string filename = "barcode.pbm"; // Nome do arquivo PBM que contém o código de barras

    // Extrai o identificador EAN-8 do arquivo PBM usando a função da classe BarcodeUtils
    std::string identifier = BarcodeUtils::extractIdentifierFromPBM(filename);
    if (identifier.empty()) { // Verifica se a extração falhou
        std::cerr << "Erro ao extrair o identificador do arquivo PBM.\n"; // Mostra uma mensagem de erro
        return 1; // Finaliza o programa com código de erro
    }

    // Mostra o identificador extraído
    std::cout << "Identificador extraído: " << identifier << "\n";

    // Valida o identificador usando a função da classe BarcodeUtils
    if (BarcodeUtils::validateEAN8(identifier)) {
        std::cout << "O código de barras é válido.\n"; // Mensagem se o código for válido
    } else {
        std::cout << "O código de barras é inválido.\n"; // Mensagem se o código for inválido
    }

    return 0; 
}
