# Comparando Algoritmos de Ordenação

Este projeto foi desenvolvido como parte do trabalho da disciplina de Estrutura de Dados I do segundo semestre do curso de Ciência da Computação. O objetivo do trabalho era implementar e comparar o desempenho de diferentes algoritmos de ordenação.

## Descrição do Projeto

### Algoritmos Implementados
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Quick Sort
5. Merge Sort

### Comparação de Desempenho

- Os algoritmos foram testados em vetores de tamanhos diferentes: 50 mil, 100 mil, 150 mil e 200 mil números inteiros.
- Os tempos de execução foram medidos para cada algoritmo em cada tamanho de vetor.
- Os resultados estão disponíveis no arquivo `resultados.csv` dentro da pasta `C`. Esse arquivo foi gerado pelo executável do arquivo `comparacao.c`.

### Executando o Projeto

Para executar o projeto, siga estas etapas:

1. **Pré-requisitos:**
   - Certifique-se de ter instalado o compilador C (como o GCC) e o Python em sua máquina.
   - Todas as bibliotecas Python necessárias estão listadas no arquivo "requirements.txt". Você pode instalá-las usando o comando:
     ```
     pip install -r requirements.txt
     ```

2. **Código em C:**
   - O código-fonte em C está localizado no diretório "C".
   - Compile o arquivo "comparacao.c" para gerar o executável:
     ```
     gcc -o /C/comparacao /C/comparacao.c
     ```
   - Execute o programa:
     ```
     ./C/comparacao
     ```

3. **Visualização dos Gráficos:**
   - Você pode criar os gráficos a partir dos dados do arquivo "resultados.csv" usando os seguintes arquivos:
     - "criar-graficos.py": Gera arquivos de imagem com os gráficos.
     - "criar-graficos.ipynb": Jupyter Notebook para visualizar os gráficos interativamente.

4. **Explorando Variáveis:**
   - Sinta-se à vontade para modificar as variáveis no topo do arquivo "comparacao.c" para ajustar os testes conforme necessário. Comentários explicam o propósito de cada variável.

## Observação
Devido a problemas para testar os vetores de 150 mil e 200 mil inteiros, o código foi otimizado da melhor maneira possível, mas talvez isso tenha deixado ele um pouco confuso.
