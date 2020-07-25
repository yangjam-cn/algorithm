/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: tree_avl
 * @Description: 二叉平衡树
 * @Author: yangjam
 * @Version: demo
 * @Date: 2020-07-25 18:59:45
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-07-25 21:11:21
 */ 
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <queue>

using namespace std;


/* 二叉平衡树结点 */
struct node
{
    int  value;      /* 数据域 */
    int  height;     /* 结点高度 */
    node *lchild;    /* 左子树 */
    node *rchild;    /* 右子树 */
};


/* 创建新结点 */
node *create_node(int value)
{
    node *root = new node;
    if (root != nullptr)
    {
        root->value = value;
        root->height = 1;    /* 非空结点初始化高度为1 */
        root->lchild = root->rchild = nullptr;
    }
    return root;
}


/* 返回结点高度 */
int get_height(node *root)
{
    if (nullptr == root)
    {
        return 0;
    }
    else
    {
        return root->height;
    }
    
}


/* 更新结点高度 */
void update_height(node* &root)
{
    root->height = max(get_height(root->lchild), get_height(root->rchild)) + 1;
}


/* 计算结点的平衡因子 */
int get_balance_factor(node *root)
{
    return get_height(root->lchild) - get_height(root->rchild);
}


/* 左旋操作 */
void left_rotation(node* &root)
{
    node *ptr = root->rchild;      /* 保存右子树结点 */
    root->rchild = ptr->lchild;    /* 更新结点右子树为右子树结点的左子树 */
    ptr->lchild = root;            /* 右子树的左子树更新为根结点 */

    update_height(root);           /* 先更新原根节点的高度，父节点的高度依赖子节点确定 */
    update_height(ptr);            /* 后更新新根节点的高度 */

    root = ptr;                    /* 更新根节点 */
}

/* 右旋操作 */
void right_rotation(node* &root)
{
    node *ptr = root->lchild;      /* 保存左子树结点 */
    root->lchild = ptr->rchild;    /* 更新结点左子树为其右子树结点的左子树 */
    ptr->rchild = root;            /* 左子树的右子树更新为根结点 */

    update_height(root);
    update_height(ptr);

    root = ptr;
}

void insert(node* &root, int value)
{
    if (nullptr == root)
    {
        root = create_node(value);
        return;
    }
    if (value == root->value)
    {
        return;
    }
    else if (value < root->value)
    {
        insert(root->lchild, value);
        update_height(root);
        if (get_balance_factor(root) == 2)
        {
            if (get_balance_factor(root->lchild) == 1)
            {
                right_rotation(root);
            }
            else if (get_balance_factor(root->lchild) == -1)
            {
                left_rotation(root->lchild);
                right_rotation(root);
            }
        }
    }
    else
    {
        insert(root->rchild, value);
        update_height(root);
        if (get_balance_factor(root) == -2)
        {
            if (get_balance_factor(root->rchild) == -1)
            {
                left_rotation(root);
            }
            else if (get_balance_factor(root->rchild) == 1)
            {
                right_rotation(root->rchild);
                left_rotation(root);
            }
        }
    }
}

void inorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->lchild);
    cout << root->value << " ";
    inorder(root->rchild);
}

void preorder(node *root)
{
    if (nullptr == root)
    {
        return;
    }
    cout << root->value << " ";
    preorder(root->lchild);
    preorder(root->rchild);
}

void delete_tree(node* &root)
{
    if (root != nullptr)
    {
        delete_tree(root->lchild);
        delete_tree(root->rchild);
        delete root;
        root = nullptr;
    }
    return;
}

int main(void)
{
    int size, value;
    node *root = nullptr;
    cin >> size;
    srand((unsigned int)time(nullptr));
    for (int i = 0; i < size; i++)
    {
        value = rand() % 100;
        cout << value << " ";
        insert(root, value);
    }
    putchar('\n');

    preorder(root);
    putchar('\n');

    inorder(root);
    putchar('\n');

    delete_tree(root);
    return 0;
}