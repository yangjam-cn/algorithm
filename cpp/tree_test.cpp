/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: tree_test
 * @Description: 树的实现及相关操作
 * @Author: yangjam
 * @Version: demo
 * @Date: 2020-07-23 08:48:45
 * @History: 
    * 7.23 增加树的定义、完全二叉树的创建、遍历方式及复原算法 
    * 7.24 增加二叉搜索树
 * @LastEditTime: 2020-07-24 18:57:02
 */ 
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/* 叶子结点定义 */
struct node
{
    int data;        /* 数据域 */
    node *lchild;    /* 指向左子树根节点的指针 */
    node *rchild;    /* 指向右子树根节点的指针 */
};

vector<node*> g_preorder;     /* 先序序列 */
vector<node*> g_inorder;      /* 中序序列 */
vector<node*> g_postorder;    /* 后序序列 */
vector<node*> g_sequence;     /* 层序序列 */


/* 
 * 创建新结点 
 * 1. 申请结点空间
 * 2. 若结点指针非空，则数据域赋值，指针域赋nullptr
 * 3. 若结点指针为空，返回空指针
 */
node *create_node(int value)
{
    node *ptr = new node;
    /* 注：当new无法分配地址时，通常会引发异常 */
    if (ptr != nullptr)
    {
        ptr->data = value;
        ptr->lchild = ptr->rchild = nullptr;
        return ptr;
    }
    return nullptr;
}


/* 
 * 创建完全二叉树(complete binary tree)
 * 1. 如果根节点为空，则创建新结点，返回；
 * 2. 若根节点非空，则按层序的顺序访问结点，直到找到空结点为止，对空结点执行第一步；
 * 层序访问：
 * 1. 将根结点加入队列；
 * 2. 取出队首元素，访问左右结点，若均非空则将左右结点加入队列，进行下一轮循环，否则退出循环；
 * 3. 判断退出循环时结点指针的空结点域，创建新结点；
 */
void create_cbt(node* &root, int value)
{
    if (root == nullptr)
    {
        root = create_node(value);
        return;
    }

    queue<node*> q;

    node *ptr = root;
    q.push(root);
    while (ptr != nullptr)
    {
        ptr = q.front();
        if (ptr->lchild != nullptr)
        {
            q.push(ptr->lchild);
        }
        else
        {
            break;
        }
        if (ptr->rchild != nullptr)
        {
            q.push(ptr->rchild);
        }
        else
        {
            break;
        }
        q.pop();
    }

    if (ptr->lchild == nullptr)
    {
        ptr->lchild = create_node(value);
    }
    else
    {
        ptr->rchild = create_node(value);
    }
}


/*
 * 创建二叉搜索树(binary search tree)
 * 左子树上所有结点均小于等于根节点
 */
void create_bst(node* &root, int value)
{
    if (nullptr == root)             /* 根节点不存在，创建新结点 */
    {
        root = create_node(value);
        return;
    }
    if (value == root->data)        /* 结点在二叉树中已存在 */
    {
        return;
    }
    else if (value < root->data)    /* 小于根节点，添加到左子树 */
    {
        create_bst(root->lchild, value);
    }
    else                            /* 大于根节点，添加到右子树 */
    {
        create_bst(root->rchild, value);
    }

}


/*
 * 按后序访问的方式删除树
 * 1. 若根结点非空，则递归删除左子树与右子树
 * 2. 删除根节点，并置nullptr
 */
void delete_tree(node* &root)
{
    if (root != nullptr)
    {
        delete_tree(root->lchild);
        delete_tree(root->rchild);
        delete root;
        root = nullptr;
    }
}


/*
 * 先序遍历
 * 1. 访问根结点
 * 2. 递归访问左子树
 * 3. 递归访问右子树
 */
void preorder(node *root)
{
    if (root == nullptr)    /* 递归边界 */
    {
        return;
    }
    printf("%d ", root->data);
    g_preorder.push_back(root);
    preorder(root->lchild);
    preorder(root->rchild);
}

/*
 * 中序遍历
 * 1. 递归访问左子树
 * 2. 访问根结点
 * 3. 递归访问右子树
 */
void inorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->lchild);
    printf("%d ", root->data);
    g_inorder.push_back(root);
    inorder(root->rchild);
}

/*
 * 后序遍历
 * 1. 递归访问左子树
 * 2. 递归访问右子树
 * 3. 访问根节点
 */
void postorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d ", root->data);
    g_postorder.push_back(root);
}


/*
 * 层序遍历
 * 1. 若根节点非空，将根节点加入队列；
 * 2. 取出队首元素，访问该结点；
 * 3. 若结点的左右结点域非空，则依次加入队列；
 * 4. 若队列非空，则回到2，否则退出循环
 */
void seq_traversal(node *root)
{
   if (root != nullptr)
   {
       queue<node*> q;
       q.push(root);
       while (!q.empty())
       {
           node *ptr = q.front();

           printf("%d ", ptr->data);
           g_sequence.push_back(ptr);

           if (ptr->lchild != nullptr)
           {
               q.push(ptr->lchild);
           }
           if (ptr->rchild != nullptr)
           {
               q.push(ptr->rchild);
           }

           q.pop();
       }
       putchar('\n');
   } 
}


/*
 * 根据先序序列和中序序列恢复二叉树
 * 先序序列首元素为根节点，确定根节点在中序序列中的下标loc
 * 以根节点在中序的下标为间隔划分为左右子树两部分确定结点数量
 * 依据结点数量确定左右子树先序序列
 * 对左右子树递归确定根节点
 */
