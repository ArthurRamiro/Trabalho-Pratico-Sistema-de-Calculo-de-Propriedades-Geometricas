#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Módulo 3 TP - Arthur Ramiro

// Estrutura para armazenar dados de uma figura geométrica
typedef struct {
    char nome[50];  // Nome pode ter até 50 caracteres
    char tipo[20];  // Tipo da figura (Círculo, Retângulo, Triângulo)
    double dimensao1;  // Raio (círculo), largura (retângulo), base (triângulo)
    double dimensao2;  // Altura (triângulo ou retângulo)
    double area;
    double perimetro;
} Figura;

// Funções para cálculo de áreas e perímetros
double calcular_area_circulo(double raio) {
    return 3.14 * raio * raio;
}

double calcular_perimetro_circulo(double raio) {
    return 2 * 3.14 * raio;
}

double calcular_area_retangulo(double largura, double altura) {
    return largura * altura;
}

double calcular_perimetro_retangulo(double largura, double altura) {
    return 2 * (largura + altura);
}

double calcular_area_triangulo(double base, double altura) {
    return (base * altura) / 2;
}

double calcular_perimetro_triangulo(double base, double altura) {
    double hipotenusa = sqrt(base * base + altura * altura);
    return base + altura + hipotenusa;
}

// Função recursiva para calcular o fatorial de um número
long long fatorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * fatorial(n - 1);
    }
}

// Função para calcular o perímetro aproximado de uma figura irregular
double calcular_perimetro_irregular(int lados, double comprimento_lado) {
    long long fator = fatorial(lados);  // Usando o fatorial de n lados para calcular um valor aproximado
    double perimetro_aproximado = lados * comprimento_lado / fator;
    return perimetro_aproximado;
}

// Função para exibir o menu
void exibir_menu() {
    printf("\nEscolha a figura geométrica:\n");
    printf("1. Círculo\n");
    printf("2. Retângulo\n");
    printf("3. Triângulo\n");
    printf("4. Figura Irregular\n");
    printf("0. Sair\n");
}

// Função para exibir as informações de todas as figuras
void exibir_tabela(Figura* figuras, int count) {
    printf("\n----------------------------------------------------------------------------------------------------------\n");
    printf("| %-20s | %-15s | %-12s | %-12s | %-7s | %-9s | %-9s |\n", "Nome", "Tipo", "Dimensão 1", "Dimensão 2", "Área", "Perímetro", "Figura");
    printf("----------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("| %-20s | %-15s | %-12.2lf | %-12.2lf | %-7.2lf | %-9.2lf | %-9d |\n", 
            figuras[i].nome, figuras[i].tipo, figuras[i].dimensao1, figuras[i].dimensao2, figuras[i].area, figuras[i].perimetro, i + 1);
    }
    printf("----------------------------------------------------------------------------------------------------------\n");
}

// Função para trocar as dimensões de duas figuras usando ponteiros
void trocar_dimensoes(Figura* fig1, Figura* fig2) {
    double temp_dimensao1 = fig1->dimensao1;
    double temp_dimensao2 = fig1->dimensao2;

    fig1->dimensao1 = fig2->dimensao1;
    fig1->dimensao2 = fig2->dimensao2;

    fig2->dimensao1 = temp_dimensao1;
    fig2->dimensao2 = temp_dimensao2;
}

