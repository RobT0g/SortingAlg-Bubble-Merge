from matplotlib import pyplot as plt
import pandas as pd


dicttimebubble = dict()
dicttimeinsert = dict()
for i in range(1, 11):
    try:
        arquivo = open(f'Outputs/{i}-bubble.txt', 'r')
        vettimes = arquivo.read().split('\n')
        vettimes = [float(time.replace('\n', '')) for time in vettimes]
        dicttimebubble[f'{i}K-Bubble'] = vettimes.copy()
        arquivo.close()
        arquivo = open(f'Outputs/{i}-insert.txt', 'r')
        vettimes = arquivo.read().split('\n')
        vettimes = [float(time.replace('\n', '')) for time in vettimes]
        dicttimeinsert[f'{i}k-Insert'] = vettimes.copy()
        arquivo.close()
    except Exception as e:
        print(e)
    finally:
        arquivo.close


dftimeBubble = pd.DataFrame(dicttimebubble, columns=dicttimebubble.keys())

dftimeInsert = pd.DataFrame(dicttimeinsert, columns=dicttimeinsert.keys())


dicttimebubbe1 = dict()
dicttimemerge = dict()
for i in range(2, 16):
    try:
        arquivo = open(f'Outputs/{i*10}-bubble.txt', 'r')
        vettimes = arquivo.read().split('\n')
        vettimes = [float(time.replace('\n', '')) for time in vettimes]
        dicttimebubbe1[f'{i*10}-bubble'] = vettimes

        vettimes = arquivo.read
        arquivo.close()
        arquivo = open(f'Outputs/{i*10}-merge.txt', 'r')
        vettimes = arquivo.read().split('\n')
        vettimes = [float(line) for line in vettimes]

    except Exception as e:
        print(e)
    finally:
        arquivo.close


dftimeBubble1 = pd.DataFrame(dicttimebubbe1, columns=dicttimebubbe1.keys())
dftimeMerge = pd.DataFrame(dicttimemerge, columns=dicttimemerge.keys())


with pd.ExcelWriter('ExcelFiles/InefficientSortTimes.xlsx') as writer:
    dftimeBubble.to_excel(writer, sheet_name='Bubble')
    dftimeInsert.to_excel(writer, sheet_name='Insert')

'''with pd.ExcelWriter('ExcelFiles/InefficientSortTimes.xlsx', mode='a') as writer:
    
print('Folhas inseridas')
'''