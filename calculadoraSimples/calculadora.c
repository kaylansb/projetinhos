#include <stdio.h>

void exibirOpcoes();
void lerNums(int *a, int *b);

int main(){
    int opcao, numA, numB, resultado;
    char usarCalc = 's';

    while (usarCalc == 's' || usarCalc == 'S'){
        
        exibirOpcoes();
        scanf("%d", &opcao);
        getchar();
        
        switch (opcao){
            case 1: {
                lerNums(&numA, &numB);
                resultado = numA + numB;
                printf("Resultado: %d + %d = %d\n", numA, numB, resultado);
                break;
        
            }
            case 2: {
                lerNums(&numA, &numB);
                resultado = numA - numB;
                printf("Resultado: %d - %d = %d\n", numA, numB, resultado);
                break;
        
            }
            case 3: {
                lerNums(&numA, &numB);
                resultado = numA * numB;
                printf("Resultado: %d x %d = %d\n", numA, numB, resultado);
                break;
        
            }
            case 4: {
                lerNums(&numA, &numB);
                if (numB == 0)
                    printf("Erro: Divisão Por Zero Não é Permitida.\n");
                else {
                    resultado = numA / numB;
                    printf("Resultado: %d / %d = %d\n", numA, numB, resultado);
                }
                break;
        
            }
            case 5: {
                usarCalc = 'n';
                break;
        
            }
            
            default:{
                printf("Opção Inválida.\n");
                break;
            }

        }
        
        while (usarCalc != 'n'){
            printf("Deseja Realizar Outra Operação? (s/n): ");
            scanf("%c", &usarCalc);
            getchar();
            if (usarCalc == 's' || usarCalc == 'S' || usarCalc == 'n' || usarCalc == 'N')
                break;
            else
                printf("Resposta inválida. Por favor, digite 's' para sim ou 'n' para não.\n");
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

void lerNums(int *a, int *b){
    printf("Digite o Primeiro Número: ");
    scanf("%d", a);
    getchar();
    
    printf("Digite o Segundo Número: ");
    scanf("%d", b);
    getchar();

}