// Função para liberar a memória alocada dinamicamente
void liberar_memoria(Figura* figuras) {
    free(figuras);
}

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    Figura* figuras = malloc(sizeof(Figura) * 10);  // Alocação dinâmica para armazenar até 10 figuras
    if (figuras == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    int count = 0;  // Contador de figuras
    int opcao, operacao;

    do {
        exibir_menu();
        printf("Digite sua opção: ");
        scanf("%d", &opcao);

        if (opcao == 0) {
            printf("Saindo do programa...\n");
            break;
        }

        if (count >= 10) {
            printf("Limite de figuras atingido.\n");
            break;
        }

        Figura nova_figura;
        printf("Digite o nome da figura: ");
        scanf(" %[^\n]%*c", nova_figura.nome);  // Permite que o usuário digite o nome da figura com espaços

        switch(opcao) {
            case 1:  // Círculo
                printf("Digite o raio do círculo: ");
                scanf("%lf", &nova_figura.dimensao1);
                printf("\nEscolha a operação:\n");
                printf("1. Cálculo da área\n");
                printf("2. Cálculo do perímetro\n");
                printf("Digite sua opção: ");
                scanf("%d", &operacao);

                if (operacao == 1) {
                    nova_figura.area = calcular_area_circulo(nova_figura.dimensao1);
                    nova_figura.perimetro = calcular_perimetro_circulo(nova_figura.dimensao1);
                } else if (operacao == 2) {
                    nova_figura.area = calcular_area_circulo(nova_figura.dimensao1);
                    nova_figura.perimetro = calcular_perimetro_circulo(nova_figura.dimensao1);
                } else {
                    printf("Operação inválida!\n");
                    break;
                }
                strcpy(nova_figura.tipo, "Círculo");
                figuras[count++] = nova_figura;
                break;

            case 2:  // Retângulo
                printf("Digite a largura do retângulo: ");
                scanf("%lf", &nova_figura.dimensao1);
                printf("Digite a altura do retângulo: ");
                scanf("%lf", &nova_figura.dimensao2);
                printf("\nEscolha a operação:\n");
                printf("1. Cálculo da área\n");
                printf("2. Cálculo do perímetro\n");
                printf("Digite sua opção: ");
                scanf("%d", &operacao);

                if (operacao == 1) {
                    nova_figura.area = calcular_area_retangulo(nova_figura.dimensao1, nova_figura.dimensao2);
                    nova_figura.perimetro = calcular_perimetro_retangulo(nova_figura.dimensao1, nova_figura.dimensao2);
                } else if (operacao == 2) {
                    nova_figura.area = calcular_area_retangulo(nova_figura.dimensao1, nova_figura.dimensao2);
                    nova_figura.perimetro = calcular_perimetro_retangulo(nova_figura.dimensao1, nova_figura.dimensao2);
                } else {
                    printf("Operação inválida!\n");
                    break;
                }
                strcpy(nova_figura.tipo, "Retângulo");
                figuras[count++] = nova_figura;
                break;

            case 3:  // Triângulo
                printf("Digite a base do triângulo: ");
                scanf("%lf", &nova_figura.dimensao1);
                printf("Digite a altura do triângulo: ");
                scanf("%lf", &nova_figura.dimensao2);
                printf("\nEscolha a operação:\n");
                printf("1. Cálculo da área\n");
                printf("2. Cálculo do perímetro\n");
                printf("Digite sua opção: ");
                scanf("%d", &operacao);

                if (operacao == 1) {
                    nova_figura.area = calcular_area_triangulo(nova_figura.dimensao1, nova_figura.dimensao2);
                    nova_figura.perimetro = calcular_perimetro_triangulo(nova_figura.dimensao1, nova_figura.dimensao2);
                } else if (operacao == 2) {
                    nova_figura.area = calcular_area_triangulo(nova_figura.dimensao1, nova_figura.dimensao2);
                    nova_figura.perimetro = calcular_perimetro_triangulo(nova_figura.dimensao1, nova_figura.dimensao2);
                } else {
                    printf("Operação inválida!\n");
                    break;
                }
                strcpy(nova_figura.tipo, "Triângulo");
                figuras[count++] = nova_figura;
                break;

            case 4:  // Figura Irregular
                printf("Digite o número de lados da figura irregular: ");
                int lados;
                scanf("%d", &lados);
                printf("Digite o comprimento de cada lado: ");
                double comprimento_lado;
                scanf("%lf", &comprimento_lado);

                double perimetro_irregular = calcular_perimetro_irregular(lados, comprimento_lado);
                printf("Perímetro aproximado da figura irregular com %d lados: %.2lf\n", lados, perimetro_irregular);
                
                strcpy(nova_figura.tipo, "Irregular");
                nova_figura.dimensao1 = lados;  // Salva o número de lados na primeira dimensão
                nova_figura.dimensao2 = comprimento_lado;  // Salva o comprimento de cada lado na segunda dimensão
                nova_figura.perimetro = perimetro_irregular;  // Salva o perímetro calculado
                nova_figura.area = 0;  // A área não será calculada para figuras irregulares nesse exemplo
                figuras[count++] = nova_figura;
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }

        printf("\nDeseja realizar outra operação? (1 - Sim, 0 - Não): ");
        scanf("%d", &opcao);

    } while (opcao == 1);

    // Exibir tabela de todas as figuras calculadas
    exibir_tabela(figuras, count);

    // Liberar a memória alocada dinamicamente
    liberar_memoria(figuras);

    return 0;
}
