// 二叉树的链表实现
// 2020.4.6
#include<stdio.h>
#include<malloc.h>
#include<time.h>
#include<stdlib.h>


#define N 10

typedef int data_type;
typedef struct TreeNode {
    data_type data;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
}tree_node;
typedef tree_node *btree;

btree create_tree(btree root, data_type data)
{
    btree new_node = (btree)malloc(sizeof(tree_node));
    if (new_node != NULL) {
        new_node->data = data;
        new_node->lchild = NULL;
        new_node->rchild = NULL;
        if (root == NULL) {
            root = new_node;
            return root;
        }
        else {
            btree ptr = root, current;
            while (ptr != NULL) {
                current = ptr;
                if (ptr->data > data)
                    ptr = ptr->lchild;
                else
                    ptr = ptr->rchild;
            }
            if (current->data > data)
                current->lchild = new_node;
            else 
                current->rchild = new_node;
        }
        return root;
    }
    else {
        printf("Failed to create new node!\n");
        exit(-1);
    }
}

void free_tree(btree node)
{
    if (node != NULL) {
        free_tree(node->lchild);
        free_tree(node->rchild);
        printf("%d\t", node->data);
        free(node);
        node = NULL;
    }
}

void main(void)
{
    data_type array[N];
    btree root = NULL;
    srand((unsigned int)time(NULL));
    for (int i = 0; i < N; i++) {
        array[i] = rand() % 20;
        printf("%d\t", array[i]);
        root = create_tree(root, array[i]);
    }
    printf("\n");
    btree ptr = root;
    printf("left subtree:\n");
    ptr = root;
    while (ptr != NULL) {
        printf("%d\t", ptr->data);
        ptr = ptr->lchild;
    }
    printf("\n");
    free_tree(root);
    printf("\n");
}