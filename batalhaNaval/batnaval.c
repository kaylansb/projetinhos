#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define dim 10
#define maxTiposNavios 3

typedef struct {
    int qtdNavios;
    int tamNavio;
}
infoNavios;

void escolherPosDosNavios(char tabuleiro[][dim]);
int scanCoord(char *linha, char *coluna);
int temNavioEmCoord(char tabuleiro[][dim], char linha, char coluna, int navioTam);
int validarCoord(char coords[]);
void converterCoords(char coords[]);
void colocarNavioNoTabuleiro(char tabuleiro[][dim], char linhaVertice, char colunaVertice, int navioTam);
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
        scanCoord(&linha, &coluna);
        printf("%d e %d\n", linha, coluna);
    
    //}
    
    return 0;
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

void escolherPosDosNavios(char tabuleiro[][dim]){
    infoNavios navio[maxTiposNavios] = {
    {1, 4},
    {1, 3},
    {3, 1}, };

    char linhaVertice, colunaVertice;
    int i, j, posicaoInvalida;

    for (i = 0; i < maxTiposNavios; i++){
        for (j = 0; j < navio[i].qtdNavios; j++){
            printf("Digite a Coordenada Do Vértice Superior Esquerdo Do Navio De Tamanho %d: ", navio[i].tamNavio);
            
            posicaoInvalida = TRUE;
            while (posicaoInvalida){
                if (!scanCoord(&linhaVertice, &colunaVertice) && 
                    !temNavioEmCoord(tabuleiro, linhaVertice, colunaVertice, navio[i].tamNavio)) //TIRAR ESSE NOT
                    printf("Posição Inválida! Digite Novamente: ");
                else 
                    posicaoInvalida = FALSE;
            }
            colocarNavioNoTabuleiro(tabuleiro, linhaVertice, colunaVertice, navio[i].tamNavio);
            mostrarTabuleiro(tabuleiro);
        }
    }

}

int scanCoord(char *linha, char *coluna){
    char ch, coords[3]; //dar valores fixos para coords para n ficar com lixo
    int i = 0;

    while ((ch = getchar()) != '\n'){
        if (i < 3)
            coords[i] = ch;
        i++;
    }

    if (i > 3)
        return FALSE;

    if (!validarCoord(coords))
        return FALSE;

    converterCoords(coords);
    *coluna = coords[0];
    *linha = coords[1];


    return TRUE;
}

int validarCoord(char coords[]){
    if ((coords[0] >= 'A' && coords[0] <= 'J') || (coords[0] >= 'a' && coords[0] <= 'j')){
        
        if (coords[1] >= '1' && coords[1] <= '9'){    
            if ((coords[1] == '1' && coords[2] == '0') || (coords[2] == '\n'))
                return TRUE;
        }
    }
    
    return FALSE;
}

void converterCoords(char coords[]){
    if (coords[0] >= 'a' && coords[0] <= 'j')
        coords[0] -= 'a';
    else if (coords[0] >= 'A' && coords[0] <= 'J')
        coords[0] -= 'A';

    if (coords[2] == '0')
        coords[1] = 9;
    else
        coords[1] -= '1';
}

int temNavioEmCoord(char tabuleiro[][dim], char linha, char coluna, int navioTam){
    int i, j;

    for (i = linha; i < navioTam + linha; i++){
        for (j = coluna; j < navioTam + coluna; j++){
            if (tabuleiro[i][j] == 'N')
                return TRUE;
        }
    }

    return FALSE;
}

void colocarNavioNoTabuleiro(char tabuleiro[][dim], char linhaVertice, char colunaVertice, int navioTam){
    int i, j;
    
    for (i = linhaVertice; i < navioTam + linhaVertice; i++){
        for (j = colunaVertice; j < navioTam + colunaVertice; j++){
            tabuleiro[i][j] = 'N';
        }
    }
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

// void scanCoord(char *linha, char *coluna){
//     char ch, coords[3];
//     int i, ehValido = FALSE;

//     while (!ehValido){
//         for (i = 0; i < 3; i++)
//             coords[i] = getchar();
        
//         if (coords[2] != '\n')
//             limparBuffer();

//         if (validarEConverterCoord(coords))
//             ehValido = TRUE;
//         else
//             printf("Coordenada Inválida! Digite Novamente: ");
//     }
    
//     *coluna = coords[0];
//     *linha = coords[1];
// }
