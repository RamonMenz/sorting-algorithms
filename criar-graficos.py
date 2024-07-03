import pandas as pd
import plotly_express as px

tabela = pd.read_csv('./C/resultados.csv', delimiter=';')

tamanho_vetores = [
    '50 mil inteiros',
    '100 mil inteiros',
    '150 mil inteiros',
    '200 mil inteiros'
]

grafico = px.bar(
    tabela,
    x='Algoritmo',
    y=tamanho_vetores,
    barmode='group',
    title="Tempos de execução de diferentes Algoritmos de Ordenação",
    text_auto=True,
    labels={
        'variable': 'Tamanho dos Vetores',
        'value': 'Tempo (ms)'
    }
)
grafico.write_image('comparacao.png')
# grafico.show() # para ver o gráfico em um navegador

grafico = px.bar(
    tabela.tail(2),
    x='Algoritmo',
    y=tamanho_vetores,
    barmode='group',
    title="Tempos de execução do Merge Sort e do Quick Sort",
    text_auto=True,
    labels={
        'variable': 'Tamanho dos Vetores',
        'value': 'Tempo (ms)'
    }
)
grafico.write_image('comparacao_zoom.png')
# grafico.show() # para ver o gráfico em um navegador
