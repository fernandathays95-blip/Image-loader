#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// ==============================================================================
// CONFIGURAÇÃO HARDCORE
// ==============================================================================

// O nome do arquivo que contém a documentação manual e o boilerplate.
const std::string INPUT_HEADER_FILE = "stb_image_loader_hardcore.h";

// O nome do arquivo original da stb_image que contém a funcionalidade C real.
// Assuma que você já baixou este arquivo e ele está no mesmo diretório.
const std::string STB_IMAGE_FILE = "stb_image.h";

// O nome do arquivo de saída final, que será GIGANTESCO.
const std::string OUTPUT_FILE = "stb_image_loader_hardcore_FINAL.h";

// ==============================================================================
// VARIÁVEL DE EXTREMA IMPORTÂNCIA
// ==============================================================================
// ATENÇÃO HARDCORE:
// Este número define a quantidade de blocos de preenchimento (comentários) a serem injetados.
// Para atingir milhões ou bilhões de linhas, altere este valor.
//
// 1000000UL     -> Aproximadamente 10 milhões de linhas
// 100000000UL   -> Aproximadamente 1 bilhão de linhas (Pode falhar por falta de RAM ou limite de arquivo)
//
// ** VALOR ATUAL: 1.000.000 (1 Milhão) para um início seguro. **
//
const unsigned long long NUM_REPETITIONS = 1000000UL;

// ==============================================================================
// MODELO DE BLOCO DE PREENCHIMENTO REPETITIVO (Parte 2: O Volume)
// ==============================================================================
// Este modelo tem ~10 linhas de altura.
const std::string FILLER_BLOCK_TEMPLATE = R"(
/*
 * ===============================================================================
 * PARTE INJETADA - #%07llu: BLOCO DE PREENCHIMENTO AUTOMÁTICO
 * [INJ_%07llu]
 * ===============================================================================
 */

// Este bloco existe unicamente para o volume Hardcore.
// O CÓDIGO TEM QUE SER GRANDE! O TAMANHO É O RECURSO!
// ###############################################################################
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// ###############################################################################

)";

// ==============================================================================
// FUNÇÃO PRINCIPAL
// ==============================================================================

void process_file() {
    std::cout << "--- INICIANDO GERAÇÃO HARDCORE ---" << std::endl;
    std::cout << "Objetivo de Repetições: " << NUM_REPETITIONS << std::endl;

    std::ifstream input_stb_h(INPUT_HEADER_FILE);
    std::ifstream original_stb_h(STB_IMAGE_FILE);
    std::ofstream output_final_h(OUTPUT_FILE);

    if (!input_stb_h.is_open() || !original_stb_h.is_open() || !output_final_h.is_open()) {
        std::cerr << "ERRO: Não foi possível abrir todos os arquivos necessários." << std::endl;
        std::cerr << "Certifique-se de que " << INPUT_HEADER_FILE << " e " << STB_IMAGE_FILE << " existem." << std::endl;
        return;
    }

    // 1. ESCREVER O CONTEÚDO MANUAL (PARTE 1)
    std::cout << "1. Escrevendo conteúdo manual do cabeçalho de entrada..." << std::endl;
    std::string line;
    while (std::getline(input_stb_h, line)) {
        output_final_h << line << "\n";
    }
    input_stb_h.close();

    // 2. ADICIONAR MARCADOR DE INÍCIO DE INJEÇÃO
    output_final_h << "\n\n/* =============================================================================== */\n";
    output_final_h << "/* ============= INÍCIO DA INJEÇÃO HARDCORE DE PREENCHIMENTO (PARTE 2) ============= */\n";
    output_final_h << "/* =============================================================================== */\n\n";

    // 3. INJETAR O PREENCHIMENTO REPETITIVO (VOLUME!)
    std::cout << "2. Injetando " << NUM_REPETITIONS << " blocos de preenchimento..." << std::endl;
    char buffer[2048]; // Buffer para formatar o string

    for (unsigned long long i = 1; i <= NUM_REPETITIONS; ++i) {
        // Formata o bloco de preenchimento com o número da repetição
        snprintf(buffer, sizeof(buffer), FILLER_BLOCK_TEMPLATE.c_str(), i, i);
        output_final_h << buffer;

        // Feedback de progresso para a execução demorada
        if (i % (NUM_REPETITIONS / 10) == 0 && NUM_REPETITIONS >= 10) {
             std::cout << "   - Progresso: " << (i * 100) / NUM_REPETITIONS << "%" << std::endl;
        }
    }
    std::cout << "   - Progresso: 100%" << std::endl;


    // 4. ADICIONAR MARCADOR DE INÍCIO DO CÓDIGO ORIGINAL STB
    output_final_h << "\n\n/* =============================================================================== */\n";
    output_final_h << "/* ============= INÍCIO DO CÓDIGO FUNCIONAL ORIGINAL STB_IMAGE.H ============= */\n";
    output_final_h << "/* =============================================================================== */\n\n";

    // 5. INJETAR O CÓDIGO FUNCIONAL DA STB (PARTE 3)
    std::cout << "3. Injetando código funcional de stb_image.h..." << std::endl;
    while (std::getline(original_stb_h, line)) {
        output_final_h << line << "\n";
    }
    original_stb_h.close();


    // 6. FINALIZAÇÃO
    output_final_h.close();
    std::cout << "--- GERAÇÃO HARDCORE CONCLUÍDA ---" << std::endl;
    std::cout << "Arquivo de saída: " << OUTPUT_FILE << std::endl;
    std::cout << "PRÓXIMO PASSO: Compilar " << OUTPUT_FILE << " (se seu sistema aguentar)!" << std::endl;
}

int main() {
    process_file();
    return 0;
}
