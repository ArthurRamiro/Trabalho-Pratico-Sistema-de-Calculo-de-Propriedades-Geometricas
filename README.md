# Trabalho Prático - Sistema de Cálculos de Figuras Geométricas

Este trabalho prático tem como objetivo o desenvolvimento de um sistema em C que receba uma série de figuras geométricas (como círculo, retângulo e triângulo) e realize cálculos relacionados às suas propriedades, como área e perímetro. O sistema será desenvolvido de forma incremental, com entregas baseadas nos módulos descritos abaixo.

O principal objetivo deste projeto é consolidar os conhecimentos adquiridos na disciplina, abordando tópicos fundamentais e avançados como o uso de ponteiros, estruturas e alocação dinâmica de memória.

## Módulo 01: Fundamentos de Programação em C

### Objetivos:
- Implementar funcionalidades básicas de entrada e saída para receber os dados das figuras geométricas.
- Aplicar estruturas condicionais e de repetição para calcular propriedades das figuras com base nos dados fornecidos.

### Entregáveis:
1. **Entrada e Saída Básica**:
    - Implementar um programa que solicite ao usuário os dados básicos das figuras geométricas:
        - Círculo: Raio.
        - Retângulo: Largura e altura.
        - Triângulo: Base e altura.
    - Exibir esses dados de forma organizada na tela.

2. **Estruturas Condicionais**:
    - Criar um menu para o usuário escolher a figura geométrica e a operação desejada:
        - Cálculo de área ou perímetro.
    - Usar estruturas condicionais (`if`, `switch`) para executar a operação correspondente.

3. **Comandos de Repetição**:
    - Permitir que o programa seja executado múltiplas vezes até que o usuário escolha sair.

4. **Laços Aninhados**:
    - Adicionar uma funcionalidade para calcular e exibir as áreas de várias figuras fornecidas pelo usuário em sequência.

---

## Módulo 02: Funções, Vetores, Strings e Matrizes

### Objetivos:
- Modularizar o código utilizando funções para calcular áreas e perímetros.
- Implementar vetores e matrizes para armazenar os dados das figuras geométricas.
- Introduzir manipulação de strings para gerenciar nomes e descrições das figuras.

### Entregáveis:
1. **Sub-rotinas (Funções)**:
    - Implementar funções específicas para calcular:
        - Área e perímetro do círculo.
        - Área e perímetro do retângulo.
        - Área do triângulo (utilizando a fórmula básica).
    - Criar uma função para exibir o menu de opções.

2. **Vetores e Strings**:
    - Usar vetores para armazenar os valores calculados (áreas e perímetros) de até 10 figuras geométricas.
    - Implementar manipulação de strings para associar nomes (como "Figura 1", "Figura 2") aos cálculos realizados.

3. **Matrizes**:
    - Implementar uma matriz para armazenar dados das figuras (e.g., dimensões de cada figura, áreas e perímetros calculados).
    - Exibir os dados de forma tabular.

4. **Validação de Dados**:
    - Adicionar verificações para garantir que os valores fornecidos pelo usuário sejam válidos (e.g., números positivos).

---

## Módulo 03: Recursos Avançados em C

### Objetivos:
- Aplicar conceitos avançados, como recursão, ponteiros e alocação dinâmica de memória.
- Introduzir o uso de structs para organizar os dados das figuras geométricas.

### Entregáveis:
1. **Recursão**:
    - Implementar uma funcionalidade recursiva para calcular o fatorial de um número, usado para cálculo aproximado do perímetro de uma figura irregular com n lados.

2. **Ponteiros**:
    - Substituir o uso direto de variáveis por ponteiros para manipular os dados das figuras geométricas.
    - Implementar uma função que use ponteiros para trocar as dimensões de duas figuras.

3. **Alocação Dinâmica de Memória**:
    - Usar alocação dinâmica para armazenar os dados das figuras em tempo de execução.
    - Garantir que a memória seja liberada corretamente após o uso.

4. **Structs**:
    - Criar uma estrutura `Figura` com os seguintes campos:
        - Nome da figura.
        - Tipo (Círculo, Retângulo, Triângulo).
        - Dimensões (como raio, largura, altura).
        - Área e perímetro.
    - Implementar um vetor dinâmico de structs para armazenar múltiplas figuras.

5. **Exibição Final**:
    - Permitir que o programa exiba um relatório detalhado de todas as figuras processadas, incluindo nome, tipo, dimensões, área e perímetro.

---

## Conclusão

Este sistema, ao longo de sua construção, abordará tanto os fundamentos quanto conceitos mais avançados de programação em C, e proporcionará uma compreensão mais profunda sobre estruturas de dados, manipulação de memória e resolução de problemas através da programação.
