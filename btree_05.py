class tree:
    def __init__(self):
        self.data = None
        self.left = None
        self.right = None
    def create_tree(self, val):
        new_node = tree()
        new_node.data = val
        new_node.left = None
        new_node.right = None
        if self.data  == None:
            self = new_node
            return self
        else:
            current = self
            while current is not None:
                backup = current
                if current.data > val:
                    current = current.left
                else:
                    current = current.right
            if backup.data > val:
                backup.left = new_node
            else:
                backup.right = new_node
            return self
    
    def preorder(self):
        if self is not None:
            print(self.data, end='\t')
            if self.left is not None:
                self.left.preorder()
            if self.right is not None:
                self.right.preorder()
    
    def search(self, val):
        while True:
            if self is None:
                return None
            else:
                if self.data == val:
                    return self 
                elif self.data > val:
                    self = self.left
                else:
                    self = self.right


data = [7, 4, 1, 5, 16, 8, 11, 12, 15, 9, 2]
root = tree()
for i in range(11):
    root = root.create_tree(data[i])
ptr = root
ptr.preorder()
# print(ptr.search(7))
# print(ptr.search(22))
