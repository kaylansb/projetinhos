#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define dim 10
#define maxTiposNavios 3

typedef struct {
    int qtd;
    int tam;
}
infoNavios;

void escolherPosDosNavios(char tabuleiro[][dim]);
void scanCoord(char *linha, char *coluna, int navioTam);
int validarEConverterCoord(char coords[]);
void colocarNavioNoTabuleiro(char tabuleiro[][dim], char linhaSup, char colunaSup, int navioTam);
void mostrarTabuleiro(char tabuleiro[][dim]);

int main(){
    char tabuleiro1[dim][dim] = {
    //    a   b   c   d   e   f   g   h   i   j 
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 1
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 2
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 3
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 4
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 5
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 6
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 7
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 8
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 9
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}, }; // 10

    char tabuleiro2[dim][dim] = {
    //    a   b   c   d   e   f   g   h   i   j 
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 1
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 2
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 3
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 4
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 5
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 6
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 7
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 8
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 9
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}, }; // 10

    int jogoTerminou = FALSE;
    char linha, coluna;

    printf("Agora Você Deve Escolher Onde Posicionar Seus Navios!\n");
    printf("Lembre-se Que TODOS Os Navios São Quadrados!\n");

    mostrarTabuleiro(tabuleiro1);
    escolherPosDosNavios(tabuleiro1);

    mostrarTabuleiro(tabuleiro2);
    escolherPosDosNavios(tabuleiro2);

    //while (!jogoTerminou){
        mostrarTabuleiro(tabuleiro2);
        printf("Digite Uma Coordenada Para Atingir Um Navio Inimigo: ");
        scanCoord(&linha, &coluna, 0);
        printf("%d e %d\n", linha, coluna);
    
    //}
    
    return 0;
}

void escolherPosDosNavios(char tabuleiro[][dim]){
    infoNavios navio[maxTiposNavios] = {
    {1, 4},
    {1, 3},
    {3, 1}, };

    char linhaSup, colunaSup;
    int i, j;

    for (i = 0; i < maxTiposNavios; i++){
        for (j = 0; j < navio[i].qtd; j++){
            printf("Digite a Coordenada Do Vértice Superior Esquerdo Do Navio De Tamanho %d: ", navio[i].tam);
            scanCoord(&linhaSup, &colunaSup, navio[i].tam);
            printf("%d e %d\n", linhaSup, colunaSup);
            colocarNavioNoTabuleiro(tabuleiro, linhaSup, colunaSup, navio[i].tam);
            mostrarTabuleiro(tabuleiro);
        }
    }

}

void scanCoord(char *linha, char *coluna, int navioTam){
    char ch, coords[3] = {'1', 'a', 'a'};
    int i, ehValido = FALSE;

    while (!ehValido){
        i = 0;
        while ((ch = getchar()) != '\n'){
            if (i < 3){
                coords[i] = ch;
            }
            i++;
        }
        if (coords[2] == '0' && coords[1] != '1')
            ;
        else if (i <= 3)
            ehValido = validarEConverterCoord(coords);

        if (!ehValido)
            printf("Coordenada Inválida! Digite Novamente: ");
    }

    *linha = coords[0];
    *coluna = coords[1];
}

int validarEConverterCoord(char coords[]){
    if (coords[1] >= '1' && coords[1] <= '9'){
        coords[1] -= '1';
        
        if ( coords[2] == '0' && coords[1] == 0)
            coords[1] = 10;

        if (coords[0] >= 'a' && coords[0] <= 'j'){
            coords[0] -= 'a';    
            return TRUE;
        }
        else if (coords[0] >= 'A' && coords[0] <= 'J'){
            coords[0] -= 'A';
            return TRUE;
        }
    }
    
    return FALSE;
    
}

void colocarNavioNoTabuleiro(char tabuleiro[][dim], char linhaSup, char colunaSup, int navioTam){
    int i, j;
    // colocar linhaSup + 1 ou somar 1 antes para ficar de acordo com o indice
    for (i = linhaSup; i < navioTam + linhaSup; i++){
        for (j = colunaSup; j < navioTam + colunaSup; j++){
            // printf("%d e %d\n", i, j);
            tabuleiro[i][j] = 'N';
        }
    }
}

void mostrarTabuleiro(char tabuleiro[][dim]){
    int i, j;

    printf("---------------------\n");
    printf("A B C D E F G H I J\n");
    printf("---------------------\n");

    for (i = 0; i < dim; i++){
        for (j = 0; j < dim; j++){
            printf("%c ", tabuleiro[i][j]);
        }
        printf("| %d\n", i+1);
    }
    printf("---------------------\n");

}




//     char tabuleiro1[dim][dim] = {
//  //   a   b   c   d   e   f   g   h   i   j 
//     {'N','N','N','N',' ',' ',' ',' ',' ',' '},    // 1
//     {'N','N','N','N',' ',' ',' ',' ',' ',' '},    // 2
//     {'N','N','N','N',' ',' ','N',' ',' ',' '},    // 3
//     {'N','N','N','N',' ',' ',' ',' ',' ',' '},    // 4
//     {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 5
//     {' ',' ',' ',' ',' ',' ',' ','N','N','N'},    // 6
//     {' ',' ',' ',' ','N',' ',' ','N','N','N'},    // 7
//     {' ',' ',' ',' ',' ','N',' ','N','N','N'},    // 8
//     {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 9
//     {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}, }; // 10
