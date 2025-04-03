#include <stdio.h>
#include <string.h>
#include <locale.h>

// Módulo 2 TP - Arthur Ramiro Martins - 24.1.8192

// Definindo constantes
#define MAX_FIGURAS 10
#define NOME_MAX 20

// Estruturas para armazenar dados das figuras
typedef struct
{
    char nome[NOME_MAX];
    float area;
    float perimetro;
    float dimensoes[3]; // Raio, largura/altura/base/altura

} Figura; // A estrutura armazena o nome da figura, área, perímetro e dimensões relevantes.

// Funções específicas foram criadas para calcular a área e o perímetro de cada figura:
float calcularAreaCirculo(float raio)
{
    return 3.14159 * raio * raio;
}

float calcularPerimetroCirculo(float raio)
{
    return 2 * 3.14159 * raio;
}

float calcularAreaRetangulo(float largura, float altura)
{
    return largura * altura;
}

float calcularPerimetroRetangulo(float largura, float altura)
{
    return 2 * (largura + altura);
}

float calcularAreaTriangulo(float base, float altura)
{
    return (base * altura) / 2;
}

// Função para exibir o menu de opções ao usuário:
void exibirMenu()
{
    printf("\nEscolha uma figura geométrica:\n");
    printf("1. Círculo\n");
    printf("2. Retângulo\n");
    printf("3. Triângulo\n");
    printf("0. Sair\n");
}

// A função validarEntrada foi criada para que os valores fornecidos pelo usuário sejam positivos:
int validarEntrada(float valor)
{
    return valor > 0;
}

// Função principal
int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    Figura figuras[MAX_FIGURAS]; // O vetor figuras armazena até 10 instâncias da estrutura Figura, permitindo armazenar os resultados dos cálculos
    int contador = 0;
    int opcao;

    do
    {
        exibirMenu();
        printf("Opção: ");
        scanf("%d", &opcao);

        if (opcao == 0)
        {
            break; // Sair do loop
        }

        if (contador >= MAX_FIGURAS)
        {
            printf("Limite de figuras atingido!\n");
            continue;
        }

        switch (opcao)
        {
        case 1:
        { // Círculo
            float raio;
            printf("Digite o raio do círculo: ");
            scanf("%f", &raio);
            if (!validarEntrada(raio))
            {
                printf("Valor inválido! O raio deve ser positivo.\n");
                break;
            }
            figuras[contador].area = calcularAreaCirculo(raio);
            figuras[contador].perimetro = calcularPerimetroCirculo(raio);
            strcpy(figuras[contador].nome, "Círculo"); // O strcpy é usado para associar nomes às figuras geométricas
            figuras[contador].dimensoes[0] = raio;     // Armazenando apenas o raio
            contador++;
            break;
        }
        case 2:
        { // Retângulo
            float largura, altura;
            printf("Digite a largura do retângulo: ");
            scanf("%f", &largura);
            printf("Digite a altura do retângulo: ");
            scanf("%f", &altura);
            if (!validarEntrada(largura) || !validarEntrada(altura))
            {
                printf("Valores inválidos! Largura e altura devem ser positivos.\n");
                break;
            }
            figuras[contador].area = calcularAreaRetangulo(largura, altura);
            figuras[contador].perimetro = calcularPerimetroRetangulo(largura, altura);
            strcpy(figuras[contador].nome, "Retângulo"); // O strcpy é usado para associar nomes às figuras geométricas
            figuras[contador].dimensoes[0] = largura;    // Armazenando largura
            figuras[contador].dimensoes[1] = altura;     // Armazenando altura
            contador++;
            break;
        }
        case 3:
        { // Triângulo
            float base, altura;
            printf("Digite a base do triângulo: ");
            scanf("%f", &base);
            printf("Digite a altura do triângulo: ");
            scanf("%f", &altura);
            if (!validarEntrada(base) || !validarEntrada(altura))
            {
                printf("Valores inválidos! Base e altura devem ser positivos.\n");
                break;
            }
            figuras[contador].area = calcularAreaTriangulo(base, altura);
            strcpy(figuras[contador].nome, "Triângulo"); // O strcpy é usado para associar nomes às figuras geométricas
            figuras[contador].dimensoes[0] = base;       // Armazenando base
            figuras[contador].dimensoes[1] = altura;     // Armazenando altura
            contador++;
            break;
        }
        default:
            printf("Opção inválida! Tente novamente.\n");
        }

    } while (opcao != 0);

    // Exibição dos resultados em formato tabular
    printf("\nResultados:\n");
    printf("%-15s %-10s %-10s\n", "Figura", "Área", "Perímetro");
    for (int i = 0; i < contador; i++)
    {
        printf("%-15s %-10.2f %-10.2f\n", figuras[i].nome, figuras[i].area, figuras[i].perimetro);
    }

    return 0;
}
