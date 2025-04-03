#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// TP 3 - Arthur Ramiro Martins

// Estrutura para armazenar dados de uma figura geom�trica
typedef struct {
    char nome[50];  // Nome pode ter at� 50 caracteres
    char tipo[20];  // Tipo da figura (C�rculo, Ret�ngulo, Tri�ngulo)
    double dimensao1;  // Raio (c�rculo), largura (ret�ngulo), base (tri�ngulo)
    double dimensao2;  // Altura (tri�ngulo ou ret�ngulo)
    double area;
    double perimetro;
} Figura;

// Fun��es para c�lculo de �reas e per�metros
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

// Fun��o recursiva para calcular o fatorial de um n�mero
long long fatorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * fatorial(n - 1);
    }
}

// Fun��o para calcular o per�metro aproximado de uma figura irregular
double calcular_perimetro_irregular(int lados, double comprimento_lado) {
    long long fator = fatorial(lados);  // Usando o fatorial de n lados para calcular um valor aproximado
    double perimetro_aproximado = lados * comprimento_lado / fator;
    return perimetro_aproximado;
}

// Fun��o para exibir o menu
void exibir_menu() {
    printf("\nEscolha a figura geom�trica:\n");
    printf("1. C�rculo\n");
    printf("2. Ret�ngulo\n");
    printf("3. Tri�ngulo\n");
    printf("4. Figura Irregular\n");
    printf("0. Sair\n");
}

// Fun��o para exibir as informa��es de todas as figuras
void exibir_tabela(Figura* figuras, int count) {
    printf("\n----------------------------------------------------------------------------------------------------------\n");
    printf("| %-20s | %-15s | %-12s | %-12s | %-7s | %-9s | %-9s |\n", "Nome", "Tipo", "Dimens�o 1", "Dimens�o 2", "�rea", "Per�metro", "Figura");
    printf("----------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("| %-20s | %-15s | %-12.2lf | %-12.2lf | %-7.2lf | %-9.2lf | %-9d |\n", 
            figuras[i].nome, figuras[i].tipo, figuras[i].dimensao1, figuras[i].dimensao2, figuras[i].area, figuras[i].perimetro, i + 1);
    }
    printf("----------------------------------------------------------------------------------------------------------\n");
}

// Fun��o para trocar as dimens�es de duas figuras usando ponteiros
void trocar_dimensoes(Figura* fig1, Figura* fig2) {
    double temp_dimensao1 = fig1->dimensao1;
    double temp_dimensao2 = fig1->dimensao2;

    fig1->dimensao1 = fig2->dimensao1;
    fig1->dimensao2 = fig2->dimensao2;

    fig2->dimensao1 = temp_dimensao1;
    fig2->dimensao2 = temp_dimensao2;
}

