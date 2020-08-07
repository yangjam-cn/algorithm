#include "binaryTree.h"

BinaryTreeNode* create_BinaryTreeNode(int value)
{
    BinaryTreeNode *pNode = new BinaryTreeNode();
    pNode->m_nValue = value;
    pNode->m_pLeft = nullptr;
    pNode->m_pRight = nullptr;

    return pNode;
}


void connect_tree_nodes(BinaryTreeNode *pParent, BinaryTreeNode *pLeft,
    BinaryTreeNode *pRight)
{
    if (pParent != nullptr)
    {
        pParent->m_pLeft = pLeft;
        pParent->m_pRight = pRight;
    }
}

void print_tree_node(const BinaryTreeNode *pNode)
{
    if (pNode != nullptr)
    {
        printf("value of this node is: %d\n", pNode->m_nValue);

        if (pNode->m_pLeft != nullptr)
        {
            printf("value of its left child is: %d\n", pNode->m_pLeft->m_nValue);
        }
        else
        {
            printf("left child is nullptr.\n");
        }
        
        if (pNode->m_pRight != nullptr)
        {
            printf("value of its right child is: %d\n", pNode->m_pRight->m_nValue);
        }
        else
        {
            printf("right child is nullptr.\n");
        }
    }
    else
    {
        printf("this node is nullptr.\n");
    }
}

void print_tree(const BinaryTreeNode *pRoot)
{
    print_tree_node(pRoot);

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


void destory_tree(BinaryTreeNode *pRoot)
{
    if (pRoot != nullptr)
    {
        BinaryTreeNode *pLeft = pRoot->m_pLeft;
        BinaryTreeNode *pRight = pRoot->m_pRight;

        delete pRoot;
        pRoot = nullptr;

        destory_tree(pLeft);
        destory_tree(pRight);
    }
}