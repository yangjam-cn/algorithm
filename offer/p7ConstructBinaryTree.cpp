/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: p7ConstructBinaryTree.cpp
 * @Description: 重建二叉树
 * 题目：输入某二叉树的前序遍历和中序遍历的结果，重建出该二叉树。
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-08-07 08:52:53
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-08-07 10:39:02
 */
#include "include/binaryTree.h"


/*重建二叉树*/
BinaryTreeNode* construct_core(int *startPreorder, int *endPreorder, int *startInorder,
    int *endInorder);

BinaryTreeNode* construct(int *preorder, int *inorder, int length)
{
    /*输入合法性检查*/
    if (nullptr == preorder || nullptr == inorder || length <= 0)
    {
        return nullptr;
    }
    else
    {
        return construct_core(preorder, preorder + length - 1, inorder, inorder + length - 1);
    }
}

BinaryTreeNode* construct_core(int *startPreorder, int *endPreorder, int *startInorder, 
    int *endInorder)
{
    int rootValue = startPreorder[0];    /*前序的首元素为根结点*/
    BinaryTreeNode *root = new BinaryTreeNode();    /*创建根结点*/
    root->m_nValue = rootValue;
    root->m_pLeft = nullptr;
    root->m_pRight = nullptr;

    /*若前序序列只有一位元素，则元素为根结点*/
    if (startPreorder == endPreorder)
    {
        /*检查后序与前序是否一致*/
        if (startInorder == endInorder && *startPreorder == *startInorder)
        {
            return root;
        }
        else
        {
            throw "Invalid input.";    /*当前序和后序不一致时，抛出异常*/
        }
    }

    int *rootInorder = startInorder;    /*根节点在中序中的地址*/
    while (rootInorder <= endInorder && *rootInorder != rootValue)
    {
        ++rootInorder;
    }

    if (rootInorder ==  endInorder && rootValue != *rootInorder)
    {
        throw "Invalid input.";    /*节点不在中序序列中，抛出异常*/
    }

    int leftLength = rootInorder - startInorder;    /*左子树长度*/
    int *leftPreorderEnd = startPreorder + leftLength;    /*左子树序列在前序序列中的尾结点*/
    /*
     * 若rootInorder = startInorder，则leftLength = 0，左子树为空
     * 若rootInorder < endPreorder, 0 < leftLength < endP-startP，左右子树均非空
     * 若rootInorder = endPreorder，则leftLength = endP-startP，右子树为空
     */
    if (leftLength > 0)
    {
        root->m_pLeft = construct_core(startPreorder + 1, leftPreorderEnd, 
            startInorder, rootInorder -1);
    }
    if (leftLength < endPreorder - startPreorder)
    {
        root->m_pRight = construct_core(leftPreorderEnd + 1, endPreorder,
            rootInorder + 1, endInorder);
    }

    return root;
}


/*===========test code============*/
void test(const char *testName, int *preorder, int *inorder, int length)
{
    if (testName != nullptr)
    {
        printf("%s begins:\n", testName);
    }

    printf("The preorder sequence is :");
    for (int i = 0; i < length; ++i)
    {
        printf("%d\t", preorder[i]);
    }
    printf("\n");

    printf("The inorder sequence is :");
    for (int i = 0; i < length; ++i)
    {
        printf("%d\t", inorder[i]);
    }
    printf("\n");

    try
    {
        BinaryTreeNode *root = construct(preorder, inorder, length);
        print_tree(root);

        destory_tree(root);
    }
    catch(const char *str)
    {
        printf("%s\n", str);
    }
}

void test1()
{
    const int length = 8;
    int preorder[length] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inorder[length] = {4, 7, 2, 1, 5, 3, 8, 6};

    test("test1", preorder, inorder, length);
}

void test2()
{
    const int length = 5;
    int preorder[length] = {1, 2, 3, 4, 5};
    int inorder[length] = {5, 4, 3, 2, 1};

    test("test2", preorder, inorder, length);
}

void test3()
{
    const int length = 5;
    int preorder[length] = {1, 2, 3, 4, 5};
    int inorder[length] = {1, 2, 3, 4, 5};

    test("test3", preorder, inorder, length);
}

void test4()
{
    const int length = 1;
    int preorder[length] = {1};
    int inorder[length] = {1};

    test("test4", preorder, inorder, length);
}

void test5()
{
    const int length = 7;
    int preorder[length] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[length] = {4, 2, 5, 1, 6, 3, 7};

    test("test5", preorder, inorder, length);
}

void test6()
{
    test("test6", nullptr, nullptr, 0);
}

void test7()
{
    const int length = 7;
    int preorder[length] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[length] = {4, 2, 8, 1, 6, 3, 7};

    test("test7", preorder, inorder, length);
}

int main(void)
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
}