node *restore_preorder(int preL, int preR, int inL, int inR)
{
    /* 序列为空，返回空指针 */
    if (preL > preR)
    {
        return nullptr;
    }

    node *root = new node;    /* 创建新的根节点 */
    root->data = g_preorder[preL]->data;
    root->lchild = root->rchild = nullptr;

    int loc = inL;    /* 根节点在中序序列的下标 */
    for (loc = inL; loc <= inR; loc++)
    {
        if (g_inorder[loc]->data == root->data)
        {
            break;
        }
    }

    int numL = loc - inL;    /* 左子树结点数 */
    /* 左子树先序序列[preL + 1, preL + numL], 中序序列[inL, loc - 1] */
    root->lchild = restore_preorder(preL + 1, preL + numL, inL, loc - 1);
    /* 右子树先序序列[preL + numL + 1, preR], 中序序列[loc + 1, inR] */
    root->rchild = restore_preorder(preL + numL + 1, preR, loc + 1, inR);
    
    return root;
}


/*
 * 根据后序序列与中序序列复原二叉树
 */
node *restore_postorder(int postL, int postR, int inL, int inR)
{
    if (postL > postR)
    {
        return nullptr;
    }

    node *root = new node;
    root->data = g_postorder[postR]->data;
    root->lchild = root->rchild = nullptr;

    int loc = inL;
    for (loc = inL; loc <= inR; loc++)
    {
        if (g_inorder[loc]->data == root->data)
        {
            break;
        }
    }

    int numL = loc - inL;    /* 左子树结点数量 */
    root->lchild = restore_postorder(postL, postL + numL - 1, inL, loc - 1);
    root->rchild = restore_postorder(postL + numL, postR - 1, loc + 1, inR);

    return root;
}

/*
 * 根据层序序列与中序序列复原二叉树
 * 层序先后出现顺序确定了结点间父子关系
 * 中序确定了左右子树的分界
 */
node *restore_sequence(int seqL, int seqR, int inL, int inR)
{
    /* 
     * 中序序列确定了子树结点数量，当中序为空时，表明到达递归边界
     * 层序左右结点相互交叉，无法以结点数确立递归边界
     */
    if (inL > inR)
    {
        return nullptr;
    }

    int seq, loc;    /* seq结点在层序的下标，loc根节点在中序的下标 */
    /*
     * 因为层序根节点必在子节点前面出现，故从前往后遍历层序序列；
     * 对每一个结点遍历中序，若该结点在中序出现，该节点必为根节点；
     * 若没有出现在中序中，则该结点不属于此子树，切换下一结点；
     */
    for (seq = seqL; seq <= seqR; seq++)
    {
        /* 确定根节点，划分子树 */
        for (loc = inL; loc <= inR; loc++)
        {
            if (g_sequence[seq]->data == g_inorder[loc]->data)
            {
                break;
            }
        }
        /* 当层序首元素非子树序列元素时，loc=inR+1退出内循环 */
        /* 利用&&的阻断作用防止loc越界访问引发段错误 */
        if (loc <= inR && g_sequence[seq]->data == g_inorder[loc]->data)
        {
            break;
        }
    }
    /* 先确定根节点再赋值 */
    node *root = new node;
    root->data = g_sequence[seq]->data;
    /* 递归寻访子树根节点 */
    /* seq确定了根节点在层序的下标，则其子节点必在其后 */
    root->lchild = restore_sequence(seq + 1, seqR, inL, loc - 1);
    root->rchild = restore_sequence(seq + 1, seqR, loc + 1, inR);

    return root;
}

/* 以先序、中序、后序、层序的方式遍历树 */
void traversal(node *root)
{
    printf("preorder: ");
    preorder(root);
    putchar('\n');

    printf("inprder: ");
    inorder(root);
    putchar('\n');

    printf("postorder: ");
    postorder(root);
    putchar('\n');

    printf("sequence: ");
    seq_traversal(root);
    putchar('\n');
}

int main(void)
{
    node *root = nullptr;    /* 初始化根结点为nullptr */
    int size, value;         /* size为二叉树规模，value为结点数据域 */

    srand((unsigned)time(nullptr));

    scanf("%d", &size);

    /* 完全二叉树 */
    // for (int i = 0; i < size; i++)
    // {
    //     value = rand() % 100;
    //     printf("%d ", value);
    //     create_cbt(root, value);
    // }
    // putchar('\n');
    // traversal(root);

    // vector<node*>::iterator it;
    // printf("inorder: ");
    // for (it = g_inorder.begin(); it != g_inorder.end(); it++)
    // {
    //     printf("%d ", (*it)->data);
    // }
    // putchar('\n');

    // node *preRoot = restore_preorder(0, g_preorder.size() - 1, 0, 
    //     g_inorder.size() - 1);
    // printf("preorder: ");
    // preorder(preRoot);
    // putchar('\n');

    // node *postRoot = restore_postorder(0, g_postorder.size() - 1,
    //     0, g_inorder.size() - 1);
    // printf("postorder: ");
    // postorder(postRoot);
    // putchar('\n');

    // node *seqRoot = restore_sequence(0, g_sequence.size() - 1, 
    //     0, g_inorder.size() - 1);
    // printf("sequence order: ");
    // seq_traversal(seqRoot);

    // delete_tree(root);
    // delete_tree(preRoot);
    // delete_tree(postRoot);
    // delete_tree(seqRoot);

    /* 测试二叉搜索树 */
    for (int i = 0; i < size; i++)
    {
        value = rand() % 100;
        printf("%d ", value);
        create_bst(root, value);
    }
    putchar('\n');
    
    traversal(root);

    /* 测试bst复原 */
    node *preRoot = restore_sequence(0, g_sequence.size() - 1,
        0, g_inorder.size() - 1);
    traversal(preRoot);
    delete_tree(preRoot);

    delete_tree(root);

    return 0;
}
