#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define dim 3
#define X_VENCEDOR 'X'
#define O_VENCEDOR 'O'
#define EMPATE '='

void mostrarJogo(char matriz[][dim]);
void scanCoords(char *linha, char *coluna);
int ehCoordValida(char matriz[][dim], char *linha, char *coluna);
int validarDigitosDasCoords(char *linha, char *coluna);
char verificarSeJogoAcabou(char matriz[][dim], char ch);
char procurarResultadoDiagonais(char matriz[][dim], char ch);
char procurarResultadoVerticalHorizontal(char matriz[][dim], char ch);

int main(){
    int jogoTerminou = FALSE, ehValido;
    char linha, coluna, resultado;
    char matriz[dim][dim] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}, };

    printf("Jogador 1: X\n");
    printf("Jogador 2: O\n");
    while (!jogoTerminou){
        mostrarJogo(matriz);
        printf("JOGADOR 1:\n");
        printf("Digite As Coordenadas Que Desejas Jogar: ");

        ehValido = FALSE;
        while (!ehValido){
            scanCoords(&linha, &coluna);
            ehValido = ehCoordValida(matriz, &linha, &coluna);
            if (!ehValido)
                printf("Coordenada Inválida! Digite Novamente.\n");
        }
        matriz[linha][coluna] = 'X';

        resultado = verificarSeJogoAcabou(matriz, 'X');
        if (resultado == X_VENCEDOR || resultado == EMPATE)
            jogoTerminou = TRUE;
        else {
            mostrarJogo(matriz);
            printf("JOGADOR 2:\n");
            printf("Digite As Coordenadas Que Desejas Jogar: ");
            
            ehValido = FALSE;
            while (!ehValido){
                scanCoords(&linha, &coluna);
                ehValido = ehCoordValida(matriz, &linha, &coluna);
                if (!ehValido)
                    printf("Coordenada Inválida! Digite Novamente.\n");
            }
            matriz[linha][coluna] = 'O';
            
            resultado = verificarSeJogoAcabou(matriz, 'O');
            if (resultado == O_VENCEDOR || resultado == EMPATE)
                jogoTerminou = TRUE;
        }
    }

    mostrarJogo(matriz);
    switch (resultado){
        case X_VENCEDOR: printf("O Vencedor Foi o Jogador 1 de X!\n");
            break;
        case O_VENCEDOR: printf("O Vencedor Foi o Jogador 2 de O!\n");
            break;
        case EMPATE: printf("O Jogo Terminou Em Empate.\n");
            break;
    } 
    printf("Obrigado Por Jogar!\n");

    return 0;

}

void mostrarJogo(char matriz[][dim]){
    int i, j;

    printf("\n");
    printf("   1  "); printf(" 2  "); printf(" 3\n");

    for (i = 0; i < dim; i++){
        printf("%c  ", i+'A');
        for (j = 0; j < dim - 1; j++){
            printf("%c | ", matriz[i][j]);
        }
        printf("%c\n", matriz[i][j]);
        if (i != 2)
            printf("  -----------\n");
    }
    printf("\n");
}

void scanCoords(char *linha, char *coluna){
    int i;
    char coords[2], ch;

    i = 0;
    while ((ch = getchar()) != '\n'){
        if (i < 2){
            coords[i] = ch;
            i++;
        }
    }
    *linha = coords[0];
    *coluna = coords[1];

}

int ehCoordValida(char matriz[][dim], char *linha, char *coluna){
    
    if (validarDigitosDasCoords(linha, coluna) && matriz[*linha][*coluna] == ' ')
        return 1;
    else
        return 0;

}

int validarDigitosDasCoords(char *linha, char *coluna){
    if (*coluna >= '1' && *coluna <= '3'){
        *coluna -= ('0' + 1);
        if (*linha >= 'a' && *linha <= 'c'){
            *linha -= 'a';
            return TRUE;
        }
        else if (*linha >= 'A' && *linha <= 'C'){
            *linha -= 'A';
            return TRUE;
        }
    }

    return FALSE;
}

char verificarSeJogoAcabou(char matriz[][dim], char ch){
    
    if (procurarResultadoDiagonais(matriz, ch))
        return ch;
    else
        return procurarResultadoVerticalHorizontal(matriz, ch);
    
}

char procurarResultadoDiagonais(char matriz[][dim], char ch){
    int i, j;
    int diagonalPrincipal = 0, diagonalSecundaria = 0;
    
    for (i = 0, j = 2; i < 3; i++, j--){
        if (matriz[i][i] == ch)
            diagonalPrincipal++;
        if (matriz[i][j] == ch)
            diagonalSecundaria++;
    }

    if (diagonalPrincipal == 3 || diagonalSecundaria == 3)
        return ch;
    else
        return '\0';

}

char procurarResultadoVerticalHorizontal(char matriz[][dim], char ch){
    int i, j;
    int sequenciaVertical = 0, sequenciaHorizontal = 0, espacosVazios = 0;
    
    for (i = 0; i < 3; i++){
        sequenciaVertical = 0;
        sequenciaHorizontal = 0;
        for (j = 0; j < 3; j++){
            if (matriz[i][j] == ch)
                sequenciaHorizontal++;
            if (matriz[j][i] == ch)
                sequenciaVertical++;
            else if (matriz[j][i] == ' ')
                espacosVazios++;
            
        }
        
        if (sequenciaVertical == 3 || sequenciaHorizontal == 3)
            return ch;
    }

    if (espacosVazios == 0)
        return EMPATE;
    else
        return '\0';

}