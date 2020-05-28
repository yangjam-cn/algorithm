/*
 *二叉搜索树的实现
 *2020年 04月 15日 星期三 13:05:10 CST
 *youngjam
*/
#include<malloc.h>
#include<stdlib.h>
#include "datatype.h"

/*====== 定义列表 ======*/
#define true 1
#define false 0
/* 定义树形结构体 */
typedef struct TreeNode *tree;
typedef struct TreeNode {
    data_type data;
    tree left_child;
    tree right_child;
} tree_node;

/*====== 函数列表 ======*/


/* 检查malloc函数分配地址是否成功 */
int is_null(void *ptr);
/* 初始化函数 */
tree init_tree(tree root);
/* 创建新的节点 */
tree new_node(void);
/* 创建二叉搜索树 */
void build_tree(tree root);
/* 删除二叉树 */
tree delete_tree(tree root);
/* 先序遍历 */
void preorder_traversal(tree root);
/* 中序遍历 */
void inorder_traversal(tree root);
/* 后序遍历 */
void postorder_traversal(tree root);

/*
 *判断malloc函数分配地址空间是否成功，否则异常退出
*/
int is_null(void *ptr)
{
    if (ptr == NULL) {
        printf("memory allocation failure!\n");
        exit(-1);
    }
    else
        return false;
}

/*
 *初始化树根节点
*/
tree init_tree(tree root)
{
    if (root == NULL) {
        root = (tree)malloc(sizeof(tree_node));
        if (!is_null(root)) {
            root->left_child = NULL;
            root->right_child = NULL;
            get_data(&(root->data));
        } 
    }
    else {
        printf("root is not null!\n");
    }
    return root;
}

/*
 *创建新节点
*/
tree new_node(void)
{
    tree node = (tree)malloc(sizeof(tree_node));
    if (!is_null(node)) {
        node->left_child = NULL;
        node->right_child = NULL;
        get_data(&(node->data));
        return node;
    }
}

/*
 *创建二叉搜索树
*/
void build_tree(tree root)
{
    if (root == NULL) {
        printf("root is null!\n");
        return;
    }
    else {
        tree node = new_node();
        tree current = root, backup = NULL;
        while (current != NULL) {
            backup = current;
            if (compare_element(node->data, current->data))
                current = current->right_child;
            else 
                current = current->left_child;
        }
        if (compare_element(node->data, backup->data))
            backup->right_child = node;
        else 
            backup->left_child = node;
    }
}

/* 
 *删除二叉树
*/
tree delete_tree(tree root)
{
    if (root != NULL) {
        delete_tree(root->left_child);
        delete_tree(root->right_child);
        free(root);
        root = NULL;
    }
    return root;
}

/*  
 *先序遍历==》中左右
*/
void preorder_traversal(tree root)
{
    if (root != NULL) {
        print_data(root->data);
        preorder_traversal(root->left_child);
        preorder_traversal(root->right_child);
    }
}
/*
 *中序遍历==》左中右
*/
void inorder_traversal(tree root)
{
    if (root != NULL) {
        inorder_traversal(root->left_child);
        print_data(root->data);
        inorder_traversal(root->right_child);
    }
}

/* 
 *后序遍历==》左右中
*/
void postorder_traversal(tree root)
{
    if (root != NULL) {
        postorder_traversal(root->left_child);
        postorder_traversal(root->right_child);
        print_data(root->data);
    }
}