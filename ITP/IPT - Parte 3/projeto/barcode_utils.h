#ifndef BARCODE_UTILS_H
#define BARCODE_UTILS_H

#include <iostream>    
#include <fstream>     
#include <string>      
#include <vector>      
#include <algorithm>   
#include <cmath>       

class BarcodeUtils { // Classe utilitária para manipulação de códigos de barras
public:
    // Função para gerar um código de barras EAN-8
    static std::string generateEAN8Barcode(const std::string& identifier) {
        if (identifier.length() != 8) { // Verifica se o identificador tem 8 caracteres
            std::cerr << "O identificador EAN-8 deve ter 8 dígitos.\n"; // Mostra erro
            return ""; // Retorna vazio se inválido
        }

        // Marcadores que definem o início, centro e fim do código de barras
        const std::string START_MARKER = "101"; 
        const std::string CENTER_MARKER = "01010"; 
        const std::string END_MARKER = "101"; 

        // Constrói o código de barras começando com o marcador de início
        std::string barcode = START_MARKER;

        // Loop pelos 4 primeiros dígitos (lado esquerdo do código)
        for (int i = 0; i < 4; ++i) {
            int digit = identifier[i] - '0'; // Converte caractere para número
            barcode += L_CODE[digit]; // Adiciona o padrão L_CODE correspondente
        }

        barcode += CENTER_MARKER; // Adiciona o marcador central

        // Loop pelos 4 últimos dígitos (lado direito do código)
        for (int i = 4; i < 8; ++i) {
            int digit = identifier[i] - '0';
            barcode += R_CODE[digit]; // Adiciona o padrão R_CODE correspondente
        }

        barcode += END_MARKER; // Adiciona o marcador de fim

        return barcode; // Retorna o código de barras gerado
    }

    // Função para criar uma imagem PBM (formato texto)
    static void createPBMImage(const std::string& filename, const std::string& barcode) {
        std::ofstream file(filename); // Abre/cria o arquivo para escrita
        if (!file) { // Verifica erro na abertura do arquivo
            std::cerr << "Erro ao criar o arquivo de imagem.\n";
            return;
        }

        // Calcula dimensões da imagem baseada no comprimento do código de barras
        int barcodeLength = barcode.length();
        int moduleWidth = 3;  // Cada módulo (barra) tem 3 pixels de largura
        int margin = 10;      // Margem de 10 pixels
        int width = barcodeLength * moduleWidth + 2 * margin; // Largura total
        int height = 58;      // Altura fixa

        file << "P1\n";  // Escreve o cabeçalho do formato PBM
        file << width << " " << height << "\n";  // Escreve dimensões da imagem

        // Preenche a imagem com pixels baseados no código de barras
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                if (x < margin || x >= width - margin) { // Áreas de margem
                    file << "0 "; // Branco
                } else { 
                    int barcodeIndex = (x - margin) / moduleWidth; // Índice no código de barras
                    char module = barcode[barcodeIndex]; // Caractere do módulo
                    file << (module == '1' ? "1 " : "0 "); // Preenche preto (1) ou branco (0)
                }
            }
            file << "\n"; // Nova linha
        }

        file.close(); // Fecha o arquivo
    }

    // Valida um código EAN-8
    static bool validateEAN8(const std::string& identifier) {
        // Verifica se o identificador tem 8 caracteres e só contém dígitos
        if (identifier.length() != 8 || !std::all_of(identifier.begin(), identifier.end(), ::isdigit)) {
            return false; // Inválido
        }

        int sum = 0; // Soma acumulada para cálculo do dígito verificador
        for (size_t i = 0; i < 7; ++i) {
            int digit = identifier[i] - '0';
            sum += (i % 2 == 0 ? digit * 3 : digit); // Ponderação alternada
        }

        int nearestMultipleOfTen = ((sum + 9) / 10) * 10; // Arredonda para o múltiplo de 10 mais próximo
        int checkDigit = nearestMultipleOfTen - sum; // Calcula o dígito verificador

        return checkDigit == (identifier[7] - '0'); // Verifica com o último dígito
    }

    // Extrai identificador de um arquivo PBM
    static std::string extractIdentifierFromPBM(const std::string& filename) {
        std::ifstream file(filename); // Abre o arquivo
        if (!file) { // Erro ao abrir o arquivo
            std::cerr << "Erro ao abrir o arquivo: " << filename << "\n";
            return "";
        }

        std::string line;
        std::vector<std::string> barcodeData; // Armazena linhas do código de barras

        // Ignora cabeçalho do PBM
        int lineCounter = 0;
        while (std::getline(file, line)) {
            if (lineCounter++ < 3) continue; // Pula as 3 primeiras linhas
            barcodeData.push_back(line); // Salva as linhas restantes
        }

        file.close();

        std::string binaryBarcode; // Sequência binária do código de barras
        for (const auto& row : barcodeData) {
            for (char c : row) {
                if (c == '1' || c == '0') {
                    binaryBarcode += c; // Adiciona 0s e 1s
                }
            }
        }

        std::string identifier; // Identificador resultante
        for (size_t i = 0; i < binaryBarcode.length(); i += 7) {
            if (identifier.size() >= 8) break; // Para quando tiver 8 dígitos

            std::string segment = binaryBarcode.substr(i, 7); // Segmento de 7 bits
            identifier += '0'; // Adiciona '0' (substituir com lógica real)
        }

        return identifier; // Retorna identificador
    }

    // Padrões de codificação para L_CODE e R_CODE
    static const std::vector<std::string> L_CODE;
    static const std::vector<std::string> R_CODE;
};

// Definição dos padrões L_CODE e R_CODE
const std::vector<std::string> BarcodeUtils::L_CODE = {
    "0001101", "0011001", "0010011", "0111101", "0100011",
    "0110001", "0101111", "0111011", "0110111", "0001011"
};

const std::vector<std::string> BarcodeUtils::R_CODE = {
    "1110010", "1100110", "1101100", "1000010", "1011100",
    "1001110", "1010000", "1000100", "1001000", "1110100"
};

#endif
