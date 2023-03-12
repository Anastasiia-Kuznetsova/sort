import matplotlib.pyplot as pyplot
import numpy as np
from matplotlib.colors import hsv_to_rgb
from matplotlib.patches import Wedge
import os


with open('whatsort.txt') as file:
    f = file.readline()
if int(f) == 1:
    with open('sorts/bubble.txt') as file:
        strings = np.array([string for string in file.read().split('\n')])
        st = 'bubble'
elif int(f) == 2:
    with open('sorts/insert.txt') as file:
        strings = np.array([string for string in file.read().split('\n')])
        st = 'insert'
elif int(f) == 3:
    with open('sorts/choice.txt') as file:
        strings = np.array([string for string in file.read().split('\n')])
        st = 'choice'
elif int(f) == 4:
    with open('sorts/heap.txt') as file:
        strings = np.array([string for string in file.read().split('\n')])
        st = 'heap'
tp = []
for i in range(len(strings)):
    tp.append(strings[i].split())
    tp[i] = [int(x) for x in tp[i]]

lenOfArray = len(tp[0])# количество элементов

count = int(len(strings)) # количество кадров(в данном случае каждый 20 кадр)
shift = lenOfArray - count #сдвиг, чтобы последний кадр был последним в выборке
fig, ax = pyplot.subplots(figsize=(12, 12))
mx = np.amax(tp[0])
for i in range(count - 1):
    #data = np.array([int(item) for item in strings[i*20 + shift].split()])
    data = np.array(tp[i])
    convertData = data / mx
    for j in range(lenOfArray):
        colorrgb = hsv_to_rgb([convertData[j], 1, 1])
        color = []
        for k in range(3):
            color.append(hex(int(colorrgb[k]*255)).split('x')[-1].zfill(2))
        fov = Wedge((0, 0), 1, j*360/lenOfArray, (j+1)*360/lenOfArray,
                    color=f'#{color[0]}{color[1]}{color[2]}')
        ax.add_artist(fov)
    ax.axis([-1.2, 1.2, -1.2, 1.2])
    ax.axis('off')
    out = str(i).zfill(4)
    pyplot.text(-1.5, 1.5, 'Номер итерации: ' + str(i + 1))
    directory = '/home/anastasia/sorts/' + st
    if not os.path.exists(directory): os.makedirs(directory)
    pyplot.savefig(fname = '/home/anastasia/sorts/' + st+'/' + out +'.jpg')
    ax.clear()
