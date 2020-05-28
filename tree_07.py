# 二叉运算树
# 用链表实现二叉运算树
class TreeNode:
    def __init__(self, value):
        self.value = value
        self.left_Node = None
        self.right_Node = None


class Binary_Search_Tree:
    def __init__(self):
        self.rootNode = None
    
    def __init__(self, data):
        for i in range(len(data)):
            self.Add_Node_To_Tree(data[i])
    
    def Add_Node_To_Tree(self, value):
        currentNode = self.rootNode
        if self.rootNode == None:
            self.rootNode = TreeNode(value)
            return
        while True:
            if value < currentNode.value:
                if currentNode.left_Node == None:
                    currentNode.left_Node = TreeNode(value)
                    return
                else:
                    currentNode = currentNode.left_Node
            else:
                if currentNode.right_Node == None:
                    currentNode.right_Node = TreeNode(value)
                else:
                    currentNode = currentNode.right_Node

