/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: BFS_exp1
 * @Description: 
    * 给出一个m*n的矩阵，矩阵中的元素为0或1。称位置(x,y)与其上下左右四个位置是相邻的。如果矩阵中有若干个1是相邻的(不必两两相邻)，那么称这些1构成一个“块”。求给定矩阵中“块”的数量。
    * 0111001
    * 0010000
    * 0000100
    * 0001110
    * 1110100
    * 1111000
 * @Author: yangjam
 * @Version: demo
 * @Date: 2020-07-22 12:31:55
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-07-24 18:59:12
 */ 
/*
BFS模板
void BFS(int s)
{
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        取出队首元素top；
        访问队首元素top；
        将队首元素出队；
        将top的下一层结点中未曾入队的结点全部入队，并标记为已入队；
    }
}
 */
#include <queue>
#include <cstdio>
using namespace std;

const int MAX_SIZE = 20;

struct coordinates
{
    int m_x, m_y;
}loc;

int row, col;
int matrix[MAX_SIZE][MAX_SIZE];
bool enqueued[MAX_SIZE][MAX_SIZE] = {false};

int move_x[4] = {0, 0, -1, 1};
int move_y[4] = {-1, 1, 0, 0};

/**
 * @Function: judge
 * @Description: 判断该坐标是否需要访问
 * @Input: 
    * x：行坐标
    * y: 列坐标
 * @Output: 
 * @Return: 若坐标合法且当前位置为1且未访问过则返回true，否则返回false 
 * @Others: 
 */
bool judge(int x, int y)
{
    /* 坐标越界返回false */
    if ((x >= row) || (x < 0) || (y >= col) || (y < 0))
    {
        return false;
    }
    /* 当前位置为0或已访问过则跳过 */
    if ((0 == matrix[x][y]) || enqueued[x][y])
    {
        return false;
    }
    return true;
}


/**
 * @Function: BFS
 * @Description: 广度优先搜索
 * @Input: 
 * @Output: 
 * @Return: 
 * @Others: 
 */
void BFS(int x, int y)
{
    queue<coordinates> q;
    loc.m_x = x;
    loc.m_y = y;
    q.push(loc);
    enqueued[x][y] = true;
    while (!q.empty())
    {
        coordinates top = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int new_x = top.m_x + move_x[i];
            int new_y = top.m_y + move_y[i];
            if (judge(new_x, new_y))
            {
                loc.m_x = new_x;
                loc.m_y = new_y;
                q.push(loc);
                enqueued[new_x][new_y] = true;
            }
        }
    }
}

int main(void)
{
    scanf("%d %d", &row, &col);
    for (int x = 0; x < row; x++)
    {
        for (int y = 0; y < col; y++)
        {
            scanf("%d", &matrix[x][y]);
        }
    }
    int blocks = 0;
    for (int x = 0; x < row; x++)
    {
        for (int y = 0; y < col; y++)
        {
            if (1 == matrix[x][y] && !enqueued[x][y])
            {
                blocks++;
                BFS(x, y);
            }
        }
    }
    printf("%d", blocks);
    return 0;
}