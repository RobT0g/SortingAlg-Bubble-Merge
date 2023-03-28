# Gera um vetor desordenado de inteiros e salva o mesmo vetor três vezes em extenções diferentes
# Exteções: .txt, .csv, .xlsx

import pandas as pd
from random import sample
import os

def saveFile(dataSet:list[int], filePath)->bool:
    '''Salva a o vetor dataSet em três arquivos .txt, .csv e .xlsx
    -dataSet: passa o vetor que será salvo
    -filePath: nome do darquivo de destino'''
    if not os.path.isdir('Arquivos'):
        os.mkdir('./Arquivos')
    '''dataframe = pd.DataFrame(dataSet, columns=['Valores'])
    # Gerando arquivo .xlsx os valores ordenados aleatoreamente 
    dataframe.to_excel(f'Arquivos/{filePath}.xlsx', index=False)

    # Gerando arquivo .csv
    dataframe.to_csv(f'Arquivos/{filePath}.csv', index=False)'''

    # Gerando arquivo .txt
    with open(f'Arquivos/{filePath}.txt', 'w') as arquivo:
        arquivo.write(f'{len(dataSet)}')
        [arquivo.write(f'\n{str(i)}') for i in dataSet]
        arquivo.close()
    with open(f'Outputs/{filePath}-bubble.txt', 'w') as arquivo:
        pass
    with open(f'''Outputs/{filePath}-{'insert' if int(filePath) <= 10 else 'merge'}.txt''', 'w') as arquivo:
        pass
    return True
    
def genVet(n:int, step:int=1000)->list[list[int]]: 
    dataSet=list()
    listDataSet = list()
    for i in range(1, n+1):
        amostra = range(i*step)
        print(f'Criando datSet de {i*step} valores...')
        dataSet= sample(amostra, i*step)
        print(f'Vetor {i*step} valores criado.')
        listDataSet.append(dataSet)
    return listDataSet


if __name__=='__main__':
    vetStep1k = genVet(10)
    for data in vetStep1k:
        saveFile(dataSet=data, filePath=f'{len(data)//1000}')

    vetStep10k = genVet(15, step=10000)
    for data in vetStep10k:
        saveFile(dataSet=data, filePath=f'{len(data)//1000}')