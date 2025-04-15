import matplotlib.pyplot as plt

class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

def add_node(root, key):
    if root is None:
        return Node(key)
    if key < root.key:
        root.left = add_node(root.left, key)
    else:
        root.right = add_node(root.right, key)
    return root

def plot_tree(node, x=0, y=0, dx=1, positions=None, ax=None):
    if positions is None:
        positions = {}
    if ax is None:
        _, ax = plt.subplots()

    # Reverse the y-coordinate (negative for upward direction)
    positions[node.key] = (x, -y)
    ax.text(x, -y, str(node.key), fontsize=10, ha='center', bbox=dict(facecolor='white', edgecolor='black'))

    if node.left:
        ax.plot([x, x - dx], [-y, -(y + 1)], color="black")
        plot_tree(node.left, x - dx, y + 1, dx / 2, positions, ax)
    if node.right:
        ax.plot([x, x + dx], [-y, -(y + 1)], color="black")
        plot_tree(node.right, x + dx, y + 1, dx / 2, positions, ax)

    return ax

# Build the binary tree
root = None
values = [50, 30, 70, 20, 40, 60, 80]
for value in values:
    root = add_node(root, value)

# Plot the binary tree
ax = plot_tree(root)
plt.show()
