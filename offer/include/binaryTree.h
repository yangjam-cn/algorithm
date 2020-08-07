/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: bianryTree.h
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-08-06 21:41:26
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-08-06 22:05:59
 */
#pragma once
#include <cstdio>


struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};

/*创建二叉树结点*/
__declspec( dllexport) BinaryTreeNode* create_BinaryTreeNode(int value);

/*连接二叉树父子结点*/
__declspec( dllexport ) void connect_tree_nodes(BinaryTreeNode *pParent, 
    BinaryTreeNode *pLeft, BinaryTreeNode *pRight);

/*打印结点及其子结点的值*/
__declspec( dllexport ) void print_tree_node(const BinaryTreeNode *pNode);

/*x先序打印树*/
__declspec( dllexport ) void print_tree(const BinaryTreeNode *pRoot);

/*删除树*/
__declspec( dllexport ) void destory_tree(BinaryTreeNode *pRoot);