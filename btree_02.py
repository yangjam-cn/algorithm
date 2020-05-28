class tree:
    def __init__(self):
        self.data = 0
        self.left = None
        self.right = None

def create_tree(root, val):
    new_node = tree()
    new_node.data = val
    new_node.left = None
    new_node.right = None
    if root == None:
        root = new_node
        return root
    else:
        current = root
        while current != None:
            backup = current
            if current.data > val:
                current = current.left
            else:
                current = current.right
        if backup.data > val:
            backup.left = new_node
        else:
            backup.right = new_node
        return root

ptr = None
root = None
data = [5, 6, 24, 8, 12, 3, 17, 1, 9]
for i in range(9):
    ptr = create_tree(ptr, data[i])
print('left:')
root = ptr
while root != None:
    print("%d" % root.data)
    root = root.left
