# 2020.1.13
# 树的遍历
class tree:
    def __init__(self):
        self.val = 0
        self.left = None
        self.right = None


def create_tree(root, val):
    new_node = tree()
    new_node.val = val
    new_node.left = None
    new_node.right = None
    if root == None:
        root = new_node
        return root
    else:
        current = root
        while current != None:
            backup = current
            if val > current.val:
                current = current.right
            else:
                current = current.left
        if backup.val > val:
            backup.left = new_node
        else:
            backup.right = new_node
        return root


data = [2, 4, 6, 8, 1, 3, 5, 7, 9]
ptr = None
root = None
for i in range(9):
    root = create_tree(root, data[i])
ptr = root


# 中序遍历 left->root->right
# t2->t1->None->p1->None->p2->t4->t3->None->p3->None->p4->t6->t5->None->p5->None->p6->t8->t7->None->p7->None->p8->t9->None->p9->None->None
def Inorder_traversal(ptr):
    if ptr != None:
        Inorder_traversal(ptr.left)
        print(ptr.val, end='\t')
        Inorder_traversal(ptr.right)
Inorder_traversal(ptr)
print()

# 后序遍历 left->right->root
# t2->t1->None->r1->None->r1_p1->r2->t4->t3->None->r3->None->r3_p3->r4->t6->t5->None->r5->None->r5_p5->r6->t8->t7->None->r7->None->r7_p7->r8->t9->None->r9->None->r9_p9->r8_p8->r6_p8->r4_p4->r2_p2->end
def Postorder_traversal(ptr):
    if ptr != None:
        Postorder_traversal(ptr.left)
        Postorder_traversal(ptr.right)
        print(ptr.val, end='\t')
Postorder_traversal(ptr)
print()

# 前序遍历 root->left->right
# p2->t1_p1->None->None->r2->t4_p4->t3_p3->None->None->r4->t6_p6->t5_p5->None->None->r6->t8_p8->t7_p7->None->None->r8->t9_p9->None->None->end
def Preorder_traversal(ptr):
    if ptr != None:
        print(ptr.val, end='\t')
        Preorder_traversal(ptr.left)
        Preorder_traversal(ptr.right)
Preorder_traversal(ptr)
print()




