#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define dim 3

void mostrarJogo(char matriz[][dim]);
int verificarSeJogoAcabou(char matriz[][dim], char ch);
// void scanCoords(char *linha, char *coluna);
// int validarCoordenadas(char *linha, char *coluna);

int main(){
    int jogoTerminou = FALSE;
    char linha, coluna;
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
        scanf("%c%c", &linha, &coluna);
        getchar();
        linha -= 'a';
        coluna -= '0';
        matriz[linha][coluna - 1] = 'X';

        if (verificarSeJogoAcabou(matriz, 'X'))
            jogoTerminou = TRUE;
        else {
            mostrarJogo(matriz);
            printf("JOGADOR 2:\n");
            printf("Digite As Coordenadas Que Desejas Jogar: ");
            scanf("%c%c", &linha, &coluna);
            getchar();
            linha -= 'a';
            coluna -= '0';
            matriz[linha][coluna - 1] = 'O';
            
            if (verificarSeJogoAcabou(matriz, 'O'))
                jogoTerminou = TRUE;
        }
    }
    mostrarJogo(matriz);
    printf("O Jogo Terminou! Obrigado Por Jogar!\n");

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

int verificarSeJogoAcabou(char matriz[][dim], char ch){
    int i, j;
    int sequenciaA = 0, sequenciaB = 0, espacosVazios = 0;

    for (i = 0, j = 2; i < 3; i++, j--){
        if (matriz[i][i] == ch)
            sequenciaA++;
        if (matriz[i][j] == ch)
            sequenciaB++;
    }

    if (sequenciaA == 3 || sequenciaB == 3)
        return 1;
    else {
        
        for (i = 0; i < 3; i++){
            sequenciaA = 0;
            sequenciaB = 0;
            for (j = 0; j < 3; j++){
                if (matriz[i][j] == ch)
                    sequenciaA++;

                if (matriz[j][i] == ch)
                    sequenciaB++;
                else if (matriz[i][j] == ' ')
                    espacosVazios++;
            }
        }

        if (sequenciaA == 3 || sequenciaB == 3 || espacosVazios == 0)
            return 1;
        else
            return 0;
    }
    
}

// int ehCoordValida(char matriz[][dim], char linha, char coluna){
    
//     if (matriz[linha][coluna] == ' ')
//         return 1;
//     else
//         return 0;
// }

// void scanCoords(char *linha, char *coluna){
//     int i;
//     char coords[2], ch;

//     i = 0;
//     while ((ch = getchar()) != '\n'){
//         if (i < 2){
//             coords[i] = ch;
//             i++;
//         }
//     }
//     *linha = coords[0];
//     *coluna = coords[1];

// }

// int validarCoordenadas(char *linha, char *coluna){
//     if (coluna >= '1' && coluna <= '3'){
//         coluna -= '0';
//         if (linha >= 'a' && linha <= 'c'){
//             linha -= 'a';
//             return TRUE;
//         }
//         else if (linha >= 'A' && linha <= 'C'){
//             linha -= 'A';
//             return TRUE;
//         }
//     }

//     return FALSE;

// }


    // mostrarJogo(matriz);
        
    // scanf("%c %c", &linha, &coluna);
    // verifica Input;
    // bota X ou O na Matriz;
    // if (verificaSeAcabou ou se ainda tem espaco)
    //     cabo;
    // else {
    //     scanf("%c %c", &linha, &coluna);
    //     verifica Input;
    //     bota X ou O na Matriz;
    //     verifica se acabou;
    //     if (verificaSeAcabou ou se ainda tem espaco)
    //         cabo;
    // }
