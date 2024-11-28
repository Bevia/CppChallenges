import networkx as nx
import matplotlib.pyplot as plt

# Create the graph structure
G = nx.Graph()
edges = [(0, 1), (0, 2), (1, 3), (1, 4), (2, 5)]
G.add_edges_from(edges)

# BFS traversal
bfs_traversal = list(nx.bfs_edges(G, 0))
nodes_visited = [0] + [v for u, v in bfs_traversal]

# Plot and save the image
pos = nx.spring_layout(G)
plt.figure(figsize=(8, 6))
nx.draw(G, pos, with_labels=True, node_color="lightblue", node_size=500, edge_color="gray")
nx.draw_networkx_edges(G, pos, edgelist=bfs_traversal, edge_color="red", width=2)
nx.draw_networkx_nodes(G, pos, nodelist=nodes_visited, node_color="orange", node_size=600)
plt.title("Breadth-First Search (BFS) Traversal")
plt.savefig('bfs_traversal.png')  # This saves the image to your local directory
plt.show()