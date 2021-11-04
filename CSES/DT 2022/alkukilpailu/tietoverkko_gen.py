import os, sys
from os import path

nodes = 200000

with open('tverkko.in', 'w') as f:
    print(nodes, file=f)

    for i in range(1, nodes):
        print(i, i + 1, 10, file=f)


