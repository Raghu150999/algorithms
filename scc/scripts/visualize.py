import plotly.graph_objects as go
import matplotlib.pyplot as plt
import sys
import pandas as pd
import networkx as nx

plt.style.use('ggplot')

edgefile = sys.argv[1]
n = int(sys.argv[2])
m = int(sys.argv[3])
f = open(sys.argv[4])

G = nx.DiGraph()

G.add_nodes_from(list(range(1, n)))

edges = pd.read_csv(edgefile)

for i in range(len(edges)):
    G.add_edge(int(edges.loc[i, 'Source']), int(edges.loc[i, 'Target']))

component = []

for i in range(0, n):
    component.append(0)

while True:
    l = f.readline().split()
    if not l:
        break
    cno = int(l[0])
    l.pop(0)
    for i in l:
        component[int(i)-1] = cno

plt.figure(figsize=(15, 15))
# nx.draw_networkx(G, with_labels = False, node_color = component, arrowsize = 10, font_color='white')
nx.draw_networkx_nodes(G, pos=nx.spring_layout(
    G), with_labels=False, node_color=component)
plt.savefig("4.png")
