class FileNode:
    def __init__(self, name):
        self.name = name
        self.children = []

def deserialize(data_list):
    if not data_list:
        return None

    value = data_list.pop(0)
    if value == '#':
        return None

    node = FileNode(value)
    while data_list and data_list[0] != '#':
        child = deserialize(data_list)
        if child:
            node.children.append(child)
    if data_list:
        data_list.pop(0)  # Remove the '#'
    return node

# Deserialize the string to reconstruct the file system tree
data = "Root Folder1 File1.txt # # Folder2 File2.txt # # # File3.txt # #".split()
file_system_tree = deserialize(data)