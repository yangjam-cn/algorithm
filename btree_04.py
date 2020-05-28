# 2020.1.13
# 树的基本操作
class tree:
    def __init__(self):
        self.data = 0
        self.left = None
        self.right = None
    
    def search(self, val):
        while True:
            if self == None:
                return None
            else:
                if self.data == val:
                    return self
                elif self.data > val:
                    self = self.left
                else:
                    self = self.right


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


def preorder_traversal(ptr):
    if ptr is not None:
        print(ptr.data, end='\t')
        preorder_traversal(ptr.left)
        preorder_traversal(ptr.right)

data = [7, 4, 1, 5, 16, 8, 11, 12, 15, 9, 2]
root = None
for i in range(11):
    root = create_tree(root, data[i])
ptr = root
preorder_traversal(ptr)
print()
if ptr.search(11) != None:
    print('Found!')
if ptr.search(22) == None:
    print('Not find!')