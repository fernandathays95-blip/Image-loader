/*
 * =================================================================
 *
 * MAIN_LOADER_HARDCORE.C
 *
 * Arquivo de teste para demonstrar a funcionalidade da
 * STB_IMAGE_LOADER_HARDCORE.H (A Biblioteca de Milhões de Linhas).
 *
 * =================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// -------------------------------------------------------------------------------
// Ponto CRÍTICO:
// O padrão da biblioteca STB requer que a macro de implementação seja definida
// em EXATAMENTE UM arquivo .c/.cpp.
// Esta macro insere o código de milhares de linhas para JPG, PNG, etc.
// -------------------------------------------------------------------------------
#define STB_IMAGE_IMPLEMENTATION

// Incluímos nosso cabeçalho gigantesco!
// (Certifique-se de que este arquivo .c e o stb_image_loader_hardcore.h estão na mesma pasta)
#include "stb_image_loader_hardcore.h"


// =================================================================
// FUNÇÃO PRINCIPAL DE EXECUÇÃO
// =================================================================
int main(int argc, char *argv[]) {
    
    // --- Desenho Hardcore ---
    /*
        [ M A I N ]
        \     \
        \     \
        [ C A R R E G A ]
        /     /
        /     /
        [ F I M ]
    */
    // ------------------------

    printf("*************************************************************\n");
    printf("* INICIANDO: MEGA IMAGE LOADER HARDCORE - TESTE DE FUNCIONALIDADE *\n");
    printf("*************************************************************\n\n");
    
    if (argc < 2) {
        printf("USO: %s <caminho_para_imagem>\n", argv[0]);
        printf("Exemplo: %s test_image.png\n\n", argv[0]);
        printf("--- Tentando carregar uma imagem de exemplo padrão ---\n");
        
        // Chamada da função de teste definida no seu cabeçalho.
        // NOTA: Você deve ter um arquivo chamado "default_test.jpg" ou "default_test.png" 
        // na mesma pasta para este teste funcionar.
        hardcore_example_load("default_test.jpg");
        
    } else {
        printf("--- Tentando carregar imagem via argumento ---\n");
        hardcore_example_load(argv[1]);
    }
    
    printf("\n*************************************************************\n");
    printf("* TESTE CONCLUÍDO. A biblioteca de milhões de linhas funciona! *\n");
    printf("*************************************************************\n");
    
    return 0;
}

// -------------------------------------------------------------------------------
// Instruções de Compilação (para sistemas GCC/Clang):
// gcc -o loader_test main_loader_hardcore.c
//
// Para rodar:
// ./loader_test my_awesome_photo.png
// -------------------------------------------------------------------------------
