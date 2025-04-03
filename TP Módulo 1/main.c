#include <stdio.h>

int main() {
    int escolha;
    char continuar;
    
    do {
        // Exibição de um menu onde o usuário pode escolher entre círculo, retângulo e triângulo ou sair:
        printf("\nEscolha uma figura geométrica:\n");
        printf("1. Círculo\n");
        printf("2. Retângulo\n");
        printf("3. Triângulo\n");
        printf("4. Sair\n");
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);

        if (escolha == 4) {
            break; // Sair do loop se a opção for 4
        }

        // Variáveis para armazenar dados das figuras:
        float raio, largura, altura, base;
        float area, perimetro;
        
        //Dependendo da figura escolhida, o programa solicita os dados necessários:
        switch (escolha) {
            case 1: // Círculo
                printf("Digite o raio do círculo: ");
                scanf("%f", &raio);
                area = 3.14 * raio * raio; // Cálculo da área
                perimetro = 2 * 3.14 * raio; // Cálculo do perímetro
                printf("Círculo - Raio: %.2f, Área: %.2f, Perímetro: %.2f\n", raio, area, perimetro);
                break;

            case 2: // Retângulo
                printf("Digite a largura do retângulo: ");
                scanf("%f", &largura);
                printf("Digite a altura do retângulo: ");
                scanf("%f", &altura);
                area = largura * altura; // Cálculo da área
                perimetro = 2 * (largura + altura); // Cálculo do perímetro
                printf("Retângulo - Largura: %.2f, Altura: %.2f, Área: %.2f, Perímetro: %.2f\n", largura, altura, area, perimetro);
                break;

            case 3: // Triângulo
                printf("Digite a base do triângulo: ");
                scanf("%f", &base);
                printf("Digite a altura do triângulo: ");
                scanf("%f", &altura);
                area = (base * altura) / 2; // Cálculo da área
                perimetro = base + 2 * (altura); // Perímetro aproximado considerando um triângulo isósceles
                printf("Triângulo - Base: %.2f, Altura: %.2f, Área: %.2f, Perímetro (aproximado): %.2f\n", base, altura, area, perimetro);
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }

        // Perguntar se o usuário deseja continuar
        printf("Deseja realizar outra operação? (S/N): ");
        scanf(" %c", &continuar);

    } while (continuar == 'S' || continuar == 's');

    return 0;
}