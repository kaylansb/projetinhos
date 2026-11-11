#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define dim 10
#define maxTiposNavios 3
#define MEU_TABULEIRO 4
#define TABULEIRO_INIMIGO 5

typedef struct {
    int qtdNavios;
    int tamNavio;
}
infoNavios;

void mostrarTabuleiro(char tabuleiro[][dim], int tabuleiroPOV);
void escolherPosDosNavios(char tabuleiro[][dim]);
int scanCoord(char *linha, char *coluna);
int validarCoord(char coords[]);
void converterCoords(char coords[]);
int temNavioEmCoord(char tabuleiro[][dim], char linha, char coluna, int navioTam);
int coordExtrapolaTabuleiro(char linhaVertice, char colunaVertice, int navioTam);
void colocarNavioNoTabuleiro(char tabuleiro[][dim], char linhaVertice, char colunaVertice, int navioTam);
void atacarInimigo(char tabuleiro[][dim], char linha, char coluna);
int houveVencedor(char tabuleiro[][dim], int jogador);

int main(){
    char tabuleiro1[dim][dim] = {
 //   a   b   c   d   e   f   g   h   i   j 
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 1
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 2
    {' ',' ','N',' ',' ',' ','N',' ',' ',' '},    // 3
    {' ',' ','N',' ',' ',' ',' ',' ',' ',' '},    // 4
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 5
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 6
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 7
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 8
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 9
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}, }; // 10


    char tabuleiro2[dim][dim] = {
 //   a   b   c   d   e   f   g   h   i   j 
    {' ','N',' ',' ',' ',' ',' ',' ',' ',' '},    // 1
    {' ','N',' ',' ',' ',' ',' ',' ',' ',' '},    // 2
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 3
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 4
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 5
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 6
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 7
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 8
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 9
    {' ',' ','N',' ',' ',' ',' ',' ',' ',' '}, }; // 10

    int jogoTerminou = FALSE, vencedor;
    char linha, coluna;

    // printf("Agora Você Deve Escolher Onde Posicionar Seus Navios!\n");
    // printf("Lembre-se Que TODOS Os Navios São Quadrados!\n");

    // mostrarTabuleiro(tabuleiro1, MEU_TABULEIRO);
    // escolherPosDosNavios(tabuleiro1);

    // mostrarTabuleiro(tabuleiro2, MEU_TABULEIRO);
    // escolherPosDosNavios(tabuleiro2);

    mostrarTabuleiro(tabuleiro1, MEU_TABULEIRO);
    mostrarTabuleiro(tabuleiro2, MEU_TABULEIRO);

    while (!jogoTerminou){
        printf("SUA VEZ DE JOGAR JOGADOR 1!\n");
        mostrarTabuleiro(tabuleiro1, MEU_TABULEIRO);
        mostrarTabuleiro(tabuleiro2, TABULEIRO_INIMIGO);
        printf("Digite Uma Coordenada Para Atingir Um Navio Inimigo: ");
        
        while (!scanCoord(&linha, &coluna)){
            printf("Coordenada Inválida! Digite Novamente: ");
        }
        
        atacarInimigo(tabuleiro2, linha, coluna);
        mostrarTabuleiro(tabuleiro2, TABULEIRO_INIMIGO);
    
        if (vencedor = houveVencedor(tabuleiro2, 1))
            jogoTerminou = TRUE;
        else {
            printf("\n\nAGORA É A SUA VEZ JOGADOR 2!\n");
            mostrarTabuleiro(tabuleiro2, MEU_TABULEIRO);
            mostrarTabuleiro(tabuleiro1, TABULEIRO_INIMIGO);
            printf("Digite Uma Coordenada Para Atingir Um Navio Inimigo: ");
            
            while (!scanCoord(&linha, &coluna)){
                printf("Coordenada Inválida! Digite Novamente: ");
            }

            atacarInimigo(tabuleiro1, linha, coluna);
            mostrarTabuleiro(tabuleiro1, TABULEIRO_INIMIGO);
        
            if (vencedor = houveVencedor(tabuleiro1, 2))
                jogoTerminou = TRUE;
        }
    }
    
    switch (vencedor){
        case 1: printf("Parabéns Jogador 1! Você Venceu!\n");
            break;
        case 2: printf("Parabéns Jogador 2! Você Venceu!\n");
            break;
    }
    printf("Obrigado Por Jogarem! :D\n");

    return 0;
}

void mostrarTabuleiro(char tabuleiro[][dim], int tabuleiroPOV){
    int i, j;

    printf("---------------------\n");
    printf("A B C D E F G H I J\n");
    printf("---------------------\n");

    for (i = 0; i < dim; i++){
        for (j = 0; j < dim; j++){
            if (tabuleiroPOV == MEU_TABULEIRO)
                printf("%c ", tabuleiro[i][j]);

            else if (tabuleiroPOV == TABULEIRO_INIMIGO && tabuleiro[i][j] != 'N')
                printf("%c ", tabuleiro[i][j]);

            else
                printf("  ");
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
                if (!scanCoord(&linhaVertice, &colunaVertice) || 
                temNavioEmCoord(tabuleiro, linhaVertice, colunaVertice, navio[i].tamNavio) || 
                coordExtrapolaTabuleiro(linhaVertice, colunaVertice, navio[i].tamNavio))
                    printf("Posição Inválida! Digite Novamente: ");
                else 
                    posicaoInvalida = FALSE;
            }
            colocarNavioNoTabuleiro(tabuleiro, linhaVertice, colunaVertice, navio[i].tamNavio);
            mostrarTabuleiro(tabuleiro, MEU_TABULEIRO);
        }
    }

}

int scanCoord(char *linha, char *coluna){
    char ch, coords[3] = "00\n";
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

int coordExtrapolaTabuleiro(char linhaVertice, char colunaVertice, int navioTam){
    if (navioTam == 1)
        return FALSE;
    
    int limiteHorizontal = 'j' - 'a';
    int limiteVertiical = 10;

    if (colunaVertice + navioTam - 1 > limiteHorizontal)
        return TRUE;
    else if (linhaVertice + navioTam > limiteVertiical)
        return TRUE;
    else
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

void atacarInimigo(char tabuleiro[][dim], char linha, char coluna){
    if (tabuleiro[linha][coluna] == 'N' || tabuleiro[linha][coluna] == 'O')
        tabuleiro[linha][coluna] = 'O';

    else if (tabuleiro[linha][coluna] == ' ')
        tabuleiro[linha][coluna] = 'X';
}

int houveVencedor(char tabuleiro[][dim], int jogador){
    int i, j;

    for (i = 0; i < dim; i++){
        for (j = 0; j < dim; j++){
            if (tabuleiro[i][j] == 'N')
                return FALSE;
        }
    }

    if (jogador == 1)
        return 1;
    else
        return 2;
}

    // char tabuleiro1[dim][dim] = {
    // //    a   b   c   d   e   f   g   h   i   j 
    //     {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 1
    //     {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 2
    //     {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 3
    //     {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 4
    //     {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 5
    //     {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 6
    //     {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 7
    //     {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 8
    //     {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 9
    //     {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}, }; // 10

    // char tabuleiro2[dim][dim] = {
    // //    a   b   c   d   e   f   g   h   i   j 
    //     {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 1
    //     {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 2
    //     {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 3
    //     {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 4
    //     {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 5
    //     {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 6
    //     {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 7
    //     {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 8
    //     {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},    // 9
    //     {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}, }; // 10