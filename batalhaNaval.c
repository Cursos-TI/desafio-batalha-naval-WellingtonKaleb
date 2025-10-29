#include <stdio.h>

// Definição das constantes para as dimensões do tabuleiro e das formas.
#define linhas 10
#define colunas 10

#define Lcone 3
#define Ccone 5

#define Lcruz 3
#define Ccruz 5

#define Loctaedro 3
#define Coctaedro 5

int main()
{
    // -----------------------------------------------------------
    // INICIALIZAÇÃO DO TABULEIRO
    // -----------------------------------------------------------
    // Declaração da matriz 10x10 que representa o tabuleiro do jogo.
    int tabuleiro[linhas][colunas];

    // Inicialização de todas as células do tabuleiro com 0 (representando água/vazio).
    for (int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
        {
            tabuleiro[i][j] = 0;
        }
    }


    // -----------------------------------------------------------
    // DEFINIÇÃO DAS COORDENADAS E TAMANHOS DOS NAVIOS
    // -----------------------------------------------------------
    // Definição da posição inicial e tamanho do Navio Horizontal (valor 3).
    int linhaNavioHorizontal = 3;
    int colunaNavioHorizontal = 2;
    int tamanhoNavioHorizontal = 3;

    // Definição da posição inicial e tamanho do Navio Vertical (valor 3).
    int linhaNavioVertical = 6;
    int colunaNavioVertical = 2;
    int tamanhoNavioVertical = 3;

    // Definição da posição inicial e tamanho do Navio Diagonal 1 (valor 3).
    int linhaNavioDiagonal1 = 0;
    int colunaNavioDiagonal1 = 8;
    int tamanhoNavioDiagonal1 = 3;

    // Definição da posição inicial e tamanho do Navio Diagonal 2 (valor 3).
    int linhaNavioDiagonal2 = 7;
    int colunaNavioDiagonal2 = 5;
    int tamanhoNavioDiagonal2 = 3;


    // -----------------------------------------------------------
    // POSICIONAMENTO E EXIBIÇÃO DOS NAVIOS
    // -----------------------------------------------------------
    printf("-- Exibicao das Coordenadas dos Navios --\n");
    
    // Posiciona e exibe o Navio Horizontal.
    printf("--- Posicao do Navio Horizontal (tamanho %d) ---\n", tamanhoNavioHorizontal);
    for (int j = 0; j < tamanhoNavioHorizontal; j++)
    {
        int colunaAtual = colunaNavioHorizontal + j;
        // Marca a posição no tabuleiro com 3.
        tabuleiro[linhaNavioHorizontal][colunaAtual] = 3;
        // Exibe a coordenada.
        printf("Parte %d: (%d, %d)\n", j + 1, linhaNavioHorizontal, colunaAtual);
    }
    printf("\n");

    // Posiciona e exibe o Navio Vertical.
    printf("--- Posicao do Navio Vertical (tamanho %d) ---\n", tamanhoNavioVertical);
    for (int i = 0; i < tamanhoNavioVertical; i++)
    {
        int linhaAtual = linhaNavioVertical + i;
        // Marca a posição no tabuleiro com 3.
        tabuleiro[linhaAtual][colunaNavioVertical] = 3;
        // Exibe a coordenada.
        printf("Parte %d: (%d, %d)\n", i + 1, linhaAtual, colunaNavioVertical);
    }
    printf("\n");

    // Posiciona e exibe o Navio Diagonal 1 (descendo e indo para a esquerda).
    printf("--- Posicao do Navio Diagonal1 (tamanho %d) ---\n", tamanhoNavioDiagonal1);
    for (int i = 0; i < tamanhoNavioDiagonal1; i++)
    {
        // Marca a posição atual no tabuleiro com 3.
        tabuleiro[linhaNavioDiagonal1][colunaNavioDiagonal1] = 3;
        printf("Parte %d: (%d,%d)\n", i + 1, linhaNavioDiagonal1, colunaNavioDiagonal1);
        // Atualiza as coordenadas para a próxima parte na diagonal.
        linhaNavioDiagonal1++, colunaNavioDiagonal1--;
    }
    printf("\n");

    // Posiciona e exibe o Navio Diagonal 2 (descendo e indo para a direita).
    printf("--- Posicao do Navio Diagonal2 (tamanho %d) ---\n", tamanhoNavioDiagonal2);
    for (int i = 0; i < tamanhoNavioDiagonal2; i++)
    {
        // Marca a posição atual no tabuleiro com 3.
        tabuleiro[linhaNavioDiagonal2][colunaNavioDiagonal2] = 3;
        printf("Parte %d: (%d, %d)\n", i + 1, linhaNavioDiagonal2, colunaNavioDiagonal2);
        // Atualiza as coordenadas para a próxima parte na diagonal.
        linhaNavioDiagonal2++, colunaNavioDiagonal2++;
    }
    printf("\n");

    // -----------------------------------------------------------
    // DEFINIÇÃO DA FORMA: CONE
    // -----------------------------------------------------------
    // Cria uma matriz para a forma Cone (3x5) inicializada com 0.
    int cone[Lcone][Ccone] = {0};
    int colunaOrigem_Cone = 2; // Coluna central para a ponta do cone.

    // Lógica para preencher a forma Cone com o valor 5.
    for (int i = 0; i < Lcone; i++)
    {
        // Preenche a coluna central em todas as linhas.
        cone[i][colunaOrigem_Cone] = 5;
        
        // Na linha 1, preenche [1, 1], [1, 2], [1, 3] (Forma triangular/crescente).
        if (i == 1)
        {
            for (int j = 0; j < 3; j++)
            {
                int localatual = i + j; // Índices: 1, 2, 3
                cone[i][localatual] = 5;
            }
        }

        // Na linha 2, preenche toda a largura (Base do cone).
        if (i == 2)
        {
            for (int j = 0; j < Ccone; j++)
            {
                cone[i][j] = 5;
            }
        }
    }


    // -----------------------------------------------------------
    // DEFINIÇÃO DA FORMA: CRUZ
    // -----------------------------------------------------------
    // Cria uma matriz para a forma Cruz (3x5) inicializada com 0.
    int cruz[Lcruz][Ccruz] = {0};
    int linhaOrigem_Cruz = 1; // Linha central para o braço horizontal.
    int colunaOrigem_Cruz = 2; // Coluna central para o braço vertical.

    // Lógica para preencher a forma Cruz com o valor 5.
    for (int i = 0; i < Lcruz; i++)
    {
        // Na linha 0, preenche apenas o centro para o topo do braço vertical.
        if (i == 0)
        {
            int linhaAtual = linhaOrigem_Cruz - 1; // Linha 0
            cruz[linhaAtual][colunaOrigem_Cruz] = 5;
        }

        // Na linha 1, preenche toda a largura para o braço horizontal.
        if (i == 1)
        {
            for (int j = 0; j < Ccruz; j++)
            {
                int colunaAtual = j;
                cruz[linhaOrigem_Cruz][colunaAtual] = 5;
            }
        }
        
        // Na linha 2, preenche apenas o centro para a base do braço vertical.
        if (i == 2)
        {
            int linhaAtual = linhaOrigem_Cruz + 1; // Linha 2
            cruz[linhaAtual][colunaOrigem_Cruz] = 5;
        }
    }


    // -----------------------------------------------------------
    // DEFINIÇÃO DA FORMA: OCTAEDRO (Losango Horizontal)
    // -----------------------------------------------------------
    // Cria uma matriz para a forma Octaedro (3x5) inicializada com 0.
    int octaedro[Loctaedro][Coctaedro] = {0};
    int colunaOrigem_Octaedro = 2; // Coluna central.

    // Lógica para preencher a forma Octaedro/Losango com o valor 5.
    for (int i = 0; i < Loctaedro; i++)
    {
        // Preenche a coluna central em todas as linhas para formar o tronco vertical.
        octaedro[i][colunaOrigem_Octaedro] = 5;

        // Na linha 1, preenche as colunas adjacentes (1, 2, 3) para formar a largura máxima.
        if (i == 1)
        {
            for (int j = 0; j < Coctaedro; j++)
            {
                if (j > 0 && j < 4) // Colunas 1, 2, 3
                {
                    int colunaAtual = j;
                    octaedro[i][colunaAtual] = 5;
                }
            }
        }
    }


    // -----------------------------------------------------------
    // APLICAÇÃO DO CONE NO TABULEIRO E VERIFICAÇÃO DE COLISÃO
    // -----------------------------------------------------------
    int linhaInicial_Cone = 0;
    int colunaInicial_Cone = 2;

    // Itera sobre a matriz do Cone para aplicá-la ao tabuleiro (com offset).
    for (int i = 0; i < Lcone; i++)
    {
        for (int j = 0; j < Ccone; j++)
        {
            // Se a posição do Cone não for vazia (valor 5):
            if (cone[i][j] != 0) 
            {
                // Verifica se há um navio (3) na posição de destino.
                if (tabuleiro[linhaInicial_Cone + i][colunaInicial_Cone + j] == 3)
                {
                    // Colisão: Altera a posição do navio para 1 (atingido).
                    tabuleiro[linhaInicial_Cone + i][colunaInicial_Cone + j] = 1;
                }
                // Se a posição de destino está vazia (0).
                else if (tabuleiro[linhaInicial_Cone + i][colunaInicial_Cone + j] == 0)
                {
                    // Sem colisão: Preenche com o valor da forma (5).
                    tabuleiro[linhaInicial_Cone + i][colunaInicial_Cone + j] = cone[i][j];
                }
                // NOTA: Se já houver uma forma (5), o valor não muda (5 permanece 5).
            }
        }
    }


    // -----------------------------------------------------------
    // APLICAÇÃO DA CRUZ NO TABULEIRO E VERIFICAÇÃO DE COLISÃO
    // -----------------------------------------------------------
    int linhaInicial_Cruz = 4;
    int colunaInicial_Cruz= 5;

    // Itera sobre a matriz da Cruz para aplicá-la ao tabuleiro (com offset).
    for (int i = 0; i < Lcruz; i++)
    {
        for (int j = 0; j < Ccruz; j++)
        {
            // Se a posição da Cruz não for vazia (valor 5):
            if (cruz[i][j] != 0)
            {
                // Verifica se há um navio (3) na posição de destino.
                if (tabuleiro[linhaInicial_Cruz + i][colunaInicial_Cruz + j] == 3)
                {
                    // Colisão: Altera a posição do navio para 1 (atingido).
                    tabuleiro[linhaInicial_Cruz + i][colunaInicial_Cruz + j] = 1;
                }
                // Se a posição de destino está vazia (0).
                else if (tabuleiro[linhaInicial_Cruz + i][colunaInicial_Cruz + j] == 0)
                {
                    // Sem colisão: Preenche com o valor da forma (5).
                    tabuleiro[linhaInicial_Cruz + i][colunaInicial_Cruz + j] = cruz[i][j];
                }
            }
        }
    }


    // -----------------------------------------------------------
    // APLICAÇÃO DO OCTAEDRO NO TABULEIRO E VERIFICAÇÃO DE COLISÃO
    // -----------------------------------------------------------
    int linhaInicial_Octaedro = 5;
    int colunaInicial_Octaedro = 0; // Posição de origem correta.

    // Itera sobre a matriz do Octaedro para aplicá-la ao tabuleiro (com offset).
    for (int i = 0; i < Loctaedro; i++)
    {
        for (int j = 0; j < Coctaedro; j++)
        {
            // Se a posição do Octaedro não for vazia (valor 5):
            if (octaedro[i][j] != 0)
            {
                // Verifica se há um navio (3) na posição de destino.
                if (tabuleiro[linhaInicial_Octaedro + i][colunaInicial_Octaedro + j] == 3)
                {
                    // Colisão: Altera a posição do navio para 1 (atingido).
                    tabuleiro[linhaInicial_Octaedro + i][colunaInicial_Octaedro + j] = 1;
                }
                // Se a posição de destino está vazia (0).
                else if (tabuleiro[linhaInicial_Octaedro + i][colunaInicial_Octaedro + j] == 0)
                {
                    // Sem colisão: Preenche com o valor da forma (5).
                    tabuleiro[linhaInicial_Octaedro + i][colunaInicial_Octaedro + j] = octaedro[i][j];
                }
            }
        }
    }


    // -----------------------------------------------------------
    // EXIBIÇÃO FINAL DO TABULEIRO
    // -----------------------------------------------------------
    printf("..Tabuleiro..\n");

    // Imprime o cabeçalho das colunas (0 a 9).
    printf("  ");
    for (int j = 0; j < colunas; j++)
    {
        printf(" %d", j);
    }
    printf("\n");

    // Imprime cada linha do tabuleiro.
    for (int i = 0; i < linhas; i++)
    {
        // Imprime o cabeçalho da linha (0 a 9).
        printf("%d ", i);

        // Imprime o valor de cada célula na linha.
        for (int j = 0; j < colunas; j++)
        {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}