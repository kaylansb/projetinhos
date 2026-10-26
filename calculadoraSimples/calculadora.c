#include <stdio.h>
#define TRUE 1
#define FALSE 0

void exibirOpcoes();
void lerNums(float *a, float *b);
int scanNum(int *p);
int scanFloat(float *f);
int scanChar(char *ch);
void limparBuffer();

int main(){
    int opcao, cobaiaInt;
    char usarCalc = 's';
    float numA, numB, resultado;

    while (usarCalc == 's' || usarCalc == 'S'){
        
        exibirOpcoes();
        while (!scanNum(&opcao)){
            printf("Opção Inválida. Digite Uma Opção Válida.\n");
        }
        opcao -= '0';

        switch (opcao){
            case 1: {
                lerNums(&numA, &numB);
                resultado = numA + numB;
                cobaiaInt = resultado;
                if (cobaiaInt == resultado)
                    printf("Resultado: %.0f + %.0f = %.0f\n", numA, numB, resultado);
                else 
                    printf("Resultado: %.2f + %.2f = %.2f\n", numA, numB, resultado);
                break;
        
            }
            case 2: {
                lerNums(&numA, &numB);
                resultado = numA - numB;
                cobaiaInt = resultado;
                if (cobaiaInt == resultado)
                    printf("Resultado: %.0f - %.0f = %.0f\n", numA, numB, resultado);
                else
                    printf("Resultado: %.2f - %.2f = %.2f\n", numA, numB, resultado);
                break;
        
            }
            case 3: {
                lerNums(&numA, &numB);
                resultado = numA * numB;
                cobaiaInt = resultado;
                if (cobaiaInt == resultado)
                    printf("Resultado: %.0f x %.0f = %.0f\n", numA, numB, resultado);
                else
                    printf("Resultado: %.2f x %.2f = %.2f\n", numA, numB, resultado);
                break;
        
            }
            case 4: {
                lerNums(&numA, &numB);
                if (numB == 0.0)
                    printf("Erro: Divisão Por Zero Não é Permitida.\n");
                else {
                    resultado = numA / numB;
                    cobaiaInt = resultado;
                    if (cobaiaInt == resultado)
                        printf("Resultado: %.0f / %.0f = %.0f\n", numA, numB, resultado);
                    else
                        printf("Resultado: %.2f / %.2f = %.2f\n", numA, numB, resultado);
                }
                break;
        
            }
            case 5: {
                usarCalc = 'n';
                break;
        
            }

        }
        
        // menor sentido isso aq sendo que é só sair com opcao 5
        
        if (usarCalc == 's' || usarCalc == 'S'){
            printf("Deseja Realizar Outra Operação? (s/n): ");
            
            while (!scanChar(&usarCalc)){
                printf("Resposta inválida. Por favor, digite 's' para sim ou 'n' para não.\n");
            }
        }

    }

    printf("Obrigado Por Usar a Calculadora! Até a Próxima.\n");

    return 0;
}

void exibirOpcoes(){
    printf("========================\n");
    printf("Calculadora Simples\n");
    printf("========================\n");

    printf("Selecione Uma Operação:\n");
    
    printf("1. Adição\n");
    printf("2. Subtração\n");
    printf("3. Multiplicação\n");
    printf("4. Divisão\n");
    printf("5. Sair\n");

    printf("Opção: ");
}

void lerNums(float *a, float *b){
    printf("Digite o Primeiro Número: ");
    while (!scanFloat(a)){
        printf("Valor Inválido! Digite um Número.\n");
    }
    
    printf("Digite o Segundo Número: ");
    while (!scanFloat(b)){
        printf("Valor Inválido! Digite um Número.\n");
    }

}

int scanNum(int *p){
    *p = getchar();
    char finalInput = getchar();

    if (finalInput == '\n' && (*p >= '1' && *p <= '5'))
        return 1;
    
    else if (finalInput != '\n')
        limparBuffer();

    return 0;
}

int scanFloat(float *f){
    int leu = FALSE;

    if (scanf("%f", f))
        leu = TRUE;
    char finalInput = getchar();

    if (leu && finalInput == '\n')
        return 1;

    else if (finalInput != '\n')
        limparBuffer();

    return 0;
}

int scanChar(char *ch){
    *ch = getchar();
    char finalInput = getchar();

    if (finalInput == '\n' && (*ch == 's' || *ch == 'S' || *ch == 'n' || *ch == 'N'))
        return 1;

    else if (finalInput != '\n')
        limparBuffer();

    return 0;
}

void limparBuffer(){
    char lixo = getchar();

    while (lixo != '\n'){
        lixo = getchar();
    }
}