#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5 // Tamanho das matrizes de habilidade

void exibirTabuleiro(int tabuleiro[][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 0) {
                printf("0 "); // Água
            } else if (tabuleiro[i][j] == 3) {
                printf("3 "); // Navio
            } else if (tabuleiro[i][j] == 5) {
                printf("5 "); // Área afetada
            } else {
                printf("? "); // Erro ou valor inesperado
            }
        }
        printf("\n");
    }
}

void aplicarHabilidade(int tabuleiro[][TAMANHO_TABULEIRO], int habilidade[][TAMANHO_HABILIDADE], int linhaOrigem, int colunaOrigem) {
    int linhaHabilidade, colunaHabilidade, linhaTabuleiro, colunaTabuleiro;

    for (linhaHabilidade = 0; linhaHabilidade < TAMANHO_HABILIDADE; linhaHabilidade++) {
        for (colunaHabilidade = 0; colunaHabilidade < TAMANHO_HABILIDADE; colunaHabilidade++) {
            if (habilidade[linhaHabilidade][colunaHabilidade] == 1) { // Posição afetada
                linhaTabuleiro = linhaOrigem - TAMANHO_HABILIDADE / 2 + linhaHabilidade;
                colunaTabuleiro = colunaOrigem - TAMANHO_HABILIDADE / 2 + colunaHabilidade;

                if (linhaTabuleiro >= 0 && linhaTabuleiro < TAMANHO_TABULEIRO &&
                    colunaTabuleiro >= 0 && colunaTabuleiro < TAMANHO_TABULEIRO) {
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5; // Marca a área afetada
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0}; // Inicializa o tabuleiro com água

    // Habilidades (Cone, Cruz, Octaedro)
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };

    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
    };

    // Navios (Exemplo)
    tabuleiro[0][9] = 3;
    tabuleiro[1][9] = 3;
    tabuleiro[2][9] = 3;
    tabuleiro[0][5] = 3;
    tabuleiro[0][6] = 3;
    tabuleiro[0][7] = 3;
    tabuleiro[7][1] = 3;
    tabuleiro[8][2] = 3;
    tabuleiro[9][3] = 3;

    // Aplica habilidades
    aplicarHabilidade(tabuleiro, cone, 2, 2);
    aplicarHabilidade(tabuleiro, cruz, 6, 7);
    aplicarHabilidade(tabuleiro, octaedro, 5, 3);

    // Exibe o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}     