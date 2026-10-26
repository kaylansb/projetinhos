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
int validarCoordenadas(char linha, char coluna);

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

        scanf("%c", &linha);
        if (linha != '\n')
            scanf("%c", &coluna);



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

int validarCoordenadas(char linha, char coluna){
    if (coluna >= '1' && coluna <= '3'){
        if (linha >= 'a' && linha <= 'c'){
            linha -= 'a';
            return 1;
        }
        else if (linha >= 'A' && linha <= 'C'){
            linha -= 'A';
            return 1;
        }
    }

    return 0;

}