// Fun��o para liberar a mem�ria alocada dinamicamente
void liberar_memoria(Figura* figuras) {
    free(figuras);
}

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    Figura* figuras = malloc(sizeof(Figura) * 10);  // Aloca��o din�mica para armazenar at� 10 figuras
    if (figuras == NULL) {
        printf("Erro ao alocar mem�ria.\n");
        return 1;
    }

    int count = 0;  // Contador de figuras
    int opcao, operacao;

    do {
        exibir_menu();
        printf("Digite sua op��o: ");
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
        scanf(" %[^\n]%*c", nova_figura.nome);  // Permite que o usu�rio digite o nome da figura com espa�os

        switch(opcao) {
            case 1:  // C�rculo
                printf("Digite o raio do c�rculo: ");
                scanf("%lf", &nova_figura.dimensao1);
                printf("\nEscolha a opera��o:\n");
                printf("1. C�lculo da �rea\n");
                printf("2. C�lculo do per�metro\n");
                printf("Digite sua op��o: ");
                scanf("%d", &operacao);

                if (operacao == 1) {
                    nova_figura.area = calcular_area_circulo(nova_figura.dimensao1);
                    nova_figura.perimetro = calcular_perimetro_circulo(nova_figura.dimensao1);
                } else if (operacao == 2) {
                    nova_figura.area = calcular_area_circulo(nova_figura.dimensao1);
                    nova_figura.perimetro = calcular_perimetro_circulo(nova_figura.dimensao1);
                } else {
                    printf("Opera��o inv�lida!\n");
                    break;
                }
                strcpy(nova_figura.tipo, "C�rculo");
                figuras[count++] = nova_figura;
                break;

            case 2:  // Ret�ngulo
                printf("Digite a largura do ret�ngulo: ");
                scanf("%lf", &nova_figura.dimensao1);
                printf("Digite a altura do ret�ngulo: ");
                scanf("%lf", &nova_figura.dimensao2);
                printf("\nEscolha a opera��o:\n");
                printf("1. C�lculo da �rea\n");
                printf("2. C�lculo do per�metro\n");
                printf("Digite sua op��o: ");
                scanf("%d", &operacao);

                if (operacao == 1) {
                    nova_figura.area = calcular_area_retangulo(nova_figura.dimensao1, nova_figura.dimensao2);
                    nova_figura.perimetro = calcular_perimetro_retangulo(nova_figura.dimensao1, nova_figura.dimensao2);
                } else if (operacao == 2) {
                    nova_figura.area = calcular_area_retangulo(nova_figura.dimensao1, nova_figura.dimensao2);
                    nova_figura.perimetro = calcular_perimetro_retangulo(nova_figura.dimensao1, nova_figura.dimensao2);
                } else {
                    printf("Opera��o inv�lida!\n");
                    break;
                }
                strcpy(nova_figura.tipo, "Ret�ngulo");
                figuras[count++] = nova_figura;
                break;

            case 3:  // Tri�ngulo
                printf("Digite a base do tri�ngulo: ");
                scanf("%lf", &nova_figura.dimensao1);
                printf("Digite a altura do tri�ngulo: ");
                scanf("%lf", &nova_figura.dimensao2);
                printf("\nEscolha a opera��o:\n");
                printf("1. C�lculo da �rea\n");
                printf("2. C�lculo do per�metro\n");
                printf("Digite sua op��o: ");
                scanf("%d", &operacao);

                if (operacao == 1) {
                    nova_figura.area = calcular_area_triangulo(nova_figura.dimensao1, nova_figura.dimensao2);
                    nova_figura.perimetro = calcular_perimetro_triangulo(nova_figura.dimensao1, nova_figura.dimensao2);
                } else if (operacao == 2) {
                    nova_figura.area = calcular_area_triangulo(nova_figura.dimensao1, nova_figura.dimensao2);
                    nova_figura.perimetro = calcular_perimetro_triangulo(nova_figura.dimensao1, nova_figura.dimensao2);
                } else {
                    printf("Opera��o inv�lida!\n");
                    break;
                }
                strcpy(nova_figura.tipo, "Tri�ngulo");
                figuras[count++] = nova_figura;
                break;

            case 4:  // Figura Irregular
                printf("Digite o n�mero de lados da figura irregular: ");
                int lados;
                scanf("%d", &lados);
                printf("Digite o comprimento de cada lado: ");
                double comprimento_lado;
                scanf("%lf", &comprimento_lado);

                double perimetro_irregular = calcular_perimetro_irregular(lados, comprimento_lado);
                printf("Per�metro aproximado da figura irregular com %d lados: %.2lf\n", lados, perimetro_irregular);
                
                strcpy(nova_figura.tipo, "Irregular");
                nova_figura.dimensao1 = lados;  // Salva o n�mero de lados na primeira dimens�o
                nova_figura.dimensao2 = comprimento_lado;  // Salva o comprimento de cada lado na segunda dimens�o
                nova_figura.perimetro = perimetro_irregular;  // Salva o per�metro calculado
                nova_figura.area = 0;  // A �rea n�o ser� calculada para figuras irregulares nesse exemplo
                figuras[count++] = nova_figura;
                break;

            default:
                printf("Op��o inv�lida! Tente novamente.\n");
        }

        printf("\nDeseja realizar outra opera��o? (1 - Sim, 0 - N�o): ");
        scanf("%d", &opcao);

    } while (opcao == 1);

    // Exibir tabela de todas as figuras calculadas
    exibir_tabela(figuras, count);

    // Liberar a mem�ria alocada dinamicamente
    liberar_memoria(figuras);

    return 0;
}
