#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define dim 3

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

void mostrarJogo(char matriz[][dim]);
void scanCoords(char *linha, char *coluna);
int validarCoordenadas(char *linha, char *coluna);

int main(){
    int jogoTerminou = FALSE, ehValido = FALSE;
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

        while (!ehValido){
            scanCoords(&linha, &coluna);
            ehValido = validarCoordenadas(&linha, &coluna);
            if (!ehValido)
                printf("Digite uma Coordenada Válida.\n");
        }
        
    }
        

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

int validarCoordenadas(char *linha, char *coluna){
    if (coluna >= '1' && coluna <= '3'){
        coluna -= '0';
        if (linha >= 'a' && linha <= 'c'){
            linha -= 'a';
            return TRUE;
        }
        else if (linha >= 'A' && linha <= 'C'){
            linha -= 'A';
            return TRUE;
        }
    }

    return FALSE;

}