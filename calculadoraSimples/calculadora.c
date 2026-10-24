#include <stdio.h>
#define TRUE 1
#define FALSE 0

void exibirOpcoes();
void lerNums(float *a, float *b);
int scanNum(int *p);
int scanChar(char *ch);
void limparBuffer();

int main(){
    int opcao, ehValido;
    char usarCalc = 's';
    float numA, numB, resultado;

    while (usarCalc == 's' || usarCalc == 'S'){
        
        exibirOpcoes();
        if (!scanNum(&opcao)){
            ehValido = FALSE;
            while (!ehValido){
                printf("Opção Inválida. Digite Uma Opção Válida.\n");
                ehValido = scanNum(&opcao);
            }
        }
        opcao -= '0';

        switch (opcao){
            case 1: {
                lerNums(&numA, &numB);
                resultado = numA + numB;
                printf("Resultado: %.2f + %.2f = %.2f\n", numA, numB, resultado);
                break;
        
            }
            case 2: {
                lerNums(&numA, &numB);
                resultado = numA - numB;
                printf("Resultado: %.2f - %.2f = %.2f\n", numA, numB, resultado);
                break;
        
            }
            case 3: {
                lerNums(&numA, &numB);
                resultado = numA * numB;
                printf("Resultado: %.2f x %.2f = %.2f\n", numA, numB, resultado);
                break;
        
            }
            case 4: {
                lerNums(&numA, &numB);
                if (numB == 0.0)
                    printf("Erro: Divisão Por Zero Não é Permitida.\n");
                else {
                    resultado = numA / numB;
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
            
            if (!scanChar(&usarCalc)){
                ehValido = FALSE;
                while (!ehValido){
                    printf("Resposta inválida. Por favor, digite 's' para sim ou 'n' para não.\n");
                    ehValido = scanChar(&usarCalc);
                }
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
    scanf("%f", a);
    getchar();
    
    printf("Digite o Segundo Número: ");
    scanf("%f", b);
    getchar();

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
