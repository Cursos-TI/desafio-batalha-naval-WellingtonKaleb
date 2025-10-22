#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.
#define linhas 10
#define colunas 10

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    int tabuleiro[linhas][colunas];

    for (int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
        {
            tabuleiro[i][j] = 0;
        }
    }
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.

    // Posicao do Navio Horizontal:
    int linhaNavioHorizontal = 3;
    int colunaNavioHorizontal = 2;
    int tamanhoNavioHorizontal = 3;

    // Posicao do Navio Vertical:
    int linhaNavioVertical = 5;
    int colunaNavioVertical = 3;
    int tamanhoNavioVertical = 3;


    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Declarando posicao do Navio Horizontal:
    printf("-- Exibicao das Coordenadas dos Navios --\n");
    printf("--- Posicao do Navio Horizontal (tamanho %d) ---\n", tamanhoNavioHorizontal);
    for (int j = 0; j < tamanhoNavioHorizontal; j++) {
        int colunaAtual = colunaNavioHorizontal + j;
        // Marca a posição no tabuleiro
        tabuleiro[linhaNavioHorizontal][colunaAtual] = 3;
        // Exibe a coordenada
        printf("Parte %d: (%d, %d)\n", j + 1, linhaNavioHorizontal, colunaAtual);
    }
    printf("\n");

    // Declarando posicao do Navio Vertical:
    printf("--- Posicao do Navio Vertical (tamanho %d) ---\n", tamanhoNavioVertical);
    for (int i = 0; i < tamanhoNavioVertical; i++)
    {
        int linhaAtual = linhaNavioVertical + i;
        // Marca a posição no tabuleiro
        tabuleiro[linhaAtual][colunaNavioVertical] = 3;
        // Exibe a coordenada
        printf("Parte %d: (%d, %d)\n", i + 1, linhaAtual, colunaNavioVertical);
    }
    printf("\n");


    // Exibicao do Tabuleiro:
    printf("..Tabuleiro..\n");

    printf("  ");

    for (int j = 0; j < colunas; j++)
    {
        printf(" %d", j);
    }

    printf("\n");

    for (int i = 0; i < linhas; i++)
    {
        printf("%d ", i);

        for (int j = 0; j < colunas; j++)
        {
            printf(" %d", tabuleiro[i][j]);
        }

        printf("\n");
    }
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
