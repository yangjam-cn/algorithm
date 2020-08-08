/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: p8NextNodeBinaryTrees.cpp
 * @Description: 二叉树的下一个结点
 * 题目：给定一颗二叉树和其中的一个结点，找出中序遍历的下一个结点，树中的结点除了左右结点外还有指向
 * 父结点的指针
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-08-07 14:10:45
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-08-07 17:02:12
 */
#include <cstdio>

struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
    BinaryTreeNode *m_pParent;
};


/*
 * 中序 左->父->右
 * s1:右子树为空
    * 本身为根，next = null 
    * 本身为左子树，next = parent
    * 本身为右子树，next = parent->parent... (until parent = parent->parent->left)
 * s2:右子树非空，next=right->left... (until right->left = null)
 */
BinaryTreeNode* get_next(BinaryTreeNode *pNode)
{
    if (nullptr == pNode)
    {
        return nullptr;
    }

    BinaryTreeNode *pNext = nullptr;
    
    /*右子树非空*/
    if (pNode->m_pRight != nullptr)
    {
        pNext = pNode->m_pRight;
        while (pNext->m_pLeft != nullptr)
        {
            pNext = pNext->m_pLeft;
        }
    }
    /*右子树为空*/
    // else
    // {
    //     /*父节点非空*/
    //     if (pNode->m_pParent != nullptr)
    //     {
    //         BinaryTreeNode *curNode = pNode;
    //         BinaryTreeNode *parentNode = pNode->m_pParent;
    //         if (curNode == parentNode->m_pLeft)    /*本身为左子树*/
    //         {
    //             pNext = parentNode;
    //         }
    //         else    /*右子树*/
    //         {
    //             while (curNode != parentNode->m_pLeft)
    //             {
    //                 curNode = parentNode;
    //                 parentNode = parentNode->m_pParent;
    //             }
    //             pNext = curNode;
    //         }
    //     }
    // }
    else if (pNode->m_pParent != nullptr)
    {
        BinaryTreeNode *pCurrent = pNode;
        BinaryTreeNode *pParent = pNode->m_pParent;
        while (pParent != nullptr && pCurrent == pParent->m_pRight)
        {
            pCurrent = pParent;
            pParent = pParent->m_pParent;
        }    /*end while*/
        pNext = pParent;
    }

    return pNext;
}


/*========================*/
/*新建二叉树结点*/
BinaryTreeNode* create_binary_tree(int value)
{
    BinaryTreeNode *pNode = new BinaryTreeNode();
    pNode->m_nValue = value;
    pNode->m_pLeft = nullptr;
    pNode->m_pRight = nullptr;
    pNode->m_pParent = nullptr;

    return pNode;
}


/*连接二叉树结点*/
void connect_tree_node(BinaryTreeNode *pParent, BinaryTreeNode *pLeft, 
    BinaryTreeNode *pRight)
{
    if (pParent != nullptr)
    {
        pParent->m_pLeft = pLeft;
        pParent->m_pRight = pRight;

        if (pLeft != nullptr)
        {
            pLeft->m_pParent = pParent;
        }
        if (pRight != nullptr)
        {
            pRight->m_pParent = pParent;
        }
    }
}


/*打印二叉树结点信息*/
void print_tree_node(BinaryTreeNode *pNode)
{
    if (pNode != nullptr)
    {
        printf("vlaue of this node is: %d\n", pNode->m_nValue);

        if (pNode->m_pLeft != nullptr)
        {
            printf("vlaue of its left child is: %d\n", pNode->m_pLeft->m_nValue);
        }
        else
        {
            printf("left child is null.\n");
        }

        if (pNode->m_pRight != nullptr)
        {
            printf("value of its left child is: %d\n", pNode->m_pRight->m_nValue);
        }
        else
        {
            printf("right child is null.\n");
        }
    }
}


/*打印二叉树*/
void print_tree(BinaryTreeNode *pRoot)
{
    print_tree(pRoot);

    if (pRoot != nullptr)
    {
        if (pRoot->m_pLeft != nullptr)
        {
            print_tree(pRoot->m_pLeft);
        }
        if (pRoot->m_pRight != nullptr)
        {
            print_tree(pRoot->m_pRight);
        }
    }
}


/*删除二叉树*/
void destory_tree(BinaryTreeNode *pRoot)
{
    if (pRoot != nullptr)
    {
        destory_tree(pRoot->m_pLeft);
        destory_tree(pRoot->m_pRight);
        delete pRoot;
    }
}


/*============test code============*/
void test(const char *testName, BinaryTreeNode *pNode, BinaryTreeNode *expected)
{
    if (testName != nullptr)
    {
        printf("%s begins: ", testName);
    }

    BinaryTreeNode *pNext = get_next(pNode);
    if (pNext == expected)
    {
        printf("passed.\n");
    }
    else
    {
        printf("failed.\n");
    }
}


void test1_7()
{
    BinaryTreeNode *pNode8 = create_binary_tree(8);
    BinaryTreeNode *pNode6 = create_binary_tree(6);
    BinaryTreeNode *pNode10 = create_binary_tree(10);
    BinaryTreeNode *pNode5 = create_binary_tree(5);
    BinaryTreeNode *pNode7 = create_binary_tree(7);
    BinaryTreeNode *pNode9 = create_binary_tree(9);
    BinaryTreeNode *pNode11 = create_binary_tree(11);

    connect_tree_node(pNode8, pNode6, pNode10);
    connect_tree_node(pNode6, pNode5, pNode7);
    connect_tree_node(pNode10, pNode9, pNode11);

    test("test1", pNode8, pNode9);
    test("test2", pNode6, pNode7);
    test("test3", pNode10, pNode11);
    test("test4", pNode5, pNode6);
    test("test5", pNode7, pNode8);
    test("test6", pNode9, pNode10);
    test("test7", pNode11, nullptr);

    destory_tree(pNode8);
}

int main(void)
{
    test1_7();
    return 0;
}