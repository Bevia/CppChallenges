import matplotlib.pyplot as plt

class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

# Function to add nodes to the binary tree
def add_node(root, key):
    if root is None:
        return Node(key)
    if key < root.key:
        root.left = add_node(root.left, key)
    else:
        root.right = add_node(root.right, key)
    return root

# Function to invert the binary tree
def invert_tree(root):
    if root is None:
        return None
    root.left, root.right = invert_tree(root.right), invert_tree(root.left)
    return root

# Function to plot the binary tree
def plot_tree(node, x=0, y=0, dx=1, positions=None, ax=None):
    if positions is None:
        positions = {}
    if ax is None:
        _, ax = plt.subplots()

    positions[node.key] = (x, -y)  # Use negative y to ensure the root is at the top
    ax.text(x, -y, str(node.key), fontsize=10, ha='center', bbox=dict(facecolor='white', edgecolor='black'))

    if node.left:
        ax.plot([x, x - dx], [-y, -(y + 1)], color="black")
        plot_tree(node.left, x - dx, y + 1, dx / 2, positions, ax)
    if node.right:
        ax.plot([x, x + dx], [-y, -(y + 1)], color="black")
        plot_tree(node.right, x + dx, y + 1, dx / 2, positions, ax)

    return ax

# Build the original binary tree
values = [4, 2, 7, 1, 3, 6, 9]
root = None
for value in values:
    root = add_node(root, value)

# Plot the original binary tree
plt.figure(figsize=(8, 6))
ax = plot_tree(root)
plt.title("Original Binary Tree")
plt.show()

# Invert the binary tree
root = invert_tree(root)

# Plot the inverted binary tree
plt.figure(figsize=(8, 6))
ax = plot_tree(root)
plt.title("Inverted Binary Tree")
plt.show()
