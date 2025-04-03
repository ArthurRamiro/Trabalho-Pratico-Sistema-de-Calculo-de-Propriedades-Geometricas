#include <stdio.h>
#include <string.h>
#include <locale.h>

// M�dulo 2 TP - Arthur Ramiro Martins - 24.1.8192

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

} Figura; // A estrutura armazena o nome da figura, �rea, per�metro e dimens�es relevantes.

// Fun��es espec�ficas foram criadas para calcular a �rea e o per�metro de cada figura:
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

// Fun��o para exibir o menu de op��es ao usu�rio:
void exibirMenu()
{
    printf("\nEscolha uma figura geom�trica:\n");
    printf("1. C�rculo\n");
    printf("2. Ret�ngulo\n");
    printf("3. Tri�ngulo\n");
    printf("0. Sair\n");
}

// A fun��o validarEntrada foi criada para que os valores fornecidos pelo usu�rio sejam positivos:
int validarEntrada(float valor)
{
    return valor > 0;
}

// Fun��o principal
int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    Figura figuras[MAX_FIGURAS]; // O vetor figuras armazena at� 10 inst�ncias da estrutura Figura, permitindo armazenar os resultados dos c�lculos
    int contador = 0;
    int opcao;

    do
    {
        exibirMenu();
        printf("Op��o: ");
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
        { // C�rculo
            float raio;
            printf("Digite o raio do c�rculo: ");
            scanf("%f", &raio);
            if (!validarEntrada(raio))
            {
                printf("Valor inv�lido! O raio deve ser positivo.\n");
                break;
            }
            figuras[contador].area = calcularAreaCirculo(raio);
            figuras[contador].perimetro = calcularPerimetroCirculo(raio);
            strcpy(figuras[contador].nome, "C�rculo"); // O strcpy � usado para associar nomes �s figuras geom�tricas
            figuras[contador].dimensoes[0] = raio;     // Armazenando apenas o raio
            contador++;
            break;
        }
        case 2:
        { // Ret�ngulo
            float largura, altura;
            printf("Digite a largura do ret�ngulo: ");
            scanf("%f", &largura);
            printf("Digite a altura do ret�ngulo: ");
            scanf("%f", &altura);
            if (!validarEntrada(largura) || !validarEntrada(altura))
            {
                printf("Valores inv�lidos! Largura e altura devem ser positivos.\n");
                break;
            }
            figuras[contador].area = calcularAreaRetangulo(largura, altura);
            figuras[contador].perimetro = calcularPerimetroRetangulo(largura, altura);
            strcpy(figuras[contador].nome, "Ret�ngulo"); // O strcpy � usado para associar nomes �s figuras geom�tricas
            figuras[contador].dimensoes[0] = largura;    // Armazenando largura
            figuras[contador].dimensoes[1] = altura;     // Armazenando altura
            contador++;
            break;
        }
        case 3:
        { // Tri�ngulo
            float base, altura;
            printf("Digite a base do tri�ngulo: ");
            scanf("%f", &base);
            printf("Digite a altura do tri�ngulo: ");
            scanf("%f", &altura);
            if (!validarEntrada(base) || !validarEntrada(altura))
            {
                printf("Valores inv�lidos! Base e altura devem ser positivos.\n");
                break;
            }
            figuras[contador].area = calcularAreaTriangulo(base, altura);
            strcpy(figuras[contador].nome, "Tri�ngulo"); // O strcpy � usado para associar nomes �s figuras geom�tricas
            figuras[contador].dimensoes[0] = base;       // Armazenando base
            figuras[contador].dimensoes[1] = altura;     // Armazenando altura
            contador++;
            break;
        }
        default:
            printf("Op��o inv�lida! Tente novamente.\n");
        }

    } while (opcao != 0);

    // Exibi��o dos resultados em formato tabular
    printf("\nResultados:\n");
    printf("%-15s %-10s %-10s\n", "Figura", "�rea", "Per�metro");
    for (int i = 0; i < contador; i++)
    {
        printf("%-15s %-10.2f %-10.2f\n", figuras[i].nome, figuras[i].area, figuras[i].perimetro);
    }

    return 0;
}
